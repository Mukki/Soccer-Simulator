#include "AffichageNegociation.h"

AffichageNegociation::AffichageNegociation(void)
{

}

void AffichageNegociation::afficherOffre(float montantPrec)
{
	cout << "Offre : " << montantPrec << "$ " << endl << endl;
}

void AffichageNegociation::afficherAcceptation(float montantPrec)
{
	cout << "Acceptation : " << montantPrec << "$ " << endl << endl;
}

void AffichageNegociation::afficherRefus(float montantPrec)
{
	cout << "Refus : " << montantPrec << "$ " << endl << endl;
}