libcgraphviz
------------

C-library of Graphviz <http://www.graphviz.org>.

Simplifies embedding Graphviz's C-libraries into an application which uses CMake as build system.

Include this repository with add_subdirectory() in your CMake file and use these CMake variables to build and link libcgraphviz:

    LIBCGRAPHVIZ_LIBRARY     : library name
    LIBCGRAPHVIZ_INCLUDE_DIR : include directories
    LIBCGRAPHVIZ_DEFINITIONS : definitions needed when compiling client code
    

Set before calling add_subdirectory()

    LIBCGRAPHVIZ_DLL
   
to TRUE when a Dll should be build.


Graphviz's version is available via:

    LIBCGRAPHVIZ_MAJOR_VERSION
    LIBCGRAPHVIZ_MINOR_VERSION
    LIBCGRAPHVIZ_PATCH_VERSION

 