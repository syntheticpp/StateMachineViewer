cmake_minimum_required(VERSION 2.8.9)

project(statemachineviewer)

set(smvdir ${CMAKE_CURRENT_SOURCE_DIR}/statemachineviewer)

if(qt5)
    add_definitions(-DQT5)
else()
    cmake_policy(SET CMP0020 NEW) # link qtmain
    set(QT_USE_IMPORTED_TARGETS true)
    find_package(Qt4 ${QT_MIN_VERSION} REQUIRED QtCore QtGui)
    include(${QT_USE_FILE})
endif()

if(WIN32)
    set(LIBCGRAPHVIZ_DLL 1)
    add_definitions(-DMAKE_GAMMARAY_LIB)
endif()

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

add_definitions(-DGAMMARAY_GRAPHVIZ_EMBEDDED -DMAKE_GAMMARAY_LIB)
add_definitions(${GRAPHVIZ_COMPILE_FLAGS})

include_directories(${GRAPHVIZ_INCLUDE_DIR} ${GRAPHVIZ_INCLUDE_DIR}/graphviz ${CMAKE_CURRENT_BINARY_DIR} ${smvdir})

file(GLOB sources   ${smvdir}/*.cpp)
file(GLOB gvsources ${smvdir}/gvgraph/*.cpp)

file(GLOB headers   ${smvdir}/*.h)
file(GLOB gvheaders ${smvdir}/gvgraph/*.h)

if(qt5)
    macro(qt_moc)
        qt5_wrap_cpp(${ARGN} OPTIONS "-nw")
    endmacro()
    macro(qt_uic)
        qt5_wrap_ui(${ARGN})
    endmacro()
else()
    macro(qt_moc)
        qt4_wrap_cpp(${ARGN} OPTIONS "-nw")
    endmacro()
    macro(qt_uic)
        qt4_wrap_ui(${ARGN})
    endmacro()
endif()

qt_moc(moced ${headers})
qt_uic(uiced ${smvdir}/statemachineviewer.ui)

source_group("Generated Files" FILES ${moced} ${uiced})
    
list(REMOVE_ITEM sources ${smvdir}/test_main.cpp)

add_library(statemachineviewer SHARED ${sources} ${headers} ${gvsources} ${gvheaders} ${moced} ${uiced})
set(linklibs ${GRAPHVIZ_GRAPH_LIBRARY} ${QT_QTGUI_LIBRARIES}  ${QT_QTCORE_LIBRARIES})
target_link_libraries(statemachineviewer ${linklibs})


if(test)
    add_executable(statemachineviewer_test
        gvgraph/gvgraph.cpp
        gvgraph/gvgraphitems.cpp
        gvgraph/gvutils.cpp
        test_main.cpp)

    target_link_libraries(statemachineviewer_test ${linklibs})
endif()


qt_moc(moced examples/trafficlight/trafficlight.h)
add_executable(trafficlight examples/trafficlight/main.cpp examples/trafficlight/trafficlight.h ${moced})
target_link_libraries(trafficlight statemachineviewer ${linklibs})
