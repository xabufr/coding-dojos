#ifndef DOOR_H
#define DOOR_H

class Door
{
public:
    Door();
    bool isOpen() const;
    void open();
    void close();
    void switchState();

private:
    bool m_opened;
};

#endif // DOOR_H
