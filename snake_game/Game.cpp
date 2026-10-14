#include"Game.h"

Game::Game() : LastMoveTime(SDL_GetTicks()) {
}

void Game::SetState(State state)
{
    this->state = state;
}

void Game::Run()
{
	while (Running)
	{
        RenderClear();
        if (state == MENU)
        {
            RenderTitle(menu.Title,420);
            RenderTitle(menu.StartReminderTitle, 520);
        }
        HandleInput();
        if (state == State::PLAYING&&!snake.Isdead())
        {
            Update();
            RenderObject();
        }
        if (snake.Isdead())
        {
            snake.SnakeClear();
            RenderTitle(menu.EndReminderTitle_1, 420);
            RenderTitle(menu.EndReminderTitle_2,510);
        }
        if (state == State::OVER)
        {
            Running =false;
            menu.~Menu();
        }
        RenderPresent();
	}
}

void Game::HandleInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) Running = false;
        if (event.type == SDL_EVENT_KEY_DOWN) {
            if (event.key.scancode== SDL_SCANCODE_SPACE) SetState(State::PLAYING);
            if (event.key.scancode == SDL_SCANCODE_ESCAPE) SetState(State::OVER);
            if (event.key.scancode == SDL_SCANCODE_R && snake.Isdead())
            {
                snake.ReInitSnake();
                SetState(State::PLAYING);
            }
            if (state == PLAYING)
            {
                switch (event.key.scancode) {
                case SDL_SCANCODE_UP:    snake.SetDirection(Snake::Direction::UP);    break;
                case SDL_SCANCODE_DOWN:   snake.SetDirection(Snake::Direction::DOWN);  break;
                case SDL_SCANCODE_LEFT:  snake.SetDirection(Snake::Direction::LEFT);  break;
                case SDL_SCANCODE_RIGHT:  snake.SetDirection(Snake::Direction::RIGHT); break;
                }
            }
        }
    }
}

void Game::Update()
{
    bool ate=false;//开始设置没有迟到食物
    if (SDL_GetTicks() - LastMoveTime >= 150)
    {
        vector<int>point = snake.NextHeadPosition();
        if (food.Get_x() == point[0] && food.Get_y() == point[1])
        {
            ate = true;
        }
        snake.SetAtefood(ate);//将ate传给snake
        snake.move();
        LastMoveTime = SDL_GetTicks();
        if (ate) food.Respawn();//如果吃到食物，更新food
    }
}

void Game::RenderObject()
{
    snake.Print();
    food.Print();
}

void Game::RenderTitle(const string&Title,int y)
{
    menu.PrintTitle(Title, y);
}
