#include "Stade.h"

Stade::Stade()
{
	nbPlaces = 0;
	terrain = "";
	adresse = "";
	nomStade = "";
}

Stade::Stade(int placesStade, string terrainStade, string addrStade, string nameStade) 
{
	nbPlaces = placesStade;
	terrain = terrainStade;
	adresse = addrStade;
	nomStade = nameStade;
}

Stade::~Stade() {
}

int Stade::leNbPlaces()
{
	return nbPlaces;
}

string Stade::leTerrain()
{
	return terrain;
}

string Stade::lAdresse()
{
	return adresse;
}

string Stade::leNom()
{
	return nomStade;
}