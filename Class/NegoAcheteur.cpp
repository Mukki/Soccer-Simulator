#include "NegoAcheteur.h"

NegoAcheteur::NegoAcheteur(void)
{

}

NegoAcheteur::NegoAcheteur(float montantMax, float montantMin, int duree, Club* representantClub, queue<Message*>* msgVendeur, queue<Message*>* msgAcheteur, Joueur* joueurEchange) : Negociateur(montantMax, montantMin, duree, representantClub)
{
	maBteMsg = msgAcheteur;
	autreBteMsg = msgVendeur;
	montantCourant = new float(NegoAcheteur::getMontantMin());
}

NegoAcheteur::~NegoAcheteur()
{
	while (!maBteMsg->empty())
		maBteMsg->pop();

	while (!autreBteMsg->empty())
		autreBteMsg->pop();
}

float NegoAcheteur::negocier()
{
	Message* msgTmp;
	Negociation uneNegociation;

	uneNegociation.proposerOffre(NegoAcheteur::getMontantMin(), autreBteMsg, 0, montantCourant);
	while (true)
	{
		if (!maBteMsg->empty())
		{
			msgTmp = maBteMsg->front();
			maBteMsg->pop();

			if (msgTmp->getType() == 0)			//S'il s'agit d'une offre (0)
			{
				if (msgTmp->getMontant() > NegoAcheteur::getMontantMax())		//Si le montant offert par le vendeur est supérieur au montant maximal désiré par l'acheteur, faire une contre offre
				{
					uneNegociation.proposerOffre(msgTmp->getMontant(), autreBteMsg, 2, montantCourant);
				}
				else if (((msgTmp->getMontant() <= NegoAcheteur::getMontantMax()) && (msgTmp->getMontant() >= NegoAcheteur::getMontantMin())) || (msgTmp->getMontant() <= NegoAcheteur::getMontantMin()))		//Si le montant est entre le max et le min, accepter
				{
					uneNegociation.accepterOffre(msgTmp->getMontant(), autreBteMsg);
					break;
				}	
				else		//Sinon refuser
				{
					uneNegociation.rejeterOffre(msgTmp->getMontant(), autreBteMsg);
					break;
				}
			}
			else if (msgTmp->getType() == 1)		//S'il s'agit d'une acceptation (1)
			{
				//Faire le transfert
				break;
			}
			else								//S'il s'agit d'un refus (2)
			{
				break;
			}
		}
	}
	return 0;
}