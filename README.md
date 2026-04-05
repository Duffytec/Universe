# Universe

`Universe` 是一个基于 `C++11 + OpenGL + GLFW + GLEW` 的程序化宇宙/行星渲染示例。仓库现在已经内置 `GLFW` 和 `GLEW` 源码，`git pull` 后会优先使用 `third_party/` 里的依赖进行构建。

## 依赖

- CMake 3.16+
- 支持 OpenGL 的桌面图形驱动
- GLU
- C++11 编译器

## 当前支持的平台

- Linux: 已验证可通过 CMake 编译
- Windows: 使用 MinGW 构建

## Linux 构建

Ubuntu/Debian 可先安装构建工具和系统 OpenGL/X11 依赖：

```bash
sudo apt update
sudo apt install -y \
  build-essential \
  cmake \
  libglu1-mesa-dev \
  libx11-dev \
  libxrandr-dev \
  libxinerama-dev \
  libxcursor-dev \
  libxi-dev
```

构建：

```bash
cmake -S . -B build
cmake --build build -j
```

运行：

```bash
./build/universe
```

如果运行时出现 `glfwInit failed`，通常不是源码问题，而是当前会话没有可用桌面图形环境、OpenGL 驱动未安装完整，或者是在受限/无头环境中启动。

## Windows 构建

使用 `MSYS2 MinGW64`。仓库已自带 `GLFW` 和 `GLEW`，Windows 不需要再单独安装这两个库。

1. 安装 `MSYS2`
2. 打开 `MSYS2 MinGW 64-bit` 终端
3. 安装依赖

```bash
pacman -S --needed \
  mingw-w64-x86_64-toolchain \
  mingw-w64-x86_64-cmake \
  mingw-w64-x86_64-ninja
```

4. 配置并构建

```bash
cmake -S . -B build -G Ninja
cmake --build build
```

5. 运行

```bash
./build/universe.exe
```

如果 Windows 上仍然报 `glfw3` 或 `GLEW` 未找到，优先检查：

- 是否在 `MSYS2 MinGW 64-bit` 终端里运行，而不是普通 `MSYS` 终端
- `cmake` 是否来自 MinGW 环境而不是其他 Windows 安装

## 项目结构

```text
Universe/
|-- Application/
|-- Geometry/
|   `-- QuadtreeTerrain/
|-- GL/
|   `-- OpenGL.h
|-- Math/
|   `-- VectorMath/
|-- Shaders/
|   `-- GLSL/
|-- third_party/
|   |-- glfw/
|   `-- glew/
|-- CMakeLists.txt
|-- ProcedurusMain.cpp
|-- README.md
`-- LICENSE
```

## 运行说明

- `W/A/S/D`: 平移移动
- `↑/↓/←/→`: 旋转视角
- `Q/E`: 滚转
- 鼠标左键拖拽: 旋转视角
- 鼠标中键拖拽: 平移
- 鼠标右键拖拽: 缩放/前后移动
- `Esc`: 退出
- `F1`: 显示/隐藏控制说明
- `F2`: 显示/隐藏轨道
- `F3`: 线框模式切换
- `F4`: 冻结 LOD
- `F5`: 时间反向
- `0-9`: 时间单位切换
- 小键盘 `+/-`: 调节地形分裂距离
- `Del`: 删除当前指向的天体并生成粒子特效
- `R`: 重置场景
- `Alt + T/O/G/L/F/H`: 调整行星地形参数，按住 `Shift` 反向调整

## 说明

- 仓库不再包含历史构建目录、旧 IDE 工程文件和过时的 `GLee` 代码
- 当前推荐的唯一构建入口是 `CMakeLists.txt`
- `CMake` 会优先使用仓库内置的 `third_party/glfw` 和 `third_party/glew`

## 许可证

详见 `LICENSE`。
