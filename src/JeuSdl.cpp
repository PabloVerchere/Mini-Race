#include "JeuSdl.h"
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <algorithm>


JeuSdl::JeuSdl(SDL_Window* main, SDL_Renderer* renderer) {
    unsigned int nbtour = 1; // Valeur par defaut
    unsigned int nbvoitures = 4; // Valeur par defaut
    terrain.setCarte(debut(main, renderer, nbtour, nbvoitures)); // Recupere le nb de tours, de voitures et le terrain
    terrain.initPt();
    setNbTour(nbtour);
    setNbVoitures(nbvoitures);

    CP = terrain.getCP();
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
    terrain.initCarte(); // retire les position de départ de la carte

    for(unsigned int k = 0; k < 4; k++) {
        if(k+1 > nb_voitures) {
            voitures[k].setVisible(0); // N'affiche que le nombre de voitures selectionné
        }
    }
}
JeuSdl::~JeuSdl() {}


void JeuSdl::initTerrain(SDL_Renderer* renderer, SDL_Texture** Textures) const{ // Charge les textures du terrain
    SDL_Surface* HerbeSurface = IMG_Load("data/herbe.png");
    SDL_Texture* HerbeTexture = SDL_CreateTextureFromSurface(renderer, HerbeSurface);
    Textures[0] = HerbeTexture;
    SDL_Surface* RouteSurface = IMG_Load("data/route.png");
    SDL_Texture* RouteTexture = SDL_CreateTextureFromSurface(renderer, RouteSurface);
    Textures[1] = RouteTexture;
    SDL_Surface* DamierSurface = IMG_Load("data/damier.png");
    SDL_Texture* DamierTexture = SDL_CreateTextureFromSurface(renderer, DamierSurface);
    Textures[2] = DamierTexture;
    SDL_Surface* BoostSurface = IMG_Load("data/boost.png");
    SDL_Texture* BoostTexture = SDL_CreateTextureFromSurface(renderer, BoostSurface);
    Textures[3] = BoostTexture;

    SDL_FreeSurface(HerbeSurface);
    SDL_FreeSurface(RouteSurface);
    SDL_FreeSurface(DamierSurface);
    SDL_FreeSurface(BoostSurface);
}

void JeuSdl::initVoiture(SDL_Renderer* renderer, SDL_Texture** Textures) { // Charge les textures des voitures
    SDL_Surface* Voiture0Surface = IMG_Load("data/voiture_bleu.png");
    voitures[0].setTexture(SDL_CreateTextureFromSurface(renderer, Voiture0Surface));
    Textures[0] = voitures[0].getTexture();
    SDL_Surface* Voiture1Surface = IMG_Load("data/voiture_jaune.png");
    voitures[1].setTexture(SDL_CreateTextureFromSurface(renderer, Voiture1Surface));
    Textures[1] = voitures[1].getTexture();
    SDL_Surface* Voiture2Surface = IMG_Load("data/voiture_rouge.png");
    voitures[2].setTexture(SDL_CreateTextureFromSurface(renderer, Voiture2Surface));
    Textures[2] = voitures[2].getTexture();
    SDL_Surface* Voiture3Surface = IMG_Load("data/voiture_verte.png");
    voitures[3].setTexture(SDL_CreateTextureFromSurface(renderer, Voiture3Surface));
    Textures[3] = voitures[3].getTexture();

    SDL_FreeSurface(Voiture0Surface);
    SDL_FreeSurface(Voiture1Surface);
    SDL_FreeSurface(Voiture2Surface);
    SDL_FreeSurface(Voiture3Surface);

}

std::string JeuSdl::debut(SDL_Window* main, SDL_Renderer* renderer, unsigned int &nb_tour, unsigned int &nb_voitures) {
    std::string result;

    // Affichage logo
    SDL_Surface* logoSurface = IMG_Load("data/logo.png");
    SDL_Texture* logoTexture = SDL_CreateTextureFromSurface(renderer, logoSurface);
    SDL_Rect logoRect = {160, -100,1600, 400};

    // Affichage Terrains
    SDL_Surface* T0S = IMG_Load("data/Terrain0.png");
    SDL_Surface* T1S = IMG_Load("data/Terrain1.png");
    SDL_Surface* T2S = IMG_Load("data/Terrain2.png");
    SDL_Surface* T3S = IMG_Load("data/Terrain3.png");

    SDL_Texture* T0T = SDL_CreateTextureFromSurface(renderer, T0S);
    SDL_Texture* T1T = SDL_CreateTextureFromSurface(renderer, T1S);
    SDL_Texture* T2T = SDL_CreateTextureFromSurface(renderer, T2S);
    SDL_Texture* T3T = SDL_CreateTextureFromSurface(renderer, T3S);

    int longueur = 600; int largeur = 300;
    int x0 = 50; int y0 = 250;
    int x1 = 50; int y1 = 600;
    int x2 = 700; int y2 = 250;
    int x3 = 700; int y3 = 600;
    SDL_Rect Rect0 = {x0, y0, longueur, largeur};
    SDL_Rect Rect1 = {x1, y1, longueur, largeur};
    SDL_Rect Rect2 = {x2, y2, longueur, largeur};
    SDL_Rect Rect3 = {x3, y3, longueur, largeur};

    // Affichage message tours
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("data/times.ttf", 100);
    SDL_Color noir = {0, 0, 0};
    std::string messageT;
    SDL_Surface* SurfacetexteT;
    SDL_Texture* TextureTexteT;
    SDL_Rect msgRect = {1310, 250, 600, 150};
    
    // Affiche message voitures
    std::string messageV;
    SDL_Surface* SurfacetexteV;
    SDL_Texture* TextureTexteV;
    SDL_Rect msgRect0 = {1310, 410, 600, 150};
    SDL_Surface* V0S = IMG_Load("data/voiture_bleu.png");
    SDL_Surface* V1S = IMG_Load("data/voiture_jaune.png");
    SDL_Surface* V2S = IMG_Load("data/voiture_rouge.png");
    SDL_Surface* V3S = IMG_Load("data/voiture_verte.png");
    SDL_Texture* V0T = SDL_CreateTextureFromSurface(renderer, V0S);
    SDL_Texture* V1T = SDL_CreateTextureFromSurface(renderer, V1S);
    SDL_Texture* V2T = SDL_CreateTextureFromSurface(renderer, V2S);
    SDL_Texture* V3T = SDL_CreateTextureFromSurface(renderer, V3S);
    SDL_Rect Nb_v0 = {1500, 600, 80, 80};
    SDL_Rect Nb_v1 = {1600, 600, 80, 80};
    SDL_Rect Nb_v2 = {1500, 700, 80, 80};
    SDL_Rect Nb_v3 = {1600, 700, 80, 80};

    bool run = true;
    int sX, sY;
    const Uint8* state = SDL_GetKeyboardState(NULL);
    while (run) { // Boucle jusqu'a la selection du circuit et retournr nb tours et voitures
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            SDL_RenderClear(renderer);

            messageT = "Nombre de tours : " + std::to_string(nb_tour) + " (+~-)"; // Selection nb tours
            SurfacetexteT = TTF_RenderText_Blended(font, messageT.c_str(), noir);
            TextureTexteT = SDL_CreateTextureFromSurface(renderer, SurfacetexteT);
            SDL_RenderCopy(renderer, TextureTexteT, NULL, &msgRect);

            messageV = "Nombre de voitures : (*~/)";
            SurfacetexteV = TTF_RenderText_Blended(font, messageV.c_str(), noir); // Selection nb voitures
            TextureTexteV = SDL_CreateTextureFromSurface(renderer, SurfacetexteV);
            SDL_RenderCopy(renderer, TextureTexteT, NULL, &msgRect);

            SDL_RenderCopy(renderer, logoTexture, NULL, &logoRect); // Logo
            SDL_RenderCopy(renderer, T0T, NULL, &Rect0); // Terrain 0
            SDL_RenderCopy(renderer, T1T, NULL, &Rect1); // Terrain 1
            SDL_RenderCopy(renderer, T2T, NULL, &Rect2); // Terrain 2
            SDL_RenderCopy(renderer, T3T, NULL, &Rect3); // Terrain 3
            SDL_RenderCopy(renderer, TextureTexteT, NULL, &msgRect); // Tours
            SDL_RenderCopy(renderer, TextureTexteV, NULL, &msgRect0); // Voitures

            SDL_RenderCopy(renderer, V0T, NULL, &Nb_v0); // Voiture 0
            if(nb_voitures >= 2) {
                SDL_RenderCopy(renderer, V1T, NULL, &Nb_v1); // Voiture 1
            }
            if(nb_voitures >= 3) {
                SDL_RenderCopy(renderer, V2T, NULL, &Nb_v2); // Voiture 2
            }
            if(nb_voitures == 4) {
                SDL_RenderCopy(renderer, V3T, NULL, &Nb_v3); // Voiture 3
            }
            SDL_RenderPresent(renderer);
            
            if (event.button.button == SDL_BUTTON_LEFT) { // Verifie si l'on clique sur un terrain
                SDL_GetMouseState(&sX, &sY);
                if(sourisCoEntre(Vect2D(x0, y0), Vect2D(x0+longueur, y0+largeur), Vect2D(sX, sY))) {
                    run = false;
                    result =  "data/Terrain0.txt";
                }
                if(sourisCoEntre(Vect2D(x1, y1), Vect2D(x1+longueur, y1+largeur), Vect2D(sX, sY))) {
                    run = false;
                    result = "data/Terrain1.txt";
                }
                if(sourisCoEntre(Vect2D(x2, y2), Vect2D(x2+longueur, y2+largeur), Vect2D(sX, sY))) {
                    run = false;
                    result = "data/Terrain2.txt";
                }
                if(sourisCoEntre(Vect2D(x3, y3), Vect2D(x3+longueur, y3+largeur), Vect2D(sX, sY))) {
                    run = false;
                    result = "data/Terrain3.txt";
                }   
            }
            if(event.type == SDL_KEYDOWN) {
                if(state[SDL_SCANCODE_KP_PLUS]) {
                    nb_tour += 1;
                    }
                if(state[SDL_SCANCODE_KP_MINUS]) {
                    if(nb_tour > 1) {
                        nb_tour -= 1;
                    }
                }
                if(state[SDL_SCANCODE_KP_MULTIPLY]) {
                    if(nb_voitures < 4) {
                        nb_voitures += 1;
                    }
                }
                if(state[SDL_SCANCODE_KP_DIVIDE]) {
                    if(nb_voitures > 1) {
                        nb_voitures -= 1;
                    }
                }
            }
        }
    }
    // Libération des ressources
    SDL_FreeSurface(logoSurface);
    SDL_FreeSurface(SurfacetexteT);
    SDL_FreeSurface(T0S);
    SDL_FreeSurface(T1S);
    SDL_FreeSurface(T2S);
    SDL_FreeSurface(T3S);
    SDL_FreeSurface(V0S);
    SDL_FreeSurface(V1S);
    SDL_FreeSurface(V2S);
    SDL_FreeSurface(V3S);
    SDL_FreeSurface(SurfacetexteV);

    SDL_DestroyTexture(logoTexture);
    SDL_DestroyTexture(TextureTexteT);
    SDL_DestroyTexture(T0T);
    SDL_DestroyTexture(T1T);
    SDL_DestroyTexture(T2T);
    SDL_DestroyTexture(T3T);
    SDL_DestroyTexture(V0T);
    SDL_DestroyTexture(V1T);
    SDL_DestroyTexture(V2T);
    SDL_DestroyTexture(V3T);
    SDL_DestroyTexture(TextureTexteV);

    TTF_CloseFont(font);
    TTF_Quit();
    return result;
}

void JeuSdl::timer(SDL_Window* main, SDL_Renderer* renderer, int TILE_SIZE, SDL_Texture** Terrain, SDL_Texture** VoitureT, SDL_Texture** VoitureTC) { // 3'' avant le depart
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("data/times.ttf", 100);
    SDL_Color blanc = {255, 255, 255};
    SDL_Surface* msgS;
    SDL_Texture* msgT;

    int longueur = 32*60; // Longueur de la fenetre
    int largeur = 32*30; // Largeur de la fenetre
    int taille = 70; // Taille de l'affichage
    SDL_Rect msgRect = {(longueur - taille)/2, (largeur - taille)/2, taille, taille};

    for(unsigned int i = 3; i >= 1; i--) { // Decompte de 3 avant le lancement
        SDL_RenderClear(renderer);

        afficheTerrain(main, renderer, Terrain, TILE_SIZE); // Terrain
        afficheVoitures(main, renderer, VoitureT, TILE_SIZE); // Voitures
        afficheClassement(main, renderer, VoitureTC, nb_tour); // Classement
        msgS = TTF_RenderText_Blended(font, std::to_string(i).c_str(), blanc);
        msgT = SDL_CreateTextureFromSurface(renderer, msgS);

        SDL_RenderCopy(renderer, msgT, NULL, &msgRect);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_FreeSurface(msgS);
    SDL_DestroyTexture(msgT);
}

float JeuSdl::getTemps() {
    return tempsDebut;
}

void JeuSdl::setTemps(clock_t temps_) {
    tempsDebut = temps_;
}

float JeuSdl::temps(clock_t temps0) { // Retourne le temps depuis temps0
    clock_t tempsFloat = 3 * (clock() - temps0)/10000; // Temps *100, en secondes
    std::string tempsString = std::to_string(tempsFloat/100.0); // Temps avec 2 decimales
    tempsString = tempsString.substr(0, tempsString.size() - 4); // Enleve les 0 en trop a la fin

    return stof(tempsString); // Convertie la string en float
}

void JeuSdl::afficheTemps(SDL_Window* main, SDL_Renderer* renderer, float temps) {
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("data/times.ttf", 100);
    SDL_Color blanc = {255, 255, 255};
    SDL_Surface* msgS;
    SDL_Texture* msgT;

    int longueur = 32*60; // Longueur de la fenetre
    int taille = 70; // Taille de l'affichage
    SDL_Rect msgRect = {(longueur - taille)/2, 0, taille, taille/2};

    msgS = TTF_RenderText_Blended(font, std::to_string(temps).substr(0, std::to_string(temps).size() - 4).c_str(), blanc); 
    msgT = SDL_CreateTextureFromSurface(renderer, msgS);
    SDL_RenderCopy(renderer, msgT, NULL, &msgRect); // Copie le temps en haut au centre

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_FreeSurface(msgS);
    SDL_DestroyTexture(msgT);

}

void JeuSdl::afficheTerrain(SDL_Window* main, SDL_Renderer* renderer, SDL_Texture** Textures, int TILE_SIZE) const{
    char tuile;
    SDL_Rect dstRect;

    for(unsigned char i = 0; i < 30; i++) {
        for(unsigned char j = 0; j < 60; j++) {
            dstRect = {j*TILE_SIZE, i*TILE_SIZE, TILE_SIZE, TILE_SIZE};

            tuile = terrain.getCarte(i, j);
            switch(tuile) {
                case '#':
                    SDL_RenderCopy(renderer, Textures[0], NULL, &dstRect);
                    break;
                case '.':
                    SDL_RenderCopy(renderer, Textures[1], NULL, &dstRect);
                    break;
                case '4':
                    SDL_RenderCopy(renderer, Textures[2], NULL, &dstRect);
                    break;
                case '/':
                    SDL_RenderCopy(renderer, Textures[3], NULL, &dstRect);
                    break;
                default:
                    SDL_RenderCopy(renderer, Textures[1], NULL, &dstRect);
                    break;
            }
        }
    }
}

void JeuSdl::afficheVoitures(SDL_Window* main, SDL_Renderer* renderer, SDL_Texture** Textures, int TILE_SIZE) const{
    SDL_Rect rect[4];
    for(unsigned int i = 0; i < 4; i++) {
        if(voitures[i].getVisible()) {
            rect[i] = {int(voitures[i].getPosition().getY()), int(voitures[i].getPosition().getX()), TILE_SIZE, TILE_SIZE};
            SDL_RenderCopyEx(renderer, Textures[i], NULL, &rect[i], voitures[i].getAngle(), NULL, SDL_FLIP_NONE);       
        }
    }
}

void JeuSdl::afficheClassement(SDL_Window* main, SDL_Renderer* renderer, SDL_Texture** Textures, int nbTour) {
    Textures = MajClassement(renderer, Textures, nbTour);
        SDL_Rect r[nb_voitures];
        for(int i = 0; i < nb_voitures; i++) { // Ne tient pas compte de l'orddre de passage des CP
            r[i] = {int(i*1920/nb_voitures), 960, int(1920/nb_voitures), 60};
            SDL_RenderCopy(renderer, Textures[i], NULL, &r[i]);
        }
}

SDL_Texture** JeuSdl::MajClassement(SDL_Renderer* renderer, SDL_Texture** Textures, int nbTour) {
    for(unsigned int i = 0; i < 4; i++) {
        if(terrain.getCarte(Vect2D((int(voitures[i].getPosition().getX()+16)/32), int((voitures[i].getPosition().getY()+16)/32))) == char(48 + 4 + 1 + voitures[i].getDernierCP())) { // si la voiture est sur un CP (dans l'ordre)
            voitures[i].setDernierCP(voitures[i].getDernierCP() +1);
            voitures[i].setCP(voitures[i].getDernierCP());
        }
        if(voitures[i].tousCP() && terrain.getCarte(Vect2D((int(voitures[i].getPosition().getX()+16)/32), int((voitures[i].getPosition().getY()+16)/32))) == char(48 + 4)) {
            voitures[i].initCP(CP);
            voitures[i].setDernierCP(-1);
            voitures[i].setTour(voitures[i].getTour() +1);
        }
        if(voitures[i].getTour() == nbTour) {
            voitures[i].setVisible(0);
            if(voitures[i].getTemps() == 0) { // Si on n'a pas deja affete une valeur, on set le temps de fin
                voitures[i].setTemps(temps(tempsDebut));
            }         
        }
    }

    
    Voiture tmp[4]; // Cree un tampon pour ne pas modifier voitures
    for(unsigned int i = 0; i < 4; i++) {
        tmp[i] = voitures[i];
    }
    std::sort(tmp, tmp + 4, comparaison); // trie les voitures (par croissance de DernierCP)
    for(unsigned int i = 0; i < 4; i++) {
        Textures[i] = tmp[i].getTexture(); // Copie les textures
    }
    return Textures;
}

bool JeuSdl::comparaison(const Voiture &v1, const Voiture &v2) {
    if (v1.getVisible() == 1 && v2.getVisible() == 0)
        return true; // Si v1 est visible et v2 non, v1 passe devant
    if (v1.getTour() > v2.getTour()) {
        return true; // v1 a parcouru plus de tours que v2
    } else if (v1.getTour() == v2.getTour() && v1.getDernierCP() >= v2.getDernierCP()) {
        return true; // v1 et v2 ont parcouru le même nombre de tours, mais v1 a atteint le CP en premier ou en même temps que v2
    } else {
        return false; // v2 est devant v1
    }
}


void JeuSdl::avancerIA(int TILE_SIZE) {
    Vect2D pos[2];
    Vect2D co[2];

    for(unsigned int i = 0; i < 2; i++) {
        pos[i] = (getVoiture(2+i).getPosition()/TILE_SIZE).entier(); // Postion de la voiture
        co[i] = terrain.getCo(i, terrain.getDernierPt(i)); // Postion du prochain point

        if(pos[i] == co[i]) { // Si la voiture est sur le point, elle se dirige vers le prochain
            terrain.setDernierPt(i);
        }
        else {
            getVoiture(2+i).setAngle(-1 * (180 / M_PI) * pos[i].atan2(co[i]));

            getVoiture(2+i).avancer();
            if(collision(2+i)) {
                getVoiture(2+i).reculer();
            }
        }

    }
}

void JeuSdl::departVoitures(int TILE_SIZE) {
    voitures[0].setPosition(Vect2D(voitures[0].getPosition().getX()*TILE_SIZE, voitures[0].getPosition().getY()*TILE_SIZE));
    voitures[1].setPosition(Vect2D(voitures[1].getPosition().getX()*TILE_SIZE, voitures[1].getPosition().getY()*TILE_SIZE));
    voitures[2].setPosition(Vect2D(voitures[2].getPosition().getX()*TILE_SIZE, voitures[2].getPosition().getY()*TILE_SIZE));
    voitures[3].setPosition(Vect2D(voitures[3].getPosition().getX()*TILE_SIZE, voitures[3].getPosition().getY()*TILE_SIZE));
}

bool JeuSdl::collision(int idV) { 
    bool col = false;
    for(unsigned int i = 0; i < 4; i++) {
        if(i!=idV) {
            if((voitures[idV].getPosition().dist(voitures[i].getPosition()) < 32) && (voitures[i].getVisible())) { // collision entre voitures
                col = true;
            }
        }

        // Collision avec le terrain pour les 4 points de la voitures
        if((terrain.getCarte((Vect2D(int((voitures[idV].getPosition().getX())/32), int((voitures[idV].getPosition().getY())/32)))) == '#') || 
            (terrain.getCarte((Vect2D(int((voitures[idV].getPosition().getX())/32), int((voitures[idV].getPosition().getY()+32)/32)))) == '#') ||
            (terrain.getCarte((Vect2D(int((voitures[idV].getPosition().getX()+32)/32), int((voitures[idV].getPosition().getY())/32)))) == '#') ||
            (terrain.getCarte((Vect2D(int((voitures[idV].getPosition().getX()+32)/32), int((voitures[idV].getPosition().getY()+32)/32)))) == '#')) { 
            col = true;
        }

        // Boost
        if(terrain.getCarte((Vect2D(int((voitures[idV].getPosition().getX()+16)/32), int((voitures[idV].getPosition().getY()+16)/32)))) == '/') {
            voitures[idV].setVitesse(8);
        }
        else {
            voitures[idV].setVitesse(4);
        }

    }
    return col;
}

bool JeuSdl::sourisCoEntre(Vect2D X, Vect2D Y, Vect2D pos) {
    return (((X.getX() <= pos.getX()) && (pos.getX() <= Y.getX()))  &&  ((X.getY() <= pos.getY()) && (pos.getY() <= Y.getY())));
}

bool JeuSdl::est_fini() { // Vrai si toute les voitures sont invisibles
    bool fin = true;
    for(unsigned int i = 0; i < 4; i++) {
        if(voitures[i].getVisible()) {
            fin = false;
        }
    }
    return fin;
}

void JeuSdl::fin(SDL_Window* main, SDL_Renderer* renderer) {
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("data/times.ttf", 100);
    SDL_Color noir = {0, 0, 0};
    SDL_Surface* tempsS;
    SDL_Texture* tempsT;

    float tabTemps[4];
    for(int i = 0; i < 4; i++) { // Init tabTemps
        tabTemps[i] = voitures[i].getTemps();
    }
    int tabTempsSize = sizeof(tabTemps) / sizeof(tabTemps[0]); // Recupere la taille du tableau
    std::sort(tabTemps, tabTemps + tabTempsSize); // Trie tout le tableau par temps

    SDL_RenderClear(renderer);
    SDL_Rect tabVRect[nb_voitures];
    SDL_Rect tabTRect[nb_voitures];
    for(int i = 0; i < nb_voitures; i++) { // Affiche le classement des voitures avec leurs temps
        
        tabVRect[i] = {690, int(i*1080/nb_voitures), int(1080/nb_voitures), int(1080/(nb_voitures*1.8))};
        SDL_RenderCopy(renderer, voitures[nb_voitures - 1 - i].getTexture(), NULL, &tabVRect[i]);

        tabTRect[i] = {1000, i*270, 270, 152};
        tempsS = TTF_RenderText_Blended(font, std::to_string(tabTemps[i]).substr(0, std::to_string(tabTemps[i]).size() - 4).c_str(), noir);
        tempsT = SDL_CreateTextureFromSurface(renderer, tempsS);
        SDL_RenderCopy(renderer, tempsT, NULL, &tabTRect[i]);
    }

    SDL_FreeSurface(tempsS);

    SDL_RenderPresent(renderer);
    SDL_Delay(4000); // Delai avant de relancer une partie
    TTF_CloseFont(font);
    TTF_Quit();
}

Terrain& JeuSdl::getTerrain() {
    return terrain;
}

Voiture& JeuSdl::getVoiture(unsigned int i) {
    return voitures[i];
}

void JeuSdl::setVoiture(unsigned int i, const Voiture &V) {
    voitures[i] = V;
}

unsigned int JeuSdl::getNbTour() const{
    return nb_tour;
}

void JeuSdl::setNbTour(unsigned int nb_tour_) {
    nb_tour = nb_tour_;
}

unsigned int JeuSdl::getNbVoitures() const{
    return nb_voitures;
}

void JeuSdl::setNbVoitures(unsigned int nb_voitures_) {
    nb_voitures = nb_voitures_;
}

void JeuSdl::stopInvisible() {
    for(unsigned int i = 0; i < 4; i++) {
        if(!voitures[i].getVisible()) {
            voitures[i].setVitesse(0);
        }
    }
}