#include "JoueurAutonome.h"

//Constructeurs
JoueurAutonome::JoueurAutonome(void)
{
	//NOP
}

JoueurAutonome::JoueurAutonome(string ja_prenom, string ja_nom, float taille, float poids, string villeNaissance) : Joueur(ja_prenom, ja_nom, taille, poids, villeNaissance)
{
	//NOP
}

//Accesseurs GET
float JoueurAutonome::getTaille()
{
	return Joueur::getTaille();
}

float JoueurAutonome::getPoids()
{
	return Joueur::getPoids();
}

string JoueurAutonome::getVilleNaissance() 
{
	return Joueur::getVilleNaissance();
}

float JoueurAutonome::briserContrat()
{
	return penalite;
}