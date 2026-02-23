/*
 *@文件 ： rule.cpp
 *@描述 ： 异常父类告示牌的默认设置
 *@作者 ： 小恐龙大魔王
 *@时间 ： 2026-2-10
 */
#include "abnormity.hpp"
#include "scene.hpp"

void Abnormity::rule_set()
{
    rule_background_set();
}
void Abnormity::rule_background_set() { p_s->rule_background_set(); }
void Abnormity::rule_player_reset() { p_s->rule_player_reset(); }
void Abnormity::rule_update()
{
    on_rule();
}
void Abnormity::rule_update(float deltatime)
{
    // 空实现
}
void Abnormity::rule_draw(sf::RenderWindow &c_window)
{
    // 默认不绘制任何内容
}
void Abnormity::rule_draw_2(sf::RenderWindow &c_window)
{
    c_window.draw(p_s->c_corridor.rule_sprite);
}
void Abnormity::switch_RuleToCorridor()
{
    p_s->switch_RuleToCorridor();
    this->scene_set();
}
bool Abnormity::HandleEvent_Rule_on(const sf::Event::KeyPressed &key)
{
    if (p_s->HandleEvent_Rule_on(key))
    {
        this->scene_set();
        return true;
    }
    return false;
}
void Abnormity::on_rule()
{
    // 空实现
}