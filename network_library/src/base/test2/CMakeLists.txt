cmake_minimum_required(VERSION 2.8)

project(demo)

# 设置 C++ 标准（可选，取决于你使用的标准）
set(CMAKE_CXX_STANDARD 11)

# 查找 POSIX 线程库
find_package(Threads REQUIRED)

# 添加可执行文件
add_executable(main ThreadPoolTest.cc ThreadPool.cc Thread.cc CurrentThread.cc)

# 链接 POSIX 线程库
target_link_libraries(main PRIVATE ${CMAKE_THREAD_LIBS_INIT})
