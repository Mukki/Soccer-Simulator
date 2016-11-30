#include "Periode.h"

Periode::Periode(void)
{
	//NOP
}

Periode::Periode(int duree, int nbButsLocaux, int nbButsVisiteurs)
{
	this->duree = duree;
	this->nbButsLocaux = nbButsLocaux;
	this->nbButsVisiteurs = nbButsVisiteurs;
}

Periode::~Periode()
{
	//NOP
}

int Periode::laDuree()
{
	return duree;
}

int Periode::leNbButsLocaux()
{
	return nbButsLocaux;
}

int Periode::leNbButsVisiteurs()
{
	return nbButsVisiteurs;
}