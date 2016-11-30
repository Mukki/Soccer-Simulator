#pragma once
#ifndef NEGOCIATEUR_H
#define NEGOCIATEUR_H

#include "Club.h"
#include "Negociation.h"

using namespace std;

class Negociateur
{
	friend class Negociation;

private:
	float montantMax;
	float montantMin;
	int duree;
	Club* representantClub;
	queue<Message*>* msg;
	
public:
	//Constructeurs
	Negociateur(void);
	Negociateur(float, float, int, Club*);

	//Destructeur
	~Negociateur();

	//Accesseurs GET
	float getMontantMax() { return montantMax; }
	float getMontantMin() { return montantMin; }
	int getDuree() { return duree; }
	Club* getClub() { return representantClub; }

	//Autres fonctions
	virtual float negocier();
};
#endif