#include"tools.h"
 SDL_Window* window = NULL;
 SDL_Renderer* renderer = NULL;
#include<iostream>
#include<fstream>
#include<vector>

string FindAsset(const string& name) {
    vector<string> cands;
    // SDL_GetBasePath() 返回 exe 所在目录，自带结尾分隔符，内存由 SDL 持有（不要 free）
    const char* base = SDL_GetBasePath();
    if (base) {
        string b(base);
        cands.push_back(b + name);                        // exe 同级目录（分发打包用）
        cands.push_back(b + "../../" + name);             // <工程>\x64\Debug -> 工程目录
        cands.push_back(b + "../../../" + name);
        cands.push_back(b + "../../snake_game/" + name);  // <解决方案>\x64\Debug -> 工程目录
    }
    cands.push_back(name);                                // 当前工作目录
    cands.push_back("snake_game/" + name);
    for (size_t i = 0; i < cands.size(); ++i) {
        ifstream f(cands[i].c_str(), ios::binary);
        if (f.good()) {
            cout << "asset found: " << cands[i] << endl;
            return cands[i];
        }
    }
    cout << "asset NOT found: " << name << " (searched " << cands.size() << " locations)" << endl;
    return name;
}

void InitGame() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init 失败: %s", SDL_GetError());
    }
    TTF_Init();
}

void CreateWindowAndRender() {
    if (!SDL_CreateWindowAndRenderer("Greedy Snake", 2048, 1024, 0, &window, &renderer)) {
        SDL_Log("创建窗口/渲染器失败: %s", SDL_GetError());
    }
}

void RenderClear() {
    SDL_SetRenderDrawColorFloat(renderer, 0.0f, 0.0f, 0.0f, 1.0f);
    SDL_RenderClear(renderer);
}

void RenderPresent() {
    SDL_RenderPresent(renderer);
}

float ToPixel_x(int  x)
{
    return  (float)(x * X_ChangeSize);
}

float ToPixel_y(int y)
{
    return (float)(y * Y_ChangeSize);
}

void RenderText( TTF_Font*font,const string&Title,SDL_Renderer*render,int y,const array<int,4>color)
{
    if (!font) cout << "font is NULL";
    SDL_Color Textcolor= { color[0],color[1],color[2],color[3]};//文字颜色
    SDL_Surface* surface = TTF_RenderText_Blended(font, Title.c_str(), Title.size(), Textcolor);
    if (!surface) return;
    SDL_Texture *texture = SDL_CreateTextureFromSurface(render, surface);//获取文字的纹理
    if (!texture) return;
    SDL_FRect rect;//建立文字渲染矩形
    rect.x =(2048-surface->w)/2;
    rect.y = y;
    rect.w = surface->w;
    rect.h = surface->h;
    SDL_DestroySurface(surface);//销毁中间变量
    SDL_RenderTexture(render, texture, NULL, &rect);
    SDL_DestroyTexture(texture);//渲染后销毁纹理
}

