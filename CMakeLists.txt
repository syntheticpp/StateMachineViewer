cmake_minimum_required(VERSION 2.8.9)

project(statemachineviewer)

cmake_policy(SET CMP0020 NEW) # link qtmain
set(QT_USE_IMPORTED_TARGETS true)
find_package(Qt4 ${QT_MIN_VERSION} REQUIRED QtCore QtGui)
include(${QT_USE_FILE})


set(LIBCGRAPHVIZ_DLL 1)
add_subdirectory(libcgraphviz)
set(GRAPHVIZ_MAJOR_VERSION ${LIBCGRAPHVIZ_MAJOR_VERSION})
set(GRAPHVIZ_MINOR_VERSION ${LIBCGRAPHVIZ_MINOR_VERSION})
set(GRAPHVIZ_PATCH_VERSION ${LIBCGRAPHVIZ_PATCH_VERSION})
set(GRAPHVIZ_GRAPH_LIBRARY ${LIBCGRAPHVIZ_LIBRARY})
set(GRAPHVIZ_INCLUDE_DIR ${LIBCGRAPHVIZ_INCLUDE_DIR})
set(GRAPHVIZ_FOUND 1)
set(GRAPHVIZ_GVC_LIBRARY "")
set(GRAPHVIZ_EMBEDDED 1)

add_definitions(-DGRAPHVIZ_MAJOR_VERSION=${GRAPHVIZ_MAJOR_VERSION} -DGRAPHVIZ_MINOR_VERSION=${GRAPHVIZ_MINOR_VERSION})
add_definitions(${LIBCGRAPHVIZ_DEFINITIONS})

add_definitions(-DGAMMARAY_GRAPHVIZ_EMBEDDED)
add_definitions(${GRAPHVIZ_COMPILE_FLAGS})

include_directories(${GRAPHVIZ_INCLUDE_DIR} ${GRAPHVIZ_INCLUDE_DIR}/graphviz)


qt4_wrap_ui(uiced statemachineviewer.ui)

set(sources
    statemachineviewerinterface.cpp
    #server
    statemachineviewerserver.cpp
    transitionmodel.cpp
    statemodel.cpp
    statemachinewatcher.cpp
    # gui & client
    statemachineviewerclient.cpp
    statemachineview.cpp
    statemachineviewerwidget.cpp
    # this part depends on graphviz
    gvgraph/gvgraph.cpp
    gvgraph/gvgraphitems.cpp
    gvgraph/gvutils.cpp)
    
add_library(statemachineviewer SHARED ${sources} ${headers} ${uiced})
set(linklibs ${GRAPHVIZ_GVC_LIBRARY} ${GRAPHVIZ_CGRAPH_LIBRARY} ${QT_QTGUI_LIBRARIES}  ${QT_QTCORE_LIBRARIES})
target_link_libraries(statemachineviewer ${linklibs})


if(test)
    add_executable(statemachineviewer_test
        gvgraph/gvgraph.cpp
        gvgraph/gvgraphitems.cpp
        gvgraph/gvutils.cpp
        test_main.cpp)

    target_link_libraries(statemachineviewer_test ${linklibs})
endif()
