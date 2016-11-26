#pragma once
#ifndef PARCOURS_H_
#define PARCOURS_H_
#include <string>
#include "Date.h"

using namespace std;
class Parcours
{
private:
	//Variables Parcours
	string nomClub;
	Date datePassage;

public:
	//Constructeur
	Parcours(string, Date);
	//Retourne nom du club
	string getClub();
	//Retourne la date
	Date getDate();
};
#endif
