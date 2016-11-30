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
	Rupture();
	Rupture(Joueur*, string, Club*, float);
	~Rupture();

	Joueur* leJoueur();
	string laRaisonDepart();
	Club* leNouveauClub();
	float laPenalite();
};
#endif