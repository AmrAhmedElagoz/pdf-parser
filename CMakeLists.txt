cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(pdfParser)

FILE(GLOB_RECURSE SOURCES src/*.cpp)
set(ZLIB_ROOT "../shard/zlib")

find_package(ZLIB REQUIRED)

if(NOT ZLIB_FOUND)
    set(ZLIB_INCLUDE_DIRS "${ZLIB_ROOT}/include")
    set(ZLIB_LIBRARIES "${ZLIB_ROOT}/lib/libz.a")  # or libz.so for shared library
endif()

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)

# Include directories for your target
target_include_directories(${PROJECT_NAME} PRIVATE ${ZLIB_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link against zlib
target_link_libraries(${PROJECT_NAME} PRIVATE ${ZLIB_LIBRARIES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
# Optional: Print status for debugging
message(STATUS "ZLIB include dirs: ${ZLIB_INCLUDE_DIRS}")
message(STATUS "ZLIB libraries: ${ZLIB_LIBRARIES}")