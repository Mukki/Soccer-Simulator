#pragma once
#ifndef MESSAGE_H
#define MESSAGE_H

class Message {
private:
	int type;
	float montant;
public:
	//Constructeurs
	Message(void);
	Message(int, float);

	//Accesseur
	int getType() { return type; }
	float getMontant() { return montant; }
};

#endif