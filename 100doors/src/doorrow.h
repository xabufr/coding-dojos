#ifndef DOORROW_H
#define DOORROW_H

#include <array>
#include "door.h"

class DoorRow
{
public:
    DoorRow();
    bool isDoorOpen(int doorIndex) const;
    void changeDoorsWithIndexMultipleOf(int multiple);

private:
    std::array<Door, 100> m_doors;
};

#endif // DOORROW_H
