#include "Joueur.h"
#include "Sportif.h"

Joueur::Joueur()
{
	//NOP
}

Joueur::Joueur(string nom, string prenom, float taille, float poids, string villeNaissance) : Sportif(nom, prenom)
{
	this->taille = taille;
	this->poids = poids;
	this->villeNaissance = villeNaissance;
}

Joueur::~Joueur()
{
	//NOP
}

string Joueur::leNom()
{
	return nom;
}

string Joueur::lePrenom()
{
	return prenom;
}

float Joueur::laTaille()
{
	return taille;
}

float Joueur::lePoids()
{
	return poids;
}

string Joueur::laVilleNaissance()
{
	return villeNaissance;
}

void Joueur::ajoutParcours(string nomClub, Date datePassage)
{
	vect_parcours.push_back(Parcours(nomClub, datePassage));
}

float Joueur::briserContrat()
{
	return 0;
}