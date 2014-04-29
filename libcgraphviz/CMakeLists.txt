
cmake_minimum_required(VERSION 2.8.9)

project(libcgraphviz C)


if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    if(NOT LIBCGRAPHVIZ_STATIC)
        set(LIBCGRAPHVIZ_DLL 1)
    endif()
endif()


set(LIBCGRAPHVIZ_MAJOR_VERSION 2  CACHE STRING "libcgraphviz" FORCE)
set(LIBCGRAPHVIZ_MINOR_VERSION 38 CACHE STRING "libcgraphviz" FORCE)
set(LIBCGRAPHVIZ_PATCH_VERSION 0  CACHE STRING "libcgraphviz" FORCE)


set(SRCDIR ${CMAKE_CURRENT_SOURCE_DIR}/graphviz-${LIBCGRAPHVIZ_MAJOR_VERSION}.${LIBCGRAPHVIZ_MINOR_VERSION}.${LIBCGRAPHVIZ_PATCH_VERSION})

set(LIB_CDT
    ${SRCDIR}/lib/cdt/dttree.c
    ${SRCDIR}/lib/cdt/dtclose.c
    ${SRCDIR}/lib/cdt/dtdisc.c
    ${SRCDIR}/lib/cdt/dtextract.c
    ${SRCDIR}/lib/cdt/dtflatten.c
    ${SRCDIR}/lib/cdt/dthash.c
    ${SRCDIR}/lib/cdt/dtlist.c
    ${SRCDIR}/lib/cdt/dtmethod.c
    ${SRCDIR}/lib/cdt/dtopen.c
    ${SRCDIR}/lib/cdt/dtrenew.c
    ${SRCDIR}/lib/cdt/dtrestore.c
    ${SRCDIR}/lib/cdt/dtsize.c
    ${SRCDIR}/lib/cdt/dtstat.c
    ${SRCDIR}/lib/cdt/dtstrhash.c
    ${SRCDIR}/lib/cdt/dtview.c
    ${SRCDIR}/lib/cdt/dtwalk.c)

set(LIB_COMMON
    ${SRCDIR}/lib/common/args.c
    ${SRCDIR}/lib/common/arrows.c
    ${SRCDIR}/lib/common/colxlate.c
    ${SRCDIR}/lib/common/emit.c
    ${SRCDIR}/lib/common/geom.c
    ${SRCDIR}/lib/common/globals.c
    ${SRCDIR}/lib/common/htmllex.c
    ${SRCDIR}/lib/common/htmlparse.c
    ${SRCDIR}/lib/common/htmltable.c
    ${SRCDIR}/lib/common/input.c
    ${SRCDIR}/lib/common/intset.c
    ${SRCDIR}/lib/common/labels.c
    ${SRCDIR}/lib/common/memory.c
    ${SRCDIR}/lib/common/ns.c
    ${SRCDIR}/lib/common/output.c
    ${SRCDIR}/lib/common/pointset.c
    ${SRCDIR}/lib/common/postproc.c
    ${SRCDIR}/lib/common/psusershape.c
    ${SRCDIR}/lib/common/routespl.c
    ${SRCDIR}/lib/common/shapes.c
    ${SRCDIR}/lib/common/splines.c
    ${SRCDIR}/lib/common/timing.c
    ${SRCDIR}/lib/common/utils.c
    ${SRCDIR}/lib/common/ellipse.c
    ${SRCDIR}/lib/common/textspan.c
    ${SRCDIR}/lib/common/taper.c)

set(LIB_DOTGEN
    ${SRCDIR}/lib/dotgen/acyclic.c
    ${SRCDIR}/lib/dotgen/aspect.c
    ${SRCDIR}/lib/dotgen/class1.c
    ${SRCDIR}/lib/dotgen/class2.c
    ${SRCDIR}/lib/dotgen/cluster.c
    ${SRCDIR}/lib/dotgen/compound.c
    ${SRCDIR}/lib/dotgen/conc.c
    ${SRCDIR}/lib/dotgen/decomp.c
    ${SRCDIR}/lib/dotgen/dotinit.c
    ${SRCDIR}/lib/dotgen/dotsplines.c
    ${SRCDIR}/lib/dotgen/fastgr.c
    ${SRCDIR}/lib/dotgen/flat.c
    ${SRCDIR}/lib/dotgen/mincross.c
    ${SRCDIR}/lib/dotgen/position.c
    ${SRCDIR}/lib/dotgen/rank.c
    ${SRCDIR}/lib/dotgen/sameport.c)

set(LIB_GVC
    ${SRCDIR}/lib/gvc/gvc.c
    ${SRCDIR}/lib/gvc/gvconfig.c
    ${SRCDIR}/lib/gvc/gvcontext.c
    ${SRCDIR}/lib/gvc/gvdevice.c
    ${SRCDIR}/lib/gvc/gvevent.c
    ${SRCDIR}/lib/gvc/gvjobs.c
    ${SRCDIR}/lib/gvc/gvlayout.c
    ${SRCDIR}/lib/gvc/gvloadimage.c
    ${SRCDIR}/lib/gvc/gvplugin.c
    ${SRCDIR}/lib/gvc/gvrender.c
    ${SRCDIR}/lib/gvc/gvtextlayout.c
    ${SRCDIR}/lib/gvc/gvusershape.c)

set(LIB_LABELS
    ${SRCDIR}/lib/label/xlabels.c
    ${SRCDIR}/lib/label/xlabels.c
    ${SRCDIR}/lib/label/index.c
    ${SRCDIR}/lib/label/node.c
    ${SRCDIR}/lib/label/rectangle.c
    ${SRCDIR}/lib/label/split.q.c)

set(LIB_ORTHO
    ${SRCDIR}/lib/ortho/fPQ.c
    ${SRCDIR}/lib/ortho/fPQ.h
    ${SRCDIR}/lib/ortho/maze.c
    ${SRCDIR}/lib/ortho/maze.h
    ${SRCDIR}/lib/ortho/ortho.c
    ${SRCDIR}/lib/ortho/ortho.h
    ${SRCDIR}/lib/ortho/partition.c
    ${SRCDIR}/lib/ortho/partition.h
    ${SRCDIR}/lib/ortho/rawgraph.c
    ${SRCDIR}/lib/ortho/rawgraph.h
    ${SRCDIR}/lib/ortho/sgraph.c
    ${SRCDIR}/lib/ortho/sgraph.h
    ${SRCDIR}/lib/ortho/structures.h
    ${SRCDIR}/lib/ortho/trap.h
    ${SRCDIR}/lib/ortho/trapezoid.c)

set(LIB_PACK
    ${SRCDIR}/lib/pack/ccomps.c
    ${SRCDIR}/lib/pack/pack.c)

set(LIB_PATHPLAN
    ${SRCDIR}/lib/pathplan/cvt.c
    ${SRCDIR}/lib/pathplan/inpoly.c
    ${SRCDIR}/lib/pathplan/route.c
    ${SRCDIR}/lib/pathplan/shortest.c
    ${SRCDIR}/lib/pathplan/shortestpth.c
    ${SRCDIR}/lib/pathplan/solvers.c
    ${SRCDIR}/lib/pathplan/triang.c
    ${SRCDIR}/lib/pathplan/util.c
    ${SRCDIR}/lib/pathplan/visibility.c)

set(LIB_XDOT
    ${SRCDIR}/lib/xdot/xdot.c)

set(LIB_PLUGIN_CORE
    ${SRCDIR}/plugin/core/gvloadimage_core.c
    ${SRCDIR}/plugin/core/gvplugin_core.c
    ${SRCDIR}/plugin/core/gvrender_core_dot.c
    ${SRCDIR}/plugin/core/gvrender_core_fig.c
    ${SRCDIR}/plugin/core/gvrender_core_map.c
    ${SRCDIR}/plugin/core/gvrender_core_pic.c
    ${SRCDIR}/plugin/core/gvrender_core_pov.c
    ${SRCDIR}/plugin/core/gvrender_core_ps.c
    ${SRCDIR}/plugin/core/gvrender_core_svg.c
    ${SRCDIR}/plugin/core/gvrender_core_tk.c
    ${SRCDIR}/plugin/core/gvrender_core_vml.c)

set(LIB_PLUGIN_DOT_LAYOUT
    ${SRCDIR}/plugin/dot_layout/gvlayout_dot_layout.c
    ${SRCDIR}/plugin/dot_layout/gvplugin_dot_layout.c
    ${SRCDIR}/plugin/dot_layout/gvplugin_dot_layout.c)

set(LIB_CGRAPH
    ${SRCDIR}/lib/cgraph/agerror.c
    ${SRCDIR}/lib/cgraph/agxbuf.c
    ${SRCDIR}/lib/cgraph/apply.c
    ${SRCDIR}/lib/cgraph/attr.c
    ${SRCDIR}/lib/cgraph/edge.c
    ${SRCDIR}/lib/cgraph/flatten.c
    ${SRCDIR}/lib/cgraph/graph.c
    ${SRCDIR}/lib/cgraph/id.c
    ${SRCDIR}/lib/cgraph/imap.c
    ${SRCDIR}/lib/cgraph/io.c
    ${SRCDIR}/lib/cgraph/mem.c
    ${SRCDIR}/lib/cgraph/node.c
    ${SRCDIR}/lib/cgraph/obj.c
    ${SRCDIR}/lib/cgraph/pend.c
    ${SRCDIR}/lib/cgraph/rec.c
    ${SRCDIR}/lib/cgraph/refstr.c
    ${SRCDIR}/lib/cgraph/scan.c
    ${SRCDIR}/lib/cgraph/subg.c
    ${SRCDIR}/lib/cgraph/utils.c
    ${SRCDIR}/lib/cgraph/write.c
    ${SRCDIR}/lib/cgraph/grammar.c)

file(GLOB_RECURSE HEADERS ${SRCDIR} *.h)

include_directories(
    ${SRCDIR}/lib/cgraph
    ${SRCDIR}/lib/pathplan
    ${SRCDIR}/lib/common
    ${SRCDIR}/lib/gvc
    ${SRCDIR}/lib/dotgen
    ${SRCDIR}/lib/fdpgen
    ${SRCDIR}/lib/cdt
    ${SRCDIR}/lib/patchwork
    ${SRCDIR}/lib/xdot
    ${SRCDIR}/lib/ortho
    ${SRCDIR}/lib/pack
    ${SRCDIR}/lib/label
    ${SRCDIR}/libltdl
    ${SRCDIR})


if(WIN32)
   set(WIN32SRC  ${SRCDIR}/lib/gvc/regex_win32.c)
endif()


if(LIBCGRAPHVIZ_DLL)
    set(LIBCGRAPHVIZ_LIBTYPE SHARED)
    add_definitions(-DGVDLL -DWIN32_DLL -DGVPLUGIN_CORE_EXPORTS -DCGRAPH_EXPORTS -DGVC_EXPORTS -DGVPLUGIN_DOT_LAYOUT_EXPORTS -DPATHPLAN_EXPORTS)
    add_definitions(-D_BLD_pathplan -D_BLD_cdt  -D_BLD_gvc -D_BLD_cgraph -D_BLD_dot -D_BLD_dotneato -D_PACKAGE_ast)
    set(LIBCGRAPHVIZ_DEFINITIONS -DWIN32_DLL CACHE STRING "libcgraph" FORCE)
else()
    set(LIBCGRAPHVIZ_DEFINITIONS CACHE STRING "libcgraphviz" FORCE)
endif()


if(MSVC)
    include_directories(${SRCDIR}/windows)
    if(CMAKE_C_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W1" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    endif()
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W1" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    endif()
endif()

add_definitions(-DHAVE_CONFIG_H -DNO_PRAGMA_LINKING)

add_library(libcgraphviz ${LIBCGRAPHVIZ_LIBTYPE}
    ${LIB_CDT} ${LIB_COMMON} ${LIB_DOTGEN} ${LIB_CGRAPH} ${LIB_GVC}
    ${LIB_LABELS} ${LIB_ORTHO} ${LIB_PACK} ${LIB_PATHPLAN} ${LIB_XDOT}
    ${LIB_PLUGIN_CORE} ${LIB_PLUGIN_DOT_LAYOUT} ${WIN32SRC}
    ${SRCDIR}/../libcgraphviz_dot_builtins.c
    ${HEADERS})

set_target_properties(libcgraphviz PROPERTIES PREFIX "")

set(LIBCGRAPHVIZ_INCLUDE_DIR ${SRCDIR}/lib/gvc ${SRCDIR}/lib/cgraph ${SRCDIR}/lib/common ${SRCDIR}/lib/pathplan ${SRCDIR}/lib/cdt CACHE STRING "libcgraphviz" FORCE)
set(LIBCGRAPHVIZ_LIBRARY libcgraphviz CACHE STRING "libcgraphviz" FORCE)

mark_as_advanced(LIBCGRAPHVIZ_INCLUDE_DIR LIBCGRAPHVIZ_LIBRARY)
mark_as_advanced(LIBCGRAPHVIZ_MAJOR_VERSION LIBCGRAPHVIZ_MINOR_VERSION LIBCGRAPHVIZ_PATCH_VERSION)
