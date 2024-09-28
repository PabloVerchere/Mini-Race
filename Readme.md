# Projet LIFAPCD - Mini Race

**GISPERT Florent, VERCHERE Pablo**
Jeu de voiture, camera de dessus type [Super_Sprint](https://en.wikipedia.org/wiki/Super_Sprint).

## Documentation
Ouvrir le fichier ``./doc/html/index.html``

## Touche de jeu
	Joueur 1: ZQSD
    Joueur 2: 8456


# Fonctionnalitées
## Mode Texte
Jouable à 2 sur un seul terrain, un seul tour.
A la fin de la partie, les voitures disparaisse. Il faut executer ``Ctrl + C`` puis relancer ``./bin/Texte``

**Pour jouer**
Se placer dans la racine du jeu.
Executer ``./bin/Texte`` dans un terminal.


## Mode Graphique
Jouable seul, à 2, avec 0, 1 ou 2 bots. Sur 4 differents terrain, sur un nombre de tours choisit.
Le classement et le temps est affiche durant la partie, à la fin un classement s'affiche avec le temps de chacun.
Puis on revient sur le menu pour relancer une partie.

**Pour jouer**
Se placer dans la racine du jeu.
Executer ``bin/Sdl`` dans un terminal.


## En cas de probleme
Se placer dans la racine du jeu.
Executer ``make clean`` dans un terminal, puis ``make``

**PS:** Les warning du ``make`` sont du à l'utilisation de la librairies ``conio.h`` utilisée dans le **mode Texte**.