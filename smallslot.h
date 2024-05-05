#ifndef SMALLSLOT_H
#define SMALLSLOT_H

#include "slot.h"
#include "motor.h"
#include <string>

class SmallSlot : public Slot {
private:
    Motor* motor1;
public:
    SmallSlot(int slotid, std::string productName, int price, int motor1id);
    void drop() const ;
    Motor& getMotor() const;
};

#endif // SMALLSLOT_H
