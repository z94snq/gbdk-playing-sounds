cmake_minimum_required(VERSION 3.15)
project(gbdk-playing-sounds NONE)

# GBDK Configuration
set(GBDK_HOME "C:/gbdk")

# Custom flags for lcc
set(CUSTOM_FLAGS "")

# Debug flags for lcc
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(DEBUG_FLAGS "-debug")
    message(STATUS "Debug mode enabled")
else()
    set(DEBUG_FLAGS "")
endif()

# Find lcc compiler
if(WIN32)
    find_program(LCC NAMES lcc.exe PATHS "${GBDK_HOME}/bin" NO_DEFAULT_PATH)
else()
    find_program(LCC NAMES lcc PATHS "${GBDK_HOME}/bin" NO_DEFAULT_PATH)
endif()

if(NOT LCC)
    message(FATAL_ERROR "lcc compiler not found in ${GBDK_HOME}/bin")
endif()

# Find source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.c")

# Find assembly files
file(GLOB_RECURSE ASMSOURCES CONFIGURE_DEPENDS "*.s")

# Find header files
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "headers/*.h")

# Build ROM target
add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/rom.gb
    COMMAND ${LCC} ${DEBUG_FLAGS} -I${CMAKE_SOURCE_DIR}/headers ${CUSTOM_FLAGS} -o ${CMAKE_BINARY_DIR}/rom.gb ${SOURCES} ${ASMSOURCES}
    DEPENDS ${SOURCES} ${ASMSOURCES} ${HEADERS}
    COMMENT "Building GB ROM: ${CMAKE_BINARY_DIR}/rom.gb"
)

add_custom_target(rom.gb ALL DEPENDS ${CMAKE_BINARY_DIR}/rom.gb)

# Register additional files for cleaning
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_CLEAN_FILES
    ${CMAKE_BINARY_DIR}/rom.o
    ${CMAKE_BINARY_DIR}/rom.lst
    ${CMAKE_BINARY_DIR}/rom.map
    ${CMAKE_BINARY_DIR}/rom.ihx
    ${CMAKE_BINARY_DIR}/rom.sym
    ${CMAKE_BINARY_DIR}/rom.cdb
    ${CMAKE_BINARY_DIR}/rom.adb
    ${CMAKE_BINARY_DIR}/rom.asm
    ${CMAKE_BINARY_DIR}/rom.noi
)

# Configuration output
message(STATUS "GBDK Home: ${GBDK_HOME}")
message(STATUS "LCC Compiler: ${LCC}")
message(STATUS "Output ROM: ${CMAKE_BINARY_DIR}/rom.gb")
