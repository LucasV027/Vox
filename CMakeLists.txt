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

        src/Application/Application.cpp
        src/Application/Application.h
        src/Application/Window.cpp
        src/Application/Window.h
        src/Application/Timer.cpp
        src/Application/Timer.h
        src/Application/Renderer.cpp
        src/Application/Renderer.h
        src/Application/UI.cpp
        src/Application/UI.h
        src/Application/Input.cpp
        src/Application/Input.h

        src/Core/Voxel.cpp
        src/Core/Voxel.h
        src/Core/Block.cpp
        src/Core/Block.h
        src/Core/Chunk.cpp
        src/Core/Chunk.h

        src/Render/IndexBuffer.cpp
        src/Render/IndexBuffer.h
        src/Render/Program.cpp
        src/Render/Program.h
        src/Render/Texture.cpp
        src/Render/Texture.h
        src/Render/VertexArray.cpp
        src/Render/VertexArray.h
        src/Render/VertexBuffer.cpp
        src/Render/VertexBuffer.h
        src/Render/VertexBufferLayout.cpp
        src/Render/VertexBufferLayout.h
        src/Render/DebugCallBack.h
        src/Render/DebugCallBack.cpp
        src/Render/SkyBox.cpp
        src/Render/SkyBox.h
        src/Render/Camera.cpp
        src/Render/Camera.h

        src/Extern/stb_image.cpp
        src/Extern/stb_image.h
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
