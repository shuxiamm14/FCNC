# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 14)
add_compile_options(-g)
# Project's name

project(ttH_fake)

find_package(ROOT 6 REQUIRED COMPONENTS TMVA TMVAGui Minuit RooFitCore RooFit)
include(${ROOT_USE_FILE})

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

#EIGEN3 package needed if dont have one, go git checkout and put the package path here
set(TOOLDIR /Users/Liby/work/tools)
set(PLOTTOOLDIR /Users/Liby/work/tau_analysis/FCNC/plotTools)
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

add_library(nominal SHARED ${PROJECT_SOURCE_DIR}/src/nominal.C ${PROJECT_SOURCE_DIR}/include/nominal.h)
target_link_libraries(nominal ${ROOT_LIBRARIES} applyTF ${PLOTTOOLLIB})
target_compile_definitions(nominal PRIVATE PACKAGE_DIR="${CMAKE_SOURCE_DIR}")

add_library(hadhadtree SHARED ${PROJECT_SOURCE_DIR}/src/hadhadtree.C ${PROJECT_SOURCE_DIR}/include/hadhadtree.h)
target_link_libraries(hadhadtree ${ROOT_LIBRARIES} nominal ${PLOTTOOLLIB} dict)
target_compile_definitions(hadhadtree PRIVATE PACKAGE_DIR="${CMAKE_SOURCE_DIR}")

add_library(tthmltree SHARED ${PROJECT_SOURCE_DIR}/src/tthmltree.C ${PROJECT_SOURCE_DIR}/include/tthmltree.h)
target_link_libraries(tthmltree ${ROOT_LIBRARIES} nominal ${PLOTTOOLLIB} dict)
target_compile_definitions(tthmltree PRIVATE PACKAGE_DIR="${CMAKE_SOURCE_DIR}")

file( GLOB APP_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/util/tth* )
foreach( sourcefile ${APP_SOURCES} )
    string( REPLACE ".cc" "_run" exename ${sourcefile} )
    string( REPLACE "util/" "" exename ${exename} )
    add_executable( ${exename} ${sourcefile})
    target_compile_definitions(${exename} PRIVATE PACKAGE_DIR="${CMAKE_SOURCE_DIR}")
	target_link_libraries(${exename} ${ROOT_LIBRARIES} tthmltree)
endforeach( sourcefile ${APP_SOURCES} )

file( GLOB APP_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/util/xtfw* )
foreach( sourcefile ${APP_SOURCES} )
    string( REPLACE ".cc" "_run" exename ${sourcefile} )
    string( REPLACE "util/" "" exename ${exename} )
    add_executable( ${exename} ${sourcefile})
    target_compile_definitions(${exename} PRIVATE PACKAGE_DIR="${CMAKE_SOURCE_DIR}")
  target_link_libraries(${exename} ${ROOT_LIBRARIES} hadhadtree)
endforeach( sourcefile ${APP_SOURCES} )

add_executable( print_cutflow_hadhad_run util/print_cutflow_hadhad.cc)

target_compile_definitions(print_cutflow_hadhad_run PRIVATE PACKAGE_DIR="${CMAKE_SOURCE_DIR}")
target_link_libraries(print_cutflow_hadhad_run ${PLOTTOOLLIB} ${ROOT_LIBRARIES})