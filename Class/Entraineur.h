#pragma once
#ifndef ENTRAINEUR_H_
#define ENTRAINEUR_H_

#include <string>
#include "Palmares.h"
#include <vector>
#include "Date.h"
#include "Club.h"
#include "Sportif.h"
#include "Employe.h"

class Entraineur : public Sportif, public Employe
{
private:
	string lieuObtention;
	vector<Palmares> vect_titre;

public:
	Entraineur();
	Entraineur(string nom, string prenom, string lieu, float salaireHoraire = 0, float salaireAnnuel = 0);
	~Entraineur();

	string lelieuObtention();
	int leNbPalmares();
	Palmares* lePalmares(int i);

	void ajouterPalmares(string titre, string jours, string mois, string annee, Club* club);
};
#endif