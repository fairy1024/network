include_directories(../base)

add_executable(AsyncLoggingTest AsyncLoggingTest.cc)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/test)

target_link_libraries(AsyncLoggingTest tiny_network)

