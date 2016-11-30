#pragma once
#ifndef NEGOCIATION_H
#define NEGOCIATION_H

#include <queue>
#include <mutex>

#include "Message.h"
#include "AffichageNegociation.h"

using namespace std;

class Negociateur;

class Negociation
{
private:
	Message* newMsg;
	AffichageNegociation affichage;
	mutex mutex;

public:
	Negociation();
	~Negociation();

	void proposerOffre(float, queue<Message*>*, int, float*);
	void accepterOffre(float, queue<Message*>*);
	void rejeterOffre(float, queue<Message*>*);
};
#endif