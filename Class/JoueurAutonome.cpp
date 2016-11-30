#include "JoueurAutonome.h"

JoueurAutonome::JoueurAutonome(void)
{
	//NOP
}

JoueurAutonome::JoueurAutonome(string nom, string prenom, float taille, float poids, string villeNaissance) : Joueur(nom, prenom, taille, poids, villeNaissance)
{
	//NOP
}

JoueurAutonome::~JoueurAutonome()
{
	//NOP
}

float JoueurAutonome::briserContrat()
{
	return penalite;
}