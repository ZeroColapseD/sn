#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "day_time.h"
#include "doctest.h"

TEST_CASE("testing day_time 1") {
    day_time dt;
    dt.set_time(0,0,0);
    const day_time& dtc = dt;
    CHECK(dt.set_time(0,0,0));
    CHECK(dtc.get_seconds() == 0);
    CHECK(dtc.get_minutes() == 0);
    CHECK(dtc.get_hours() == 0);
    CHECK(dtc.to_string() == "00:00:00");

    CHECK(!dt.set_time(24,0,0));
    CHECK(dtc.get_seconds() == 0);
    CHECK(dtc.get_minutes() == 0);
    CHECK(dtc.get_hours() == 0);
    CHECK(dtc.to_string() == "00:00:00");

    CHECK(!dt.set_time(0,60,0));
    CHECK(dtc.get_seconds() == 0);
    CHECK(dtc.get_minutes() == 0);
    CHECK(dtc.get_hours() == 0);
    CHECK(dtc.to_string() == "00:00:00");

    CHECK(!dt.set_time(0,0,60));
    CHECK(dtc.get_seconds() == 0);
    CHECK(dtc.get_minutes() == 0);
    CHECK(dtc.get_hours() == 0);
    CHECK(dtc.to_string() == "00:00:00");

    CHECK(dt.set_time(15,24,45));
    CHECK(dtc.get_seconds() == 45);
    CHECK(dtc.get_minutes() == 24);
    CHECK(dtc.get_hours() == 15);
    CHECK(dtc.to_string() == "15:24:45");

    CHECK(dt.set_time(0,1,9));
    CHECK(dtc.get_seconds() == 9);
    CHECK(dtc.get_minutes() == 1);
    CHECK(dtc.get_hours() == 0);
    CHECK(dtc.to_string() == "00:01:09");

    CHECK(dt.set_time(10,10,20));
    CHECK(dtc.get_seconds() == 20);
    CHECK(dtc.get_minutes() == 10);
    CHECK(dtc.get_hours() == 10);
    CHECK(dtc.to_string() == "10:10:20");
}
