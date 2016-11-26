#include "Joueur.h"
#include "Sportif.h"

Joueur::Joueur()
{
	//NOP
}

//Constructeur Joueur
Joueur::Joueur(string j_nom, string j_prenom, float taille, float poids, string villeNaissance) : Sportif(j_prenom, j_nom)
{
	this->taille = taille;
	this->poids = poids;
	this->villeNaissance = villeNaissance;
}

void Joueur::ajoutParcours(string nomClub, Date datePassage)
{
	vect_parcours.push_back(Parcours(nomClub, datePassage));
}

//Accesseur GET
string Joueur::getNom() { return nom; }
string Joueur::getPrenom() { return prenom; }
float Joueur::getTaille() { return taille; }
float Joueur::getPoids() { return poids; }
string Joueur::getVilleNaissance() { return villeNaissance; }

float Joueur::briserContrat()
{
	return 0;
}
