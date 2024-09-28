# include "Piste.h"
# include <iostream>
using namespace std;

Piste::Piste() {
    dimX = 1;
    dimY = 1;
    depart.setX(0);
    depart.setX(0);
}

Piste::~Piste() {} 




void Piste::afficherTxt() {
    for(int i = 0; i < dimX; i++) {
        for(int j = 0; j < dimY; j++) {
            cout << "0";
        }
        cout << endl;
    }
}