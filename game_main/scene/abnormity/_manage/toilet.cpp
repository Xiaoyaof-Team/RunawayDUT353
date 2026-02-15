/*
 *@文件 ： toilet.cpp
 *@描述 ： 异常父类卫生间的默认设置
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-10
 */
#include "abnormity.hpp"
#include "scene.hpp"

void Abnormity::toilet_set()
{
    toilet_background_set();
    toilet_door_set();
    toilet_wash_basin_set();
    toilet_mirror_set();
}
void Abnormity::toilet_background_set() { p_s->toilet_background_set(); }
void Abnormity::toilet_door_set() { p_s->toilet_door_set(); }
void Abnormity::toilet_wash_basin_set() { p_s->toilet_wash_basin_set(); }
void Abnormity::toilet_mirror_set() { p_s->toilet_mirror_set(); }
void Abnormity::toilet_player_set() { p_s->toilet_player_set(); }
void Abnormity::switch_ToiletToCorridor()
{
    p_s->switch_ToiletToCorridor();
    this->scene_set();
}
void Abnormity::switch_ToiletToMirror()
{
    p_s->switch_ToiletToMirror();
    this->scene_set();
}
void Abnormity::toilet_update()
{
    on_toilet_mirror();
    on_toilet_wash_basin();
    on_toilet_door();
    on_toilet_lid();
}
void Abnormity::toilet_draw(sf::RenderWindow &c_window)
{
    c_window.draw(p_s->c_toilet.background_sprite);
    c_window.draw(p_s->c_toilet.door_sprite);
    c_window.draw(p_s->c_toilet.wash_basin_sprite);
    c_window.draw(p_s->c_toilet.mirror_sprite);
    c_window.draw(p_s->mirror_text);
}
void Abnormity::toilet_draw_2(sf::RenderWindow &c_window)
{
    // 默认不绘制任何内容
}
bool Abnormity::HandleEvent_Toilet_ondoor(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Toilet_ondoor(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
bool Abnormity::HandleEvent_Toilet_onmirror(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Toilet_onmirror(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
bool Abnormity::HandleEvent_Toilet_onwashbasin(const sf::Event::KeyPressed &key)
{
    // 空实现
    return false;
}
bool Abnormity::HandleEvent_Toilet_onlid(const sf::Event::KeyPressed &key)
{
    // 空实现
    return false;
}
void Abnormity::on_toilet_mirror() { p_s->on_toilet_mirror(); }
void Abnormity::on_toilet_wash_basin()
{
    // 空实现
}
void Abnormity::on_toilet_door()
{
    // 空实现
}
void Abnormity::on_toilet_lid()
{
    // 空实现
}

bool Abnormity::isplayerwithtoilet_mirror() { return p_s->isplayerwithtoiletmirror(); }
bool Abnormity::isplayerwithtoilet_door() { return p_s->isplayerwithtoiletdoor(); }
bool Abnormity::isplayerwithtoilet_washbasin() { return p_s->isplayerwithtoiletwashbasin(); }
bool Abnormity::isplayerwithtoilet_lid() { return p_s->isplayerwithtoiletlid(); }