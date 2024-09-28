#include "Vect2D.h"
#include <math.h>


Vect2D::Vect2D() {}
Vect2D::Vect2D(float posX, float posY) {
    x = posX;
    y = posY;
}
Vect2D::~Vect2D() {}


Vect2D Vect2D::operator+(const Vect2D &V) {
    Vect2D result;
    result.x = x + V.x;
    result.y = y + V.y;

    return result;
}

Vect2D Vect2D::operator/(int d) {
    Vect2D result;
    result.x = x/d;
    result.y = y/d;

    return result;
}

Vect2D Vect2D::operator=(const Vect2D &V) {
    x = V.x;
    y = V.y;
    return *this;
}

bool Vect2D::operator==(const Vect2D &V) {
    return (x == V.x) && (y == V.y);
}

float Vect2D::getX() const{
    return x;
}

void Vect2D::setX(float xCoord) {
    x = xCoord;
}

float Vect2D::getY() const{
    return y;
}

void Vect2D::setY(float yCoord) {
    y = yCoord;
}

float Vect2D::dist(const Vect2D &V) {
    return sqrt(pow((x - V.x), 2) + pow((y - V.y), 2));
}

float Vect2D::atan2(const Vect2D &V) { // Angle entre les 2 vect en radian
    return std::atan2(y - V.y, x - V.x);
}

Vect2D Vect2D::entier() { // Arrondis le coordonnées, a l'entier superieur ou inferieur suivant la partie decimale
    if(x - int(x) >= 0.5) {
        x += 1;
    }
    x = int(x);

    if(y - int(y) >= 0.5) {
        y += 1;
    }
    y = int(y);
    
    return *this;
}