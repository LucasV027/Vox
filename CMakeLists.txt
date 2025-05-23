cmake_minimum_required(VERSION 3.15)
project(vox)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build (Debug, Release, Dist)" FORCE)
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Dist")
    set(ASSETS_DIR "assets")
else ()
    set(ASSETS_DIR "${CMAKE_SOURCE_DIR}/assets")
endif ()

add_executable(${PROJECT_NAME}
        src/main.cpp

        src/core/Application.cpp
        src/core/Application.h
        src/core/Window.cpp
        src/core/Window.h
        src/core/Timer.cpp
        src/core/Timer.h
        src/core/UI.cpp
        src/core/UI.h
        src/core/Inputs.cpp
        src/core/Inputs.h
        src/core/Keys.h

        src/graphics/IndexBuffer.cpp
        src/graphics/IndexBuffer.h
        src/graphics/Program.cpp
        src/graphics/Program.h
        src/graphics/Texture.cpp
        src/graphics/Texture.h
        src/graphics/VertexArray.cpp
        src/graphics/VertexArray.h
        src/graphics/VertexBuffer.cpp
        src/graphics/VertexBuffer.h
        src/graphics/VertexBufferLayout.cpp
        src/graphics/VertexBufferLayout.h
        src/graphics/DebugCallBack.h
        src/graphics/DebugCallBack.cpp
        src/graphics/SkyBox.cpp
        src/graphics/SkyBox.h
        src/graphics/Camera.cpp
        src/graphics/Camera.h
        src/graphics/Renderer.cpp
        src/graphics/Renderer.h
        src/graphics/RenderCommand.h
        src/graphics/RenderCommand.cpp
        src/graphics/Renderable.h

        src/voxel/World.h
        src/voxel/World.cpp
        src/voxel/Cube.cpp
        src/voxel/Cube.h

        src/controller/Controller.cpp
        src/controller/Controller.h
        src/controller/Controllers.cpp
        src/controller/Controllers.h
        src/controller/RendererController.cpp
        src/controller/RendererController.h
        src/controller/CameraController.cpp
        src/controller/CameraController.h

        src/extern/stb_image.cpp
        src/extern/stb_image.h
)

target_include_directories(${PROJECT_NAME} PRIVATE src)
target_compile_definitions(${PROJECT_NAME} PRIVATE ASSETS_DIR="${ASSETS_DIR}")

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
            "${CMAKE_SOURCE_DIR}/assets"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets"
    )
endif ()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Assets directory: ${ASSETS_DIR}")
