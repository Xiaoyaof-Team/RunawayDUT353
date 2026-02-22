/*
 *@ 文件 ： Application_Update.cpp
 *@ 描述 ： 游戏主体框架状态机的更新
 *@ 作者 ： 小恐龙大魔王
 *@ 补充 ：
 *@ 时间 ： 2026-2-1
 */
#include "Application.hpp"
#include <cmath>

void Application::UpdateCamera(float deltaTime)
{
    timeinView += sf::seconds(deltaTime) / 2.f;
    if (timeinView.asSeconds() > 3.14159 * 2)
    {
        timeinView = sf::Time::Zero;
    }
    // SED: 在这里添加相机更新逻辑
    // 相机跟随玩家，并添加上下浮动效果
    sf::Vector2f cameraPos;
    // 添加轻微摇晃
    if (c_gameState.is_sway == L"是")
    {
        c_camera.setRotation(sf::degrees(std::sin(timeinView.asSeconds()) * 0.4f));
        cameraPos = c_player.getPosition() - sf::Vector2f(0.f, 100.f + 5.0f * std::sin(timeinView.asSeconds() * 2.f));
    }
    else
    {
        c_camera.setRotation(sf::degrees(0.f));
        cameraPos = c_player.getPosition() - sf::Vector2f(0.f, 100.f);
    }

    // 计算相机跟随鼠标水平的偏移
    if (c_gameState.is_Mouse_Follow_Camera == L"是" && c_menu.c_menuState.currentState == MenuState::None)
    {
        // 产生动画效果
        // 计算鼠标偏移
        float mouseX_change = sf::Mouse::getPosition(c_window).x - (c_window.getSize().x / 2.f);
        // 鼠标位移的比例
        float offsetRatio = mouseX_change / (c_window.getSize().x / 2.f);
        // 设置最大偏移的范围
        float maxOffset = 100.f;
        // 计算目标最大偏移
        float sign = offsetRatio > 0 ? 1.f : -1.f;
        float targetOffset = sign * std::sqrt(std::abs(offsetRatio)) * maxOffset;
        // 平滑过渡动画效果
        float currentOffset = Last_distance_to_player;
        float diff = targetOffset - currentOffset;

        // 动态计算平滑速度：距离越远，速度越快；距离越近，速度越慢
        float baseSpeed = 2.0f;
        float distanceFactor = std::abs(diff) / maxOffset;
        float smoothSpeed = baseSpeed + 10.0f * distanceFactor * distanceFactor;

        Last_distance_to_player = currentOffset + diff * (1.0f - std::exp(-smoothSpeed * deltaTime));
    }
    else
    {
        float smoothSpeed = 5.0f;
        Last_distance_to_player = Last_distance_to_player + (0.f - Last_distance_to_player) * (1.0f - std::exp(-smoothSpeed * deltaTime));
    }

    cameraPos.x += Last_distance_to_player;

    const auto &bgBounds = c_allAbnormity.p_s->currentSceneBackground->getGlobalBounds();
    // 使用 getGlobalBounds 提供的绝对坐标，确保不受精灵 Origin 设置的影响
    float bgLeft = bgBounds.position.x;
    float bgRight = bgLeft + bgBounds.size.x;
    float halfViewWidth = c_camera.getSize().x / 2.0f;

    // 如果背景宽度小于视图宽度，则将相机固定在背景中心
    if (bgBounds.size.x <= c_camera.getSize().x)
    {
        cameraPos.x = bgLeft + bgBounds.size.x / 2.0f;
    }
    else
    {
        if (cameraPos.x + halfViewWidth > bgRight)
        {
            cameraPos.x = bgRight - halfViewWidth;
        }
        if (cameraPos.x - halfViewWidth < bgLeft)
        {
            cameraPos.x = bgLeft + halfViewWidth;
        }
    }

    c_camera.setCenter(cameraPos);
    c_window.setView(c_camera);
}

// 自动调整比例
void Application::UpdateCameraViewPort(uint32_t width, uint32_t height)
{
    float windowRatio = (float)width / (float)height;
    float viewRatio = 1920.f / 1080.f;
    float sizeX = 1.f;
    float sizeY = 1.f;
    float posX = 0.f;
    float posY = 0.f;

    if (windowRatio > viewRatio)
    {
        sizeX = viewRatio / windowRatio;
        posX = (1.f - sizeX) / 2.f;
    }
    else
    {
        sizeY = windowRatio / viewRatio;
        posY = (1.f - sizeY) / 2.f;
    }

    c_camera.setViewport(sf::FloatRect({posX, posY}, {sizeX, sizeY}));
    c_uiView.setViewport(sf::FloatRect({posX, posY}, {sizeX, sizeY}));
    c_window.setView(c_camera);
}