#include "Reglement.h"

//Constructeurs
Reglement::Reglement(void)
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

//Accesseurs GET
float Reglement::getSeuil()
{
	return seuil;
}

string Reglement::getDroits()
{
	return droits;
}

float Reglement::getMontantTransfert()
{
	return montantTransfert;
}

float Reglement::getMontantEncaisse() 
{
	return montantEncaisse;
}

float Reglement::getMontantRestant()
{
	return montantRestant;
}