#pragma once
#ifndef PERIODE_H
#define PERIODE_H

class Periode
{
private:
	int duree;
	int nbButsLocaux;
	int nbButsVisiteurs;

public:
	//Constructeurs
	Periode(void);
	Periode(int, int, int);

	//Accesseurs GET
	int getDuree() { return duree; }
	int getNbButsLocaux() { return nbButsLocaux; }
	int getNbButsVisiteurs() { return nbButsVisiteurs; }
};
#endif