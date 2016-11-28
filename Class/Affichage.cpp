#include "Affichage.h"

//Constructeur
Affichage::Affichage(LigueSoccer* ligueSoccer)
{
	this->ligueSoccer = ligueSoccer;
}

//Ajout d'un Club
void Affichage::ajouterClub()
{
	//Variables temporaires
	string nom;
	string histoire;
	string couleur;
	string ville;
	string adresse;

	//Affichage du formulaire
	system("cls");
	cout << "Ajout d'un club" << endl;
	cout << "Entrez un nom : "; cin >> nom;			
	cout << "Entrez une histoire : "; cin >> histoire; 
	cout << "Entrez une couleur : "; cin >> couleur; 
	cout << "Entrez une ville : "; cin >> ville; 
	cout << "Entrez une adresse : "; cin >> adresse;
	//Ajout du club
	ligueSoccer->ajouterClub(nom,histoire,couleur,ville,adresse);
}

//Affichage de Clubs
void Affichage::afficherClub()
{
	system("cls");
	int nbClub = ligueSoccer->vect_club.size();
	//Affichage de tout les clubs
	cout << "Affichage des Clubs" << endl;
	cout << "Nombre de clubs : " << nbClub << endl << endl;

	for(int i=0;i<nbClub;i++)
		{
		cout << "Nom du club :" << ligueSoccer->getClub(i)->getNom() << endl;
		cout << "Histoire du club :" << ligueSoccer->getClub(i)->getHist() << endl;
		cout << "Couleur du club :" << ligueSoccer->getClub(i)->getCoul() << endl;
		cout << "Ville du club :" << ligueSoccer->getClub(i)->getVille() << endl;
		cout << "Adresse du club :" << ligueSoccer->getClub(i)->getAdr() << endl;
		cout << "" << ligueSoccer->getClub(i)->getNbPalmares() << " Palmares" << endl << endl;
		}

	system("pause");
}

//Supprimer un Club
void Affichage::supprimerClub()
{
	system("cls");
	int nbClub = ligueSoccer->vect_club.size();
	int choix;
	cout << "Suppression d'un Club" << endl; 

	for(int i=0;i<nbClub;i++)
		{
			cout << "(" << i+1 << ") Club : " << ligueSoccer->vect_club[i]->getNom() << endl;	
		}

	cout << "Entrez le numeros du club a supprimer : "; cin >> choix;
	choix--;

	ligueSoccer->supprimerClub(choix);

	system("cls");
	cout << "Supression" << endl;
	cout << "Suppression Confirmee" << endl << endl;

	system("pause");
}

//Ligue précodé pour les tests
void Affichage::ligueHardcoder()
{
	//Liste de clubs
	ligueSoccer->ajouterClub("Les Tanant", "Ben des choses", "Bleu", "Bidonville", "2020 du finfin");
	ligueSoccer->ajouterClub("Verminator", "Ben des choses", "Bleu", "Bidonville", "2020 du finfin");
	ligueSoccer->ajouterClub("Les Trolls", "Ben des choses", "Bleu", "Bidonville", "2020 du finfin");
	ligueSoccer->ajouterClub("Canada", "Ben des choses", "Bleu", "Bidonville", "2020 du finfin");
	ligueSoccer->ajouterClub("Patate", "Ben des choses", "Bleu", "Bidonville", "2020 du finfin");

	//Liste de joueurs
	Reglement unReglement(8000, "Quitter l'equipe", 7000, 2000, 5000);
	Date dateEntree("20", "10", "2016");
	Date dateContrat("20", "10", "2018");

	ligueSoccer->vect_club[0]->ajoutJoueurAutonome("Joe", "Tremblay", 12, 12, "Chicoutimi");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[0]->getJoueur(0), ligueSoccer->getClub(0), ligueSoccer->getClub(1), 10, dateEntree, unReglement, dateContrat);
	ligueSoccer->vect_club[0]->ajoutJoueurNonAutonome("Kikoup", "Tremblay", 12, 12, "Dolbeau");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[0]->getJoueur(0), ligueSoccer->getClub(0), ligueSoccer->getClub(2), 8, dateEntree, unReglement, dateContrat);
	ligueSoccer->vect_club[0]->ajoutJoueurAutonome("Wassup", "Tremblay", 12, 12, "Mistassini");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[0]->getJoueur(0), ligueSoccer->getClub(0), ligueSoccer->getClub(3), 2, dateEntree, unReglement, dateContrat);

	ligueSoccer->vect_club[1]->ajoutJoueurNonAutonome("Guy", "Tremblay", 12, 12, "Quebec");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[1]->getJoueur(0), ligueSoccer->getClub(1), ligueSoccer->getClub(0), 5, dateEntree, unReglement, dateContrat);
	ligueSoccer->vect_club[1]->ajoutJoueurAutonome("Voshka", "Tremblay", 12, 12, "Montreal");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[1]->getJoueur(0), ligueSoccer->getClub(1), ligueSoccer->getClub(2), 9, dateEntree, unReglement, dateContrat);

	ligueSoccer->vect_club[2]->ajoutJoueurNonAutonome("Abdenour", "Bouzouane", 12, 12, "Trois-Rivieres");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[2]->getJoueur(0), ligueSoccer->getClub(2), ligueSoccer->getClub(0), 9, dateEntree, unReglement, dateContrat);
	ligueSoccer->vect_club[2]->ajoutJoueurAutonome("Donald", "Trump", 12, 12, "Gatineau");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[2]->getJoueur(0), ligueSoccer->getClub(2), ligueSoccer->getClub(1), 9, dateEntree, unReglement, dateContrat);

	ligueSoccer->vect_club[3]->ajoutJoueurNonAutonome("Hillary", "Clinton", 12, 12, "New York City");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[3]->getJoueur(0), ligueSoccer->getClub(3), ligueSoccer->getClub(4), 9, dateEntree, unReglement, dateContrat);

	ligueSoccer->vect_club[4]->ajoutJoueurAutonome("Adria", "Rose", 12, 12, "New York City");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[4]->getJoueur(0), ligueSoccer->getClub(4), ligueSoccer->getClub(3), 9, dateEntree, unReglement, dateContrat);

	//Liste d'entraineur
	ligueSoccer->ajouterEntraineur("Bobby", "Lapointe", "Quebec");
	ligueSoccer->getEntraineur(0)->ajouterPalmares("Meilleur Cogneur", "1", "1", "2010", ligueSoccer->getClub(0));

	ligueSoccer->ajouterEntraineur("Roger", "Baston", "Montreal");
	ligueSoccer->getEntraineur(0)->ajouterPalmares("Le plus chialeux", "1", "1", "2010", ligueSoccer->getClub(2));
	ligueSoccer->getEntraineur(0)->ajouterPalmares("Meilleur porteur d'eau", "1", "1", "2010", ligueSoccer->getClub(2));

	ligueSoccer->ajouterEntraineur("Bob", "KassePied", "Loltown");

	//Liste des rencontres
	for (int x = 24; x > 20; x--) {
		Date uneDate(to_string(x), "10", "2016");
		Club* clubUn;
		Club* clubDeux;
		int variableUn, variableDeux;

		variableUn = rand() % 5;

		if ((variableUn + 1) > 4) {
			variableDeux = variableUn - 1;
		}
		else {
			variableDeux = variableUn + 1;
		}

		clubUn = new Club;
		clubDeux = new Club;
		clubUn = ligueSoccer->getClub(variableUn);
		clubDeux = ligueSoccer->getClub(variableDeux);
		Rencontre* uneRencontre;
		uneRencontre = new Rencontre(uneDate, clubUn, clubDeux);
		calendrierRencontres.ajoutRencontre(uneRencontre);
	}

	for (int x = 20; x > 16; x--) {
		Date uneDate(to_string(x), "10", "2016");
		Club* clubUn;
		Club* clubDeux;
		Match* unMatch;
		int variableUn, variableDeux;

		variableUn = rand() % 5;

		if ((variableUn + 1) > 4) {
			variableDeux = variableUn - 1;
		}
		else {
			variableDeux = variableUn + 1;
		}

		clubUn = new Club;
		clubDeux = new Club;
		clubUn = ligueSoccer->getClub(variableUn);
		clubDeux = ligueSoccer->getClub(variableDeux);

		Equipe equipeLoc(clubUn, 8, 1, ligueSoccer->vect_club[variableUn]->getJoueur(0));
		Equipe equipeVis(clubDeux, 8, 1, ligueSoccer->vect_club[variableDeux]->getJoueur(0));
		Periode premPer(15, rand() % 5, rand() % 5);
		Periode deuxPer(15, rand() % 5, rand() % 5);
		Resultat result((premPer.getNbButsLocaux() + deuxPer.getNbButsLocaux()), (premPer.getNbButsVisiteurs() + deuxPer.getNbButsVisiteurs()));
		unMatch = new Match(equipeLoc, equipeVis, premPer, deuxPer, result);
		Rencontre* uneRencontre;
		uneRencontre = new Rencontre(uneDate, clubUn, clubDeux, unMatch);
		calendrierRencontres.ajoutRencontre(uneRencontre);
	}
}

//Affiche les joueurs
void Affichage::afficherJoueur(){

	system("cls");

	int nbClub = ligueSoccer->vect_club.size();
	int choix;
	cout << "Selection d'un Club pour afficher ses joueurs" << endl; 

	for(int i=0;i<nbClub;i++)
		{
			cout << "(" << i+1 << ") Club : " << ligueSoccer->vect_club[i]->getNom() << endl;	
		}

	cout << "Entrez le numeros du club a afficher les joueurs : "; cin >> choix;
	choix--;

	system("cls");

	//Pointeurs
	Club* club = ligueSoccer->getClub(choix);
	int nbJoueurs = club->getNbJoueur();
	
	cout << "Equipe : " << club->getNom() << endl;
	cout << "Nombre de joueurs : " << nbJoueurs << endl;
	
	for(int i=0;i<nbJoueurs;i++)
		{
		Joueur* pJoueur = club->getJoueur(i);
		Contrat* pContrat = ligueSoccer->getContrat(i);
		Date dateTmp;
		string date;

		dateTmp = pContrat->getDateEntree();
		date = dateTmp.getDateToString();

		cout << "(" << i+1 << ") " << pJoueur->getNom() << " " << pJoueur->getPrenom() << endl;
		}

	cout << endl << endl;
	system("pause");
}

//Affiche les entraineurs
void Affichage::afficherEntraineurs()
{
	system("cls");
	int nbEntraineurs = ligueSoccer->getNbEntraineur();

	cout << "Liste des entraineurs" << endl;

	cout << "Nombre d'entraineurs : " << nbEntraineurs << endl << endl;
	cout << "_____________________________________________________________" << endl << endl;

	for(int i=0;i<nbEntraineurs;i++)
		{
		Entraineur* pEntraineur = ligueSoccer->getEntraineur(i);
		cout << "(" << i+1 << ") " << pEntraineur->getNom() << " " << pEntraineur->getPrenom() << endl;
		cout << "Lieu obtention du grade : " << pEntraineur->getlieuObtention() << endl;
		
		int nbPalmares = pEntraineur->getNbPalmares();

		for(int j=0;j<nbPalmares;j++)
			{
			Palmares* pPalmares = ligueSoccer->getEntraineur(i)->getPalmares(j);
			cout << endl;
			cout << endl;
			cout << "Palmares" << endl;
			cout << "Titre : " << pPalmares->getTitre() << endl;
			cout << "Date  : " << pPalmares->getDate() << endl;
			cout << "Club  : " << pPalmares->getClub()->getNom() << endl;
			cout << endl;
			}
		cout << "_____________________________________________________________" << endl << endl;
		}

	cout << endl << endl;

	system("pause");
}

//Affiche le meilleur entraineur
void Affichage::afficherMeilleurEntraineur()
{
	system("cls");

	//Variable tampon
	int nbEntraineurs = ligueSoccer->getNbEntraineur();
	if(nbEntraineurs)
	{
	int nbPalmares=ligueSoccer->getEntraineur(0)->getNbPalmares(),cpt=0,index=0;
	Entraineur* unEntraineur;
	//Cherche le meilleur entraineur
	for(int i=0;i<nbEntraineurs;i++)
		{	
		for(int j=0;j<nbEntraineurs;j++)
			{
			if(ligueSoccer->getEntraineur(i)->getNbPalmares() < 
			   ligueSoccer->getEntraineur(j)->getNbPalmares() )
				{
				nbPalmares = ligueSoccer->getEntraineur(j)->getNbPalmares();
				index = j;
				break;
				}		
			}	
		}
	unEntraineur = ligueSoccer->getEntraineur(index);

	//Affiche le résultat
	cout << "Entraineur le plus titre" << endl;
	cout << "Nom : " << unEntraineur->getNom() << endl;
	cout << "Avec " << unEntraineur->getNbPalmares() << " palmares " << endl;
	cout << endl;

	}
	else
		cout << "Aucun entraineur trouve" << endl;

	system("pause");
}

//afficher le meilleur club
void Affichage::afficherMeilleurClub()
{
	system("cls");

	//Variables tampons
	int nbClub = ligueSoccer->getNbClub();
	if(nbClub)
	{
	int nbPalmares=ligueSoccer->getClub(0)->getNbPalmares(),cpt=0,index=0;
	Club* unClub;
	//Cherche le meilleur club
	for(int i=0;i<nbClub;i++)
		{	
		for(int j=0;j<nbClub;j++)
			{
			if(ligueSoccer->getClub(i)->getNbPalmares() < 
			   ligueSoccer->getClub(j)->getNbPalmares() )
				{
				nbPalmares = ligueSoccer->getClub(j)->getNbPalmares();
				index = j;
				break;
				}		
			}	
		}
	unClub = ligueSoccer->getClub(index);
	//Affiche le resultat
	cout << "Club le plus titre" << endl;
	cout << "Nom : " << unClub->getNom() << endl;
	cout << "Avec " << unClub->getNbPalmares() << " palmares " << endl;
	cout << endl;

	}
	else
		cout << "Aucuns clubs trouves" << endl;

	system("pause");
}

//Affiche le calendrier des rencontres
void Affichage::afficherCalendrier()
{
	system("cls");

	cout << "Calendrier des rencontres" << endl << endl;

	for (int i = 0; i < calendrierRencontres.getSizeof(); i++) {
		cout << "Rencontre #" << i + 1 << endl;
		cout << "Club local : " << calendrierRencontres.getNomClubLocal(i) << endl;
		cout << "Club visiteur : " << calendrierRencontres.getNomClubVisit(i) << endl;
		cout << "Date de l'affrontement : " << calendrierRencontres.getDate(i) << endl;

		if (calendrierRencontres.getRencontre(i)->getMatch() != NULL) {
			cout << "Resultat equipe locale : " << calendrierRencontres.getRencontre(i)->getMatch()->getResultat().getNbButsLocaux() << endl;
			cout << "Resultat equipe visiteur : " << calendrierRencontres.getRencontre(i)->getMatch()->getResultat().getNbButsVisiteurs() << endl;
		}
		else {
			cout << "Le match n'a pas encore eu lieu ou n'aura pas lieu..." << endl;
		}
		cout << "_____________________________________________________________" << endl << endl;
	}

	system("pause");
}

//Ajouter joueur
void Affichage::ajouterJoueur()
{
	system("cls");

	int nbClub = ligueSoccer->vect_club.size();
	int choix, ancienClub;
	cout << "Dans quel club voulez-vous ajouter un joueur?" << endl;

	for (int i = 0; i<nbClub; i++)
	{
		cout << "(" << i + 1 << ") Club : " << ligueSoccer->vect_club[i]->getNom() << endl;
	}

	cout << "Entrez le numeros du club a ajouter un joueur : "; 
	cin >> choix;
	choix--;
	cout << "Entrez le numero de l'ancien club avec lequel le joueur etait : ";
	cin >> ancienClub;
	ancienClub--;

	string leNom, lePrenom, laVilleNaissance, jourEntree, moisEntree, anneeEntree, jourContrat, moisContrat, anneeContrat, droits;
	float poids, taille, seuil, montantTransfert;
	int dureeContrat;

	cout << "Ajouter un joueur" << endl;
	cout << "Entrez le nom : ";
	cin >> leNom;
	cout << endl << "Entrer le prenom du joueur : ";
	cin >> lePrenom;
	cout << endl << "Entrez le poids du joueur : ";
	cin >> poids;
	cout << endl << "Entrez la taille du joueur : ";
	cin >> taille;
	cout << endl << "Entrez la ville de naissance du joueur : ";
	cin >> laVilleNaissance;
	cout << endl << "Entrez la duree du contrat : ";
	cin >> dureeContrat;
	cout << endl << "Entrez le jour d'entree en vigueur du contrat (jj) : ";
	cin >> jourEntree;
	cout << endl << "Entrez le mois d'entree en vigueur du contrat (mm) : ";
	cin >> moisEntree;
	cout << endl << "Entrez l'annee d'entree en vigueur du contrat (aaaa) : ";
	cin >> anneeEntree;
	cout << endl << "Entrez le jour de fin du contrat (jj) : ";
	cin >> jourContrat;
	cout << endl << "Entrez le mois de fin du contrat (mm) : ";
	cin >> moisContrat;
	cout << endl << "Entrez l'annee de fin du contrat (aaaa) : ";
	cin >> anneeContrat;
	cout << endl << "Entrez le seuil maximal pour l'echange du joueur ($) : ";
	cin >> seuil;
	cout << endl << "Entrez le montant pour lequel le joueur a ete transfere vers son club actuel : ";
	cin >> montantTransfert;
	cout << endl << "Entrez les droits du joueur : ";
	cin.ignore(100, '\n');
	getline(cin, droits);

	Date dateEntree(jourEntree, moisEntree, anneeEntree);
	Date dateContrat(jourContrat, moisContrat, anneeContrat);
	Reglement unReglement(seuil, droits, montantTransfert, (seuil * 0.3f), (seuil * 0.7f));
	Contrat* unContrat;
	unContrat = new Contrat(ligueSoccer->getClub(choix)->getJoueur(0), ligueSoccer->getClub(choix), ligueSoccer->getClub(ancienClub), dureeContrat, dateEntree, unReglement, dateContrat);

	ligueSoccer->vect_club[choix]->ajoutJoueur(leNom, lePrenom, taille, poids, laVilleNaissance);
	ligueSoccer->vect_contrat.push_back(unContrat);

	system("pause");
}

//Rupture de contrat
void Affichage::rompreContrat()
{
	system("cls");

	string prenomJoueurContractant;
	int indice;

	cout << "Entrez le prenom du joueur dont vous voulez rompre le contrat : " << endl;
	cin >> prenomJoueurContractant;
	cout << endl;
	indice = ligueSoccer->trouverJoueurContrat(prenomJoueurContractant);

	if (indice != 999) {

		Contrat* contratTrouve;
		contratTrouve = new Contrat;

		Club* clubLibere;
		clubLibere = new Club;

		Club* clubContractant;
		clubContractant = new Club;

		Date dateContrat;

		cout << "Un joueur contractant correspondant a votre entree a ete retrouve : " << endl;
		cout << "___________________________________________________________________ " << endl << endl;
		contratTrouve = ligueSoccer->getContrat(indice);
		contratTrouve->getJoueurContractant();
		dateContrat = contratTrouve->getDateEntree();
		clubLibere = contratTrouve->getClubLibere();
		clubContractant = contratTrouve->getClubContractant();
		cout << "Nom du joueur contractant :              " << contratTrouve->getJoueurContractant()->getPrenom() << " " << contratTrouve->getJoueurContractant()->getNom() << endl;
		cout << "Date d'entree en vigueur du contrat :    " << dateContrat.getDateToString() << endl;
		cout << "Duree du contrat (annees)  :             " << contratTrouve->getDureeContrat() << endl;
		cout << "Club libere :                            " << clubLibere->getNom() << endl;
		cout << "Club contractant :                       " << clubContractant->getNom() << endl << endl;
	}
	else {
		cout << "Aucun joueur contractant trouve correspondant a votre critere de recherche" << endl << endl;
	}

	int choix, indiceNouvelEquipe, annee;
	string jourEntree, moisEntree, anneeEntree, jourContrat, moisContrat, anneeContrat;

	int indiceVieilleEquipe = ligueSoccer->trouverClubJoueur(ligueSoccer->getContrat(indice)->getClubContractant()->getNom());

	float seuil;
	string droits, raison;
	float montantTransfert;
	float montantEncaisse;
	float montantRestant;

	if (ligueSoccer->getContrat(indice)->getJoueurContractant()->briserContrat() == 0)
	{
		cout << "Il s'agit d'un joueur non autonome. Avec les infos precedentes, peut-il toujours mettre fin a son contrat?" << endl;
		cout << "(1) Oui" << endl;
		cout << "(2) Non" << endl;
		cin >> choix;

		switch (choix)
		{
			case 1:
				for (int i = 0; i<ligueSoccer->getNbClub(); i++)
				{
					cout << "(" << i + 1 << ") Club : " << ligueSoccer->vect_club[i]->getNom() << endl;
				}
				cout << "Dans quel numero qu'equipe voulez-vous inserer le joueur?" << endl;
				cin >> indiceNouvelEquipe;
				cout << "Quel est la duree du nouveau contrat? (annee)" << endl;
				cin >> annee;
				cout << endl << "Entrez le jour d'entree en vigueur du contrat (jj) : ";
				cin >> jourEntree;
				cout << endl << "Entrez le mois d'entree en vigueur du contrat (mm) : ";
				cin >> moisEntree;
				cout << endl << "Entrez l'annee d'entree en vigueur du contrat (aaaa) : ";
				cin >> anneeEntree;
				cout << endl << "Entrez le jour de fin du contrat (jj) : ";
				cin >> jourContrat;
				cout << endl << "Entrez le mois de fin du contrat (mm) : ";
				cin >> moisContrat;
				cout << endl << "Entrez l'annee de fin du contrat (aaaa) : ";
				cin >> anneeContrat;
				cout << endl << "Entrez le seuil du nouveau reglement : ";
				cin >> seuil;
				cout << endl << "Entrez les nouveaux droits pour le reglement : ";
				cin >> droits;
				cout << endl << "Entrez le nouveau montant de tranferts : ";
				cin >> montantTransfert;
				cout << endl << "Entrez le nouveau montant d'encaisse du club : ";
				cin >> montantEncaisse;
				cout << endl << "Entrez le nouveau montant d'encaisse du joueur : ";
				cin >> montantRestant;

				if (indiceVieilleEquipe != 999)
					ligueSoccer->finContrat(ligueSoccer->getContrat(indice)->getJoueurContractant(), ligueSoccer->getClub(indiceNouvelEquipe - 1), ligueSoccer->getClub(indiceVieilleEquipe), annee, Date(jourEntree, moisEntree, anneeEntree), Date(jourContrat, moisContrat, anneeContrat), Reglement(seuil, droits, montantTransfert, montantEncaisse, montantRestant), indiceNouvelEquipe - 1, indiceVieilleEquipe);
				break;
			case 2:
				break;
			default:
				cout << "Choix invalide. Veuillez recommencer du debut." << endl;
		}
	}
	else
	{
		cout << "Il s'agit d'un joueur autonome. Avec les informations precedentes, celui-ci brise-t-il son contrant ou arrive-t-il a echeance?" << endl;
		cout << "(1) Romp son contrat" << endl;
		cout << "(2) Arrive a echeance" << endl;
		cin >> choix;

		for (int i = 0; i<ligueSoccer->getNbClub(); i++)
		{
			cout << "(" << i + 1 << ") Club : " << ligueSoccer->vect_club[i]->getNom() << endl;
		}
		cout << "Dans quel numero qu'equipe voulez-vous inserer le joueur?" << endl;
		cin >> indiceNouvelEquipe;
		cout << "Quel est la duree du nouveau contrat? (annee)" << endl;
		cin >> annee;
		cout << endl << "Entrez le jour d'entree en vigueur du contrat (jj) : ";
		cin >> jourEntree;
		cout << endl << "Entrez le mois d'entree en vigueur du contrat (mm) : ";
		cin >> moisEntree;
		cout << endl << "Entrez l'annee d'entree en vigueur du contrat (aaaa) : ";
		cin >> anneeEntree;
		cout << endl << "Entrez le jour de fin du contrat (jj) : ";
		cin >> jourContrat;
		cout << endl << "Entrez le mois de fin du contrat (mm) : ";
		cin >> moisContrat;
		cout << endl << "Entrez l'annee de fin du contrat (aaaa) : ";
		cin >> anneeContrat;
		cout << endl << "Entrez le seuil du nouveau reglement : ";
		cin >> seuil;
		cout << endl << "Entrez les nouveaux droits pour le reglement : ";
		cin >> droits;
		cout << endl << "Entrez le nouveau montant de tranferts : ";
		cin >> montantTransfert;
		cout << endl << "Entrez le nouveau montant d'encaisse du club : ";
		cin >> montantEncaisse;
		cout << endl << "Entrez le nouveau montant d'encaisse du joueur : ";
		cin >> montantRestant;

		switch (choix)
		{
		case 1:
			cout << endl << "Veuillez entrez la raison du depart : ";
			cin >> raison;

			if (indiceVieilleEquipe != 999)
				ligueSoccer->ruptureContrat(ligueSoccer->getContrat(indice)->getJoueurContractant(), ligueSoccer->getClub(indiceNouvelEquipe - 1), ligueSoccer->getClub(indiceVieilleEquipe), annee, Date(jourEntree, moisEntree, anneeEntree), Date(jourContrat, moisContrat, anneeContrat), Reglement(seuil, droits, montantTransfert, montantEncaisse, montantRestant), indiceNouvelEquipe - 1, indiceVieilleEquipe, raison);
			break;
		case 2:
			if (indiceVieilleEquipe != 999)
				ligueSoccer->finContrat(ligueSoccer->getContrat(indice)->getJoueurContractant(), ligueSoccer->getClub(indiceNouvelEquipe - 1), ligueSoccer->getClub(indiceVieilleEquipe), annee, Date(jourEntree, moisEntree, anneeEntree), Date(jourContrat, moisContrat, anneeContrat), Reglement(seuil, droits, montantTransfert, montantEncaisse, montantRestant), indiceNouvelEquipe - 1, indiceVieilleEquipe);
			break;
		default:
			cout << "Choix invalide. Veuillez recommencer du debut." << endl;
		}
	}

	system("pause");
}

//Ajouter un match au calendrier des rencotres
void Affichage::ajouterMatch() {
	system("cls");

	int nbClub = ligueSoccer->vect_club.size();
	int clubLocal, clubVisit;
	cout << "Ajouter une rencontre" << endl;

	for (int i = 0; i<nbClub; i++)
	{
		cout << "(" << i + 1 << ") Club : " << ligueSoccer->vect_club[i]->getNom() << endl;
	}

	cout << endl << "Entrez le numero du club local : ";
	cin >> clubLocal;
	clubLocal--;
	cout << endl << "Entrez le numero du club visiteur : ";
	cin >> clubVisit;
	clubVisit--;

	Match* unMatch;
	Joueur* capitaineLoc;
	capitaineLoc = new Joueur;
	Joueur* capitaineVis;
	capitaineVis = new Joueur;
	Rencontre* uneRencontre;

	string jourRencontre, moisRencontre, anneeRencontre, prenomCaptLoc, prenomCaptVis;
	char choice;
	bool flag;
	int resPremPerLoc, resDeuxPerLoc, resPremPerVis, resDeuxPerVis, nbJoueursLoc, nbJoueursVis, nbGardiensLoc, nbGardiensVis, indiceCptLoc, indiceCptVis;

	cout << endl << "Entrez le jour de la rencontre (jj) : ";
	cin >> jourRencontre;
	cout << endl << "Entrez le mois de la rencontre (mm) : ";
	cin >> moisRencontre;
	cout << endl << "Entrez l'annee de la rencontre (aaaa) : ";
	cin >> anneeRencontre;
	cout << endl << "Entrez le nombre de joueurs pour l'equipe locale : ";
	cin >> nbJoueursLoc;
	cout << endl << "Entrez le nombre de gardiens pour l'equipe locale : ";
	cin >> nbGardiensLoc;
	cout << endl << "Entrez le nombre de joueurs pour l'equipe visiteur : ";
	cin >> nbJoueursVis;
	cout << endl << "Entrez le nombre de gardiens pour l'equipe visiteur : ";
	cin >> nbGardiensVis;
	cout << endl << "Entrez le prenom du capitaine de l'equipe locale : ";
	cin >> prenomCaptLoc;

	Date dateRencontre(jourRencontre, moisRencontre, anneeRencontre);

	do {
		indiceCptLoc = ligueSoccer->trouverJoueurClub(prenomCaptLoc, clubLocal);

		if (indiceCptLoc != 999) {
			flag = 0;
			capitaineLoc = ligueSoccer->getClub(clubLocal)->getJoueur(indiceCptLoc);
		}
		else {
			flag = 1;
			cout << endl << "Veuillez entrer un prenom valide pour le capitaine : ";
			cin >> prenomCaptLoc;
		}
	} while (flag == 1);

	cout << endl << "Entrez le prenom du capitaine de l'equipe visiteur : ";
	cin >> prenomCaptVis;

	do {
		indiceCptVis = ligueSoccer->trouverJoueurClub(prenomCaptVis, clubVisit);

		if (indiceCptVis != 999) {
			flag = 0;
			capitaineVis = ligueSoccer->getClub(clubVisit)->getJoueur(indiceCptVis);
		}
		else {
			flag = 1;
			cout << endl << "Veuillez entrer un prenom valide pour le capitaine : ";
			cin >> prenomCaptVis;
		}
	} while (flag == 1);

	Equipe equipeLoc(ligueSoccer->getClub(clubLocal), nbJoueursLoc, nbGardiensLoc, capitaineLoc);
	Equipe equipeVis(ligueSoccer->getClub(clubVisit), nbJoueursVis, nbGardiensVis, capitaineVis);

	cout << endl << "La rencontre que vous ajoutez a-t-elle eu lieu? [o/n] : ";
	cin >> choice;

	if ((choice == 'o') | (choice == 'O')) {
		cout << endl << "Entrez le resultat de l'equipe locale a la premiere periode : ";
		cin >> resPremPerLoc;
		cout << endl << "Entrez le resultat de l'equipe locale a la deuxieme periode : ";
		cin >> resDeuxPerLoc;
		cout << endl << "Entrez le resultat de l'equipe visiteur a la premiere periode : ";
		cin >> resPremPerVis;
		cout << endl << "Entrez le resultat de l'equipe visiteur a la deuxieme periode : ";
		cin >> resDeuxPerVis;

		Periode premPeriode(15, resPremPerLoc, resPremPerVis);
		Periode deuxPeriode(15, resDeuxPerLoc, resDeuxPerVis);
		Resultat leResultat(resPremPerLoc + resDeuxPerLoc, resPremPerVis + resDeuxPerVis);
		unMatch = new Match(equipeLoc, equipeVis, premPeriode, deuxPeriode, leResultat);

		uneRencontre = new Rencontre(dateRencontre, ligueSoccer->getClub(clubLocal), ligueSoccer->getClub(clubVisit), unMatch);
		calendrierRencontres.ajoutRencontre(uneRencontre);
	}
	else {
		uneRencontre = new Rencontre(dateRencontre, ligueSoccer->getClub(clubLocal), ligueSoccer->getClub(clubVisit));
		calendrierRencontres.ajoutRencontre(uneRencontre);
	}
	system("pause");
}

//Afficher les rencontres d'un club
void Affichage::afficherRencontresClub()
{
	system("cls");

	string nomClub;
	int nbClub = ligueSoccer->vect_club.size();
	int choix;
	cout << "Afficher les rencontres pour un club" << endl;

	for (int i = 0; i<nbClub; i++)
	{
		cout << "(" << i + 1 << ") Club : " << ligueSoccer->vect_club[i]->getNom() << endl;
	}

	cout << endl << "Entrez le numero du club local : ";
	cin >> choix;
	choix--;
	cout << endl;

	nomClub = ligueSoccer->getClub(choix)->getNom();

	for (int i = 0; i < calendrierRencontres.getSizeof(); i++) {
		if (calendrierRencontres.getNomClubLocal(i) == nomClub) {
			cout << "Rencontre #" << i + 1 << endl;
			cout << "Club local : " << calendrierRencontres.getNomClubLocal(i) << endl;
			cout << "Club visiteur : " << calendrierRencontres.getNomClubVisit(i) << endl;
			cout << "Date de l'affrontement : " << calendrierRencontres.getDate(i) << endl;

			if (calendrierRencontres.getRencontre(i)->getMatch() != NULL) {
				cout << "Resultat equipe locale : " << calendrierRencontres.getRencontre(i)->getMatch()->getResultat().getNbButsLocaux() << endl;
				cout << "Resultat equipe visiteur : " << calendrierRencontres.getRencontre(i)->getMatch()->getResultat().getNbButsVisiteurs() << endl;
			}
			else {
				cout << "Le match n'a pas encore eu lieu ou n'aura pas lieu..." << endl;
			}
			cout << "_____________________________________________________________" << endl << endl;
		}
	}
	system("pause");
}

//Afficher les rencontres pour une date
void Affichage::afficherRencontresDate()
{
	system("cls");

	string jour, mois, annee, date;
	bool matchTrouve = 0;

	cout << "Afficher les rencontres pour une date" << endl;
	cout << "Entrez le jour (jj) : ";
	cin >> jour;
	cout << endl << "Entrez le mois (mm) : ";
	cin >> mois;
	cout << endl << "Entrez l'annee (aaaa) : ";
	cin >> annee;
	cout << endl;

	date = jour + "/" + mois + "/" + annee;


	for (int i = 0; i < calendrierRencontres.getSizeof(); i++) {
		if (calendrierRencontres.getDate(i) == date) {
			matchTrouve = 1;
			cout << "Rencontre #" << i + 1 << endl;
			cout << "Club local : " << calendrierRencontres.getNomClubLocal(i) << endl;
			cout << "Club visiteur : " << calendrierRencontres.getNomClubVisit(i) << endl;
			cout << "Date de l'affrontement : " << calendrierRencontres.getDate(i) << endl;

			if (calendrierRencontres.getRencontre(i)->getMatch() != NULL) {
				cout << "Resultat equipe locale : " << calendrierRencontres.getRencontre(i)->getMatch()->getResultat().getNbButsLocaux() << endl;
				cout << "Resultat equipe visiteur : " << calendrierRencontres.getRencontre(i)->getMatch()->getResultat().getNbButsVisiteurs() << endl;
			}
			else {
				cout << "Le match n'a pas encore eu lieu ou n'aura pas lieu..." << endl;
			}
			cout << "_____________________________________________________________" << endl << endl;
		}
	}
	if (matchTrouve == 0)
		cout << "Aucun match correspondant a la date entree n'a ete retrouve" << endl;

	system("pause");
}

void Affichage::afficherEncaisses()
{
	system("cls");

	string jour, mois, annee;
	float montantEncaisseTotal = 0;
	int choix;
	cout << "Afficher les rencontres pour un club" << endl;

	for (int i = 0; i < ligueSoccer->getNbClub(); i++)
	{
		cout << "(" << i + 1 << ") Club : " << ligueSoccer->vect_club[i]->getNom() << endl;
	}

	cout << endl << "Entrez le numero du club pour lequel vous desirez trouver le montant encaisse : ";
	cin >> choix;
	choix--;
	cout << endl;

	cout << "Entrez la date selon avant laquelle vous-voulez trouver les montants encaisses par le club : " << endl;
	cout << "Jour (jj) : ";
	cin >> jour;
	cout << endl << "Mois (mm) : ";
	cin >> mois;
	cout << endl << "Annee (aaaa) : ";
	cin >> annee;

	for (int i = 0; i < ligueSoccer->getClub(choix)->getNbContratEchu(); i++) {
		if (ligueSoccer->getClub(choix)->getContratEchu(i)->getDateContrat().getAnnee() > annee)
			montantEncaisseTotal = montantEncaisseTotal + ligueSoccer->getClub(choix)->getContratEchu(i)->getReglement().getMontantEncaisse();
		else if (ligueSoccer->getClub(choix)->getContratEchu(i)->getDateContrat().getAnnee() == annee)
			if (ligueSoccer->getClub(choix)->getContratEchu(i)->getDateContrat().getMois() > mois)
				montantEncaisseTotal = montantEncaisseTotal + ligueSoccer->getClub(choix)->getContratEchu(i)->getReglement().getMontantEncaisse();
			else if (ligueSoccer->getClub(choix)->getContratEchu(i)->getDateContrat().getMois() == mois) 
				if (ligueSoccer->getClub(choix)->getContratEchu(i)->getDateContrat().getJours() > jour)
					montantEncaisseTotal = montantEncaisseTotal + ligueSoccer->getClub(choix)->getContratEchu(i)->getReglement().getMontantEncaisse();
	}
	cout << "Montant encaisse par le club apres " << jour << "/" << mois << "/" << annee << ": " << montantEncaisseTotal << "$" << endl;

	system("pause");
}

void DebuterNego(Negociateur* nego)
{
	nego->negocier();
}

void Affichage::negocier()
{
	system("cls");

	int nbClub = ligueSoccer->vect_club.size();
	int clubAcheteur, clubVendeur, joueurEchange;
	int* flag;
	float* montantNego;
	float achMin, achMax, venMin, venMax;
	int duree;

	flag = new int();
	montantNego = new float();

	cout << "Negocier le transfert d'un joueur" << endl;

	for (int i = 0; i < nbClub; i++)
	{
		cout << "(" << i + 1 << ") Club : " << ligueSoccer->vect_club[i]->getNom() << endl;
	}

	cout << endl << "Entrez le numero du acheteur : ";
	cin >> clubAcheteur;
	clubAcheteur--;
	cout << endl << "Entrez le numero du club vendeur : ";
	cin >> clubVendeur;
	clubVendeur--;

	system("cls");

	Club* club = ligueSoccer->getClub(clubVendeur);
	int nbJoueurs = club->getNbJoueur();

	cout << "Equipe : " << club->getNom() << endl;
	cout << "Nombre de joueurs : " << nbJoueurs << endl;

	for (int i = 0; i<nbJoueurs; i++)
	{
		Joueur* pJoueur = club->getJoueur(i);
		Contrat* pContrat = ligueSoccer->getContrat(i);
		Date dateTmp;
		string date;

		dateTmp = pContrat->getDateEntree();
		date = dateTmp.getDateToString();

		cout << "(" << i + 1 << ") " << pJoueur->getNom() << " " << pJoueur->getPrenom() << endl;
	}

	cout << endl << "Entrez le numero du joueur que vous-voulez echanger : ";
	cin >> joueurEchange;
	joueurEchange--;

	system("cls");

	cout << "Veuillez entrer le montant minimal que le vendeur veut obtenir : " << endl;
	cin >> venMin;
	cout << "Veuillez-entrer le montant maximum que le vendeur veut obtenir : " << endl;
	cin >> venMax;
	cout << "Veuillez-entrer le montant maximal que l'acheteur veut payer : " << endl;
	cin >> achMax;
	cout << "Veuillez-entrer le montant minimal que l'acheteur pourra payer : " << endl;
	cin >> achMin;
	cout << "Veuillez-entrer la duree des negociations (1 jour = 1 seconde de simulation) : " << endl;
	cin >> duree;

	system("cls");
	cout << "Debut des negociations : " << endl;

	queue<Message*>* msgVendeur = new queue<Message*>();
	queue<Message*>* msgAcheteur = new queue<Message*>();

	NegoAcheteur* acheteur;
	acheteur = new NegoAcheteur(achMax, achMin, duree, ligueSoccer->getClub(clubAcheteur), msgVendeur, msgAcheteur, flag);
	NegoVendeur* vendeur;
	vendeur = new NegoVendeur(venMax, venMin, duree, ligueSoccer->getClub(clubVendeur), msgVendeur, msgAcheteur, flag, montantNego);

	thread threadAcheteur(DebuterNego, acheteur);
	thread threadVendeur(DebuterNego, vendeur);

	threadAcheteur.join();
	threadVendeur.join();

	int annee, indice, choix;
	string droits, jourEntree, moisEntree, anneeEntree, jourContrat, moisContrat, anneeContrat, raison;
	float seuil, montantTransfert, montantEncaisse, montantRestant;

	montantTransfert = *montantNego;
	montantEncaisse = (*montantNego * 0.8f);
	montantRestant = (*montantNego * 0.2f);

	indice = ligueSoccer->trouverJoueurContrat(ligueSoccer->getClub(clubVendeur)->getJoueur(joueurEchange)->getPrenom());
	int indiceVieilleEquipe = ligueSoccer->trouverClubJoueur(ligueSoccer->getContrat(joueurEchange)->getClubContractant()->getNom());

	if (*flag == 0)
	{
		cout << "Quel est la duree du nouveau contrat? (annee)" << endl;
		cin >> annee;
		cout << endl << "Entrez le jour d'entree en vigueur du contrat (jj) : ";
		cin >> jourEntree;
		cout << endl << "Entrez le mois d'entree en vigueur du contrat (mm) : ";
		cin >> moisEntree;
		cout << endl << "Entrez l'annee d'entree en vigueur du contrat (aaaa) : ";
		cin >> anneeEntree;
		cout << endl << "Entrez le jour de fin du contrat (jj) : ";
		cin >> jourContrat;
		cout << endl << "Entrez le mois de fin du contrat (mm) : ";
		cin >> moisContrat;
		cout << endl << "Entrez l'annee de fin du contrat (aaaa) : ";
		cin >> anneeContrat;
		cout << endl << "Entrez le seuil du nouveau reglement : ";
		cin >> seuil;
		cout << endl << "Entrez les nouveaux droits pour le reglement : ";
		cin >> droits;

		if (indice != 999)
		{
			if (ligueSoccer->getContrat(indice)->getJoueurContractant()->briserContrat() == 0)
			{
				if (indiceVieilleEquipe != 999)
					ligueSoccer->finContrat(ligueSoccer->getContrat(indice)->getJoueurContractant(), ligueSoccer->getClub(clubAcheteur), ligueSoccer->getClub(indiceVieilleEquipe), annee, Date(jourEntree, moisEntree, anneeEntree), Date(jourContrat, moisContrat, anneeContrat), Reglement(seuil, droits, montantTransfert, montantEncaisse, montantRestant), clubAcheteur, indiceVieilleEquipe);
			}
			else
			{
				cout << "Il s'agit d'un joueur autonome. Avec les informations precedentes, celui-ci brise-t-il son contrant ou arrive-t-il a echeance?" << endl;
				cout << "(1) Romp son contrat" << endl;
				cout << "(2) Arrive a echeance" << endl;
				cin >> choix;

				switch (choix)
				{
				case 1:
					cout << endl << "Veuillez entrez la raison du depart : ";
					cin >> raison;

					if (indiceVieilleEquipe != 999)
						ligueSoccer->ruptureContrat(ligueSoccer->getContrat(indice)->getJoueurContractant(), ligueSoccer->getClub(clubAcheteur), ligueSoccer->getClub(indiceVieilleEquipe), annee, Date(jourEntree, moisEntree, anneeEntree), Date(jourContrat, moisContrat, anneeContrat), Reglement(seuil, droits, montantTransfert, montantEncaisse, montantRestant), clubAcheteur, indiceVieilleEquipe, raison);
					break;
				case 2:
					if (indiceVieilleEquipe != 999)
						ligueSoccer->finContrat(ligueSoccer->getContrat(indice)->getJoueurContractant(), ligueSoccer->getClub(clubAcheteur), ligueSoccer->getClub(indiceVieilleEquipe), annee, Date(jourEntree, moisEntree, anneeEntree), Date(jourContrat, moisContrat, anneeContrat), Reglement(seuil, droits, montantTransfert, montantEncaisse, montantRestant), clubAcheteur, indiceVieilleEquipe);
					break;
				default:
					cout << "Choix invalide. Veuillez recommencer du debut." << endl;
				}
			}
		}
		else
		{
			cout << endl << "ERREUR LORS DU TRANSFERT" << endl << endl;
		}
	}

	delete acheteur;
	delete vendeur;
	delete msgVendeur;
	delete msgAcheteur;
	delete flag;
	delete montantNego;
	system("pause");
}