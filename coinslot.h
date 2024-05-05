#ifndef COINSLOT_H
#define COINSLOT_H
#include <vector>
#include <string>
#include <iostream>


class CoinSlot {
private:
    int coinAmount;
    const std::vector<std::pair<int, std::string>> coinValues = {
    {200, "2 euros"},
    {100, "1 euro"},
    {50, "0,5 euro"},
    {20, "0,2 euro"},
    {10, "0,1 euro"},
    {5, "0,05 euro"},
    {2, "0,02 euro"},
    {1, "0,01 euro"}
};
public:
    CoinSlot();
    int updateCoinAmount();
    int getCoinAmount() const;
    void clear();
    void returnCoin(int price);
};
#endif // COINSLOT_H
