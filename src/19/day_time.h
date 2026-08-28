#ifndef DAY_TIME_H
#define DAY_TIME_H

#include <string>

struct day_time {
    int h, m, s;
    day_time();
    bool set_time(int, int, int);
    int get_hours() const;
    int get_minutes() const;
    int get_seconds() const;
    std::string to_string() const;
};

#endif