# 贪吃蛇（SDL3 + SDL3_ttf）

用 C++ 写的贪吃蛇小游戏，Visual Studio 2026 工程（x64）。

## 环境要求

- **Visual Studio 2026**，需安装「使用 C++ 的桌面开发」工作负载（工程工具集为 `v145`）
- Windows 10 / 11 x64

## 依赖库（已随仓库提供）

| 库 | 版本 | 位置 | 许可 |
| --- | --- | --- | --- |
| SDL3 | 3.4.16 | `snake_game/SDL3/` | zlib |
| SDL3_ttf | 3.2.2 | `snake_game/SDL3_ttf/` | zlib |

配置方式：`snake_game.vcxproj` 内联了 SDL3 的包含目录/库；`SDL3_ttf.props`（属性表）负责 SDL3_ttf 的包含目录 / 库 / 依赖项，并在编译后自动把 `SDL3.dll`、`SDL3_ttf.dll` 复制到 exe 旁边。

都是 x64 和 x86 两套，四个配置（Debug/Release × x64/Win32）都能编译。

## ⚠️ 运行前必做：把字体放进工程目录

界面上的中文用**微软雅黑**渲染，代码里是 `TTF_OpenFont("msyh.ttc", ...)`。**字体文件不在工程目录时这个调用返回 NULL，文字画不出来**（不会崩，但一个字都没有）。

```powershell
copy C:\Windows\Fonts\msyh.ttc <仓库路径>\snake_game\snake_game\
```

字体路径是相对**当前工作目录**的：在 VS 里调试时工作目录就是工程目录（`snake_game/snake_game/`），所以放在那里即可；如果直接双击 exe，则要把 `msyh.ttc` 放到 exe 旁边。

**为什么仓库里没有这个字体**：微软雅黑是微软的专有字体，不允许随项目分发，因此 `.gitignore` 中排除了 `*.ttc` / `*.ttf` / `*.otf`。

## ⚠️ 编译器需要加 /utf-8

源码里有中文字面量（界面文字）。不指定编码时 MSVC 会按系统代码页（936）转换窄字符串，SDL_ttf 拿到的就是 GBK 字节 —— 中文会渲染成乱码或方框。

项目属性 → **C/C++ → 命令行 → 其他选项**，加上 `/utf-8`。
（或者把中文字面量写成 `u8"..."`，效果一样。）

## 编译运行

1. 打开 `snake_game.slnx`
2. 配置选 `Debug | x64`（或 `Release | x64`）
3. 按 F5 运行

编译后 `SDL3.dll` / `SDL3_ttf.dll` 会自动复制到输出目录，双击生成的 exe 也能直接跑（记得把字体放在 exe 旁边）。

## 操作

| 按键 | 作用 |
| --- | --- |
| 空格 | 开始游戏 |
| ↑ ↓ ← → | 改变蛇的方向 |
| R | 蛇死掉之后重新开始 |
| ESC | 进入结束状态 |
| 关闭窗口 | 退出程序 |

## 源码结构

| 文件 | 作用 |
| --- | --- |
| `main.cpp` | 入口：初始化 SDL、注册图形原型、启动 `Game` |
| `Game.h` / `Game.cpp` | 游戏主循环与状态机（菜单 / 游戏中 / 结束） |
| `Snake.h` / `Snake.cpp` | 蛇：移动、转向、撞墙与撞自己判定、吃食物 |
| `Food.h` / `Food.cpp` | 食物：随机生成与重生成 |
| `Shape.h` / `Shape.cpp` | 图形基类（`Point` / `Retangle` / `Triangle` / `Cycle`）＋原型模式（`addPrototype` / `FindAndClone`） |
| `Menu.h` / `Menu.cpp` | 菜单文字与提示 |
| `tools.h` / `tools.cpp` | SDL 初始化、窗口与渲染器、清屏/呈现、格子↔像素坐标换算 |
| `SDL3_ttf.props` | SDL3_ttf 属性表（包含目录 / 库 / DLL 复制） |

## 许可

- 本项目源码：自行选择（例如 MIT）
- `SDL3/`、`SDL3_ttf/`：**zlib 许可**，各自的 `LICENSE.txt` 必须保留
- 微软雅黑字体：**不包含**在本仓库中，请按上文说明自行复制
