#pragma once
#ifndef AFFICHAGENEGOCIATION_H
#define AFFICHAGENEGOCIATION_H

#include <iostream>

using namespace std;

class AffichageNegociation
{
private:

public:
	AffichageNegociation();
	~AffichageNegociation();

	void afficherOffre(float montantPrec);
	void afficherAcceptation(float montantPrec);
	void afficherRefus(float montantPrec);
};
#endif