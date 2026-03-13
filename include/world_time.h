#ifndef WORLD_TIME_H
#define WORLD_TIME_H
struct SimTime
{
    int day;        // 第几天 1~28
    int week_day;   // 星期几 1~7
    int hour;       // 小时 0~23
    int month;
};
void advance_time(SimTime& t);
#endif