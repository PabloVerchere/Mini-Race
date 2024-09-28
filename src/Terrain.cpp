# include "Terrain.h"
#include <fstream>
#include <assert.h>


Terrain::Terrain() {}
Terrain::~Terrain() {} 


void Terrain::initCarte() {
    for(unsigned int i = 0; i < 30; i++) {
        for(unsigned int j = 0; j < 60; j++) {
            for(unsigned char k = 0; k < 4; k++) {
                if(k+48 == getCarte(i, j)) { // ASCII(48) = 0
                    carte[i][j] = '.';
                }
            }
            for(unsigned int k = 0; k < nb_pt[0]; k++) { // Pour la voiture 2
                if(char(k+65) == getCarte(i,j)) { // ASCII(65) = A
                    carte[i][j] = '.';
                    Co[0][k] = Vect2D(i, j);
                }
            }
            for(unsigned int k = 0; k < nb_pt[1]; k++) { // Pour la voiture 3
                if(char(k+97) == getCarte(i,j)) { // ASCII(97) = a
                    carte[i][j] = '.';
                    Co[1][k] = Vect2D(i, j);
                }
            }
        }
    }
}

unsigned int Terrain::getCP() const{
    return nb_cp;
}

char Terrain::getCarte(int posX, int posY) const{
    return carte[posX][posY];
}

char Terrain::getCarte(const Vect2D &V) const {
    return carte[int(V.getX())][int(V.getY())];
}

void Terrain::setCarte(const std::string &nom_fichier) {
    std::ifstream fichier(nom_fichier);
    assert(fichier.is_open());
    for(unsigned char i = 0; i < 30; i++) {
        for(unsigned char j = 0; j < 60; j++) {
            fichier >> carte[i][j];

        }
    }
    fichier >> nb_cp;
    fichier >> nb_pt[0] >> nb_pt[1];
    fichier.close();
}

Vect2D Terrain::getCo(unsigned int v, unsigned int i) const{
    return Co[v][i];
}

unsigned int Terrain::getDernierPt(unsigned int v) const{
    return dernierPt[v];
}

void Terrain::setDernierPt(unsigned int v) {
    dernierPt[v] += 1;
    if(dernierPt[v] == nb_pt[v]) {
        dernierPt[v] = 0;
    }
}

void Terrain::initPt() {
    for(unsigned int i = 0; i < 2; i++) {
        dernierPt[i] = 0;
        for(unsigned int j = 0; j < nb_pt[i]; j++) {
            Co[i].push_back(Vect2D(-1, -1));
        }
    }
}