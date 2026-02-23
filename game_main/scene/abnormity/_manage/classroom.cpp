/*
 *@文件 ： classroom.cpp
 *@描述 ： 异常父类教室的默认设置
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-10
 */
#include "abnormity.hpp"
#include "scene.hpp"
void Abnormity::classroom_set_first() { p_s->classroom_set_first(); }
void Abnormity::classroom_set()
{
    classroom_background_set();
    classroom_clock_set();
}
void Abnormity::classroom_background_set() { p_s->classroom_background_set(); }
void Abnormity::classroom_player_set() { p_s->classroom_player_set(); }
void Abnormity::classroom_clock_set() { p_s->classroom_clock_set(); }
void Abnormity::classroom_update()
{
    on_classroom_desk();
    on_classroom_door();
}
void Abnormity::classroom_update(float deltatime)
{
    // 空实现
}
void Abnormity::classroom_draw(sf::RenderWindow &c_window)
{
    c_window.draw(p_s->c_classroom.background_sprite);
    c_window.draw(p_s->c_classroom.clock_sprite);
}
void Abnormity::classroom_draw_2(sf::RenderWindow &c_window)
{
    c_window.draw(p_s->c_classroom.desk_sprite);
    c_window.draw(p_s->text_desk);
}
void Abnormity::switch_ClassroomToCorridor()
{
    p_s->switch_ClassroomToCorridor();
    this->scene_set();
}
void Abnormity::switch_ClassroomToDesk()
{
    p_s->switch_ClassroomToDesk();
    this->scene_set();
}
bool Abnormity::HandleEvent_Classroom_ondesk(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Classroom_ondesk(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
bool Abnormity::HandleEvent_Classroom_ondoor(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Classroom_ondoor(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
void Abnormity::on_classroom_desk() { p_s->on_classroom_desk(); }
void Abnormity::on_classroom_door()
{
    // 空实现
}

bool Abnormity::isplayerwithclassroom_desk() { return p_s->isplayerwithclassroom_desk(); }
bool Abnormity::isplayerwithclassroom_door() { return p_s->isplayerwithclassroom_door(); }