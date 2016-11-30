#include "Contrat.h"

Contrat::Contrat()
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

Joueur* Contrat::leJoueurContractant()
{
	return joueurContractant;
}

Club* Contrat::leClubContractant()
{
	return clubContractant;
}

Club* Contrat::leClubLibere()
{
	return clubLibere;
}

int Contrat::laDureeContrat()
{
	return dureeContrat;
}

Date Contrat::laDateEntree()
{
	return dateEntree;
}

Reglement Contrat::leReglement()
{
	return reglement;
}

Date Contrat::laDateContrat()
{
	return dateContrat;
}