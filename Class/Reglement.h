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
	Reglement();
	Reglement(float, string, float, float, float);
	~Reglement();

	float leSeuil();
	string lesDroits();
	float leMontantTransfert();
	float leMontantEncaisse();
	float leMontantRestant();
};
#endif