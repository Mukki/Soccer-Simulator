#pragma once
#ifndef NEGOCIATION_H
#define NEGOCIATION_H

#include <queue>

#include "Message.h"

/*A SUPPRIMER*/
#include <iostream>

using namespace std;

class Negociateur;

class Negociation {
private:
	Message* newMsg;
public:
	//Constructeur
	Negociation(void);

	//Destructeur
	~Negociation();

	//Methodes de communication
	void proposerOffre(float, queue<Message*>*, int, float*);
	void accepterOffre(float, queue<Message*>*);
	void rejeterOffre(float, queue<Message*>*);
};

#endif