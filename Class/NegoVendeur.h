#pragma once
#pragma once
#ifndef NEGOVENDEUR_H
#define NEGOVENDEUR_H

#include <mutex>
#include <queue>
#include <ctime>
#include "Negociation.h"
#include "Negociateur.h"
#include "NegoAcheteur.h"
#include "Message.h"

using namespace std;

typedef chrono::high_resolution_clock Clock;

class NegoVendeur : public Negociateur
{
private:
	queue<Message*>* maBteMsg;
	queue<Message*>* autreBteMsg;
	float* montantCourant;
	mutex mutex;
	int* flag;
	float* montantNego;
public:
	//Constructeurs
	NegoVendeur(void);
	NegoVendeur(float, float, int, Club*, queue<Message*>*, queue<Message*>*, int*, float*);

	//Destructeur
	~NegoVendeur();

	//Accesseurs GET
	float getMontantMax() { return Negociateur::getMontantMax(); }
	float getMontantMin() { return Negociateur::getMontantMin(); }
	int getDuree() { return Negociateur::getDuree(); }
	Club* getClub() { return Negociateur::getClub(); }

	//Negociation
	float negocier();
};

#endif