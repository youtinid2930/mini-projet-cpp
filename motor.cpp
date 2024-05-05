#include "motor.h"
#include <iostream>


using namespace std;


Motor::Motor(int id) {
    this->id = id;
}


void Motor::Trigger() {
    cout << "Moteur "<<id<<" est active" << endl;
}


int Motor::getId() const {return id;}
