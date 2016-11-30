#include "NegoAcheteur.h"

NegoAcheteur::NegoAcheteur()
{
	//NOP
}

NegoAcheteur::NegoAcheteur(float montantMax, float montantMin, int duree, Club* representantClub, queue<Message*>* msgVendeur, queue<Message*>* msgAcheteur, int* flag) : Negociateur(montantMax, montantMin, duree, representantClub)
{
	maBteMsg = msgAcheteur;
	autreBteMsg = msgVendeur;
	montantCourant = new float(NegoAcheteur::getMontantMin());
	flag = new int();
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
	clock_t start;
	double chrono;

	start = clock();
		
	uneNegociation.proposerOffre(NegoAcheteur::getMontantMin(), autreBteMsg, 0, montantCourant);
	while (true)
	{
		chrono = (std::clock() - start) / (double)CLOCKS_PER_SEC;

		if (!maBteMsg->empty())
		{
			msgTmp = maBteMsg->front();
			maBteMsg->pop();

			if (msgTmp->leType() == 0)			//S'il s'agit d'une offre (0)
			{
				if (msgTmp->leMontant() > NegoAcheteur::getMontantMax())		//Si le montant offert par le vendeur est supérieur au montant maximal désiré par l'acheteur, faire une contre offre
				{
					uneNegociation.proposerOffre(msgTmp->leMontant(), autreBteMsg, 2, montantCourant);
				}
				else if (((msgTmp->leMontant() <= NegoAcheteur::getMontantMax()) && (msgTmp->leMontant() >= NegoAcheteur::getMontantMin())) || (msgTmp->leMontant() <= NegoAcheteur::getMontantMin()))		//Si le montant est entre le max et le min, accepter
				{
					uneNegociation.accepterOffre(msgTmp->leMontant(), autreBteMsg);
					//*flag = 0;
					break;
				}	
				else		//Sinon refuser
				{
					uneNegociation.rejeterOffre(msgTmp->leMontant(), autreBteMsg);
					//*flag = 1;
					break;
				}
			}
			else if (msgTmp->leType() == 1)		//S'il s'agit d'une acceptation (1)
			{
				//Faire le transfert
				break;
			}
			else if (chrono >= NegoAcheteur::getDuree())		//Si la negociation excède la durée du Mercator
			{
				uneNegociation.rejeterOffre(msgTmp->leMontant(), autreBteMsg);
				//*flag = 1;
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