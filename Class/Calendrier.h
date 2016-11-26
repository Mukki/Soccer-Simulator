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
	//Constructeur
	Calendrier(void);

	//Destructeur
	~Calendrier();

	//Accesseur GET
	Rencontre* getRencontre(int);
	string getDate(int);
	string getNomClubLocal(int);
	string getNomClubVisit(int);
	int getSizeof();

	//Ajouter une rencontre
	void ajoutRencontre(Rencontre*);
};
#endif