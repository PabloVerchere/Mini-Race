#ifndef _JEUSDL_H
#define _JEUSDL_H

#include "Voiture.h"
#include <string>

/** @brief Classe de jeu en mode Graphique qui connecte terrain et voiture
 * Classe principale du mode graphique qui gere la partie
*/
class JeuSdl {
    private:
        Terrain terrain; /** @brief Terrain */
        Voiture voitures[4]; /** @brief Tableau des 4 voitures */
        unsigned int nb_voitures; /** @brief Nombre de voitures dans la partie */
        unsigned int CP; /** @brief Nombre de checkpoints */
        unsigned int Pt[2]; /** @brief Nombre de points de passage pour les 2 IA */
        unsigned int nb_tour; /** @brief Nombre de tours a effectuer */
        clock_t tempsDebut; /** @brief Temps de reference au lancement de la partie */

    public:

    /** @brief Affiche le menu de selection du terrain, nombre de tour et de voitures.
     * Init les checkpoints, les points de passages, et places les voitures au depart*/
    JeuSdl(SDL_Window* main, SDL_Renderer* renderer);
    ~JeuSdl(); /** @brief Destructeur par defaut */

    /** @brief Charge les textures utilisees dans le terrain
     * @param Textures Textures du terrain a chargees*/
    void initTerrain(SDL_Renderer* renderer, SDL_Texture** Textures) const;

    /** @brief Charge les textures des voitures
     * @param Textures Textures du terrain a chargees*/
    void initVoiture(SDL_Renderer* renderer, SDL_Texture** Textures); 

    /** @brief Affiche le menu de selection du terrain, nombre de tours et de voitures
     * @param nb_tour Retourne le nombre de tours a effectuer
     * @param nb_voitures Retourne le nombre de voitures qui joue la partie
     * @return Retourne le nom du terrain pour la partie */
    std::string debut(SDL_Window* main, SDL_Renderer* renderer, unsigned int &nb_tour, unsigned int &nb_voitures);

    /** @brief Fait un decompte de 3 secondes avant le depart */
    void timer(SDL_Window* main, SDL_Renderer* renderer, int TILE_SIZE, SDL_Texture** Terrain, SDL_Texture** VoitureT, SDL_Texture** VoitureTC);

    float getTemps(); /** @brief Retourne de temps au debut, non lisible car en nombre de clicks*/

    void setTemps(clock_t temps_); /** @brief Set tempsDebut a temps_ */

    float temps(clock_t temps0); /** @brief Retourne le temps en secondes depuis temps0*/

    void afficheTemps(SDL_Window* main, SDL_Renderer* renderer, float temps0); /** @brief Affiche le temps temps0 dans la fenetre, en haut au centre */

    void afficheTerrain(SDL_Window* main, SDL_Renderer* renderer, SDL_Texture** Textures, int TILE_SIZE) const; /** @brief  Affiche le terraint */
    void afficheVoitures(SDL_Window* main, SDL_Renderer* renderer, SDL_Texture** Textures, int TILE_SIZE) const; /** @brief Affiche les voitures */
    void afficheClassement(SDL_Window* main, SDL_Renderer* renderer, SDL_Texture** Textures, int nbTour); /** @brief Affiche le classement des voitures en jeu */

    SDL_Texture** MajClassement(SDL_Renderer* renderer, SDL_Texture** vText, int nbTour); /** @brief Met a jour le classement */

    static bool comparaison(const Voiture &v1, const Voiture &v2); /** @brief Compare les voitures v1 et v2 et retourne 1 si la voiture 1 est devant, 0 sinon */

    void avancerIA(int TILE_SIZE); /** @brief  Fait jouer les IA, en passant par les points de passage */

    void departVoitures(int TILE_SIZE); /** @brief Place les voitures au depart */

    bool collision(int idV); /** @brief Verifie si la voitures idV est en collision avec un autre voitures ou le terrain, et double sa vitesse si elle est sur un boost */

    /** @brief Retourne 1 si la souris est dans le rectangle X, Y
     * @param X Coordonnee en haut a gauche du rectangle
     * @param Y Coordonne en bas a droite du rectangle
     * @param pos Coordonne de la souris
     * @return Retourne si la souris est dans le rectangle*/
    bool sourisCoEntre(Vect2D X, Vect2D Y, Vect2D pos); 

    bool est_fini(); /** @brief Verifie si le jeu est fini, ie: si toute les voitures sont invisibles */

    void fin(SDL_Window* main, SDL_Renderer* renderer); /** @brief Affiche le classement de fin et les temps */

    Terrain& getTerrain(); /** @brief Retourne le terrain */

    Voiture& getVoiture(unsigned int i); /** @brief Retourne la voiture i */
    void setVoiture(unsigned int i, const Voiture &V); /** @brief Set la voiture i a V */

    unsigned int getNbTour() const; /** @brief Retourne le nombre de tour a effectuer */
    void setNbTour(unsigned int nbTour_); /** @brief Set le nombre de tour a effectuer a nbTour_ */

    unsigned int getNbVoitures() const; /** @brief Retourne le nombre de voitures en jeu (1-4) */
    void setNbVoitures(unsigned int nbVoitures_); /** @brief Set le nombre de voitures en jeu a nbVoitures_ */

    void stopInvisible(); /** @brief Stop les voitures invisibles (vitesse = 0) */
};
#endif