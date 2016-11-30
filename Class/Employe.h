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
	Employe();
	Employe(float salaireHoraire, float salaireAnnuel);
	~Employe();

	float leSalaireHoraire();
	float leSalaireAnnuel();
};
#endif