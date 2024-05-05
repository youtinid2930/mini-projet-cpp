#ifndef WIDESLOT_H
#define WIDESLOT_H
#include "motor.h"
#include "slot.h"
#include <iostream>
#include <string>


class WideSlot : public Slot{
protected:
    Motor* motor1;
    Motor* motor2;
public:

    WideSlot(int slotid,std::string productName,int price,int motor1id,int motor2id);
    void drop() const ;
    const Motor& getMotor1() const;
    const Motor& getMotor2() const;
};
#endif // WIDESLOT_H
