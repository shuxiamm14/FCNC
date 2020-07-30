# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 14)
add_compile_options(-g)
# Project's name

project(ttH_fake)

find_package(ROOT 6 REQUIRED COMPONENTS TMVA TMVAGui Minuit RooFitCore RooFit)
include(${ROOT_USE_FILE})

message("PLOT_LIB_DIR=" $ENV{PLOT_LIB_DIR})
message("TOOL_DIR=" $ENV{TOOL_DIR})

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

#EIGEN3 package needed if dont have one, go git checkout and put the package path here
set(TOOLDIR $ENV{TOOL_DIR})
set(PLOTTOOLDIR $ENV{PLOT_LIB_DIR})
FILE(GLOB PLOTTOOLINC ${PLOTTOOLDIR}/include/ ${PLOTTOOLDIR}/include/* )
FILE(GLOB PLOTTOOLLIB ${PLOTTOOLDIR}/lib/*)
# The following folder will be included

include_directories(
	${PLOTTOOLINC}
	${PROJECT_SOURCE_DIR}/include 
	${TOOLDIR}/eigen
	${TOOLDIR}/json/include
	${TOOLDIR}/frugally-deep/include
	${TOOLDIR}/FunctionalPlus/include)

ROOT_GENERATE_DICTIONARY(dictionary
                         LINKDEF include/LinkDef.h)

if (${ROOT_VERSION} VERSION_GREATER "6.0")
   install(
      FILES
      ${CMAKE_CURRENT_BINARY_DIR}/libdictionary_rdict.pcm
      ${CMAKE_CURRENT_BINARY_DIR}/libdictionary.rootmap
      DESTINATION ${CMAKE_SOURCE_DIR}/lib)
endif (${ROOT_VERSION} VERSION_GREATER "6.0")

add_library(dict SHARED dictionary.cxx)
target_link_libraries(dict ${ROOT_LIBRARIES})
set_target_properties(dict PROPERTIES OUTPUT_NAME dictionary)

add_library(applyTF SHARED ${PROJECT_SOURCE_DIR}/src/applyTF.cc)
target_link_libraries(applyTF ${ROOT_LIBRARIES})

add_library(common SHARED ${PROJECT_SOURCE_DIR}/src/common.C)
target_link_libraries(common ${ROOT_LIBRARIES} ${PLOTTOOLLIB})
target_compile_definitions(common PRIVATE PACKAGE_DIR="${CMAKE_SOURCE_DIR}")

add_library(nominal SHARED ${PROJECT_SOURCE_DIR}/src/nominal_listfunc.C ${PROJECT_SOURCE_DIR}/src/nominal.C ${PROJECT_SOURCE_DIR}/include/nominal.h ${PROJECT_SOURCE_DIR}/src/hadhadtree.C ${PROJECT_SOURCE_DIR}/src/hadhadtree_listfunc.C ${PROJECT_SOURCE_DIR}/include/hadhadtree.h ${PROJECT_SOURCE_DIR}/src/tthmltree.C ${PROJECT_SOURCE_DIR}/src/tthmltree_v2.C ${PROJECT_SOURCE_DIR}/src/tthmltree_v3.C ${PROJECT_SOURCE_DIR}/include/tthmltree.h ${PROJECT_SOURCE_DIR}/include/tthmltree_v2.h ${PROJECT_SOURCE_DIR}/include/tthmltree_v3.h)
target_link_libraries(nominal ${ROOT_LIBRARIES} applyTF ${PLOTTOOLLIB} dict common)
target_compile_definitions(nominal PRIVATE PACKAGE_DIR="${CMAKE_SOURCE_DIR}")

file( GLOB APP_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/util/*reduce* )
foreach( sourcefile ${APP_SOURCES} )
    string( REPLACE ".cc" "_run" exename ${sourcefile} )
    string( REPLACE "util/" "" exename ${exename} )
    add_executable( ${exename} ${sourcefile})
    target_compile_definitions(${exename} PRIVATE PACKAGE_DIR="${CMAKE_SOURCE_DIR}")
	target_link_libraries(${exename} ${ROOT_LIBRARIES} nominal)
endforeach( sourcefile ${APP_SOURCES} )

file( GLOB APP_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/util/* )
list( FILTER APP_SOURCES EXCLUDE REGEX ".*reduce.*")
foreach( sourcefile ${APP_SOURCES} )
    string( REPLACE ".cc" "_run" exename ${sourcefile} )
    string( REPLACE "util/" "" exename ${exename} )
    add_executable( ${exename} ${sourcefile})
    target_compile_definitions(${exename} PRIVATE PACKAGE_DIR="${CMAKE_SOURCE_DIR}")
  target_link_libraries(${exename} ${ROOT_LIBRARIES} ${PLOTTOOLLIB} common)
endforeach( sourcefile ${APP_SOURCES} )
