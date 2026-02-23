/*
 *@文件 ： mirror.cpp
 *@描述 ： 异常父类镜子的默认设置
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-10
 */
#include "abnormity.hpp"
#include "scene.hpp"

void Abnormity::mirror_set()
{
    mirror_background_set();
    mirror_text_set();
}
void Abnormity::mirror_background_set() { p_s->mirror_background_set(); }
void Abnormity::mirror_player_reset() { p_s->mirror_player_reset(); }
void Abnormity::mirror_text_set() { p_s->mirror_text_set(); }
void Abnormity::mirror_update()
{
    // 空实现
}
void Abnormity::mirror_update(float deltatime)
{
    // 空实现
}
void Abnormity::mirror_draw(sf::RenderWindow &c_window)
{
    // 默认不绘制任何内容
}

void Abnormity::mirror_draw_2(sf::RenderWindow &c_window)
{
    c_window.draw(p_s->c_toilet.mirror_sprite);
    c_window.draw(p_s->mirror_intext);
}
void Abnormity::switch_MirrorToToilet()
{
    p_s->switch_MirrorToToilet();
    this->scene_set();
}
bool Abnormity::HandleEvent_Mirror_on(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Mirror_on(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}