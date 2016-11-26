#pragma once
#ifndef MATCH_H
#define MATCH_H

#include "Equipe.h"
#include "Periode.h"
#include "Resultat.h"

class Match
{
private:
	Equipe equipeLocale;
	Equipe equipeVisiteur;
	Periode premierePer;
	Periode deuxiemePer;
	Resultat resultatFinal;

public:
	//Constructeurs
	Match(void);
	Match(Equipe, Equipe, Periode, Periode, Resultat);

	//Accesseurs GET
	Equipe getEquipeLocale() { return equipeLocale; }
	Equipe getEquipeVisiteur() { return equipeVisiteur; }
	Periode getPremierePer() { return premierePer; }
	Periode getDeuxiemePer() { return deuxiemePer; }
	Resultat getResultat() { return resultatFinal; }
};
#endif