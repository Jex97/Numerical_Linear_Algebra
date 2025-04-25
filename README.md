# 项目名称

简要描述项目的功能和目的。

## 目录

- [简介](#简介)
- [计划](#计划)
- [功能](#功能)
- [安装](#安装)
- [使用方法](#使用方法)
- [测试](#测试)
- [贡献](#贡献)
- [许可证](#许可证)
- [致谢](#致谢)

---

## 简介

> 本项目是一个数值线性代数的简单项目，旨在学习cmake、google test以及数值计算的基础知识

---

## 计划

- [ ] 完善高斯消元算法
    - [ ] 实现主元的选择；
    - [ ] 不同实现对性能影响的分析；
    - [ ] 完善其他细节；

## 功能

- 提供高斯消元算法的实现
- 简单易用的测试框架

---

## 安装

### 前提条件

列出使用该项目所需的依赖，例如：
- C++17 或更高版本
- CMake 3.10 或更高版本

### 安装步骤

提供安装步骤，例如：
```bash
# 克隆仓库
git clone https://github.com/Jex97/Numerical_Linear_Algebra.git
cd Numerical_Linear_Algebra

# 创建构建目录
mkdir build && cd build

# 配置和构建项目
cmake ..
make
```

---

## 使用方法

## 测试

描述如何运行测试：
```bash
# 进入构建目录
cd build

# 运行测试
ctest
```

---

## 贡献

欢迎贡献代码！请遵循以下流程：
1. Fork 本仓库
2. 创建你的特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交你的修改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 提交一个 Pull Request

---

## 许可证


---

## 致谢

感谢以下资源或人员对本项目的支持：
- [Google Test](https://github.com/google/googletest) - 测试框架