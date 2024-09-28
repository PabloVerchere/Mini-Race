#include "Jeu.h"
#include <iostream>
#include "conio.h" // pour kbhit

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32


int main() { // attention conversion unsigned char - int + 48
  std::cout << "\033c"; // clear
  Jeu jeu("data/Terrain1.txt"); // Pas de selection de terrain ou du nombres de voitures dans ce mode ni d'IA

  for(int i =0; i<3; i++) { // Set a 4 par default mais doit etre a 1 ici, pas de boost non plus
    jeu.getVoiture(i).setVitesse(1);
  }

  sleep(2);

  bool run = true;
  while (run) {
    sleep(1);
    std::cout << "\033c"; //Clear

    jeu.MAJcpVoiture();
    jeu.afficherTxt(); // affichage

    char touche = ' '; // ne pas utiliser ' '
    if(kbhit()) { // si une touche est pressee
        touche = fgetc(stdin);
        run = jeu.mouvement(touche);
    }
  }

  return 0;
}