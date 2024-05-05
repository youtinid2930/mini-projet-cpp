#include "automat.h"
#include <iostream>
#include <string>


using namespace std;




int main() {

    Automat vendingMachine(5, 2); // numberslot , number de product per slot

    vendingMachine.addSlot("mix", 467, 1, 1, 2); // name  , price, slotid, motors(1,2)
    vendingMachine.addSlot("mit", 200, 2, 3,0);
    vendingMachine.addSlot("mix", 34, 3, 4, 0);
    vendingMachine.addSlot("alks", 43, 4, 5, 6);
    vendingMachine.afficheSlot();

    string currentState = "IDLE";
    int selectedSlot;
    int price;

    while (currentState != "FINISHED") {
        if (currentState == "IDLE") {
            selectedSlot = vendingMachine.getKeypad().getSelection();
            if (selectedSlot == -1) {
                cout << "" << endl;
                currentState = "FINISHED";
            } else {
                if (vendingMachine.isAvailable(selectedSlot)) {
                    price = vendingMachine.getPrice(selectedSlot);
                    if(price == 0) {
                        cout << "cette emplacement est vide" << endl;
                        currentState = "IDLE";
                    }
                    else {
                        currentState = "COLLECT_MONEY";
                        cout << "veuillez inserer des pieces totalisant " << price << " cents." << endl;
                    }

                } else {
                    cout << "l'emplacement selectionne n'est pas disponible." << endl;
                }
            }
        } else if (currentState == "COLLECT_MONEY") {
            int insertedAmount = vendingMachine.getCoinSlot().updateCoinAmount();
            if (insertedAmount == -1) {
                cout << "achat annule." << endl;
                vendingMachine.getCoinSlot().clear();
                currentState = "IDLE";
            } else {
                if (insertedAmount >= price) {
                    currentState = "DROP";
                } else {
                    cout << "fonds insuffisants. veuillez inserer plus de pieces." << endl;
                }
            }
        } else if (currentState == "DROP") {
            vendingMachine.dropSlot(selectedSlot);
            if (vendingMachine.getDropCheck().productReleased()) {
                currentState = "RETURN_MONEY";
                vendingMachine.viderSlot(selectedSlot);
            } else {
                cout << "produit non commercialise. veuillez ressayer." << endl;
                currentState = "DROP";
            }
        } else if (currentState == "RETURN_MONEY") {
            vendingMachine.getCoinSlot().returnCoin(price);
            vendingMachine.getCoinSlot().clear();
            currentState = "IDLE";
        }
    }

    return 0;
}
