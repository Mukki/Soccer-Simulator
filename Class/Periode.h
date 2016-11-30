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
	Periode();
	Periode(int duree, int nbButsLocaux, int nbButsVisiteurs);
	~Periode();

	int laDuree();
	int leNbButsLocaux();
	int leNbButsVisiteurs();
};
#endif