#指定cmake最低版本
cmake_minimum_required(VERSION 3.28.3)

#指定项目名称
project(
    cmake_test
    LANGUAGES C
    VERSION 1.0.0
    DESCRIPTION "This is a C project for testing CMake"
)

#搜索源文件，原文件目录加变量名
aux_source_directory(. SRC)

#指定生成的可执行文件
add_executable(demo ${SRC})

#指定可执行程序的生成路径，这里的相对路是makefile文件所在的目录
set(EXECUTABLE_OUTPUT_PATH ..)
