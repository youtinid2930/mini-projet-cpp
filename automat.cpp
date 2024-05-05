#include "automat.h"
#include <iostream>
#include <typeinfo>



using namespace std;


Automat::Automat(int numSlots,int numProductPerSlot) {
    this->numSlots = numSlots;
    this->numProductPerSlot = numProductPerSlot;
    this->slots = new Slot*[numSlots];
}

Automat::~Automat () {
    delete[] slots;
}

bool Automat::addSlot(string productName,int price,int slotId,int motor1Id,int motor2Id) {
    if(slotId>=numSlots) {
        return false;
    }
    if((motor1Id != 0)&& (motor2Id != 0)) {
        slots[slotId] = new WideSlot(slotId,productName,price,motor1Id,motor2Id);
        return true;
    }
    slots[slotId] = new SmallSlot(slotId,productName,price,motor1Id);

    return true;
}




bool Automat::addSlot(const Slot& slot) {
    int slotId = slot.getId();
    if(slotId >= numSlots) {
        return false;
    }

    if (typeid(slot) == typeid(WideSlot)) {
        slots[slotId] = new WideSlot(dynamic_cast<const WideSlot&>(slot));
    } else if (typeid(slot) == typeid(SmallSlot)) {
        slots[slotId] = new SmallSlot(dynamic_cast<const SmallSlot&>(slot));
    }
    return false;
}

Slot Automat::searchSlot(int slotId) {
    if(slotId<=0 || slotId>=numSlots) {
        cout << "cette emplacement invlaid "<<endl;
        return Slot(-1,"",0);
    }
    cached = *slots[slotId];
    return cached;
}


void Automat::changeSlot(int slotId,string name,int price) {
    if(slotId<=0 && slotId >=numSlots) {
        if(name != "") {
        slots[slotId]->setProductName(name);
        }
        if(price) {
            slots[slotId]->setprice(price);
        }
    }
    else {
        cout << "invalid emplacement" << endl;
    }
}


int Automat::getPieces(int slotId) const{
    if(slotId<=0 || slotId>=numSlots) {
        cout << "invlaide emplacemet "<<endl;
        return 0;
    }
    return slots[slotId]->getNumProducts();
}

bool Automat::isAvailable(int slotId) {
    if(slotId<=0 || slotId>=numSlots) {
        cout << "invlaide emplacemet "<<endl;
        return false;
    }
    return true;
}


int Automat::getPrice (int slotId) const{
    if(slotId<=0 || slotId>=numSlots) {
        cout << "invlaide emplacemet "<<endl;
        return -1;
    }
    return slots[slotId]->getPrice();
}

bool Automat::dropSlot(int slotId) {
    if(slotId<=0 || slotId>=numSlots) {
        cout << "invlaide emplacemet "<<endl;
        return false;
    }
    slots[slotId]->drop();
    return true;
}

void Automat::fellAll() {
    for (int i = 0; i < numSlots; ++i) {
        slots[i]->setNumProducts(numProductPerSlot);
    }
}


void Automat::remplir(int slotId,int numProduct) {
    if(slotId<=0 || slotId>=numSlots) {
        cout << "invlaide emplacemet "<<endl;
    }
    slots[slotId]->setNumProducts(numProduct);
}

Keypad& Automat::getKeypad() {
    return keypad;
}

CoinSlot& Automat::getCoinSlot() {
    return coinSlot;
}

DropCheck& Automat::getDropCheck() {
    return dopcheck;
}

void Automat::viderSlot(int slotId) {
    slots[slotId]->setProductName("");
    slots[slotId]->setprice(0);
    slots[slotId]->setNumProducts(0);
}


void Automat::afficheSlot() const {
    cout << "les emplacement :" << endl;
    for (int i = 1; i < numSlots; ++i) {
        cout << "id de l'emplacement " << i << ":" << endl;
        if (slots[i] != nullptr) {
            cout << "nom de produit: " << slots[i]->getProductName() << endl;
            cout << "prix : " << slots[i]->getPrice() << endl;
            cout << "Numero de produit: " << slots[i]->getNumProducts() << endl;
            if (typeid(*slots[i]) == typeid(WideSlot)) {
                WideSlot* wideSlot = dynamic_cast<WideSlot*>(slots[i]);
                cout << "Motor 1 ID: " << wideSlot->getMotor1().getId() << endl;
                cout << "Motor 2 ID: " << wideSlot->getMotor2().getId() << endl;
            } else if (typeid(*slots[i]) == typeid(SmallSlot)) {
                SmallSlot* smallSlot = dynamic_cast<SmallSlot*>(slots[i]);
                cout << "Motor ID : " << smallSlot->getMotor().getId() << endl;
            }
        } else {
            cout << "l'emmplacement est vide " << endl;
        }
        cout << endl;
    }
}
