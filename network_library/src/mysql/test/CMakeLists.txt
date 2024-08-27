add_executable(MysqlPoolTest MysqlPoolTest.cc)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/test)

find_package(Threads REQUIRED)

target_link_libraries(MysqlPoolTest PRIVATE ${CMAKE_THREAD_LIBS_INIT} tiny_network)
