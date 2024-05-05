#include "smallslot.h"
#include <iostream>





SmallSlot::SmallSlot(int slotid, std::string productName, int price, int motor1id): Slot(slotid, productName, price), motor1(new Motor(motor1id)) {}

void SmallSlot::drop() const {
    motor1->Trigger();
    std::cout << "Product delivered from slot " << getId() << std::endl;
}


Motor& SmallSlot::getMotor () const {return *motor1;}


