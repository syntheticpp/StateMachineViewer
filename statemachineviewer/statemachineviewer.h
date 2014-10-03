#pragma once

#include "statemachineviewerclient.h"
#include "statemachineviewerserver.h"
#include "statemachineviewerwidget.h"


class StateMachineViewer : public GammaRay::StateMachineViewerWidget
{
public:
    StateMachineViewer(QWidget *parent = 0, bool left2right = false) : 
        GammaRay::StateMachineViewerWidget(left2right, new GammaRay::StateMachineViewerServer, parent)
    {
        setWindowTitle(QLatin1String("StateMachineViewer"));   
    }
    
    ~StateMachineViewer()
    { 
        delete m_interface;
    }
    
    void setStateMachine(QStateMachine* sm)
    {
        m_interface->setSelectedStateMachine(sm);
        if (!sm->objectName().isEmpty()) {
            setWindowTitle(QString(QLatin1String("State machine: '%1'")).arg(sm->objectName()));   
        }
    }
};

