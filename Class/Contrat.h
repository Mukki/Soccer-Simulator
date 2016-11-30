#pragma once
#ifndef CONTRAT_H
#define CONTRAT_H

#include "Reglement.h"
#include "Date.h"
#include "Club.h"

using namespace std;

class Contrat
{
private:
	Joueur* joueurContractant;
	Club* clubContractant;
	Club* clubLibere;
	int dureeContrat;
	Date dateEntree;
	Reglement reglement;
	Date dateContrat;

public:
	Contrat();
	Contrat(Joueur* joueurContractant, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Reglement reglement, Date dateContrat);
	Contrat(const Contrat& recopie);
	~Contrat();

	Joueur* leJoueurContractant();
	Club* leClubContractant();
	Club* leClubLibere();
	int laDureeContrat();
	Date laDateEntree();
	Reglement leReglement();
	Date laDateContrat();
};
#endif