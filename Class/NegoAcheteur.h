#pragma once
#ifndef NEGOACHETEUR_H
#define NEGOACHETEUR_H

#include <mutex>
#include <queue>
#include <ctime>
#include "Negociation.h"
#include "Negociateur.h"
#include "NegoVendeur.h"
#include "Message.h"

using namespace std;

class NegoAcheteur : public Negociateur
{
private:
	queue<Message*>* maBteMsg;
	queue<Message*>* autreBteMsg;
	float* montantCourant;
	mutex mutex;
	int* flag;
public:
	//Constructeurs
	NegoAcheteur(void);
	NegoAcheteur(float, float, int, Club*, queue<Message*>*, queue<Message*>*, int*);

	//Destructeur
	~NegoAcheteur();

	//Accesseurs GET
	float getMontantMax() { return Negociateur::getMontantMax(); }
	float getMontantMin() { return Negociateur::getMontantMin(); }
	int getDuree() { return Negociateur::getDuree(); }
	Club* getClub() { return Negociateur::getClub(); }

	//Negociation
	float negocier();
};

#endif