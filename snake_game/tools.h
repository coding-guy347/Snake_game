#pragma once
#include <SDL3/SDL.h>
#include<SDL3_ttf/SDL_ttf.h>
#include<string>
#include<array>
#define X_ChangeSize 20//格子坐标转换像素坐标的尺寸
#define Y_ChangeSize 30
using namespace std;
extern SDL_Renderer* renderer;
extern SDL_Window* window;
void InitGame();//初始化游戏
void CreateWindowAndRender();//创建窗口并渲染
void RenderClear();//清理上一帧的渲染
void RenderPresent();//显示渲染结果
float ToPixel_x(int x);//转换像素坐标
float ToPixel_y(int y);
void RenderText( TTF_Font* font, const string& Title, SDL_Renderer* render,int y,const array<int ,4>color);//渲染文本
// 按 exe 所在目录（及若干回退位置）查找资源文件，返回可直接使用的路径。
// 这样打包发给别人、或把工程挪到别的路径都能找到 msyh.ttc。
string FindAsset(const string& name);