#include "Sportif.h"

Sportif::Sportif()
{
	//NOP
}

Sportif::Sportif(string nom, string prenom)
{
	this->nom = nom;
	this->prenom = prenom;
}

Sportif::~Sportif()
{
	//NOP
}

string Sportif::leNom()
{
	return nom;
}

string Sportif::lePrenom()
{
	return prenom;
}