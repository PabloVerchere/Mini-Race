#ifndef _JEU_H
#define _JEU_H

#include "Voiture.h"

/** @brief Classe de jeu du mode Texte
 * Classe qui connecte terrain a voiture et qui gere la partie
*/
class Jeu {
    private:
        Terrain terrain; /** @brief Terrain */
        Voiture voitures[4]; /** @brief Tableau des 4 voitures */
    
    public:

    Jeu(const std::string &nom_fichier); /** @brief Construit la partie sur le terrain de nom, nom_fichier, en initialisant les voitures et en les placant au depart */
    ~Jeu();/** @brief Destructeur par defaut */

    void debut() const; /** @brief Affiche le logo puis les controle du jeu */

    void MAJcpVoiture(); /** @brief Verifie que les voitures passe les checkpoints dans l'odre et affiche si une voiture a fini 1 tour */

    bool collision(const Voiture &voiture, const Terrain &T); /** @brief Verifie les collisions entre voitures et avec le terrain */

    bool mouvement(char touche); /** @brief Bouge les voitures en fonctions de la touche, touche */

    Terrain& getTerrain(); /** @brief Retourne le terrain */

    Voiture& getVoiture(unsigned int i); /** @brief Retourne la voiture i */

    void afficherTxt() const; /** @brief Affiche la partie */
};
#endif