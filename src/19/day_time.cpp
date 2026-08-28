#include "day_time.h"
#include <string>

day_time::day_time(){
    h = 0;
    m = 0;
    s = 0;
}

bool day_time::set_time(int new_h, int new_m, int new_s) {
    if (new_h >= 0 && new_h <= 23 &&
        new_m >= 0 && new_m <= 59 &&
        new_s >= 0 && new_s <= 59) {
        h = new_h;
        m = new_m;
        s = new_s;
        return true;
    }
    return false;}

int day_time::get_hours() const {return h; }

int day_time::get_minutes() const { return m;}

int day_time::get_seconds() const {return s;}

std::string day_time::to_string() const {
    std::string result;
    if (h < 10) result += '0';
    result += std::to_string(h);
    result += ':';
    if (m < 10) result += '0';
    result += std::to_string(m);
    result += ':';
    if (s < 10) result += '0';
    result += std::to_string(s);
    return result;
}