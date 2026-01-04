

# 🖥️ Computer Graphics Codes (GLUT)

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B)
![Library](https://img.shields.io/badge/Library-OpenGL%20%2F%20GLUT-green?style=for-the-badge&logo=opengl)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-orange?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-success?style=for-the-badge)

A comprehensive collection of Computer Graphics algorithms and projects implemented using **C++** and the **GLUT (OpenGL Utility Toolkit)** library. This repository serves as a resource for understanding the fundamental concepts of computer graphics, including rasterization, transformations, and clipping.

---
```
## 📑 Table of Contents
- [About the Project](#-about-the-project)
- [Features & Algorithms](#-features--algorithms)
- [Prerequisites](#-prerequisites)
- [Installation & Setup](#-installation--setup)
- [How to Run](#-how-to-run)
- [Screenshots](#-screenshots)
- [Contributing](#-contributing)
- [License](#-license)
- [Author](#-author)
```
---

## 📖 About the Project

This repository contains implementations of standard Computer Graphics algorithms taught in undergraduate courses. The codes are written in C/C++ and utilize the GLUT library for window management and input handling.
```
**Key Goals:**
* To demonstrate pixel-level manipulation using `glVertex`.
* To implement core algorithms (Bresenham, Midpoint, etc.) from scratch.
* To explore 2D and 3D geometric transformations.
```
---

## 🚀 Features & Algorithms

The repository includes implementations of the following algorithms:

### 🔹 Primitives Drawing
* **DDA Line Drawing Algorithm**
* **Bresenham's Line Drawing Algorithm**
* **Midpoint Circle Drawing Algorithm**
* **Bresenham's Circle Drawing Algorithm**


### 🔹 Filling & Clipping
* **Flood Fill & Boundary Fill Algorithms**
* **Scan-Line Polygon Filling**
* **Cohen-Sutherland Line Clipping**

### 🔹 Transformations
* **2D Transformations** (Translation, Rotation, Scaling)
* **3D Transformations**
* **Projection** (Orthographic & Perspective)


---

## 🛠 Prerequisites

Before running the codes, ensure you have the necessary compilers and libraries installed.

### Windows (MinGW/CodeBlocks)
1.  Install **MinGW** or **Code::Blocks** (with MinGW).
2.  Download **FreeGLUT** binaries.
3.  Place `freeglut.dll` in `C:\Windows\System32` (or `SysWOW64`).
4.  Place headers in the `include/GL` folder of your compiler.
5.  Place library files in the `lib` folder of your compiler.

### Linux (Ubuntu/Debian)
Install the required packages via terminal:
```bash
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install freeglut3-dev

```

### macOS

Using Homebrew:

```bash
brew install freeglut

```

---

## 💻 How to Run

You can compile the programs using a standard C++ compiler (g++).

### Using Terminal (Linux/Mac/Git Bash)

Navigate to the directory containing the source code and run:

```bash
g++ filename.cpp -o output -lGL -lGLU -lglut
./output

```

*Replace `filename.cpp` with the actual name of the file you want to run.*

### Using IDE (Code::Blocks / Visual Studio)

1. Open the `.cpp` file in your IDE.
2. Ensure the linker settings include `opengl32`, `glu32`, and `freeglut`.
3. Build and Run.

---

## 🤝 Contributing

Contributions are welcome! If you have a new algorithm or an optimization:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes.
4. Push to the branch.
5. Open a Pull Request.

---

## 👤 Author

**Kingshuk Datta**

* **GitHub:** [KingshukDatta](https://www.google.com/search?q=https://github.com/KingshukDatta)

---
```
*Made with ❤️ and OpenGL*

```
