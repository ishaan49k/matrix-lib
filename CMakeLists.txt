cmake_minimum_required(VERSION 3.16)
project(MatrixLib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable OpenMP for sparse matrix operations
find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
    target_link_libraries(MatrixLib PRIVATE OpenMP::OpenMP_CXX)
endif()

include_directories(include)
set(SOURCES src/matrix.cpp src/sparse_matrix.cpp src/sparse_matrix_csc.cpp)
add_library(MatrixLib STATIC ${SOURCES})
