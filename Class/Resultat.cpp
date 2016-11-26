#include "Resultat.h"

//Constructeurs
Resultat::Resultat(void)
{
	//NOP
}

Resultat::Resultat(int nbButsLocaux, int nbButsVisiteurs)
{
	this->nbButsLocaux = nbButsLocaux;
	this->nbButsVisiteurs = nbButsVisiteurs;
}