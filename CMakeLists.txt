cmake_minimum_required(VERSION 3.0)

project(SECKEYCLIENT)

# 执行 pkg-config 以获取 protobuf 的编译标志
execute_process(
    COMMAND pkg-config --cflags protobuf
    OUTPUT_VARIABLE PROTOBUF_COMPILE_FLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# 执行 pkg-config 以获取 protobuf 的链接标志
execute_process(
    COMMAND pkg-config --libs protobuf
    OUTPUT_VARIABLE PROTOBUF_LINK_FLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# 打印获取的信息（可选）
message(STATUS "Protobuf Compile Flags: ${PROTOBUF_COMPILE_FLAGS}")
message(STATUS "Protobuf Link Flags: ${PROTOBUF_LINK_FLAGS}")

file(GLOB SOURCES "*.cpp" "*.cc")

add_executable(main ${SOURCES})

target_compile_options(main PRIVATE ${PROTOBUF_COMPILE_FLAGS})
target_link_libraries(main PRIVATE ${PROTOBUF_LINK_FLAGS} ssl crypto jsoncpp)