#include "Jeu.h"
#include <iostream>


Jeu::Jeu(const std::string &nom_fichier) {
    terrain.setCarte(nom_fichier);
    terrain.initPt(); // Inutile dans ce mode, mais nécessaire sinon SegFault

    unsigned int CP = terrain.getCP();
    for(unsigned char l = 0; l < 4; l++) {
        voitures[l].initCP(CP);
    }

    for(unsigned char i = 0; i < 30; i++) { // hauteur
        for(unsigned char j = 0; j < 60; j++) { // largeur 
            for(unsigned char k = 0; k < 4; k++) {
                if(k+48 == terrain.getCarte(i, j)) {
                    voitures[k].setPosition(Vect2D(i, j)); // place les voitures a leur depart
                }
            }
        }
    }
    terrain.initCarte(); // retire le départ de la carte
    debut();
}
Jeu::~Jeu() {}


void Jeu::debut() const{
    std::cout << R"(
  888b     d888 d8b          d8b     8888888b.                             
  8888b   d8888 Y8P          Y8P     888   Y88b                            
  88888b.d88888                      888    888                            
  888Y88888P888 888 88888b.  888     888   d88P  8888b.   .d8888b  .d88b.  
  888 Y888P 888 888 888 "88b 888     8888888P"      "88b d88P"    d8P  Y8b 
  888  Y8P  888 888 888  888 888     888 T88b   .d888888 888      88888888 
  888   "   888 888 888  888 888     888  T88b  888  888 Y88b.    Y8b.     
  888       888 888 888  888 888     888   T88b "Y888888  "Y8888P  "Y8888  
)";
    std::cout << std::endl << "Contrôles :";
    std::cout << R"(
          ____                   ____                  ____
Joueur 1 ||Z ||        Joueur 2 ||8 ||        Quitter ||P ||
         ||__||                 ||__||                ||__||
         |/__\|                 |/__\|                |/__\|
   ____   ____   ____     ____   ____   ____
  ||Q || ||S || ||D ||   ||4 || ||5 || ||6 ||       IA: Joueur 3
  ||__|| ||__|| ||__||   ||__|| ||__|| ||__||           Joueur 4
  |/__\| |/__\| |/__\|   |/__\| |/__\| |/__\|
)";
    std::cout << std::endl;
}

void Jeu::MAJcpVoiture() {
    for(unsigned int i = 0; i < 4; i++) {
        if(terrain.getCarte(voitures[i].getPosition()) == char(48 + 4 + 1 + voitures[i].getDernierCP())) { // si la voiture est sur un CP (dans l'ordre)
            voitures[i].setDernierCP(voitures[i].getDernierCP() +1);
            voitures[i].setCP(voitures[i].getDernierCP());
        }
        if (voitures[i].tousCP() && (terrain.getCarte(voitures[i].getPosition()) == char(48 + 4))) { // verification d'un tour
            std::cout <<  "Tour FINI !!!";
            // a reinitaliser si plusieurs tours..
        }
    }
}

bool Jeu::collision(const Voiture &voiture, const Terrain &T) {
    Vect2D position_ = voiture.getPosition();
    switch (voiture.getAngle())
    {
    case 0: position_.setX(position_.getX() -1); position_.setY(position_.getY());
    if(!(position_ == getVoiture(0).getPosition()) && !(position_ == getVoiture(1).getPosition()) && !(position_ == getVoiture(2).getPosition()) && !(position_ == getVoiture(3).getPosition()) && (T.getCarte(position_) != '#')) {
      return true;
    }
    else{
      return false;
    }      
      break;
    
    case 45 : position_.setX(position_.getX() -1); position_.setY(position_.getY() +1);
    if(!(position_ == getVoiture(0).getPosition()) && !(position_ == getVoiture(1).getPosition()) && !(position_ == getVoiture(2).getPosition()) && !(position_ == getVoiture(3).getPosition()) && (T.getCarte(position_) != '#')) {
      return true;
    }
    else{
      return false;
    } 
      break;
    
    case 90 : position_.setX(position_.getX()); position_.setY(position_.getY() +1);
    if(!(position_ == getVoiture(0).getPosition()) && !(position_ == getVoiture(1).getPosition()) && !(position_ == getVoiture(2).getPosition()) && !(position_ == getVoiture(3).getPosition()) && (T.getCarte(position_) != '#')) {
      return true;
    }
    else{
      return false;
    } 
      break;
    
    case 135: position_.setX(position_.getX() +1); position_.setY(position_.getY() +1);
    if(!(position_ == getVoiture(0).getPosition()) && !(position_ == getVoiture(1).getPosition()) && !(position_ == getVoiture(2).getPosition()) && !(position_ == getVoiture(3).getPosition()) && (T.getCarte(position_) != '#')) {
      return true;
    }
    else{
      return false;
    }      
      break;

    case 180: position_.setX(position_.getX() +1); position_.setY(position_.getY() );
    if(!(position_ == getVoiture(0).getPosition()) && !(position_ == getVoiture(1).getPosition()) && !(position_ == getVoiture(2).getPosition()) && !(position_ == getVoiture(3).getPosition()) && (T.getCarte(position_) != '#')) {
      return true;
    }
    else{
      return false;
    }      
      break;

    case 225: position_.setX(position_.getX() +1); position_.setY(position_.getY() -1);
    if(!(position_ == getVoiture(0).getPosition()) && !(position_ == getVoiture(1).getPosition()) && !(position_ == getVoiture(2).getPosition()) && !(position_ == getVoiture(3).getPosition()) && (T.getCarte(position_) != '#')) {
      return true;
    }
    else{
      return false;
    }      
      break;

    case 270: position_.setX(position_.getX()); position_.setY(position_.getY() -1);
    if(!(position_ == getVoiture(0).getPosition()) && !(position_ == getVoiture(1).getPosition()) && !(position_ == getVoiture(2).getPosition()) && !(position_ == getVoiture(3).getPosition()) && (T.getCarte(position_) != '#')) {
      return true;
    }
    else{
      return false;
    }      
      break;

    case 315: position_.setX(position_.getX() -1); position_.setY(position_.getY() -1);
    if(!(position_ == getVoiture(0).getPosition()) && !(position_ == getVoiture(1).getPosition()) && !(position_ == getVoiture(2).getPosition()) && !(position_ == getVoiture(3).getPosition()) && (T.getCarte(position_) != '#')) {
      return true;
    }
    else{
      return false;
    }      
      break;
    default:
      return true;
      break;
}
}

bool Jeu::mouvement(char touche) {
    bool run = true;
    switch(touche){
      case 'p':
        run = false;
        break;

        
      case 'z':
      if(collision(getVoiture(0), getTerrain())){
        getVoiture(0).avancer();
      }
        break;

      case 'q':
        getVoiture(0).tournerGauche(45);
        break;

      case 's':
        if(collision(getVoiture(0), getTerrain())){
          getVoiture(0).reculer();
        }
        break; 

      case 'd':
        getVoiture(0).tournerDroite(45);
        break;


      case '8':
        if(collision(getVoiture(1), getTerrain())){
        getVoiture(1).avancer();
        }
        break;

      case '4':
        getVoiture(1).tournerGauche(45);
        break;

      case '5':
        if(collision(getVoiture(1), getTerrain())){
        getVoiture(1).reculer();
        }
        break; 
      
      case '6':
        getVoiture(1).tournerDroite(45);
        break;


      default:
        break;
    }
    return run;
}

Terrain& Jeu::getTerrain() {
    return terrain;
}

Voiture& Jeu::getVoiture(unsigned int i) {
    return voitures[i];
}

void Jeu::afficherTxt() const{
    bool est_voiture = false;
    for(unsigned char i = 0; i < 30; i++) {
        for(unsigned char j = 0; j < 60; j++) {
            for(unsigned char k = 0; k < 4; k++) {
                if((int(voitures[k].getPosition().getX()) == i) && (int(voitures[k].getPosition().getY()) == j)) {
                    est_voiture = true;
                    std::cout << char(k+48);
                }
            }
            if(!est_voiture) {
            std::cout << terrain.getCarte(i, j);
            }
            est_voiture = false;
        }
        std::cout << std::endl;
    }
}