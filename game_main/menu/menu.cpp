/*
 *@ 文件 ： menu.cpp
 *@ 描述 ： 菜单界面的类实现
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#include "menu.hpp"
#include "type.hpp"
#include "GameStateMachine.hpp"

Menu::Menu(GameStateMachine &c_gameState, sf::View &c_camera, AllAbnormity &c_allAbnormity) : c_gameState(c_gameState),
                                                                                              c_camera(c_camera),
                                                                                              c_allAbnormity(c_allAbnormity),
                                                                                              backgroundTexture(), backgroundSprite(backgroundTexture),
                                                                                              titleText(typeface.Black),
                                                                                              MainMenu_StartText(typeface.Bold),
                                                                                              MainMenu_SettingText(typeface.Bold),
                                                                                              MainMenu_ExitText(typeface.Bold),
                                                                                              Setting_VolumeText(typeface.Bold),
                                                                                              Setting_isFullScreenText(typeface.Bold),
                                                                                              Setting_frameRateText(typeface.Bold),
                                                                                              Setting_isSwayText(typeface.Bold),
                                                                                              Setting_isMouseleaveText(typeface.Bold),
                                                                                              Setting_isMousefollowText(typeface.Bold),
                                                                                              Setting_isSkipBeginText(typeface.Bold),
                                                                                              Setting_BackText(typeface.Bold),
                                                                                              Pause_ResumeText(typeface.Bold),
                                                                                              Pause_SettingText(typeface.Bold),
                                                                                              Pause_ExitText(typeface.Bold),
                                                                                              Over_RestartText(typeface.Bold),
                                                                                              Over_ExitText(typeface.Bold),
                                                                                              Win_ExitText(typeface.Bold),
                                                                                              Win_RestartText(typeface.Bold)
{
    Menu_loadResources(c_gameState);
}

void Menu::Menu_update(sf::RenderWindow &c_window, float deltaTime)
{
    // 1. 检测状态切换，如果切换了，就重新装载 currentAnimations
    if (c_menuState.currentState != lastAnimationState)
    {
        lastAnimationState = c_menuState.currentState;
        currentAnimations.clear();
        float startX = -500.f;

        if (c_menuState.currentState == MenuState::MainMenu)
        {
            titleText.setPosition({150.f, 100.f});
            currentAnimations.push_back(AnimatedText(&MainMenu_StartText, {startX, 450.f}, {150.f, 450.f}, 0.05f));
            currentAnimations.push_back(AnimatedText(&MainMenu_SettingText, {startX, 550.f}, {150.f, 550.f}, 0.1f));
            currentAnimations.push_back(AnimatedText(&MainMenu_ExitText, {startX, 650.f}, {150.f, 650.f}, 0.15f));
        }
        else if (c_menuState.currentState == MenuState::Setting)
        {
            titleText.setPosition({150.f, 100.f});
            currentAnimations.push_back(AnimatedText(&Setting_VolumeText, {startX, 300.f}, {150.f, 300.f}, 0.05f));
            currentAnimations.push_back(AnimatedText(&Setting_isFullScreenText, {startX, 380.f}, {150.f, 380.f}, 0.1f));
            currentAnimations.push_back(AnimatedText(&Setting_frameRateText, {startX, 460.f}, {150.f, 460.f}, 0.15f));
            currentAnimations.push_back(AnimatedText(&Setting_isSwayText, {startX, 540.f}, {150.f, 540.f}, 0.2f));
            currentAnimations.push_back(AnimatedText(&Setting_isMouseleaveText, {startX, 620.f}, {150.f, 620.f}, 0.25f));
            currentAnimations.push_back(AnimatedText(&Setting_isMousefollowText, {startX, 700.f}, {150.f, 700.f}, 0.3f));
            currentAnimations.push_back(AnimatedText(&Setting_isSkipBeginText, {startX, 780.f}, {150.f, 780.f}, 0.35f));
            currentAnimations.push_back(AnimatedText(&Setting_BackText, {startX, 860.f}, {150.f, 860.f}, 0.4f));
        }
        else if (c_menuState.currentState == MenuState::Pause)
        {
            titleText.setPosition({150.f, 100.f});
            currentAnimations.push_back(AnimatedText(&Pause_ResumeText, {startX, 450.f}, {150.f, 450.f}, 0.05f));
            currentAnimations.push_back(AnimatedText(&Pause_SettingText, {startX, 550.f}, {150.f, 550.f}, 0.1f));
            currentAnimations.push_back(AnimatedText(&Pause_ExitText, {startX, 650.f}, {150.f, 650.f}, 0.15f));
        }
        else if (c_menuState.currentState == MenuState::Over)
        {
            titleText.setPosition({150.f, 100.f});
            currentAnimations.push_back(AnimatedText(&Over_RestartText, {startX, 450.f}, {150.f, 450.f}, 0.05f));
            currentAnimations.push_back(AnimatedText(&Over_ExitText, {startX, 550.f}, {150.f, 550.f}, 0.1f));
        }
        else if (c_menuState.currentState == MenuState::Win)
        {
            titleText.setPosition({150.f, 100.f});
            currentAnimations.push_back(AnimatedText(&Win_RestartText, {startX, 450.f}, {150.f, 450.f}, 0.05f));
            currentAnimations.push_back(AnimatedText(&Win_ExitText, {startX, 550.f}, {150.f, 550.f}, 0.1f));
        }
    }

    if (c_menuState.currentState != MenuState::None)
    {
        for (auto &anim : currentAnimations)
        {
            anim.AnimatedText_update(deltaTime);
        }
        Menu_UpdateText(c_gameState, c_window);
    }
    else
    {
        return;
    }
}

void Menu::Menu_draw(sf::RenderWindow &c_window)
{
    switch (c_menuState.currentState)
    {
    case MenuState::None:
        // 不绘制任何菜单
        break;
    case MenuState::MainMenu:
        // 绘制主菜单选项
        c_window.draw(backgroundSprite);
        c_window.draw(titleText);
        c_window.draw(MainMenu_StartText);
        c_window.draw(MainMenu_SettingText);
        c_window.draw(MainMenu_ExitText);
        break;
    case MenuState::Setting:
        // 绘制设置菜单选项
        c_window.draw(backgroundSprite);
        c_window.draw(titleText);
        c_window.draw(Setting_VolumeText);
        c_window.draw(Setting_isFullScreenText);
        c_window.draw(Setting_frameRateText);
        c_window.draw(Setting_isSwayText);
        c_window.draw(Setting_isMouseleaveText);
        c_window.draw(Setting_isMousefollowText);
        c_window.draw(Setting_isSkipBeginText);
        c_window.draw(Setting_BackText);
        break;
    case MenuState::Pause:
        // 绘制暂停菜单选项
        c_window.draw(backgroundSprite);
        c_window.draw(titleText);
        c_window.draw(Pause_ResumeText);
        c_window.draw(Pause_SettingText);
        c_window.draw(Pause_ExitText);
        break;
    case MenuState::Over:
        // 绘制游戏结束菜单选项
        c_window.draw(backgroundSprite);
        c_window.draw(titleText);
        c_window.draw(Over_RestartText);
        c_window.draw(Over_ExitText);
        break;
    case MenuState::Win:
        c_window.draw(backgroundSprite);
        c_window.draw(titleText);
        c_window.draw(Win_RestartText);
        c_window.draw(Win_ExitText);
        break;
    default:
        break;
    }
}
