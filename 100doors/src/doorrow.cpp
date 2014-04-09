#include "doorrow.h"
#include <assert.h>

DoorRow::DoorRow()
{

}

bool DoorRow::isDoorOpen(int doorIndex) const
{
    --doorIndex;
    assert(doorIndex  < m_doors.size() && doorIndex  >= 0);
    return m_doors[doorIndex].isOpen();
}

void DoorRow::changeDoorsWithIndexMultipleOf(int multiple)
{
    for(int i=0; i < m_doors.size(); ++i) {
        if((i+1) % multiple == 0) {
            Door &door = m_doors[i];
            door.switchState();
        }
    }
}
