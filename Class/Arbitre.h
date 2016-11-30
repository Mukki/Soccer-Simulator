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
	Arbitre();
	Arbitre(string nom, string prenom, string lieuObt, int experience);
	~Arbitre();

	string leLieuObt();
	int lExperience();
};
#endif