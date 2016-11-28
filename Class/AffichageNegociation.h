#pragma once
#ifndef AFFICHAGENEGOCIATION_H
#define AFFICHAGENEGOCIATION_H

#include <iostream>

using namespace std;

class AffichageNegociation {
private:

public:
	AffichageNegociation(void);

	void afficherOffre(float);
	void afficherAcceptation(float);
	void afficherRefus(float);
};

#endif