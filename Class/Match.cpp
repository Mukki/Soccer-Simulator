#include "Match.h"

Match::Match(void)
{
	//NOP
}

Match::Match(Equipe equipeLocale, Equipe equipeVisiteur, Periode premierePer, Periode deuxiemePer, Resultat resultatFinal)
{
	this->equipeLocale = equipeLocale;
	this->equipeVisiteur = equipeVisiteur;
	this->premierePeriode = premierePer;
	this->deuxiemePeriode = deuxiemePer;
	this->resultatFinal = resultatFinal;
}

Match::~Match()
{
	//NOP
}

Equipe Match::lEquipeLocale()
{
	return equipeLocale;
}

Equipe Match::lEquipeVisiteur()
{
	return equipeVisiteur;
}

Periode Match::laPremierePeriode()
{
	return premierePeriode;
}

Periode Match::laDeuxiemePeriode()
{
	return deuxiemePeriode;
}

Resultat Match::leResultatFinal()
{
	return resultatFinal;
}