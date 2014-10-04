#StateMachineViewer

StateMachineViewer is a class to visualize state machines which use Qt's QStateMachine.

It monitors a running state machine and shows which state is active and through which transition it was entered.

Images could be saved at different resolutions to disk.


##Usage

StateMachineViewer is designed to be linked into an existing application.

Projects using CMake should add this project with 'add_subdirectory()' and link against 'statemachineviewer'.

Example code:
```
#include "statemachineviewer.h"

StateMachineViewer* showStateMachine(QStateMachine* machine)
{
    StateMachineViewer* smv = new StateMachineViewer();
    smv->setStateMachine(machine);
    smv->show();
    return smv;
}
```

Also see example/trafficlight.

##Thanks
Thx to the GammayRay and  Graphviz teams, on whose work StateMachineViewer is based on.

##License
License is GPL.

While developing you could also use StateMachineViewer in closed source projects as long as you don't
link against StateMachineViewer in the final product.

