/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "trafficlight.h"

#include <QStateMachine>
#include <QFinalState>
#include <QVBoxLayout>
#include <QTimer>
#include <QApplication>


#include "statemachineviewer.h"


StateMachineViewer* showStateMachine(QStateMachine* machine)
{
    StateMachineViewer* smv = new StateMachineViewer();
    smv->setStateMachine(machine);
    smv->show();
    return smv;
}


class TrafficLightWidget : public QWidget
{
public:
    TrafficLightWidget(QWidget *parent = 0)
        : QWidget(parent)
    {
        QVBoxLayout *vbox = new QVBoxLayout(this);
        m_red = new LightWidget(Qt::red);
        vbox->addWidget(m_red);
        m_yellow = new LightWidget(Qt::yellow);
        vbox->addWidget(m_yellow);
        m_green = new LightWidget(Qt::green);
        vbox->addWidget(m_green);
        QPalette pal = palette();
        pal.setColor(QPalette::Background, Qt::black);
        setPalette(pal);
        setAutoFillBackground(true);
    }

    LightWidget *redLight() const
        { return m_red; }
    LightWidget *yellowLight() const
        { return m_yellow; }
    LightWidget *greenLight() const
        { return m_green; }

private:
    LightWidget *m_red;
    LightWidget *m_yellow;
    LightWidget *m_green;
};


QState *createLightState(LightWidget *light, int duration, QState *parent = 0)
{
    QState *lightState = new QState(parent);
    QTimer *timer = new QTimer(lightState);
    timer->setInterval(duration);
    timer->setSingleShot(true);
    QState *timing = new QState(lightState);
    QObject::connect(timing, SIGNAL(entered()), light, SLOT(turnOn()));
    QObject::connect(timing, SIGNAL(entered()), timer, SLOT(start()));
    QObject::connect(timing, SIGNAL(exited()), light, SLOT(turnOff()));
    QFinalState *done = new QFinalState(lightState);
    timing->addTransition(timer, SIGNAL(timeout()), done);
    lightState->setInitialState(timing);
    return lightState;
}


class TrafficLight : public QWidget
{
    StateMachineViewer* smv;
    
public:
    TrafficLight(QWidget *parent = 0)
        : QWidget(parent)
    {
        QVBoxLayout *vbox = new QVBoxLayout(this);
        TrafficLightWidget *widget = new TrafficLightWidget();
        vbox->addWidget(widget);
        vbox->setMargin(0);

        QStateMachine *machine = new QStateMachine(this);
        machine->setObjectName("Traffic light");
        QState *redGoingYellow = createLightState(widget->redLight(), 3000);
        redGoingYellow->setObjectName("redGoingYellow");
        QState *yellowGoingGreen = createLightState(widget->yellowLight(), 1000);
        yellowGoingGreen->setObjectName("yellowGoingGreen");
        redGoingYellow->addTransition(redGoingYellow, SIGNAL(finished()), yellowGoingGreen);
        QState *greenGoingYellow = createLightState(widget->greenLight(), 3000);
        greenGoingYellow->setObjectName("greenGoingYellow");
        yellowGoingGreen->addTransition(yellowGoingGreen, SIGNAL(finished()), greenGoingYellow);
        QState *yellowGoingRed = createLightState(widget->yellowLight(), 1000);
        yellowGoingRed->setObjectName("yellowGoingRed");
        greenGoingYellow->addTransition(greenGoingYellow, SIGNAL(finished()), yellowGoingRed);
        yellowGoingRed->addTransition(yellowGoingRed, SIGNAL(finished()), redGoingYellow);

        machine->addState(redGoingYellow);
        machine->addState(yellowGoingGreen);
        machine->addState(greenGoingYellow);
        machine->addState(yellowGoingRed);
        machine->setInitialState(redGoingYellow);
        machine->start();
        
        smv = showStateMachine(machine);
    }
    
   
    void closeEvent(QCloseEvent*)
    {
        delete smv;
        qApp->quit();
    }

};


int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    TrafficLight widget;
    widget.resize(110, 300);
    widget.show();

    return app.exec();
}



