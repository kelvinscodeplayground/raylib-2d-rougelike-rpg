cmake_minimum_required(VERSION 3.0.0)
project("game")
set(CMAKE_INCLUDE_CURRENT_DIR on)
set(CMAKE_CXX_STANDARD 20)

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(raylib)

FetchContent_Declare(
    raylib_cpp
    GIT_REPOSITORY "https://github.com/RobLoach/raylib-cpp.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(raylib_cpp)

set(SOURCE_FILES
    "Main.cpp"
    "Managers/SystemManager.cpp"
)

set(HEADER_FILES
    "Managers/SystemManager.hpp"
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE
raylib
raylib_cpp
)

# Setting ASSETS_PATH
# target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine