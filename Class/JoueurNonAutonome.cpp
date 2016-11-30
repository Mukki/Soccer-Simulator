#include "JoueurNonAutonome.h"

JoueurNonAutonome::JoueurNonAutonome(void)
{
	//NOP
}

JoueurNonAutonome::JoueurNonAutonome(string nom, string prenom, float taille, float poids, string villeNaissance) : Joueur(nom, prenom, taille, poids, villeNaissance)
{
	//NOP
}

JoueurNonAutonome::~JoueurNonAutonome()
{
	//NOP
}

float JoueurNonAutonome::briserContrat()
{
	return penalite;
}