#pragma once
#ifndef CONTRAT_H
#define CONTRAT_H

#include "Reglement.h"
#include "Date.h"
#include "Club.h"

using namespace std;

class Contrat {
private:
	Joueur* joueurContractant;
	Club* clubContractant;
	Club* clubLibere;
	int dureeContrat;
	Date dateEntree;
	Reglement reglement;
	Date dateContrat;

public:
	//Constructeurs
	Contrat(void);
	Contrat(Joueur*, Club*, Club*, int, Date, Reglement, Date);
	Contrat(const Contrat& recopie);
	~Contrat();

	//Accesseurs GET
	Joueur* getJoueurContractant();
	Club* getClubContractant();
	Club* getClubLibere();
	int getDureeContrat();
	Date getDateEntree();
	Reglement getReglement();
	Date getDateContrat();

	//SET
	void setdUnCoup(Joueur* joueurContractant, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Reglement reglement, Date dateContrat);
};
#endif