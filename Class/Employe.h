#pragma once
#ifndef EMPLOYE_H
#define EMPLOYE_H

using namespace std;

class Employe
{
private :
	float salaireHoraire;
	float salaireAnnuel;
public:
	//Constructeurs
	Employe(void);
	Employe(float, float);

	//Accesseurs GET
	float getSalaireHoraire() { return salaireHoraire; }
	float getSalaireAnnuel() { return salaireAnnuel; }
};

#endif