#ifndef _VECT2D_H
#define _VECT2D_H

/**
 * @brief Classe pour les positions
 * Classe Vect2D utile pour definir les positions des differents elements du jeu
 */

class Vect2D {
    private:
        float x; /** @brief Position x */
        float y; /** @brief Position y */


    public:
        Vect2D(); /** @brief Constructeur par default */
        Vect2D(float posX, float posY); /** @brief Constructeur par copie */
        ~Vect2D(); /** @brief Destructeur par defaut */
 
        Vect2D operator+(const Vect2D &V); /** @brief Surcharge + */
        Vect2D operator/(int d); /** @brief Surcharge / */
        Vect2D operator=(const Vect2D &V); /** @brief Surcharge = */
        bool operator==(const Vect2D &V); /** @brief Surcharge == */

        float getX() const; /** @brief Retourne x */
        void setX(float xCoord); /** @brief setX a xCoord */

        float getY() const; /** @brief Retourne y */
        void setY(float yCoord); /** @brief setY a yCoord */

        float dist(const Vect2D &V); /** @brief Retourne la distance entre le veteur et V */

        float atan2(const Vect2D &V); /** @brief Retourne l'angle en radian entre le vecteur et V */

        Vect2D entier(); /** @brief Arrondis les coordonnees x et y a l'entier superieur (>0.5) ou inferieur (<0.5) */
};
#endif