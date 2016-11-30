#pragma once
#ifndef MESSAGE_H
#define MESSAGE_H

class Message
{
private:
	int type;
	float montant;

public:
	Message();
	Message(int type, float montant);
	~Message();

	int leType();
	float leMontant();
};
#endif