#pragma once
#ifndef REGLEMENT_H
#define REGLEMENT_H

#include <string>

using namespace std;

class Reglement
{
private:
	float seuil;
	string droits;
	float montantTransfert;
	float montantEncaisse;
	float montantRestant;

public:
	//Constructeurs
	Reglement(void);
	Reglement(float, string, float, float, float);

	//Accesseurs GET
	float getSeuil();
	string getDroits();
	float getMontantTransfert();
	float getMontantEncaisse();
	float getMontantRestant();
};
#endif