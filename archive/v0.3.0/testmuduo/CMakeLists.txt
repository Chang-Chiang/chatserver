cmake_minimum_required(VERSION 3.0)  # 系统要求最小 cmake 版本
project(main)  # 工程名

#          生成文件    编译选项             头文件搜索路径  库文件搜索路径
# g++ -o muduo_server -g muduo_server.cpp -I/usr/include -L/usr/lib -lmuduo_net -lmuduo_base -lpthread
# 配置编译选项 -g debug 版 可调试
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

# 配置头文件搜索路径
# include_directories

# 配置库文件搜索路径
# link_directories

# 设置需要编译的源文件列表
set(SRC_LIST ./muduo_server.cpp)

# 把指定路径下的(示例为 .)所有源文件名字放入变量名 SRC_LIST
# aux_source_directory(. SRC_LIST)

# 设置可执行文件最终存储路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 设置生成的库文件存储路径  LIBRARY_OUTPUT_PATH

 
# 生成文件 
add_executable(muduo_server ${SRC_LIST})  # 生成可执行文件
                                         # 由 SRC_LIST 变量定义的源文件编译生成可执行文件
# add_library() # 生成库文件

# 指定链接库 muduo_server 这个目标程序，需要链接 muduo_net muduo_base pthread 这三个库文件
target_link_libraries(muduo_server muduo_net muduo_base pthread)

# cmake .
