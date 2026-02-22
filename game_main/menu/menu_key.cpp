/*
 *@ 文件 ： menu_key.cpp
 *@ 描述 ： 菜单界面的类对键盘事件的实现
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#include "menu.hpp"
#include "type.hpp"

bool Menu::HandleEvent(const sf::Event::KeyPressed &key, sf::RenderWindow &c_window)
{
    // 根据当前菜单状态处理按键事件
    switch (c_menuState.currentState)
    {
    case MenuState::None:
        // 在没有菜单状态下如进入游戏状态时按下Esc键显示暂停页面
        if (key.code == sf::Keyboard::Key::Escape)
        {
            c_menuState.currentState = MenuState::Pause;
            c_menuState.lastState = c_menuState.currentState;
            return true;
        }
        break;
    case MenuState::MainMenu:
        // 在主菜单状态下按下Esc键退出游戏
        if (key.code == sf::Keyboard::Key::Escape)
        {
            c_menuState.currentState = MenuState::Over;
            c_menuState.lastState = c_menuState.currentState;
            return true;
        }
        break;
    case MenuState::Setting:
        // 在设置菜单状态下按下Esc键返回上一次菜单状态
        if (key.code == sf::Keyboard::Key::Escape)
        {
            c_menuState.currentState = c_menuState.lastState;
            c_menuState.lastState = c_menuState.currentState;
            return true;
        }
        break;
    case MenuState::Pause:
        // 在暂停菜单状态下按下Esc键返回游戏状态
        if (key.code == sf::Keyboard::Key::Escape)
        {
            c_menuState.currentState = MenuState::None;
            c_menuState.lastState = c_menuState.currentState;
            return true;
        }
        break;
    case MenuState::Over:
        // 在游戏结束菜单状态下按下Esc键返回主菜单
        if (key.code == sf::Keyboard::Key::Escape)
        {
            c_menuState.currentState = MenuState::MainMenu;
            c_menuState.lastState = c_menuState.currentState;
            return true;
        }
        break;
    default:
        break;
    }
    return false;
}