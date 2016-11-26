#pragma once
#ifndef ARBITRE_H
#define ARBITRE_H

#include <string>
#include "Sportif.h"

using namespace std;

class Arbitre : public Sportif
{
private:
	string lieuObt;
	int experience;

public:
	//Constructeurs
	Arbitre(void);
	Arbitre(string, string, string, int);

	//Accesseurs GET
	string getNom();
	string getPrenom();
	string getLieuObt();
	int getExperience();
};
#endif