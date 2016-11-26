#include "Equipe.h"

//Constructeurs
Equipe::Equipe(void)
{
	//NOP
}

Equipe::Equipe(Club* clubEquipe, int nbJoueurs, int nbGardiens, Joueur* capitaine)
{
	this->clubEquipe = clubEquipe;
	this->nbJoueurs = nbJoueurs;
	this->nbGardiens = nbGardiens;
	this->capitaine = capitaine;
}

//Accesseurs GET
Club* Equipe::getClubEquipe()
{
	return clubEquipe;
}

int Equipe::getNbJoueurs()
{
	return nbJoueurs;
}

int Equipe::getNbGardiens()
{
	return nbGardiens;
}

Joueur* Equipe::getCapitaine()
{
	return capitaine;
}