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
	Equipe();
	Equipe(Club* clubEquipe, int nbJoueurs, int nbGardiens, Joueur* capitaine);
	~Equipe();

	Club* leClubEquipe();
	int leNbJoueurs();
	int leNbGardiens();
	Joueur* leCapitaine();
};
#endif