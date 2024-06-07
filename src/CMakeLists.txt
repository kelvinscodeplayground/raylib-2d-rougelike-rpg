cmake_minimum_required(VERSION 3.0.0)
project("game")
set(CMAKE_INCLUDE_CURRENT_DIR on)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
    "Main.cpp"
)

set(HEADER_FILES
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
# target_link_libraries(${PROJECT_NAME} PRIVATE

# )