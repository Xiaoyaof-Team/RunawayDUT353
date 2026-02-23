/*
 *@ 文件 ： menu.hpp
 *@ 描述 ： 菜单界面的类声明
 *@ 作者 ： 小恐龙大魔王
 *@ 时间 ： 2026-2-1
 */
#pragma once
#include "SFML/Graphics.hpp"
#include "GameStateMachine.hpp"
#include "menuStateMachine.hpp"
#include "AllAbnormity.hpp"
#include "music.hpp"
#include <vector>

class AnimatedText;

class Menu
{
public:
    // 声明菜单状态机
    MenuStateMachine c_menuState;
    // 获得全局状态机
    GameStateMachine &c_gameState;
    // 获得异常管理类
    AllAbnormity &c_allAbnormity;

    // 获得视图
    sf::View &c_camera;

    std::vector<AnimatedText> currentAnimations; // 当前正在进行动画的文本列表
    MenuState lastAnimationState = MenuState::None; // 记录上一次动画的状态，用于检测状态切换

private:
    // 声明纹理贴图
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    // 声明标题
    sf::Text titleText;
    // 声明主菜单选项
    sf::Text MainMenu_StartText;
    sf::Text MainMenu_SettingText;
    sf::Text MainMenu_ExitText;
    // 声明设置菜单选项
    sf::Text Setting_VolumeText;
    sf::Text Setting_isFullScreenText;
    sf::Text Setting_frameRateText;
    sf::Text Setting_isSwayText;
    sf::Text Setting_isMouseleaveText;
    sf::Text Setting_isMousefollowText;
    sf::Text Setting_isSkipBeginText;
    sf::Text Setting_BackText;
    // 声明暂停菜单选项
    sf::Text Pause_ResumeText;
    sf::Text Pause_SettingText;
    sf::Text Pause_ExitText;
    // 声明游戏结束菜单选项
    sf::Text Over_RestartText;
    sf::Text Over_ExitText;
    // 声明游戏胜利菜单选项
    sf::Text Win_RestartText;
    sf::Text Win_ExitText;

public:
    Menu(GameStateMachine &c_gameState, sf::View &c_camera, AllAbnormity &c_allAbnormity);
    void Menu_update(sf::RenderWindow &c_window, float deltaTime);
    void Menu_draw(sf::RenderWindow &c_window);
    void Menu_loadResources(GameStateMachine &c_gameState);
    void Menu_UpdateText(GameStateMachine &c_gameState, sf::RenderWindow &c_window);

    bool HandleEvent(const sf::Event::KeyPressed &key, sf::RenderWindow &c_window);
    bool HandleEvent(const sf::Event::MouseButtonPressed &mouse, sf::RenderWindow &c_window);
    void handle_setting_change(const sf::Event::MouseButtonPressed &mouse, sf::RenderWindow &c_window);
    template <class T>
    bool HandleEvent(const T &, sf::RenderWindow &c_window) { return false; }
};

class AnimatedText
{
public:
    sf::Text *text_ptr;
    sf::Vector2f startPos;
    sf::Vector2f targetPos;
    float delay;             // 延迟多久开始飞入（秒）
    float elapsedTime = 0.f; // 已经过去的时间
    float duration;          // 飞入动画持续时间（秒）
    bool isAnimating = true;

public:
    AnimatedText(sf::Text *text, sf::Vector2f start, sf::Vector2f target, float delay, float duration = 0.5f)
        : text_ptr(text), startPos(start), targetPos(target), delay(delay), duration(duration)
    {
        text_ptr->setPosition(startPos);
        // 使用缓动函数后，不需要手动计算多出的距离和每秒移动距离
        // 缓动函数会自动处理超过目标位置再回弹的逻辑
    }

    void AnimatedText_update(float deltaTime)
    {
        if (!isAnimating)
            return;
        elapsedTime += deltaTime;
        if (elapsedTime < delay)
            return; // 还在等待阶段

        // 计算动画的实际进行时间
        float animTime = elapsedTime - delay;

        // 计算动画进度 (0.0 到 1.0)
        float progress = animTime / duration;

        if (progress >= 1.0f)
        {
            // 动画结束，确保停在最终目标位置
            text_ptr->setPosition(targetPos);
            isAnimating = false;
            return;
        }

        // SED：AI神力喵~

        // 使用缓动函数 (Ease-Out Back) 实现回弹效果
        // 公式：f(t) = 1 + c3 * (t - 1)^3 + c1 * (t - 1)^2
        // 其中 c1 控制回弹幅度，c1 越小回弹越轻微。原值为 1.70158f
        // 其中 c3 = c1 + 1
        // 这个公式会让进度在接近 1.0 时稍微超过 1.0，然后再回到 1.0，从而产生回弹
        float c1 = 0.7f;
        float c3 = c1 + 1.0f;
        float t = progress - 1.0f;

        float easedProgress = 1.0f + c3 * std::pow(t, 3.0f) + c1 * std::pow(t, 2.0f);

        // 根据缓动进度计算当前位置
        // 注意：这里直接使用 targetPos 和 startPos 进行插值，不需要手动计算 changePos 和 changePos_second
        float currentX = startPos.x + (targetPos.x - startPos.x) * easedProgress;
        float currentY = startPos.y + (targetPos.y - startPos.y) * easedProgress;

        text_ptr->setPosition(sf::Vector2f(currentX, currentY));
    }
};