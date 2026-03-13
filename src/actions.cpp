#include "../include/actions.h"
void do_eat(Agent& a)
{
    a.needs.basic.hunger += 20;
    a.resources.money -= 15;
}
void do_work(Agent& a)
{
    a.needs.basic.hunger -=20;
    a.emotion.loneliness -=0.5;
    a.emotion.mood += 0.5;
}
void do_work_after(Agent& a)
{
    a.emotion.loneliness +=1;
    a.emotion.mood -= 1;
}
void do_sleep(Agent& a)
{
    a.needs.basic.hunger -=20;
}
void do_daily_life(Agent& a)
{
    do_sleep(a);
    do_eat(a);
    do_work(a);
    do_eat(a);
    do_work(a);
    do_eat(a);
    do_work_after(a);
}
void do_stay_home(Agent& a)
{
    a.needs.basic.hunger += 8;
    a.needs.basic.rest -= 10;
    a.needs.higher.fun -= 15;
    a.emotion.mood += 5;
    a.emotion.stress -= 10;
    a.emotion.loneliness += 5;
}
void do_hangout_friends(Agent& a)
{
    a.needs.basic.social -= 30;

    a.needs.higher.fun -= 25;

    a.emotion.mood += 10;
    a.emotion.loneliness -= 20;
    a.emotion.stress -= 5;

    a.resources.money -= 80;
}
void do_cafe_study(Agent& a)
{
    a.needs.higher.curiosity -= 25;

    a.needs.basic.hunger += 10;

    a.emotion.stress += 5;
    a.emotion.mood += 3;

    a.resources.money -= 30;
}
void do_internet_cafe(Agent& a)
{
    a.needs.higher.fun -= 35;

    a.needs.basic.rest += 20;
    a.needs.basic.hunger += 15;

    a.emotion.mood += 8;
    a.emotion.stress -= 5;

    a.resources.money -= 50;
}
void do_travel(Agent& a)
{

    a.resources.money -= 500;
    a.emotion.stress -= 30;
    a.emotion.mood += 20;
    a.needs.higher.curiosity -= 30;
    a.needs.higher.fun -= 40;
    a.needs.basic.rest += 20;
    a.needs.basic.hunger += 15;
}
void do_single_weekend(Agent& a)
{
    //do_stay_home(Agent& a);
}
void do_double_weekend(Agent& a)
{
    //
}
