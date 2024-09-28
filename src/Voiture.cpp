#include "Voiture.h"

Voiture::Voiture() {
    angle = 0;
    tailleCP = 0;
    dernierCP = -1;
    visible = 1;
    nbTour = 0;
    vitesse = 4;
    temps = 0;
}
Voiture::~Voiture() {}


void Voiture::avancer() {
    setPosition(Vect2D((position.getX() - vitesse*cos((angle*2*M_PI)/360)), (position.getY() + vitesse*sin((angle*2*M_PI)/360))));
}

void Voiture::reculer() {
    angle += 180;
    angle %= 360;
    avancer();
    angle += 180;
    angle %= 360;
}

void Voiture::tournerGauche(int angle_) {
    setAngle(angle+360-angle_); 
}

void Voiture::tournerDroite(int angle_) {
    setAngle(angle+angle_); 
}

Vect2D Voiture::getPosition() const{
    return position;
}

void Voiture::setPosition(const Vect2D &position_) {
    position.setX(position_.getX());
    position.setY(position_.getY());
}

int Voiture::getAngle() const{
    return angle;
}

void Voiture::setAngle(int angle_) {
    angle = (angle_)%360;
}

SDL_Texture* Voiture::getTexture() const{
    return texture;
}

void Voiture::setTexture(SDL_Texture* texture_) {
    texture = texture_;
}

bool Voiture::getVisible() const{
    return visible;
}

void Voiture::setVisible(bool visible_) {
    visible = visible_;
}

unsigned int Voiture::getTour() const{
    return nbTour;
}

void Voiture::setTour(unsigned int i) {
    nbTour = i;
}

unsigned int Voiture::getVitesse() const{
    return vitesse;
}

void Voiture::setVitesse(unsigned int vitesse_) {
    vitesse = vitesse_;
}

unsigned int Voiture::getTailleCP() const{
    return tailleCP;    
}

void Voiture::initCP(unsigned int nb_cp) {
    checkpoints.clear();
    for(unsigned int i = 0; i < nb_cp; i++) {
        checkpoints.push_back(0);
    }
}

bool Voiture::tousCP() {
    bool tous = true;
    for(unsigned int i = 0; i < checkpoints.size(); i++) {
        if(checkpoints[i] != 1) {
            tous = false;
        }
    }
    return tous;
}

int Voiture::getDernierCP() const{
    return dernierCP;
}

void Voiture::setDernierCP(unsigned int i) {
    dernierCP = i;
}

bool Voiture::getCP(unsigned int i) const{
    return checkpoints[i];
}

void Voiture::setCP(unsigned int i) {
    checkpoints[i] = 1;
}

float Voiture::getTemps() const{
    return temps;
}

void Voiture::setTemps(float temps_) {
    temps = temps_;
}