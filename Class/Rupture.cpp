#include "Rupture.h"

Rupture::Rupture(void)
{
	//NOP
}

Rupture::Rupture(Joueur* unJoueurAutonome, string raisonDepart, Club* nouveauClub, float penalite)
{
	this->unJoueurAutonome = unJoueurAutonome;
	this->raisonDepart = raisonDepart;
	this->nouveauClub = nouveauClub;
	this->penalite = penalite;
}