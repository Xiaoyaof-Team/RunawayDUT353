/*
 *@文件 ： classroom_desk.cpp
 *@描述 ： 异常父类讲台的默认设置
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-10
 */
#include "abnormity.hpp"
#include "scene.hpp"

void Abnormity::classroom_desk_set()
{
    classroom_desk_background_set();
}
void Abnormity::classroom_desk_background_set() { p_s->classroom_desk_background_set(); }
void Abnormity::classroom_desk_player_reset() { p_s->classroom_desk_player_reset(); }
void Abnormity::classroom_desk_update()
{
    on_classroom_desk_text();
}
void Abnormity::classroom_desk_update(float deltatime)
{
    // 空实现
}
void Abnormity::classroom_desk_draw(sf::RenderWindow &c_window)
{
    // 默认不绘制任何内容
}
void Abnormity::classroom_desk_draw_2(sf::RenderWindow &c_window)
{
    c_window.draw(p_s->c_classroom.desk_text_sprite);
}
void Abnormity::switch_DeskToClassroom()
{
    p_s->switch_DeskToClassroom();
    this->scene_set();
}
bool Abnormity::HandleEvent_Classroom_desk_on(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Classroom_desk_on(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
void Abnormity::on_classroom_desk_text()
{
    // 空实现
}