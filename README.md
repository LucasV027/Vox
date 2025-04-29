# Vox

`Vox` is an experimental voxel engine project, heavily inspired by Minecraft. The goal is to explore and learn about voxel-based rendering and game engine development.

## Development Roadmap

#### Core Systems
- [ ] Implement window abstraction.
- [ ] Set up a debug UI using ImGui.
- [ ] Develop an input handling system.
- [ ] Create a basic camera system.
- [ ] Integrate an audio system for sound effects and ambiance.

### Rendering Features
- [ ] Render a single block to establish basic rendering functionality.
- [ ] Expand rendering to support multiple blocks for a more complex scene.
- [ ] Add a skybox to enhance environmental visuals and immersion.
- [ ] Support rendering of multiple block types for diverse environments.
- [ ] Add a lighting system to enhance visuals with realistic shading and illumination.

### Voxel World Features
- [ ] Develop a chunk-based system to optimize world management and rendering.
- [ ] Generate procedural terrain to create dynamic and varied landscapes.

### Interaction Features
- [ ] Enable basic world interaction, starting with removing blocks.
- [ ] Extend interaction to allow placing blocks in the world.
- [ ] Introduce basic physics for simple object interactions.
- [ ] Interaction with audio.
- [ ] Implement a save and load system to persist world data.

#### Future Enhancements
- [ ] Explore multiplayer or networking features for collaborative gameplay.
- [ ] Add advanced physics for more complex interactions and mechanics.
- [ ] Enhance visuals with shaders and post-processing effects.
- [ ] Experiment with AI-driven NPCs or creatures to populate the world.

## Technologies Used
- **C++**: The primary programming language for the project.
- **CMake**: For build system management.
- **GLFW**: For window and input management.
- **OpenGL**: For rendering.
- **ImGui**: For debugging and UI tools.
- **GLM**: For mathematical operations.

## Inspiration
This project draws inspiration from [Let's Make a Voxel Engine](https://sites.google.com/site/letsmakeavoxelengine/home).
