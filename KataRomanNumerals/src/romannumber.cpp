#include "romannumber.h"
#include <cmath>
#include <iostream>
#include <cassert>

RomanNumber::RomanNumber(int number)
{
    assert(number > 0 && number <= 3999);
    m_digits = {std::make_tuple("I", "V", "X"),
                std::make_tuple("X", "L", "C"),
                std::make_tuple("C", "D", "M"),
                std::make_tuple("M", "-", "-")
               };

    for (int i = 3; i >= 0; --i)
    {
        m_romanRepresentation += m_getRepresentation(number / std::pow(10, i), i);
        number %= (int) std::pow(10, i);
    }
}

std::string RomanNumber::toString() const
{
    return m_romanRepresentation;
}

std::string RomanNumber::m_getRepresentation(int digit, int order)
{
    std::string representation = "";
    if (digit <= 3)
    {
        for (int i = 1; i <= digit; ++i)
        {
            representation += m_getLetter<0>(order);
        }
    }
    else if (digit == 4)
    {
        representation = m_getLetter<0>(order) + m_getLetter<1>(order);
    }
    else if (digit >= 5 && digit <= 8)
    {
        representation = m_getLetter<1>(order);
        for (int i = 5; i < digit; ++i)
        {
            representation += m_getLetter<0>(order);
        }
    }
    else if (digit == 9)
    {
        representation = m_getLetter<0>(order) + m_getLetter<2>(order);
    }
    return representation;
}


