#include "Negociateur.h"

Negociateur::Negociateur(void)
{

}

Negociateur::Negociateur(float montantMax, float montantMin, int duree, Club* representantClub)
{
	this->montantMax = montantMax;
	this->montantMin = montantMin;
	this->duree = duree;
	this->representantClub = representantClub;
}

Negociateur::~Negociateur()
{
	delete representantClub;
}

float Negociateur::negocier()
{
	return 0.0f;
}
