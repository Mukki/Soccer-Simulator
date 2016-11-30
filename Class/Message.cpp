#include "Message.h"

Message::Message()
{
	//NOP
}

/* Si type = 0, il s'agit d'une offre
Si type = 1, il s'agit d'une offre accept�e
Si type = 2, il s'agit d'une offre refus�e */

Message::Message(int type, float montant)
{
	this->type = type;
	this->montant = montant;
}

Message::~Message()
{
	//NOP
}

int Message::leType()
{
	return type;
}

float Message::leMontant()
{
	return montant;
}