cmake_minimum_required(VERSION 3.5.0)
project(TransferQueue VERSION 0.1.0 LANGUAGES C CXX)


include_directories(
        ${PROJECT_SOURCE_DIR}/Include
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED off)
set(CMAKE_CXX_EXTENSIONS off)

find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)


add_executable(TransferQueue main.cpp)


target_link_libraries(${PROJECT_NAME} pthread)
