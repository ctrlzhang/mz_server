#查找当前目录下的所有源文件
#并将名称保存到 DIR_LIB_SRCS 变量中
aux_source_directory(. DIR_LIB_SRCS)

#生成链接库
add_library(mzframework ${DIR_LIB_SRCS})

#需要依赖util库
target_link_libraries(mzframework mzutil)

#定制安装规则
#install(TARGETS mzframework DESTINATION bin)
