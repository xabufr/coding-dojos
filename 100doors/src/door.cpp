#include "door.h"

Door::Door(): m_opened(false)
{
}

bool Door::isOpen() const
{
    return m_opened;
}

void Door::open()
{
    m_opened = true;
}

void Door::close()
{
    m_opened = false;
}

void Door::switchState()
{
    if(isOpen())
        close();
    else
        open();
}
