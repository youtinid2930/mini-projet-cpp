#ifndef SLOT_H
#define SLOT_H
#include "motor.h"
#include <string>


class Slot {
protected:
    std::string productName;
    int id;
    int numProduct;
    int price;
    // changed
public:
    Slot();
    Slot(int slotId,std::string productName,int price); // changed delete motors
    ~Slot();
    virtual void drop() const;
    std::string getProductName() const;
    void setProductName(std::string productName);
    int getNumProducts() const;
    void setNumProducts(int numProduct);
    int getPrice() const;
    void setprice(int price);
    int getId() const;
};
#endif // SLOT_H
