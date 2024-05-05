#include "coinslot.h"
#include <iostream>
#include <string>

using namespace std;


CoinSlot::CoinSlot() {
    coinAmount = 0;
}

int CoinSlot::updateCoinAmount() {
    cout << "veillez inserer une piece de de monnaie ou entrer -1 pour annuler l'achat : ";
    int insertedAmount;
    cin >> insertedAmount;
    if (insertedAmount == -1) {
        return -1;
    }
    coinAmount += insertedAmount;
    return coinAmount;
}

int CoinSlot::getCoinAmount() const{
    return coinAmount;
}


void CoinSlot::clear() {
    coinAmount = 0;
}


void CoinSlot::returnCoin(int price) {
    int coin_to_return = coinAmount - price;
    string pieces_ejecter = "";
    if(coin_to_return < 0) {
        cout << "les pieces de monnaie insuffisante !" << endl;
    }
    else if(coin_to_return == 0) {
        cout << "les pieces de monnaie suffisante, vous n'avez pas des pieces a returner."<<endl;
    }
    else {
        for(const auto &coin : coinValues) {
            //cout << "coin_to_return : "<<coin_to_return<<"coin.first: "<<coin.first<<endl;
            int numberCoin = coin_to_return / coin.first;
            //cout << "numberCoin: "<<numberCoin<< endl;
            if(numberCoin > 0) {
                cout << numberCoin << " x " << coin.second <<", ";
                coin_to_return %= coin.first;
            }
        }
        cout << endl;
    }
}


