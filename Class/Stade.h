#ifndef STADE_H
#define STADE_H

#include <string>

using namespace std;

class Stade
{
private:
	int nbPlaces;
	string terrain;
	string adresse;
	string nomStade;

public:
	Stade();
	Stade(int placesStade, string terrainStade, string addrStade, string nameStade);
	~Stade();

	int leNbPlaces();
	string leTerrain();
	string lAdresse();
	string leNom();
};
#endif