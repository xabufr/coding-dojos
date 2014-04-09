#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "door.h"
#include "doorrow.h"

BOOST_AUTO_TEST_CASE(TEST_ONE_DOOR)
{
    Door door;
    BOOST_CHECK(door.isOpen() == false);
    door.open();
    BOOST_CHECK(door.isOpen() == true);
    door.close();
    BOOST_CHECK(door.isOpen() == false);
    door.close();
    BOOST_CHECK(door.isOpen() == false);
    door.open();
    BOOST_CHECK(door.isOpen() == true);
    door.open();
    BOOST_CHECK(door.isOpen() == true);
    door.switchState();
    BOOST_CHECK(door.isOpen() == false);
    door.switchState();
    BOOST_CHECK(door.isOpen() == true);
}
BOOST_AUTO_TEST_CASE(TEST_ONE_HUNDRED_DOORS_CLOSED_IN_A_ROW)
{
    DoorRow row;
    for (int i = 1; i < 101; ++i)
    {
        BOOST_CHECK(row.isDoorOpen(i) == false);
    }
    row.changeDoorsWithIndexMultipleOf(1);
    for (int i = 1; i < 101; ++i)
    {
        BOOST_CHECK(row.isDoorOpen(i) == true);
    }
    row.changeDoorsWithIndexMultipleOf(2);
    for (int i = 1; i < 101; ++i)
    {
        bool opened = true;
        if (i % 2 == 0)
            opened = false;
        BOOST_CHECK(row.isDoorOpen(i) == opened);
    }
}
BOOST_AUTO_TEST_CASE(FINAL_TEST)
{
    DoorRow row;
    for (int i = 1; i < 101; ++i)
    {
        row.changeDoorsWithIndexMultipleOf(i);
    }
    std::array<int, 10> openedIndexes = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
    for (int i = 1; i < 101; ++i)
    {
        bool shouldBeOpened = std::find(openedIndexes.begin(), openedIndexes.end(), i) != openedIndexes.end();
        BOOST_CHECK(row.isDoorOpen(i) == shouldBeOpened);
    }
}
