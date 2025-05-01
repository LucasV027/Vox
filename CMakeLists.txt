cmake_minimum_required(VERSION 3.15)
project(vox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build (Debug, Release, Dist)" FORCE)
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Dist")
    set(RES_DIR "./res")
else ()
    set(RES_DIR "${CMAKE_SOURCE_DIR}/res")
endif ()

add_executable(${PROJECT_NAME}
        src/main.cpp

        src/app/Application.cpp
        src/app/Application.h
        src/app/Window.cpp
        src/app/Window.h
        src/app/Time.cpp
        src/app/Time.h
        src/app/Renderer.cpp
        src/app/Renderer.h
        src/app/UI.cpp
        src/app/UI.h
        src/app/Input.cpp
        src/app/Input.h

        src/core/Voxel.cpp
        src/core/Voxel.h
        src/core/Camera.cpp
        src/core/Camera.h
        src/core/Block.cpp
        src/core/Block.h
        src/core/Chunk.cpp
        src/core/Chunk.h

        src/opengl/IndexBuffer.cpp
        src/opengl/IndexBuffer.h
        src/opengl/Program.cpp
        src/opengl/Program.h
        src/opengl/Texture.cpp
        src/opengl/Texture.h
        src/opengl/VertexArray.cpp
        src/opengl/VertexArray.h
        src/opengl/VertexBuffer.cpp
        src/opengl/VertexBuffer.h
        src/opengl/VertexBufferLayout.cpp
        src/opengl/VertexBufferLayout.h

        src/extern/stb_image.cpp
        src/extern/stb_image.h
)

target_include_directories(${PROJECT_NAME} PRIVATE src)
target_compile_definitions(${PROJECT_NAME} PRIVATE RES_DIR="${RES_DIR}")

include(cmake/dependencies.cmake)
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        glad
        glfw
        glm
        imgui
)

if (CMAKE_BUILD_TYPE STREQUAL "Dist")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/res"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/res"
    )
endif ()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Ressources directory: ${RES_DIR}")
