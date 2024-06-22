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

FetchContent_Declare(
    raylib_cpp
    GIT_REPOSITORY "https://github.com/RobLoach/raylib-cpp.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

FetchContent_Declare(
    scope_guard
    GIT_REPOSITORY "https://github.com/ricab/scope_guard.git"
    GIT_TAG "origin/main"
    GIT_PROGRESS TRUE
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
)

FetchContent_MakeAvailable(raylib raylib_cpp scope_guard)

include_directories(${scope_guard_SOURCE_DIR})

set(SOURCE_FILES
    "Main.cpp"
    "Managers/SceneManager.cpp"
    "Managers/SystemManager.cpp"
    "Scenes/Board.cpp"
)

set(HEADER_FILES
    "Consts/Tiles.hpp"
    "Managers/SceneManager.hpp"
    "Managers/SystemManager.hpp"
    "Scenes/Board.hpp"
    "Scenes/Scene.hpp"
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE
raylib
raylib_cpp
)

# Setting ASSETS_PATH
# target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine