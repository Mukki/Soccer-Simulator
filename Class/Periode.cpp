#include "Periode.h"

//Constructeurs
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