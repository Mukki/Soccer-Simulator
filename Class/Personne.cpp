#include "Personne.h"

Personne::Personne()
{
	nom = "";
	prenom = "";
	age = 0;
	tache = "";
}

Personne::Personne(string nomPers, string prenomPers, int agePers, string tachePers)
{
	nom = nomPers;
	prenom = prenomPers;
	age = agePers;
	tache = tachePers;
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