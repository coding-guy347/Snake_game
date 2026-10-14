#pragma once
#include <SDL3/SDL.h>
#include<SDL3_ttf/SDL_ttf.h>
#include<string>
#include<array>
#define X_ChangeSize 20
#define Y_ChangeSize 30
using namespace std;
extern SDL_Renderer* renderer;
extern SDL_Window* window;
void InitGame();
void CreateWindowAndRender();
void RenderClear();
void RenderPresent();
float ToPixel_x(int x);
float ToPixel_y(int y);
void RenderText( TTF_Font* font, const string& Title, SDL_Renderer* render,int y,const array<int ,4>color);
// 按 exe 所在目录（及若干回退位置）查找资源文件，返回可直接使用的路径。
// 这样打包发给别人、或把工程挪到别的路径都能找到 msyh.ttc。
string FindAsset(const string& name);