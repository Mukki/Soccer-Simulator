#pragma once
#ifndef RESULTAT_H
#define RESULTAT_H

class Resultat
{
private:
	int nbButsLocaux;
	int nbButsVisiteurs;

public:
	//Constructeurs
	Resultat(void);
	Resultat(int, int);

	//Accesseurs GET
	int getNbButsLocaux() { return nbButsLocaux; }
	int getNbButsVisiteurs() { return nbButsVisiteurs; }
};
#endif