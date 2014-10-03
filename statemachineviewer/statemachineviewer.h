#pragma once

#include "statemachineviewerwidget.h"

class GAMMARAY_EXPORT StateMachineViewer : public GammaRay::StateMachineViewerWidget
{
public:
    StateMachineViewer(QWidget *parent = 0, bool left2right = false);
    
    ~StateMachineViewer();
    
    void setStateMachine(QStateMachine*);
};

