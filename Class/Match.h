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
	Periode premierePeriode;
	Periode deuxiemePeriode;
	Resultat resultatFinal;

public:
	Match();
	Match(Equipe equipeLocale, Equipe equipeVisiteur, Periode premierePeriode, Periode deuxiemePeriode, Resultat resultatFinal);
	~Match();

	Equipe lEquipeLocale();
	Equipe lEquipeVisiteur();
	Periode laPremierePeriode();
	Periode laDeuxiemePeriode();
	Resultat leResultatFinal();
};
#endif