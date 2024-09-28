#ifndef _Voiture
#define _Voiture

#include "Terrain.h"
#include <SDL2/SDL.h>

/** @brief Classe voiture
 * Classe qui gere voiture et ses attributs
*/
class Voiture {
    private:
        Vect2D position; /** @brief Position de la voiture */
        int angle; /** @brief Angle de la voiture (modulo 360) */

        std::vector <bool> checkpoints; /** @brief Tableau de booleen egal a 0 si le checkpoint n'est pas passee, 1 sinon */ // Inutile, juste a verif si dernierCP == tailleCP 
        unsigned int tailleCP; /** @brief Nombre de checkpoints */
        int dernierCP; /** @brief Dernier checkpoints passee */

        SDL_Texture* texture; /** @brief Texture de la voiture */
        bool visible; /** @brief booleen a 0 si la voiture est invisible, 1 sinon */
        unsigned int nbTour; /** @brief Nombre de tour effectuer par la voiture */
        unsigned int vitesse; /** @brief Vitesse de la voiture */
        float temps; /** @brief Temps a la fin de la course*/

    public:
        Voiture(); /** @brief Constructeur par defaut */
        ~Voiture(); /** @brief Destructeur par defaut */


        void avancer(); /** @brief Avance la voiture */
        void reculer(); /** @brief Recule la voiture */
        void tournerGauche(int angle_); /** @brief Tourne la voiture a gauche d'angle angle_ */
        void tournerDroite(int angle_); /** @brief Tourne la voiture a droite d'angle angle_ */

        Vect2D getPosition()const; /** @brief Retourne la position de la voiture */
        void setPosition(const Vect2D &position_); /** @brief Set la position de la voiture a la position position_*/
        
        int getAngle() const; /** @brief Retourne l'angle de la voiture */
        void setAngle(int angle_); /** @brief Set l'angle de la voiture a l'angle angle_ */

        SDL_Texture* getTexture() const; /** @brief Retourne la texture de la voiture */
        void setTexture(SDL_Texture* texture_); /** @brief Set la texture de la voiture a la texture texture_ */

        bool getVisible() const; /** @brief Retourne 0 si la voiture est invisible, 1 sinon */
        void setVisible(bool visible_); /** @brief Rend invisible la voiture si visible_ = 0, la rend visible si visible_ = 1 */

        unsigned int getTour() const; /** @brief Retourne le nombre de tour effectuer par la voiture */
        void setTour(unsigned int i); /** @brief Set le nombre de tour effectuer par la voiture a i */

        unsigned int getVitesse() const; /** @brief Retourne la vitesse de la voiture */
        void setVitesse(unsigned int vitesse_); /** @brief Set la vitesse de la voiture a la vitesse vitesse_*/

        unsigned int getTailleCP() const; /** @brief Retourne le nombre de checkpoints */

        void initCP(unsigned int nb_cp); /** @brief Initialise le tableau de checkpoints a 0*/

        bool tousCP(); /** @brief Retourne 1 si tous les checkpoints du tableau sont passe, 0 sinon */

        int getDernierCP() const; /** @brief Retourne le nombre de checkpoints passe -1 car la ligne de depart est le 0*/
        void setDernierCP(unsigned int i); /** @brief Set le nombre de checkpoints passe a i */

        bool getCP(unsigned int i) const; /** @brief Retourne le 0 si le checkpoints i n'est pas passe, 1 sinon */
        void setCP(unsigned int i ); /** @brief Set le checkpoints i a 1*/

        float getTemps() const; /** @brief Retourne le temps final de la voiture */
        void setTemps(float temps); /** @brief Set le temps final de la voiture a temps*/
};
#endif