cmake_minimum_required(VERSION 3.9)
project(base_process)

set(CMAKE_CXX_STANDARD 11)

add_executable(base_process   houghline.cpp)

find_package(OpenCV REQUIRED)                       # 搜索指定的外部依赖库头文件和库文件
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} )   # 链接到OpenCV库 ${jsoncpp_LIBS