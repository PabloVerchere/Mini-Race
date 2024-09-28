#ifndef _TERRAIN_H
#define _TERRAIN_H

#include "Vect2D.h"
#include  <string>
#include  <vector>

/**
 * @brief Classe gerant le terrain
 * Cette classe contient la carte des murs/route/... et les checkpoints ainsi que les points de passage pour les IA.
 */

class Terrain {
    private:
        char carte[30][60];  /** @brief Carte 2D qui contient les tuiles */
        unsigned int nb_cp; /** @brief Nombre de checkpoints */
        unsigned int nb_pt[2]; /** @brief Nombre de points pour les 2 IA */
        unsigned int dernierPt[2]; /** @brief Dernier points passee pour chaque IA */
        std::vector <Vect2D> Co[2]; /** @brief Coordonnees des points de passage pour les 2 IA */
        
    public:
        Terrain(); /** @brief Constructeur par defaut */
        ~Terrain(); /** @brief Destructeur par defaut */


        void initCarte(); /** @brief Recupere les coordonnees des points de passage et affiche de la route a la place */

        unsigned int getCP() const; /** @brief Retourne le nombre de checkpoints */

        char getCarte(int posX, int posY) const; /** @brief Retourne la tuile de coordonnee posX, posY */
        char getCarte(const Vect2D &V) const; /** @brief Retourne la tuile de position V */
        void setCarte(const std::string &nom_fichier); /** @brief  Charge la carte de a partir de son nom, nom_fichier */

        Vect2D getCo(unsigned int v, unsigned int i) const; /** @brief Retourne la position du points de passage i de la voiture v */

        unsigned int getDernierPt(unsigned int v) const; /** @brief Retourne le dernier checkpoint passee par la voiture v */
        void setDernierPt(unsigned int v); /** @brief Incremente de 1 le dernier checkpoint passee de la voiture v */

        void initPt();/** @brief Initialise dernierPt a 0 pour les 2 voitures IA, ainsi que les coordonnees des points de passage a (-1, -1) */
};
#endif