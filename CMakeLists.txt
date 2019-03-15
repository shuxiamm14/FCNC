# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)
# Project's name

project(ttH_fake)

find_package(ROOT REQUIRED COMPONENTS TMVA TMVAGui Minuit)
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
message(STATUS "plot tool includes: " ${PLOTTOOLINC})
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

add_library(applyTF SHARED ${PROJECT_SOURCE_DIR}/src/applyTF.cc)
target_link_libraries(applyTF ${ROOT_LIBRARIES})

add_library(nominal SHARED ${PROJECT_SOURCE_DIR}/src/nominal.C ${PROJECT_SOURCE_DIR}/include/nominal.h)
target_link_libraries(nominal ${ROOT_LIBRARIES} applyTF ${PLOTTOOLLIB})

add_library(hadhadtree SHARED ${PROJECT_SOURCE_DIR}/src/hadhadtree.C ${PROJECT_SOURCE_DIR}/include/hadhadtree.h)
target_link_libraries(hadhadtree ${ROOT_LIBRARIES} nominal)

add_library(tthmltree SHARED ${PROJECT_SOURCE_DIR}/src/tthmltree.C ${PROJECT_SOURCE_DIR}/include/tthmltree.h)
target_link_libraries(tthmltree ${ROOT_LIBRARIES} nominal)

file( GLOB APP_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/util/tth* )
foreach( sourcefile ${APP_SOURCES} )
    string( REPLACE ".cc" "_run" exename ${sourcefile} )
    string( REPLACE "util/" "" exename ${exename} )
    message(STATUS ${ROOT_TMVA_LIBRARY})
    add_executable( ${exename} ${sourcefile})
    target_compile_definitions(${exename} PRIVATE PACKAGE_DIR="${CMAKE_SOURCE_DIR}")
	target_link_libraries(${exename} ${ROOT_LIBRARIES} tthmltree)
endforeach( sourcefile ${APP_SOURCES} )

file( GLOB APP_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/util/xtfw* )
foreach( sourcefile ${APP_SOURCES} )
    string( REPLACE ".cc" "_run" exename ${sourcefile} )
    string( REPLACE "util/" "" exename ${exename} )
    message(STATUS ${ROOT_TMVA_LIBRARY})
    add_executable( ${exename} ${sourcefile})
    target_compile_definitions(${exename} PRIVATE PACKAGE_DIR="${CMAKE_SOURCE_DIR}")
  target_link_libraries(${exename} ${ROOT_LIBRARIES} hadhadtree)
endforeach( sourcefile ${APP_SOURCES} )