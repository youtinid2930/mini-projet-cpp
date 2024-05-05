#ifndef AUTOMAT_H
#define AUTOMAT_H
#include "slot.h"
#include <string>
#include "coinslot.h"
#include "keypad.h"
#include "dropchek.h"
#include "smallslot.h"
#include "wideslot.h"




class Automat {
private:
    Slot **slots;
    int numSlots;
    Slot cached;
    int numProductPerSlot;
    CoinSlot coinSlot;
    Keypad keypad;
    DropCheck dopcheck;
public:
    Automat(int numSlot,int numProductPerSlot);
    ~Automat();
    bool addSlot(std::string productName,int price,int slotId,int motor1Id,int motor2Id); // changed (delete motors and let one anly)

    bool addSlot(const Slot &slot); // added ( add method that add slot by Slot en paramater) ...
    Slot searchSlot(int slotId);
    void changeSlot(int slotId,std::string name,int price);
    int getPieces (int slotId) const;
    bool isAvailable(int slotId);
    int getPrice (int slotId) const;
    bool dropSlot(int slotId);
    void fellAll();
    void remplir(int slotId,int numProduct);
    Keypad& getKeypad();
    CoinSlot& getCoinSlot();
    DropCheck& getDropCheck();
    void viderSlot(int slotId);
    void afficheSlot() const;
};

#endif // AUTOMAT_H
