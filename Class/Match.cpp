#include "Match.h"

//Constructeurs
Match::Match(void)
{
	//NOP
}

Match::Match(Equipe equipeLocale, Equipe equipeVisiteur, Periode premierePer, Periode deuxiemePer, Resultat resultatFinal)
{
	this->equipeLocale = equipeLocale;
	this->equipeVisiteur = equipeVisiteur;
	this->premierePer = premierePer;
	this->deuxiemePer = deuxiemePer;
	this->resultatFinal = resultatFinal;
}