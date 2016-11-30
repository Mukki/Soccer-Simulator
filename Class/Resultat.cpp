#include "Resultat.h"

Resultat::Resultat()
{
	//NOP
}

Resultat::Resultat(int nbButsLocaux, int nbButsVisiteurs)
{
	this->nbButsLocaux = nbButsLocaux;
	this->nbButsVisiteurs = nbButsVisiteurs;
}

Resultat::~Resultat()
{
	//NOP
}

int Resultat::leNbButsLocaux()
{
	return nbButsLocaux;
}

int Resultat::leNbButsVisiteurs()
{
	return nbButsVisiteurs;
}