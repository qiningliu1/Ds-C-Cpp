# 数据结构与算法 - C/C++实现

## 项目简介
这是一个用C和C++实现各种数据结构和算法的学习项目，基于labuladong算法笔记进行系统学习。

## 开发环境
- **Windows**: MinGW-w64 + VSCode
- **Linux**: GCC + VSCode
- **Git**: 版本控制和跨平台同步

## 项目结构
```
DataStructure/
├── c/                  # C语言实现
│   └── linked_list/    # 链表
├── cpp/                # C++实现
│   └── linked_list/    # 链表
└── docs/               # 学习笔记
```

## 学习计划
- 第一周：数组和链表
- 第二周：栈和队列
- 第三周：树结构
- 第四周：图结构

## 编译和运行
### C语言版本
```bash
cd c/linked_list
gcc -g src/linked_list.c test/test_linked_list.c -o test_linked_list
./test_linked_list
```

### C++版本
```bash
cd cpp/linked_list
g++ -g src/linked_list.cpp test/test_linked_list.cpp -o test_linked_list
./test_linked_list
```

## 参考资料
- [labuladong算法笔记](https://labuladong.online/algo/intro/data-structure-basic/) 