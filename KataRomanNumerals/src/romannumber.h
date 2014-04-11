#ifndef ROMANNUMBER_H
#define ROMANNUMBER_H

#include <string>
#include <vector>
#include <tuple>

class RomanNumber
{
    public:
        RomanNumber(int number);
        std::string toString() const;
    private:
        std::string m_getRepresentation(int digit, int order);
        template<int number>
        const std::string &m_getLetter(int order)
        {
            return std::get<number>(m_digits[order]);
        }
        std::string m_romanRepresentation;
        std::vector<std::tuple<std::string, std::string, std::string>> m_digits;
};

#endif // ROMANNUMBER_H
