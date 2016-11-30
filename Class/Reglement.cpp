#include "Reglement.h"

Reglement::Reglement()
{
	//NOP
}

Reglement::Reglement(float seuil, string droits, float montantTransfert, float montantEncaisse, float montantRestant)
{
	this->seuil = seuil;
	this->droits = droits;
	this->montantTransfert = montantTransfert;
	this->montantEncaisse = montantEncaisse;
	this->montantRestant = montantRestant;
}

Reglement::~Reglement()
{
	//NOP
}

float Reglement::leSeuil()
{
	return seuil;
}

string Reglement::lesDroits()
{
	return droits;
}

float Reglement::leMontantTransfert()
{
	return montantTransfert;
}

float Reglement::leMontantEncaisse() 
{
	return montantEncaisse;
}

float Reglement::leMontantRestant()
{
	return montantRestant;
}