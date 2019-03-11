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

add_library(applyTF ${PROJECT_SOURCE_DIR}/src/applyTF.cc)
add_library(skim ${PROJECT_SOURCE_DIR}/src/nominal.C ${PROJECT_SOURCE_DIR}/src/skim.C)

file( GLOB APP_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/util/* )
foreach( sourcefile ${APP_SOURCES} )
    string( REPLACE ".cc" "_run" exename ${sourcefile} )
    string( REPLACE "util/" "" exename ${exename} )
    message(STATUS ${ROOT_TMVA_LIBRARY})
    add_executable( ${exename} ${sourcefile} )
    target_compile_definitions(${exename} PRIVATE PACKAGE_DIR="${CMAKE_SOURCE_DIR}")
	target_link_libraries(${exename} ${ROOT_LIBRARIES} applyTF skim ${PLOTTOOLLIB})
endforeach( sourcefile ${APP_SOURCES} )