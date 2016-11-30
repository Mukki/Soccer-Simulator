#include "Employe.h"

Employe::Employe()
{
	//NOP
}

Employe::Employe(float salaireHoraire, float salaireAnnuel)
{
	this->salaireHoraire = salaireHoraire;
	this->salaireAnnuel = salaireAnnuel;
}

Employe::~Employe()
{
	//NOP
}

float Employe::leSalaireHoraire()
{
	return salaireHoraire;
}

float Employe::leSalaireAnnuel()
{
	return salaireAnnuel;
}