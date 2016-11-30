#include "Equipe.h"

Equipe::Equipe()
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

Equipe::~Equipe()
{
	//NOP
}

Club* Equipe::leClubEquipe()
{
	return clubEquipe;
}

int Equipe::leNbJoueurs()
{
	return nbJoueurs;
}

int Equipe::leNbGardiens()
{
	return nbGardiens;
}

Joueur* Equipe::leCapitaine()
{
	return capitaine;
}