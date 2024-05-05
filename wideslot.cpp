#include "wideslot.h"
#include <iostream>


using namespace std;




WideSlot::WideSlot(int slotid,std::string productName,int price,int motor1id,int motor2id):Slot(slotid,productName,price) {
    motor1 = new Motor(motor1id);
    motor2 = new Motor(motor2id);
}


void WideSlot::drop() const {
    motor1->Trigger();
    motor2->Trigger();
    cout << "Produit livre a partir du logement " << getId() << endl;
}


const Motor& WideSlot::getMotor1() const {return *motor1;}
const Motor& WideSlot::getMotor2() const {return *motor2;}
