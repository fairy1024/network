# 加载子目录
set(HTTP_SRCS
  HttpServer.cc
  HttpResponse.cc
  HttpContext.cc
  main.cc
)
include_directories (../base ../net ../timer ../logger)
add_executable(HttpServer ${HTTP_SRCS})
target_link_libraries(HttpServer tiny_network)

