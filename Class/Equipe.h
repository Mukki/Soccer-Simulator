#pragma once
#ifndef EQUIPE_H
#define EQUIPE_H

#include <string>
#include "Club.h"

using namespace std;

class Equipe
{
private:
	Club* clubEquipe;
	int nbJoueurs;
	int nbGardiens;
	Joueur* capitaine;

public:
	//Constructeurs
	Equipe(void);
	Equipe(Club*, int, int, Joueur*);

	//Accesseurs GET
	Club* getClubEquipe();
	int getNbJoueurs();
	int getNbGardiens();
	Joueur* getCapitaine();
};
#endif