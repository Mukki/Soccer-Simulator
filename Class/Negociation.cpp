#include "Negociation.h"

Negociation::Negociation(void)
{

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


	/* ENLEVER LE COUT */
	cout << "Offre : " << montantPrec << "$" << endl << endl;
}

void Negociation::accepterOffre(float montantPrec, queue<Message*>* autreBteMsg)
{
	newMsg = new Message(1, montantPrec);							//Si le type est 1, il s'agit d'une acceptation
	autreBteMsg->push(newMsg);

	/* ENLEVER LE COUT */
	cout << "Acceptation : " << montantPrec << "$" << endl << endl;
}

void Negociation::rejeterOffre(float montantPrec, queue<Message*>* autreBteMsg)
{
	newMsg = new Message(2, montantPrec);					//Si le type est 2, il s'agit d'un refus
	autreBteMsg->push(newMsg);

	/* ENLEVER LE COUT */
	cout << "Refus : " << montantPrec << "$" << endl << endl;
}
