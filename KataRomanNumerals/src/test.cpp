#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include "romannumber.h"

void testNumber(int number, std::string representation)
{
    RomanNumber romanNumber(number);
    BOOST_CHECK_EQUAL(romanNumber.toString(), representation);
}

BOOST_AUTO_TEST_CASE(TEST_ONE)
{
    testNumber(1, "I");
}

BOOST_AUTO_TEST_CASE(TEST_TWO)
{
    testNumber(2, "II");
}

BOOST_AUTO_TEST_CASE(TEST_THREE)
{
    testNumber(3, "III");
}

BOOST_AUTO_TEST_CASE(TEST_FOUR)
{
    testNumber(4, "IV");
}

BOOST_AUTO_TEST_CASE(TEST_BETWEEN_FIVE_AND_EIGHT)
{
    testNumber(5, "V");
    testNumber(6, "VI");
    testNumber(7, "VII");
    testNumber(8, "VIII");
}

BOOST_AUTO_TEST_CASE(TEST_NINE)
{
    testNumber(9, "IX");
}
BOOST_AUTO_TEST_CASE(TEST_BEETWEEN_TEN_MORE)
{
    testNumber(10, "X");
    testNumber(13, "XIII");
    testNumber(14, "XIV");
    testNumber(20, "XX");
    testNumber(25, "XXV");
    testNumber(49, "XLIX");
    testNumber(50, "L");
    testNumber(1954, "MCMLIV");
    testNumber(1990, "MCMXC");
    testNumber(1999, "MCMXCIX");
    testNumber(3000, "MMM");
    testNumber(3001, "MMMI");
    testNumber(3999, "MMMCMXCIX");
}
