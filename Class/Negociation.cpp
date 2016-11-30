#include "Negociation.h"

Negociation::Negociation()
{
	//NOP
}

Negociation::~Negociation()
{
	delete newMsg;
}

void Negociation::proposerOffre(float montantPrec, queue<Message*>* autreBteMsg, int techniqueNego, float* montantCourant)
{
	montantPrec = *montantCourant;

	switch (techniqueNego)
	{
	case 0:			//Garder l'offre identique
		//nop
		break;
	case 1:			//Diminuer par un facteur 25
		montantPrec = montantPrec - (montantPrec / 25);
		break;
	case 2:			//Augmenter par un facteur 25
		montantPrec = montantPrec + (montantPrec / 25);
		break;
	case 3:			//Diminuer par un facteur 10
		montantPrec = montantPrec - (montantPrec / 10);
		break;
	case 4:			//Augmenter par un facteur 10
		montantPrec = montantPrec + (montantPrec / 10);
		break;
	}
	newMsg = new Message(0, montantPrec);	//Si le type est 0, il s'agit d'une offre
	autreBteMsg->push(newMsg);
	*montantCourant = montantPrec;

	mutex.lock();
	affichage.afficherOffre(montantPrec);
	mutex.unlock();
}

void Negociation::accepterOffre(float montantPrec, queue<Message*>* autreBteMsg)
{
	newMsg = new Message(1, montantPrec);							//Si le type est 1, il s'agit d'une acceptation
	autreBteMsg->push(newMsg);

	mutex.lock();
	affichage.afficherAcceptation(montantPrec);
	mutex.unlock();
}

void Negociation::rejeterOffre(float montantPrec, queue<Message*>* autreBteMsg)
{
	newMsg = new Message(2, montantPrec);					//Si le type est 2, il s'agit d'un refus
	autreBteMsg->push(newMsg);

	mutex.lock();
	affichage.afficherRefus(montantPrec);
	mutex.unlock();
}