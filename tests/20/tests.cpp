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

TEST_CASE("testing add_seconds") {
    day_time dt;
    CHECK(dt.set_time(10, 20, 30));
    const day_time& dtc = dt;

    SUBCASE("simple add") {
        dt.add_seconds(15);
        CHECK(dtc.get_hours() == 10);
        CHECK(dtc.get_minutes() == 20);
        CHECK(dtc.get_seconds() == 45);
    }

    SUBCASE("seconds overflow") {
        dt.add_seconds(40);
        CHECK(dtc.get_hours() == 10);
        CHECK(dtc.get_minutes() == 21);
        CHECK(dtc.get_seconds() == 10);
    }

    SUBCASE("midnight overflow") {
        dt.set_time(23, 59, 50);
        dt.add_seconds(20);
        CHECK(dtc.get_hours() == 0);
        CHECK(dtc.get_minutes() == 0);
        CHECK(dtc.get_seconds() == 10);
    }

    SUBCASE("a lot of seconds") {
        dt.set_time(0, 0, 0);
        dt.add_seconds(3661);
        CHECK(dtc.get_hours() == 1);
        CHECK(dtc.get_minutes() == 1);
        CHECK(dtc.get_seconds() == 1);
    }
}

TEST_CASE("testing add_minutes") {
    day_time dt;
    CHECK(dt.set_time(10, 50, 15));
    const day_time& dtc = dt;

    SUBCASE("minutes overflow") {
        dt.add_minutes(20);
        CHECK(dtc.get_hours() == 11);
        CHECK(dtc.get_minutes() == 10);
        CHECK(dtc.get_seconds() == 15);
    }

    SUBCASE("midnight overflow") {
        dt.set_time(23, 40, 0);
        dt.add_minutes(30);
        CHECK(dtc.get_hours() == 0);
        CHECK(dtc.get_minutes() == 10);
        CHECK(dtc.get_seconds() == 0);
    }

    SUBCASE("a lot of minutes") {
        dt.set_time(1, 10, 0);
        dt.add_minutes(1445);
        CHECK(dtc.get_hours() == 1);
        CHECK(dtc.get_minutes() == 15);
        CHECK(dtc.get_seconds() == 0);
    }
}

TEST_CASE("testing add_hours") {
    day_time dt;
    CHECK(dt.set_time(20, 15, 30));
    const day_time& dtc = dt;

    SUBCASE("add hourse") {
        dt.add_hours(2);
        CHECK(dtc.get_hours() == 22);
        CHECK(dtc.get_minutes() == 15);
        CHECK(dtc.get_seconds() == 30);
    }

    SUBCASE("midnight overflow") {
        dt.add_hours(5); // 20 + 5 = 25 -> 01:15:30
        CHECK(dtc.get_hours() == 1);
        CHECK(dtc.get_minutes() == 15);
        CHECK(dtc.get_seconds() == 30);
    }

    SUBCASE("add 2 days") {
        dt.add_hours(48);
        CHECK(dtc.get_hours() == 20);
        CHECK(dtc.get_minutes() == 15);
        CHECK(dtc.get_seconds() == 30);
    }
}
