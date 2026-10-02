# 一维热传导方程 Crank-Nicolson 求解器

用 C++ 实现的一维热传导方程隐式求解器，包含自己实现的三对角线性系统求解算法（Thomas 算法）。

## 数学方程

求解一维热传导方程：

    ∂u/∂t = α · ∂²u/∂x²,    0 < x < 1,  t > 0

初始条件：

    u(x, 0) = sin(πx)

边界条件：

    u(0, t) = 0
    u(1, t) = 0

精确解：

    u(x, t) = exp(-α·π²·t) · sin(πx)

## 数值方法

- **时间离散**：Crank-Nicolson 格式（二阶精度，无条件稳定）
- **空间离散**：中心差分（二阶精度）
- **线性求解**：Thomas 算法（三对角矩阵，O(n) 复杂度）

## 文件结构

    .
    ├── include/
    │   └── thomas.h          # Thomas 算法声明
    ├── src/
    │   ├── thomas.cpp        # Thomas 算法实现
    │   └── main.cpp          # 主程序：CN 格式时间推进
    └── README.md

## 编译运行

    clang++ -std=c++17 -I include -o heat1d_cn src/main.cpp src/thomas.cpp
    ./heat1d_cn

运行后生成 `heat1d_cn_result.txt`，第一列是坐标 x，第二列是数值解 u。

## 验证

数值解峰值（x=0.5, t=0.5）：**0.951377**

精确解峰值：**0.95186**

相对误差：**约 0.05%**