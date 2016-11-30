#pragma once
#ifndef CALENDRIER_H
#define CALENDRIER_H

#include <vector>
#include <string>
#include "Rencontre.h"

using namespace std;

class Calendrier
{
private:
	vector<Rencontre*> vect_rencontre;

public:
	Calendrier();
	~Calendrier();

	Rencontre* laRencontre(int i);
	Date laDate(int i);
	string leNomClubLocal(int i);
	string leNomClubVisiteur(int i);
	int leNbRencontre();

	void ajoutRencontre(Rencontre* uneRencontre);
};
#endif