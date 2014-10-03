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
        
    }
    
    ~StateMachineViewer()
    { 
        delete m_interface;
    }
    
    void setStateMachine(QStateMachine* sm)
    {
        m_interface->setSelectedStateMachine(sm);
    }
};

