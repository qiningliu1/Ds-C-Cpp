# Git项目创建和跨平台同步开发流程

## 概述
本文档记录了从零开始创建Git项目，并在Windows和Linux主机之间进行同步开发的完整流程。

## 环境说明
- **Windows主机**: MinGW-w64 + VSCode + PowerShell
- **Linux主机**: Ubuntu + GCC + VSCode + Bash
- **版本控制**: Git + GitHub
- **同步方式**: SSH密钥认证

---

## 第一部分：Windows端项目初始化

### 1. 创建项目目录和基本文件

```powershell
# 在项目根目录中
cd your-project-directory

# 初始化Git仓库
git init

# 创建README.md
echo "# 项目名称" > README.md

# 创建.gitignore文件
```

#### .gitignore模板（C/C++项目）
```gitignore
# 编译产生的文件
*.o
*.obj
*.exe
*.out
*.app

# 调试文件
*.dSYM/
*.su
*.idb
*.pdb
*.gdb_history
core

# IDE和编辑器文件
.vscode/settings.json
.vscode/launch.json
.vscode/tasks.json
.vs/
*.swp
*.swo
*~

# 系统文件
.DS_Store
Thumbs.db

# 构建目录
build/
bin/
obj/

# 测试可执行文件
test_*
*_test
```

### 2. 提交到本地仓库

```powershell
# 添加所有文件到暂存区
git add .

# 提交到本地仓库
git commit -m "Initial commit: project setup"

# 重命名分支为main（GitHub默认）
git branch -M main
```

### 3. 在GitHub上创建远程仓库

1. 访问 https://github.com/你的用户名
2. 点击右上角 "+" → "New repository"
3. 设置仓库信息：
   - Repository name: `项目名称`
   - Description: `项目描述`
   - Visibility: Public/Private
   - **不要勾选** "Add a README file"
   - **不要添加** .gitignore 和 license
4. 点击 "Create repository"

### 4. 连接本地仓库到GitHub

```powershell
# 添加远程仓库（替换为你的仓库地址）
git remote add origin https://github.com/你的用户名/仓库名.git

# 验证远程连接
git remote -v

# 推送到GitHub
git push -u origin main
```

---

## 第二部分：Linux主机SSH配置

### 1. 生成SSH密钥

```bash
# 打开终端
# Ctrl + Alt + T

# 生成SSH密钥（替换为你的GitHub邮箱）
ssh-keygen -t ed25519 -C "你的GitHub邮箱地址"

# 执行过程中的选择：
# Enter file: 直接回车（使用默认路径）
# Enter passphrase: 可以设密码或直接回车
# Enter same passphrase again: 重复上面的选择
```

### 2. 查看并复制公钥

```bash
# 显示公钥内容
cat ~/.ssh/id_ed25519.pub

# 复制输出的整行内容（从ssh-ed25519开始到邮箱结束）
```

### 3. 将公钥添加到GitHub

1. 访问 https://github.com
2. 右上角头像 → Settings
3. 左侧菜单 → "SSH and GPG keys"
4. 点击 "New SSH key"
5. 填写信息：
   - Title: `Linux主机` 或其他描述性名称
   - Key: 粘贴刚才复制的公钥内容
6. 点击 "Add SSH key"

### 4. 测试SSH连接

```bash
# 测试GitHub SSH连接
ssh -T git@github.com

# 成功显示：
# Hi 你的用户名! You've successfully authenticated, but GitHub does not provide shell access.
```

### 5. 克隆仓库到Linux主机

```bash
# 创建项目目录
mkdir ~/projects
cd ~/projects

# 克隆仓库（使用SSH方式）
git clone git@github.com:你的用户名/仓库名.git

# 进入项目目录
cd 仓库名

# 验证克隆成功
ls -la
git status
```

---

## 第三部分：跨平台同步开发流程

### Windows端开发流程

```powershell
# 1. 拉取最新代码
git pull origin main

# 2. 开发代码...

# 3. 查看修改
git status
git diff

# 4. 提交更改
git add .
git commit -m "描述你的修改"

# 5. 推送到GitHub
git push origin main
```

### Linux端开发流程

```bash
# 1. 拉取最新代码
git pull origin main

# 2. 开发代码...

# 3. 查看修改
git status
git diff

# 4. 提交更改
git add .
git commit -m "描述你的修改"

# 5. 推送到GitHub
git push origin main
```

---

## 第四部分：常用命令速查

### Git基础命令

```bash
# 查看状态
git status

# 查看修改
git diff

# 查看提交历史
git log --oneline

# 查看远程仓库
git remote -v

# 拉取远程更新
git pull origin main

# 推送本地更改
git push origin main
```

### 分支操作

```bash
# 创建新分支
git checkout -b feature-name

# 切换分支
git checkout main

# 查看所有分支
git branch -a

# 合并分支
git merge feature-name

# 删除本地分支
git branch -d feature-name
```

### SSH相关

```bash
# 测试GitHub连接
ssh -T git@github.com

# 查看SSH密钥
ls ~/.ssh/

# 重新生成SSH密钥
ssh-keygen -t ed25519 -C "你的邮箱"
```

---

## 第五部分：故障排除

### 常见问题及解决方案

#### 1. SSH连接失败
```bash
# 问题：Permission denied (publickey)
# 解决：检查SSH密钥是否正确添加到GitHub

# 检查SSH密钥
ls ~/.ssh/
cat ~/.ssh/id_ed25519.pub

# 重新测试连接
ssh -T git@github.com
```

#### 2. 推送失败
```bash
# 问题：rejected (non-fast-forward)
# 解决：先拉取远程更新

git pull origin main
# 解决可能的合并冲突
git push origin main
```

#### 3. 密钥文件权限问题
```bash
# 设置正确的文件权限
chmod 700 ~/.ssh
chmod 600 ~/.ssh/id_ed25519
chmod 644 ~/.ssh/id_ed25519.pub
```

---

## 第六部分：项目结构建议

### C/C++项目标准结构

```
项目名/
├── README.md              # 项目说明
├── .gitignore            # Git忽略文件
├── c/                    # C语言实现
│   └── linked_list/
│       ├── src/          # 源码文件
│       └── test/         # 测试文件
├── cpp/                  # C++实现
│   └── linked_list/
│       ├── src/          # 源码文件
│       └── test/         # 测试文件
└── docs/                 # 文档目录
    └── notes.md          # 学习笔记
```

---

## 第七部分：最佳实践

### 1. 提交信息规范
```bash
# 好的提交信息
git commit -m "Add linked list implementation in C"
git commit -m "Fix memory leak in queue operations"
git commit -m "Update README with compilation instructions"

# 避免的提交信息
git commit -m "update"
git commit -m "fix bug"
git commit -m "WIP"
```

### 2. 定期同步
- 每天开始工作前：`git pull origin main`
- 每次修改后及时提交：`git add . && git commit -m "描述"`
- 每天结束工作时：`git push origin main`

### 3. 分支管理
- main分支：稳定版本
- feature分支：新功能开发
- 完成功能后合并到main

---

## 附录：完整示例

### 创建新项目完整流程

```bash
# Windows端
mkdir MyProject
cd MyProject
git init
echo "# MyProject" > README.md
git add .
git commit -m "Initial commit"
git branch -M main
git remote add origin https://github.com/username/MyProject.git
git push -u origin main

# Linux端
ssh-keygen -t ed25519 -C "your-email@example.com"
cat ~/.ssh/id_ed25519.pub
# 添加公钥到GitHub
ssh -T git@github.com
git clone git@github.com:username/MyProject.git
cd MyProject
```

---

## 结语

这个流程一旦设置完成，后续的项目开发就可以在Windows和Linux之间无缝切换，大大提高开发效率。记住：
- Windows用于快速开发和测试
- Linux用于更接近生产环境的验证
- GitHub作为中心同步点

保存这份文档，每次新项目都可以参考执行！ 