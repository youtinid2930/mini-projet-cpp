#ifndef DROPCHECK_H
#define DROPCHECK_H
#include <iostream>
#include <random>


class DropCheck {
public:
    bool productReleased() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 99);
        int randomNum = dis(gen); // obtenir a random valeur
        if(randomNum<90) { // probabilite 90%
            return true;
        }
        return false; //probabilite 10%
    }
};
#endif // DROPCHECK_H
