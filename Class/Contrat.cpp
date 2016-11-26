#include "Contrat.h"

//Constructeurs
Contrat::Contrat(void)
{
	//NOP
}

Contrat::Contrat(Joueur* joueurContractant, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Reglement reglement, Date dateContrat)
{
	this->joueurContractant = joueurContractant;
	this->clubContractant = clubContractant;
	this->clubLibere = clubLibere;
	this->dureeContrat = dureeContrat;
	this->dateEntree = dateEntree;
	this->reglement = reglement;
	this->dateContrat = dateContrat;
}

Contrat::Contrat(const Contrat & recopie)
{
	this->clubContractant = recopie.clubContractant;
	this->clubLibere = recopie.clubLibere;
	this->dateContrat = recopie.dateContrat;
	this->joueurContractant = recopie.joueurContractant;
	this->dureeContrat = recopie.dureeContrat;
	this->dateEntree = recopie.dateEntree;
	this->reglement = recopie.reglement;
}

Contrat::~Contrat()
{
	//NOP
}

//Accesseurs GET
Joueur* Contrat::getJoueurContractant()
{
	return joueurContractant;
}

Club* Contrat::getClubContractant()
{
	return clubContractant;
}

Club* Contrat::getClubLibere()
{
	return clubLibere;
}

int Contrat::getDureeContrat()
{
	return dureeContrat;
}

Date Contrat::getDateEntree()
{
	return dateEntree;
}

Reglement Contrat::getReglement()
{
	return reglement;
}

Date Contrat::getDateContrat()
{
	return dateContrat;
}

void Contrat::setdUnCoup(Joueur* joueurContractant, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Reglement reglement, Date dateContrat)
{
	this->clubContractant = clubContractant;
	this->clubLibere = clubLibere;
	this->dateContrat = dateContrat;
	this->joueurContractant = joueurContractant;
	this->dureeContrat = dureeContrat;
	this->dateEntree = dateEntree;
	this->reglement = reglement;
}
