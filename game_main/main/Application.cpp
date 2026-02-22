/*
 *@ 文件 ： Application.cpp
 *@ 描述 ： 游戏主体框架的类方法的实现
 *@ 作者 ： 小恐龙大魔王
 *@ 补充 ：
 *@ 时间 ： 2026-2-1
 */
#include "Application.hpp"
#include <iostream>
// 构造函数
Application::Application() : c_window(sf::VideoMode({1920, 1080}), "RunawayTechbuilding1"),
                             c_allAbnormity(&c_scene),
                             c_menu(c_gameState, c_camera, c_allAbnormity),
                             c_scene(c_gameState, c_player),
                             c_gameState()
{
    CreateDefaultWindow();
    c_player.init();
    // SED::设置初始场景状态
    c_allAbnormity.currentAbnormity->scene_set();
}

// 检查程序是否运行
bool Application::IsRunning() const
{
    return c_window.isOpen();
}

// 处理事件
void Application::ProcessEvent()
{
    c_window.handleEvents([this](const auto &Tevent)
                          {
    // 事件被处理则返回true，未被处理则返回false
    if(this->HandleEvent(Tevent)) return;
    // 处理菜单事件前切换到 UI 视图
    this->c_window.setView(this->c_uiView);
    if(this->c_menu.HandleEvent(Tevent, c_window)) return; 
    if(this->c_allAbnormity.currentAbnormity->HandleEvent(Tevent)) return; });
}

// 更新游戏状态
void Application::Update()
{
    // 定义时间步长
    auto deltatime = deltaTime.restart().asSeconds();
    // SED: 更新游戏内容
    // 更新菜单状态前切换到 UI 视图
    c_window.setView(c_uiView);
    c_menu.Menu_update(c_window, deltatime);
    // std::cout << "Player Position: " << c_player.getPosition().x << ", " << c_player.getPosition().y << std::endl;
    // 更新相机
    UpdateCamera(deltatime);
    c_player.checkState(c_menu.c_menuState.currentState, c_menu.c_menuState.lastState, c_window, c_menu.c_gameState.is_SkipBegin);
    c_player.update(deltatime);
    // SED::更新场景状态
    c_allAbnormity.checkAnswer(c_menu);
    c_allAbnormity.currentAbnormity->scene_update();
}

// 刷新显示效果
void Application::Render()
{
    c_window.clear(sf::Color::Black);
    // SED: 渲染游戏内容
    c_window.setView(c_camera);
    // SED::
    c_allAbnormity.currentAbnormity->scene_draw(c_window);
    c_player.draw(c_window);
    c_allAbnormity.currentAbnormity->scene_draw_2(c_window);

    // 渲染菜单 (使用固定的 UI 视图)
    c_window.setView(c_uiView);
    c_menu.Menu_draw(c_window);

    c_window.display();
}

// 处理窗口调整大小事件
bool Application::HandleEvent(const sf::Event::Resized &resized)
{
    UpdateCameraViewPort(resized.size.x, resized.size.y);
    return true;
}

// 处理关闭事件
bool Application::HandleEvent(const sf::Event::Closed &)
{
    Close();
    return true;
}

bool Application::HandleEvent(const sf::Event::MouseButtonPressed &mouse)
{
    c_music.mouseClickSound.play();
    return false;
}

// 关闭窗口
void Application::Close()
{
    c_window.close();
}
