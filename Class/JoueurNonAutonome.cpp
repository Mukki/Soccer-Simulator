#include "JoueurNonAutonome.h"

//Constructeurs
JoueurNonAutonome::JoueurNonAutonome(void)
{
	//NOP
}

JoueurNonAutonome::JoueurNonAutonome(string ja_prenom, string ja_nom, float taille, float poids, string villeNaissance) : Joueur(ja_prenom, ja_nom, taille, poids, villeNaissance)
{
	//NOP
}

//Accesseurs GET
float JoueurNonAutonome::getTaille()
{
	return Joueur::getTaille();
}

float JoueurNonAutonome::getPoids()
{
	return Joueur::getPoids();
}

string JoueurNonAutonome::getVilleNaissance()
{
	return Joueur::getVilleNaissance();
}

float JoueurNonAutonome::briserContrat()
{
	return penalite;
}