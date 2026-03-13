#ifndef WORLD_TIME_H
#define WORLD_TIME_H

struct SimTime
{
    int month;
    int day;
    int week_day;
    int hour;
};

// 初始化时间
SimTime init_time();

// 时间推进
void advance_time(SimTime& t);

// 判断是否周末
bool is_weekend(const SimTime& t);

// 打印时间
void print_time(const SimTime& t);

#endif