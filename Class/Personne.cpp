#include "Personne.h"

Personne::Personne()
{
	//NOP
}

Personne::Personne(string nom, string prenom, int age, string tache)
{
	this->nom = nom;
	this->prenom = prenom;
	this->age = age;
	this->tache = tache;
}

Personne::~Personne()
{
	//NOP
}

string Personne::leNom()
{
	return nom;
}

string Personne::lePrenom()
{
	return prenom;
}

int Personne::lAge()
{
	return age;
}

string Personne::laTache()
{
	return tache;
}