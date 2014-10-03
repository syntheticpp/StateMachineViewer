
include_directories(${smvdir})

qt_moc(moced trafficlight.h)
add_executable(trafficlight main.cpp trafficlight.h ${moced})
target_link_libraries(trafficlight statemachineviewer)
