#include "slot.h"
#include <iostream>


using namespace std;

Slot::Slot() {
    id = 0;
    productName = "";
    price = 0;
    numProduct = 0;
}

Slot::Slot(int slotId,string productName,int price) {
    if(slotId) {
        this->id = slotId;
        this->productName = productName;
        this->price = price;
        // changed (delete motors)
        numProduct = 0;
    }
}

Slot::~Slot() {} // changed (delete "delete motors")


void Slot::drop() const {}


string Slot::getProductName() const {return  productName;}

void Slot::setProductName(string  productName) {
    this->productName = productName;
}

int Slot::getNumProducts() const {return numProduct;}

void Slot::setNumProducts(int numProduct) {
    this->numProduct = numProduct;
}

int Slot::getPrice() const {return price;}

void Slot::setprice(int price) {
    this->price = price;
}

int Slot::getId() const {return id;}



