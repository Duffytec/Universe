# Universe

一个基于 C++/OpenGL 的程序化宇宙/行星渲染项目（工程入口为 `ProcedurusMain.cpp`，窗口标题为 Procedurus）。

## 项目简介
Universe 是一个实时渲染的程序化天体系统示例，包含行星地形（四叉树 LOD）、大气与云层、星空与太阳、粒子特效等模块，适合用于图形学学习与实验。

## 主要特性
- 程序化行星地形（多分形噪声、四叉树 LOD）
- 大气、云层、行星环、星空/太阳渲染
- 基于 OpenGL 的 GLSL 着色器系统
- 摄像机自由移动与交互拾取
- FPS 统计与调试开关

## 技术栈与依赖
- C++（建议 C++11 及以上）
- OpenGL
- GLFW 2（仓库内 `glfw2` 目录）
- GLee（在 `GL/`）
- CMake

## 构建与运行
> `CMakeLists.txt` 默认从 `glfw2/build/install` 读取 GLFW 头文件与库，请先构建并安装 GLFW2。

### 构建 GLFW2
**Windows（MinGW）**：请先配置好 MinGW 环境变量，再按以下步骤预编译 `glfw2`：
```bash
cd glfw2
cd build
cmake -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX="./install" ..
mingw32-make.exe
mingw32-make install
```

**Linux**：按以下步骤预编译 `glfw2`：
```bash
cmake -S glfw2 -B glfw2/build -DCMAKE_INSTALL_PREFIX=glfw2/build/install
cmake --build glfw2/build --config Release
cmake --install glfw2/build --config Release
```

### 1) 构建 Universe
```bash
cmake -S . -B cmake-build-release
cmake --build cmake-build-release --config Release
```

### 2) 运行
- 生成的可执行文件为 `universe`（Windows 下为 `universe.exe`），通常位于构建目录中。
- 仓库内 `bin/` 目录可能包含历史构建产物，供参考。

## 操作说明
- `W/A/S/D`：平移移动
- `↑/↓/←/→`：旋转视角
- `Q/E`：滚转
- 鼠标左键拖拽：旋转视角
- 鼠标中键拖拽：平移
- 鼠标右键拖拽：缩放/前后移动
- `Esc`：退出
- `F1`：显示/隐藏控制说明
- `F2`：显示/隐藏轨道
- `F3`：线框模式切换
- `F4`：冻结 LOD
- `F5`：时间反向
- `0-9`：时间单位切换
- 小键盘 `+/-`：调节地形分裂距离
- `Del`：删除当前指向的天体并生成粒子特效
- `R`：重置场景
- `Alt + T/O/G/L/F/H`：调整行星地形参数（按住 `Shift` 反向调整）

## 目录结构
```text
Universe/
|-- Application/
|   |-- Application.h
|   |-- Camera.h
|   |-- FpsCounter.h
|   |-- TextTool.cpp
|   `-- TextTool.h
|-- Geometry/
|   |-- AstronomicalObject.cpp
|   |-- AstronomicalObject.h
|   |-- Atmosphere.cpp
|   |-- Atmosphere.h
|   |-- CloudLayer.cpp
|   |-- CloudLayer.h
|   |-- Frustum.cpp
|   |-- Frustum.h
|   |-- Geometry.cpp
|   |-- Geometry.h
|   |-- Particle2D.cpp
|   |-- Particle2D.h
|   |-- Planet.cpp
|   |-- Planet.h
|   |-- PlanetRing.cpp
|   |-- PlanetRing.h
|   |-- QuadtreeTerrain/
|   |   |-- QuadtreeTerrain.cpp
|   |   |-- QuadtreeTerrain.h
|   |   |-- QuadtreeTerrainFace.cpp
|   |   |-- QuadtreeTerrainFace.h
|   |   |-- QuadtreeTerrainNode.cpp
|   |   |-- QuadtreeTerrainNode.h
|   |   |-- QuadtreeTerrainPatch.cpp
|   |   |-- QuadtreeTerrainPatch.h
|   |   |-- QuadtreeTerrainPatchTopology.cpp
|   |   |-- QuadtreeTerrainPatchTopology.h
|   |   |-- RidgedMultifractalSphericalQuadtreeTerrain.cpp
|   |   |-- RidgedMultifractalSphericalQuadtreeTerrain.h
|   |   |-- SphericalQuadtreeTerrain.cpp
|   |   `-- SphericalQuadtreeTerrain.h
|   |-- SimpleCircle.cpp
|   |-- SimpleCircle.h
|   |-- SimpleCylinder.cpp
|   |-- SimpleCylinder.h
|   |-- SimpleDisk.cpp
|   |-- SimpleDisk.h
|   |-- SimpleSphere.cpp
|   |-- SimpleSphere.h
|   |-- Skybox.cpp
|   |-- Skybox.h
|   |-- Star.cpp
|   |-- Star.h
|   |-- Starfield.cpp
|   |-- Starfield.h
|-- Shaders/
|   |-- GLSL/
|   |   |-- atmosphere.frag
|   |   |-- atmosphere.vert
|   |   |-- axis.frag
|   |   |-- axis.vert
|   |   |-- cloud_texture.frag
|   |   |-- cloud_texture.vert
|   |   |-- clouds.frag
|   |   |-- clouds.vert
|   |   |-- patch_normalmap_heightmap.frag
|   |   |-- patch_normalmap_heightmap.vert
|   |   |-- patch_positionmap.frag
|   |   |-- patch_positionmap.vert
|   |   |-- perlin.frag
|   |   |-- planet.frag
|   |   |-- planet.vert
|   |   |-- planet_ring.frag
|   |   |-- planet_ring.vert
|   |   |-- ShaderSources.cpp
|   |   |-- ShaderSources.h
|   |   |-- skybox_texture.frag
|   |   |-- skybox_texture.vert
|   |   |-- star.frag
|   |   |-- star.vert
|   |   |-- sun.frag
|   |   `-- sun.vert
|   |-- ShaderManager.cpp
|   `-- ShaderManager.h
|-- Math/
|   |-- PerlinNoise.h
|   |-- Randomizer.cpp
|   |-- Randomizer.h
|   |-- VectorMath/
|   |   |-- Matrix2x2.h
|   |   |-- Matrix3x3.h
|   |   |-- Matrix4x4.h
|   |   |-- Vector2.h
|   |   |-- Vector3.h
|   |   `-- Vector4.h
|   `-- VectorMath.h
|-- GL/
|   |-- GLee.c
|   `-- GLee.h
|-- glfw2/                 # 第三方 GLFW2 源码
|-- bin/                   # 可能包含历史构建产物
|-- cmake-build-debug/     # 本地构建目录
|-- obj/                   # 旧版构建产物
|-- lib/
|-- Procedurus.cbp
|-- Procedurus.depend
|-- Procedurus.layout
|-- ProcedurusMain.cpp     # 入口
|-- CMakeLists.txt
|-- LICENSE
`-- README.md
```

## 许可证
详见 `LICENSE`。
