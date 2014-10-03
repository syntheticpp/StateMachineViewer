#include "statemachineviewer.h"
#include "statemachineviewerserver.h"
#include "statemachineviewerwidget.h"


StateMachineViewer::StateMachineViewer(QWidget *parent, bool left2right) : 
        GammaRay::StateMachineViewerWidget(left2right, new GammaRay::StateMachineViewerServer, parent)
{
    setWindowTitle(QLatin1String("StateMachineViewer"));   
}
    
StateMachineViewer::~StateMachineViewer()
{ 
    delete m_interface;
}
    
void StateMachineViewer::setStateMachine(QStateMachine* sm)
{
    m_interface->setSelectedStateMachine(sm);
    if (!sm->objectName().isEmpty()) {
        setWindowTitle(QString(QLatin1String("State machine: '%1'")).arg(sm->objectName()));   
    }
}


