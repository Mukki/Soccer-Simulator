#include "NegoVendeur.h"

NegoVendeur::NegoVendeur(void)
{

}

NegoVendeur::NegoVendeur(float montantMax, float montantMin, int duree, Club* representantClub, queue<Message*>* msgVendeur, queue<Message*>* msgAcheteur, int* flag, float* montantNego) : Negociateur(montantMax, montantMin, duree, representantClub)
{
	maBteMsg = msgVendeur;
	autreBteMsg = msgAcheteur;
	montantCourant = new float(NegoVendeur::getMontantMax());
	montantNego = new float();
	flag = new int();
}

NegoVendeur::~NegoVendeur()
{
	while (!maBteMsg->empty())
		maBteMsg->pop();

	while (!autreBteMsg->empty())
		autreBteMsg->pop();
}

float NegoVendeur::negocier()
{
	Message* msgTmp;
	Negociation uneNegociation;
	clock_t start;
	double chrono;

	start = clock();

	while (true)
	{
		chrono = (std::clock() - start) / (double)CLOCKS_PER_SEC;

		if (!maBteMsg->empty())
		{
			msgTmp = maBteMsg->front();
			maBteMsg->pop();
			if (msgTmp->getType() == 0)			//S'il s'agit d'une offre (0)
			{
				if (msgTmp->getMontant() < NegoVendeur::getMontantMin())		//Si le montant offert par l'acheteur est einférieur au montant minimal désiré du vendeur, faire une contre offre
				{
					uneNegociation.proposerOffre(msgTmp->getMontant(), autreBteMsg, 1, montantCourant);
				}
				else if (((msgTmp->getMontant() <= NegoVendeur::getMontantMax()) && (msgTmp->getMontant() >= NegoVendeur::getMontantMin())) || (msgTmp->getMontant() >= NegoVendeur::getMontantMax()))		//Si le montant offert par l'acheteur est entre le montant min et max, accepter
				{
					uneNegociation.accepterOffre(msgTmp->getMontant(), autreBteMsg);
					*flag = 0;
					break;
				}
				else		//Sinon refuser
				{
					uneNegociation.rejeterOffre(msgTmp->getMontant(), autreBteMsg);
					*flag = 1;
					break;
				}
			}
			else if (msgTmp->getType() == 1)		//S'il s'agit d'une acceptation (1)
			{
				//Faire le transfert
				break;
			}
			else if (chrono >= NegoVendeur::getDuree())		//Si la negociation excède la durée du Mercator
			{
				uneNegociation.rejeterOffre(msgTmp->getMontant(), autreBteMsg);
				*flag = 1;
				break;
			}
			else								//S'il s'agit d'un refus (2)
			{
				break;
			}
		}
	}
	return msgTmp->getMontant();
}