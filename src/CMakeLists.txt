cmake_minimum_required(VERSION 3.10)
project(OpencvOnnxTemplate)

set(CMAKE_CXX_STANDARD 20)

set(OpenCV_DIR "../third_party/opencv-lite-dnn-onnx-shard-world/x64/vc17/lib")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(OpencvOnnxTemplate main.cpp)
target_link_libraries(OpencvOnnxTemplate ${OpenCV_LIBS})

# copy dll to exe folder
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
add_custom_command(TARGET OpencvOnnxTemplate POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "../../third_party/opencv-lite-dnn-onnx-shard-world/x64/vc17/bin/opencv_world480d.dll"
        "$<TARGET_FILE_DIR:OpencvOnnxTemplate>")
else()
add_custom_command(TARGET OpencvOnnxTemplate POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "../../third_party/opencv-lite-dnn-onnx-shard-world/x64/vc17/bin/opencv_world480.dll"
        "$<TARGET_FILE_DIR:OpencvOnnxTemplate>")
endif()