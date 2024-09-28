#include "JeuSdl.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


SDL_Window* init() {
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "Erreur SDL_Init : " << SDL_GetError() << std::endl;
    }
    // Initialisation de SDL_image
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        std::cout << "Erreur IMG_Init : " << IMG_GetError() << std::endl;
        SDL_Quit();
    }
    // Création de la fenêtre
    SDL_Window* main = SDL_CreateWindow("Mini Race", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, 0);
    if (!main) {
        std::cout << "Erreur SDL_CreateWindow : " << SDL_GetError() << std::endl;
        IMG_Quit();
        SDL_Quit();
    }
    SDL_SetWindowResizable(main, SDL_FALSE);
    return main;
}

void icone(SDL_Window* main, SDL_Renderer* renderer) {
    SDL_Surface* iconeSurface = IMG_Load("data/damier.png"); // Chargement de l'image à utiliser comme icône
    if (iconeSurface == NULL) { // Vérification que le chargement a réussi
        std::cout << "Erreur IMG_Load : " <<  IMG_GetError() << std::endl;
    }
    SDL_SetWindowIcon(main, iconeSurface); // Utilisation de l'image comme icône pour la fenêtre
    SDL_FreeSurface(iconeSurface);
}


int main() {
    // Variables
    bool mainRun = true;
    int TILE_SIZE = 32;
    SDL_Texture* Terrain[4]; // Textures du terrain
    SDL_Texture* VoitureT[4]; // Textures des voitures
    SDL_Texture* VoitureTC[4]; // Textures des voitures pour le classement

    // Variables SDL
    SDL_Window* main = init();
    SDL_Renderer* renderer = SDL_CreateRenderer(main, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // Couleur blanc quand clear
    icone(main, renderer);


    while(mainRun) { // Boucle de jeu
        SDL_RenderClear(renderer); // Clear
        SDL_RenderPresent(renderer); // Affiche

        JeuSdl jeu(main, renderer); // Init de la carte

        // Chargement des textures
        jeu.initVoiture(renderer, VoitureT);
        jeu.initTerrain(renderer, Terrain);
        
        for(unsigned int i = 0; i < 4; i++) {  // A charger avec les textures pour le classement
            VoitureTC[i] = VoitureT[i];
        }

        jeu.departVoitures(TILE_SIZE); // Place les voitures au depart
        jeu.timer(main, renderer, TILE_SIZE, Terrain, VoitureT, VoitureTC); // Decompte de 3 avant de lancer le depart
        jeu.setTemps(clock()); // Initialise le temps du debut

        
        bool quit = false;
        const Uint8* state = SDL_GetKeyboardState(NULL);

        while (!quit) { // Boucle d'une partie
            jeu.stopInvisible(); // Arrete les voitures invisibles
            jeu.avancerIA(TILE_SIZE); // Avance les IA

            if(jeu.est_fini()) { // Si le jeu est fini, on affiche l'ecran de fin
                jeu.fin(main, renderer);
                break;
            }
            else {
                SDL_RenderClear(renderer); // Clear
                jeu.afficheTerrain(main, renderer, Terrain, TILE_SIZE); // Terrain
                jeu.afficheVoitures(main, renderer, VoitureT, TILE_SIZE); // Voitures
                jeu.afficheClassement(main, renderer, VoitureTC, jeu.getNbTour()); // Classement
                jeu.afficheTemps(main, renderer, jeu.temps(jeu.getTemps())); // Temps
                SDL_RenderPresent(renderer); // Affichage

                SDL_Event event;
                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) { // Quitter
                        quit = true;
                        mainRun = false;
                    }
                }

                if(state[SDL_SCANCODE_W]) { // W = Z
                    jeu.getVoiture(0).avancer();
                    if(jeu.collision(0)) {
                        jeu.getVoiture(0).reculer();
                    }
                }
                if(state[SDL_SCANCODE_S]) {
                    if(!jeu.collision(0)) {
                        jeu.getVoiture(0).reculer();
                    }
                }
                if(state[SDL_SCANCODE_A]) { // Q = A
                    jeu.getVoiture(0).tournerGauche(5);
                }
                if(state[SDL_SCANCODE_D]) {
                    jeu.getVoiture(0).tournerDroite(5);
                }

                if(state[SDL_SCANCODE_KP_8]) {
                    jeu.getVoiture(1).avancer();
                    if(jeu.collision(1)) {
                        jeu.getVoiture(1).reculer();
                    }
                }
                if(state[SDL_SCANCODE_KP_5]) {
                    if(!jeu.collision(1)) {
                        jeu.getVoiture(1).reculer();
                    }
                }
                if(state[SDL_SCANCODE_KP_4]) {
                    jeu.getVoiture(1).tournerGauche(5);
                }
                if(state[SDL_SCANCODE_KP_6]) {
                    jeu.getVoiture(1).tournerDroite(5);
                }
            }
        }
    }

    // Libération des ressources
    SDL_DestroyTexture(*Terrain);
    SDL_DestroyTexture(*VoitureT);
    SDL_DestroyTexture(*VoitureTC);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(main);
    
    // Arrêt de SDL
    SDL_Quit();
    return 0;
}