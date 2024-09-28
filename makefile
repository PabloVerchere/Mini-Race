all: bin/Texte bin/Sdl


obj/Vect2D.o: src/Vect2D.cpp src/Vect2D.h
	g++ -c -o obj/Vect2D.o src/Vect2D.cpp
	
obj/Terrain.o: src/Terrain.cpp src/Terrain.h src/Vect2D.h
	g++ -c -o obj/Terrain.o src/Terrain.cpp

obj/Voiture.o: src/Voiture.cpp src/Voiture.h src/Terrain.h src/Vect2D.h
	g++ -c -o obj/Voiture.o src/Voiture.cpp



obj/Jeu.o: src/Jeu.cpp src/Jeu.h src/Voiture.h src/Terrain.h src/Vect2D.h 
	g++ -c -o obj/Jeu.o src/Jeu.cpp

obj/mainTexte.o: src/mainTexte.cpp src/Jeu.h src/Voiture.h  src/Terrain.h src/Vect2D.h
	g++ -c -o obj/mainTexte.o src/mainTexte.cpp

bin/Texte: obj/mainTexte.o obj/Jeu.o obj/Voiture.o obj/Terrain.o obj/Vect2D.o 
	g++ -no-pie -o bin/Texte obj/mainTexte.o obj/Jeu.o obj/Voiture.o obj/Terrain.o obj/Vect2D.o



obj/JeuSdl.o: src/JeuSdl.cpp src/JeuSdl.h src/Voiture.h src/Terrain.h src/Vect2D.h
	g++ -c -o obj/JeuSdl.o src/JeuSdl.cpp -lSDL2 -lSDL2_image -lSDL2_ttf

obj/mainSdl.o: src/mainSdl.cpp src/JeuSdl.h src/Voiture.h src/Terrain.h src/Vect2D.h
	g++ -c -o obj/mainSdl.o src/mainSdl.cpp -lSDL2 -lSDL2_image -lSDL2_ttf


bin/Sdl: obj/mainSdl.o obj/JeuSdl.o obj/Voiture.o obj/Terrain.o obj/Vect2D.o
	g++ -no-pie -o bin/Sdl obj/mainSdl.o obj/JeuSdl.o obj/Voiture.o obj/Terrain.o obj/Vect2D.o -lSDL2 -lSDL2_image -lSDL2_ttf



clean:
	rm -f obj/* bin/*
