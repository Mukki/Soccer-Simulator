#pragma once
#ifndef RUPTURE_H
#define RUPTURE_H

#include "JoueurAutonome.h"
#include "LigueSoccer.h"

class Rupture
{
private:
	Joueur* unJoueurAutonome;
	string raisonDepart;
	Club* nouveauClub;
	float penalite;

public:
	Rupture(void);
	Rupture(Joueur*, string, Club*, float);

	Joueur* getJoueur() { return unJoueurAutonome; }
	string getRaisonDepart() { return raisonDepart; }
	Club* getNouveauClub() { return nouveauClub; }
	float getPenalite() { return penalite; }
};
#endif