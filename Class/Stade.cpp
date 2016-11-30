#include "Stade.h"

Stade::Stade()
{
	//NOP
}

Stade::Stade(int nbPlaces, string terrain, string adresse, string nomStade) 
{
	this->nbPlaces = nbPlaces;
	this->terrain = terrain;
	this->adresse = adresse;
	this->nomStade = nomStade;
}

Stade::~Stade()
{
	//NOP
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