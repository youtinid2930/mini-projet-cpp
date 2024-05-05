#ifndef KEYPAD_H
#define KEYPAD_H


class Keypad {
public:
    int getSelection () {
        int numero_selected;
        std::cout << "veillez entrer le numero de l'emplacement de produit ou -1 pour annuler : ";
        std::cin >> numero_selected;
        return numero_selected;
    }
};
#endif // KEYPAD_H
