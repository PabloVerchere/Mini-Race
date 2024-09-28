Projet LIFAPCD - Mini Race
GISPERT Florent, VERCHERE Pablo

Jeu de voiture, camera de dessus (ex : https://en.wikipedia.org/wiki/Super_Sprint).
Touche de jeu : 
    J1: ZQSD
    J2:8456

Documentation:
    Ouvrir le fichier doc/html/index.html

Mode Texte:
    Fonctionnalitees:
        Jouable a 2 sur un seul terrain, un seul tour.
        A la fin de la partie, les voitures disparaisse. Il faut executer "Ctrl + C" puis relancer "bin/Texte".

    Pour jouer:
        Se placer dans la racine du jeu.
        Executer "bin/Texte" dans un terminal.


Mode Graphique:
    Fonctionnalitees:
        Jouable seul, a 2, a 2 avec 1 ou 2 bots. Sur 4 differents terrain, sur un nombre de tours choisit.
        Le classement et le temps est affiche durant la partie, et a la fin un classement s'affiche avec le temps de chacun.
        Puis on revient sur le menu pour relancer une partie

    Pour jouer:
        Se placer dans la racine du jeu.
        Executer "bin/Sdl" dans un terminal.


En cas de probleme:
    Se placer dans la racine du jeu.
    Executer "make clean" dans un terminal, puis make.

    PS:
        Les warning du make sont du a l'utilisation de la librairies conio.h utilisee dans le mode Texte 