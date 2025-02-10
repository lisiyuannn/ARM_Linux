#如何生成动态库和静态库，然后链接他们

#指定cmake最低版本
cmake_minimum_required(VERSION 3.28.3)

#指定项目名称
project(
    cmake_test
    LANGUAGES C
    VERSION 1.0.0
    DESCRIPTION "This is a C project for testing CMake"
)

#指定头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

#指定库文件的输出目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#生成动态库
add_library(dynlib SHARED ${PROJECT_SOURCE_DIR}/src/add.c ${PROJECT_SOURCE_DIR}/src/sub.c)
#生成静态库
add_library(stalib STATIC ${PROJECT_SOURCE_DIR}/src/mul.c ${PROJECT_SOURCE_DIR}/src/div.c)

#指定生成的可执行文件
add_executable(demo ${PROJECT_SOURCE_DIR}/main.c)

#链接库文件
target_link_libraries(demo dynlib stalib)

#指定可执行程序的生成路径，这里的相对路是makefile文件所在的目录
set(EXECUTABLE_OUTPUT_PATH ..)
