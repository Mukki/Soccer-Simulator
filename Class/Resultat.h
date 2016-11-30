#pragma once
#ifndef RESULTAT_H
#define RESULTAT_H

class Resultat
{
private:
	int nbButsLocaux;
	int nbButsVisiteurs;

public:
	Resultat();
	Resultat(int nbButsLocaux, int nbButsVisiteurs);
	~Resultat();

	int leNbButsLocaux();
	int leNbButsVisiteurs();
};
#endif