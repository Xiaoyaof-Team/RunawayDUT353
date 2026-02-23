#include "sEvil_Dragon.hpp"
#include <cmath>
#include "scene.hpp"

void sEvil_Dragon::sEvil_Dragon_AnimateText(const std::wstring &newString, float deltatime, sf::Vector2f position, float displayDuration, int size, sf::Color color)
{
    is_sEvil_dragon_text_animating = true;
    // 如果已经显示全了，直接退出
    if (sEvil_dragon_text_index >= newString.size())
    {
        sEvil_dragon_text_finished = true;
        return;
    }

    sEvil_dragon_text_timer += deltatime;

    bool hasChanged = false;
    // 使用 while 循环：如果 deltatime 很大，可以一帧弹出多个字符，保证显示速度恒定
    while (sEvil_dragon_text_timer >= displayDuration && sEvil_dragon_text_index < newString.size())
    {
        sEvil_dragon_text_timer -= displayDuration; // 减去消耗的时间
        sEvil_dragon_text_index++;
        hasChanged = true;
    }

    if (hasChanged)
    {
        sEvil_dragon_text.setString(newString.substr(0, sEvil_dragon_text_index));
        fontfSound.play(); // 每次显示新字符时播放音效
        auto bounds = sEvil_dragon_text.getLocalBounds();
        sEvil_dragon_text.setOrigin(bounds.position + bounds.size / 2.f);
        sEvil_dragon_text.setPosition(position);
        sEvil_dragon_text.setCharacterSize(size);
        sEvil_dragon_text.setFillColor(color);
    }
}

void sEvil_Dragon::sEvil_Dragon_ResetTextAnimation()
{
    // 只是清空画布，不会回退当前的对话进度
    sEvil_dragon_text_timer = 0.f;
    sEvil_dragon_text_index = 0;
    sEvil_dragon_text_finished = false;
    sEvil_dragon_text.setString(L"");
}

bool sEvil_Dragon::HandleEvent_Mirror_on(const sf::Event::KeyPressed &key)
{
    // 触发事件需要有多个条件，首先应该在镜子界面中（已在全局中实现）
    if (isPlayerWithsEvil_Dragon_mirror_1 == false)
    {
        return HandleEvent_Mirror_1(key);
    }
    else if (isPlayerWithsMonster_1 == true && isPlayerWithsMonster_2 == false && isPlayerWithsEvil_Dragon_mirror_2 == false)
    {
        return HandleEvent_Mirror_2(key);
    }
    else if (isPlayerWithsMonster_1 == true && isPlayerWithsMonster_2 == true && isPlayerWithsEvil_Dragon_mirror_3 == false)
    {
        return HandleEvent_Mirror_3(key);
    }
    else if (isPlayerWithsEvil_Dragon_mirror_3 == true && isPlayerWithsEvil_Dragon_mirror_4 == false)
    {
        return HandleEvent_Mirror_4(key);
    }
    else
    {
        return Abnormity::HandleEvent_Mirror_on(key);
    }
}

bool sEvil_Dragon::HandleEvent_Mirror_1(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::E)
    {
        if (current_dialogue_index >= sEvil_dragon_dialogues_1.size() - 2)
        {
            current_dialogue_index = 0;               // 重置对话索引，防止越界，以便下一次对话
            isPlayerWithsEvil_Dragon_mirror_1 = true; // 触发事件
        }
        // 需要重置对话，然后调用初始回退函数
        dialogues_ptr = std::make_unique<std::wstring>(sEvil_dragon_dialogues_1[0]);
        current_dialogue_index = 0;
        sEvil_Dragon_ResetTextAnimation();
        is_sEvil_dragon_text_animating = false;
        Abnormity::HandleEvent_Mirror_on(key); // 实现退出镜子界面
        return true;
    }
    if (key.code == sf::Keyboard::Key::Space)
    {
        // 如果当前动画没有播放完，直接将动画设置为完成
        if (!sEvil_dragon_text_finished)
        {
            sEvil_dragon_text_index = dialogues_ptr->size() - 1;
            sEvil_dragon_text_finished = true;
            is_sEvil_dragon_text_animating = false;
            return true;
        }
        // 如果动画已经播放完了，播放下一个对话
        else
        {
            current_dialogue_index++;
            if (current_dialogue_index <= sEvil_dragon_dialogues_1.size() - 2)
            {
                dialogues_ptr = std::make_unique<std::wstring>(sEvil_dragon_dialogues_1[current_dialogue_index]);
                sEvil_Dragon_ResetTextAnimation();
                return true;
            }
            else
            {
                // 没有更多对话了，不作任何处理，并标记当前对话已经全部完成
                return true;
            }
        }
    }
    return false;
}

void sEvil_Dragon::mirror_update(float deltatime)
{
    if (isPlayerWithsEvil_Dragon_mirror_1 == false)
    {
        // 如果还没有触发事件，就触发事件1的文字动画
        sEvil_Dragon_AnimateText(*dialogues_ptr, deltatime, sf::Vector2f(910.f, 540.f));
        sEvil_Dragon_AnimateSprite(deltatime);
    }
    else if (isPlayerWithsMonster_1 == true && isPlayerWithsMonster_2 == false && isPlayerWithsEvil_Dragon_mirror_2 == false)
    {
        // 被怪物抓住
        sEvil_Dragon_AnimateText(*dialogues_ptr_2, deltatime, sf::Vector2f(910.f, 540.f));
        sEvil_Dragon_AnimateSprite(deltatime);
    }
    else if (isPlayerWithsMonster_1 && isPlayerWithsMonster_2 && isPlayerWithsEvil_Dragon_mirror_3 == false)
    {
        // 逃离怪物追击后的对话
        sEvil_Dragon_AnimateText(*dialogues_ptr_3, deltatime, sf::Vector2f(910.f, 540.f));
        sEvil_Dragon_AnimateSprite(deltatime);
    }
    else if (isPlayerWithsEvil_Dragon_mirror_3 && isPlayerWithsEvil_Dragon_mirror_4 == false)
    {
        // 第四个事件的对话
        sEvil_Dragon_AnimateText(*dialogues_ptr_4, deltatime, sf::Vector2f(910.f, 540.f));
        sEvil_Dragon_AnimateSprite(deltatime);
    }
    else
    {
        return;
    }
}

void sEvil_Dragon::mirror_draw_2(sf::RenderWindow &window)
{
    window.draw(p_s->c_toilet.mirror_sprite); // 先调用全局函数绘制背景等元素
    if (isPlayerWithsEvil_Dragon_mirror_1 == false)
    {
        p_s->mirror_intext.setString(L"");
        window.draw(sEvil_dragon_sprite);
        window.draw(sEvil_dragon_text);
    }
    else if (isPlayerWithsMonster_1 == true && isPlayerWithsMonster_2 == false && isPlayerWithsEvil_Dragon_mirror_2 == false)
    {
        p_s->mirror_intext.setString(L"");
        window.draw(sEvil_dragon_sprite);
        window.draw(sEvil_dragon_text);
    }
    else if (isPlayerWithsMonster_1 == true && isPlayerWithsMonster_2 == true && isPlayerWithsEvil_Dragon_mirror_3 == false)
    {
        p_s->mirror_intext.setString(L"");
        window.draw(sEvil_dragon_sprite);
        window.draw(sEvil_dragon_text);
    }
    else if (isPlayerWithsEvil_Dragon_mirror_3 && !isPlayerWithsEvil_Dragon_mirror_4)
    {
        p_s->mirror_intext.setString(L"");
        window.draw(sEvil_dragon_sprite);
        window.draw(sEvil_dragon_text);
    }
    else
    {
        Abnormity::mirror_draw_2(window); // 已经触发过事件了，继续调用全局函数处理事件
        return;
    }
    window.draw(sEvil_dragon_text);
}

void sEvil_Dragon::sEvil_Dragon_AnimateSprite(float deltatime)
{
    // 头像根据正弦函数进行简单的上下浮动动画
    sprite_animation_timer += deltatime;
    if (sprite_animation_timer_fade < 1.f)
    {
        sprite_animation_timer_fade += deltatime; // 头像渐渐出现
        if (sprite_animation_timer_fade > 1.f)
            sprite_animation_timer_fade = 1.f;
    }

    int alpha = static_cast<int>(255 * sprite_animation_timer_fade);
    sEvil_dragon_sprite.setColor(sf::Color(255, 255, 255, alpha));

    if (sprite_animation_timer >= 2 * 3.14159f)
    {
        sprite_animation_timer = 0.f; // 重置计时器，保持动画循环
    }
    sEvil_dragon_sprite.setScale({0.6f, 0.6f});
    // 调整头像大小
    sEvil_dragon_sprite.setPosition({760.f, 100.f + 20.f * std::sin(sprite_animation_timer)});
    // 在屏幕中心上下浮动
}

void sEvil_Dragon::corridor_update(float deltatime)
{
    if (isPlayerWithsMonster_1 && !isPlayerWithsMonster_2)
    {
        monster_appear_timer += deltatime;
        monster_sprite.setPosition({351.355f + monster_appear_timer * 940.f, 600.794f}); // 怪物出现的位置为楼梯左侧
        // 持续检测碰撞：如果怪物追上玩家，立即强制进入死亡/重置镜子界面
        if (p_s->c_player.getGlobalBounds().findIntersection(monster_sprite.getGlobalBounds()))
        {
            // 被抓时重置对话状态，确保进入镜子界面后从第一句开始显示
            current_dialogue_index = 0;
            sEvil_Dragon_ResetTextAnimation();
            dialogues_ptr_2 = std::make_unique<std::wstring>(sEvil_dragon_dialogues_2[0]);

            // 重置怪物位置和计时器，防止瞬间再次触发碰撞
            monster_appear_timer = 0.f;
            monster_sprite.setPosition({351.355f, 600.794f});

            // 修复视角高度：被抓后强制重置玩家到厕所的标准位置，避免走廊坐标干扰视角
            p_s->toilet_player_set();
            p_s->c_player.setPosition({931.284f, 376.012});

            // 切换到镜子界面处理“被抓”后的嘲讽对话
            Abnormity::switchscene(SceneState::Mirror);
        }
    }
    else
    {
        Abnormity::corridor_update(deltatime);
        return;
    }
}

bool sEvil_Dragon::HandleEvent_Corridor_ondoorleft(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        if (isPlayerWithsMonster_1 == false && isPlayerWithsEvil_Dragon_mirror_1 == true) // 只有在触发了镜子事件后，才会触发怪物事件
        {
            isPlayerWithsMonster_1 = true;   // 触发怪物出现事件
            p_s->player_text(L"快跑！！！"); // 触发玩家惊叫
            return true;
        }
        else
        {
            return Abnormity::HandleEvent_Corridor_ondoorleft(key); // 已经触发过事件了，继续调用全局函数处理事件
        }
    }
    return false;
}

void sEvil_Dragon::corridor_draw_2(sf::RenderWindow &window)
{
    if (isPlayerWithsMonster_1 && !isPlayerWithsMonster_2)
    {
        window.draw(monster_sprite);
    }
    else
    {
        Abnormity::corridor_draw_2(window); // 已经触发过事件了，继续调用全局函数处理事件
        return;
    }
}

bool sEvil_Dragon::HandleEvent_Corridor_ontoiletwoman(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        if (isPlayerWithsMonster_1 && !isPlayerWithsMonster_2) // 只有在怪物出现但还没有结束时，才会触发结束事件
        {
            isPlayerWithsMonster_2 = true;         // 触发怪物结束事件
            p_s->player_text(L"似乎不会来这里？"); // 触发玩家松了一口气的文本

            // 为第三阶段（逃脱后）的镜子对话准备好重置状态
            current_dialogue_index = 0;
            sEvil_Dragon_ResetTextAnimation();
            dialogues_ptr_3 = std::make_unique<std::wstring>(sEvil_dragon_dialogues_3[0]);

            Abnormity::HandleEvent_Corridor_ontoiletwoman(key);
            return true;
        }
        else
        {
            return Abnormity::HandleEvent_Corridor_ontoiletwoman(key); // 已经触发过事件了，继续调用全局函数处理事件
        }
    }
    return false;
}

bool sEvil_Dragon::HandleEvent_Mirror_2(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::E && current_dialogue_index >= sEvil_dragon_dialogues_2.size() - 2)
    {
        current_dialogue_index = 0;               // 重置对话索引，防止越界，以便下一次对话
        isPlayerWithsEvil_Dragon_mirror_2 = true; // 触发事件
        isPlayercanEscape = true;                 // 触发可以离开的事件
        // 需要重置对话，然后调用初始回退函数
        dialogues_ptr_2 = std::make_unique<std::wstring>(sEvil_dragon_dialogues_2[0]);
        current_dialogue_index = 0;
        sEvil_Dragon_ResetTextAnimation();
        is_sEvil_dragon_text_animating = false;
        Abnormity::HandleEvent_Mirror_on(key); // 实现退出镜子界面
        return true;
    }
    if (key.code == sf::Keyboard::Key::Space)
    {
        // 如果当前动画没有播放完，直接将动画设置为完成
        if (!sEvil_dragon_text_finished)
        {
            sEvil_dragon_text_index = dialogues_ptr_2->size() - 1;
            sEvil_dragon_text_finished = true;
            is_sEvil_dragon_text_animating = false;
            return true;
        }
        // 如果动画已经播放完了，播放下一个对话
        else
        {
            current_dialogue_index++;
            if (current_dialogue_index <= sEvil_dragon_dialogues_2.size() - 2)
            {
                dialogues_ptr_2 = std::make_unique<std::wstring>(sEvil_dragon_dialogues_2[current_dialogue_index]);
                sEvil_Dragon_ResetTextAnimation();
                return true;
            }
            else
            {
                // 没有更多对话了，不作任何处理，并标记当前对话已经全部完成
                return true;
            }
        }
    }
    return false;
}

bool sEvil_Dragon::HandleEvent_Mirror_3(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::E && current_dialogue_index >= sEvil_dragon_dialogues_3.size() - 2)
    {
        if (current_dialogue_index >= sEvil_dragon_dialogues_3.size() - 2)
        {
            current_dialogue_index = 0;               // 重置对话索引，防止越界，以便下一次对话
            isPlayerWithsEvil_Dragon_mirror_3 = true; // 触发事件
        }
        // 需要重置对话，然后调用初始回退函数
        dialogues_ptr_3 = std::make_unique<std::wstring>(sEvil_dragon_dialogues_3[0]);
        current_dialogue_index = 0;
        sEvil_Dragon_ResetTextAnimation();
        is_sEvil_dragon_text_animating = false;
        Abnormity::HandleEvent_Mirror_on(key); // 实现退出镜子界面
        return true;
    }
    if (key.code == sf::Keyboard::Key::Space)
    {
        // 如果当前动画没有播放完，直接将动画设置为完成
        if (!sEvil_dragon_text_finished)
        {
            sEvil_dragon_text_index = dialogues_ptr_3->size() - 1;
            sEvil_dragon_text_finished = true;
            is_sEvil_dragon_text_animating = false;
            return true;
        }
        // 如果动画已经播放完了，播放下一个对话
        else
        {
            current_dialogue_index++;
            if (current_dialogue_index <= sEvil_dragon_dialogues_3.size() - 2)
            {
                dialogues_ptr_3 = std::make_unique<std::wstring>(sEvil_dragon_dialogues_3[current_dialogue_index]);
                sEvil_Dragon_ResetTextAnimation();
                return true;
            }
            else
            {
                // 没有更多对话了，不作任何处理，并标记当前对话已经全部完成
                return true;
            }
        }
    }
    return false;
}

bool sEvil_Dragon::HandleEvent_Corridor_stairleft(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        if (isPlayercanEscape) // 只有在满足离开条件时，才会触发离开事件
        {
            Abnormity::HandleEvent_Corridor_stairright(key); // 触发离开事件，调用全局函数切换场景
        }
        else
        {
            p_s->player_text(L"似乎受到了强大的阻碍"); // 触发玩家尝试离开但被阻止的文本
        }
    }
    return false;
}

bool sEvil_Dragon::HandleEvent_Corridor_stairright(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        if (isPlayercanEscape) // 只有在满足离开条件时，才会触发离开事件
        {
            Abnormity::HandleEvent_Corridor_stairright(key); // 触发离开事件，调用全局函数切换场景
        }
        else
        {
            p_s->player_text(L"似乎受到了强大的阻碍"); // 触发玩家尝试离开但被阻止的文本
        }
    }
    return false;
}

bool sEvil_Dragon::HandleEvent_Toilet_ondoor(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::W)
    {
        if (isPlayerWithsEvil_Dragon_mirror_1 && isPlayerWithsMonster_1 && isPlayerWithsMonster_2 && isPlayerWithsEvil_Dragon_mirror_3 && isPlayerWithsEvil_Dragon_mirror_4 == false)
        {
            isDoorLocked = true;                 // 触发门上锁事件
            p_s->player_text(L"嘀嘀，需要密码"); // 触发玩家尝试离开但被阻止的文本
        }
        else
        {
            Abnormity::HandleEvent_Toilet_ondoor(key); // 触发离开事件，调用全局函数切换场景
        }
    }
    return false;
}

bool sEvil_Dragon::HandleEvent_Mirror_4(const sf::Event::KeyPressed &key)
{
    if (key.code == sf::Keyboard::Key::E && current_dialogue_index >= sEvil_dragon_dialogues_4.size() - 2)
    {
        if (current_dialogue_index >= sEvil_dragon_dialogues_4.size() - 2)
        {
            current_dialogue_index = 0;               // 重置对话索引，防止越界，以便下一次对话
            isPlayerWithsEvil_Dragon_mirror_4 = true; // 触发事件
            isPlayercanEscape = true;                 // 触发可以离开的事件
        }
        // 需要重置对话，然后调用初始回退函数
        dialogues_ptr_4 = std::make_unique<std::wstring>(sEvil_dragon_dialogues_4[0]);
        current_dialogue_index = 0;
        sEvil_Dragon_ResetTextAnimation();
        is_sEvil_dragon_text_animating = false;
        Abnormity::HandleEvent_Mirror_on(key); // 实现退出镜子界面
        return true;
    }
    if (key.code == sf::Keyboard::Key::Space)
    {
        // 如果当前动画没有播放完，直接将动画设置为完成
        if (!sEvil_dragon_text_finished)
        {
            sEvil_dragon_text_index = dialogues_ptr_4->size() - 1;
            sEvil_dragon_text_finished = true;
            is_sEvil_dragon_text_animating = false;
            return true;
        }
        // 如果动画已经播放完了，播放下一个对话
        else
        {
            current_dialogue_index++;
            if (current_dialogue_index <= sEvil_dragon_dialogues_4.size() - 2)
            {
                dialogues_ptr_4 = std::make_unique<std::wstring>(sEvil_dragon_dialogues_4[current_dialogue_index]);
                sEvil_Dragon_ResetTextAnimation();
                return true;
            }
            else
            {
                // 没有更多对话了，不作任何处理，并标记当前对话已经全部完成
                return true;
            }
        }
    }
    return false;
}

void sEvil_Dragon::on_corridor_stair_left()
{
    if (isPlayercanEscape)
    {
        Abnormity::on_corridor_stair_left(); // 触发离开事件，调用全局函数切换场景
    }
    else
    {
        if (p_s->c_player.getPosition().x <= 351.355f)
        {
            player_text(L"似乎受到了强大的阻碍"); // 触发玩家尝试离开但被阻止的文本
        }
    }
}

void sEvil_Dragon::on_corridor_stair_right()
{
    if (isPlayercanEscape)
    {
        Abnormity::on_corridor_stair_right(); // 触发离开事件，调用全局函数切换场景
    }
    else
    {
        if (p_s->c_player.getPosition().x >= 6805.22f)
        {
            player_text(L"似乎受到了强大的阻碍");
        }
    }
}
