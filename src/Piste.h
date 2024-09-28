#ifndef _PISTE_H
#define _PISTE_H


#include "Vect2D.h"

class Piste {
    private:
        int dimX;
        int dimY;
        
        
        Vect2D depart;

    public:
        Piste();

        ~Piste();

        void afficherTxt();




};
#endif