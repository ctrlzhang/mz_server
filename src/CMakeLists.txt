#cmake 最低版本号
cmake_minimum_required (VERSION 2.6)

#项目信息
project (mz_server)

#查找当前目录下的所有源文件,并将名称保存到DIR_SRCS目录下
aux_source_directory(. DIR_SRCS) 

#添加子目录
add_subdirectory(util)
add_subdirectory(framework)

#指定生成目标
add_executable (mz_server ${DIR_SRCS})

#添加链接库, 指明mz_server项目需要连接mzutil, mzframework库
target_link_libraries(mz_server mzutil)
target_link_libraries(mz_server mzframework)

#编译选项
SET(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wno-unused-parameter -Wno-deprecated")

#链接选项
SET(CMAKE_EXE_LINKER_FLAGS "-rdynamic -Wl,-Bstatic -Wl,-Bdynamic -lstdc++ -lpthread -ldl")
