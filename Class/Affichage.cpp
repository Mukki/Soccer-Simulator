#include "Affichage.h"

Affichage::Affichage(LigueSoccer* ligueSoccer)
{
	this->ligueSoccer = ligueSoccer;
}

Affichage::Affichage()
{
	//NOP
}

void Affichage::lireFichier()
{
	system("cls");

	string clubFilename;

	cout << "Par manque de temps, le seul fichier qui sera lus sera les clubs. Les autres auraient ete fait de maniere analogue." << endl;

	cout << "Veuillez entrer le nom du fichier de club: ";
	cin >> clubFilename;
	cout << endl;

	try
	{
		ifstream file(clubFilename);

		if (file.is_open())
		{
			string nom, histoire, couleur, ville, adresse;

			file >> nom >> histoire >> couleur >> ville >> adresse;

			while (!file.eof())
			{
				ligueSoccer->ajouterClub(nom, histoire, couleur, ville, adresse);

				file >> nom >> histoire >> couleur >> ville >> adresse;
			}

			ligueSoccer->leClub(0)->ajoutPalmares("Club de l'annee 2002", "10", "10", "2002");
			ligueSoccer->leClub(0)->ajoutPalmares("Club de l'annee 2004", "10", "10", "2004");
			ligueSoccer->leClub(0)->ajoutPalmares("Club de l'annee 2008", "10", "10", "2008");
			ligueSoccer->leClub(1)->ajoutPalmares("Club de l'annee 2010", "10", "10", "2010");
			ligueSoccer->leClub(1)->ajoutPalmares("Club de l'annee 2013", "10", "10", "2013");
			ligueSoccer->leClub(2)->ajoutPalmares("Club de l'annee 2014", "10", "10", "2014");

			Reglement unReglement(8000, "Quitter l'equipe", 7000, 2000, 5000);
			Date dateEntree1("20", "10", "2016");
			Date dateEntree2("10", "09", "2008");
			Date dateEntree3("30", "04", "1999");
			Date dateContrat("20", "10", "2018");

			ligueSoccer->vect_club[0]->ajoutJoueurAutonome("Beleren", "Jace", 10, 14, "Vryn");
			ligueSoccer->ajouterContrat(ligueSoccer->vect_club[0]->leJoueur(0), ligueSoccer->leClub(0), ligueSoccer->leClub(1), 10, dateEntree1, unReglement, dateContrat);
			ligueSoccer->vect_club[0]->ajoutJoueurNonAutonome("Naalar", "Chandra", 12, 12, "Kaladesh");
			ligueSoccer->ajouterContrat(ligueSoccer->vect_club[0]->leJoueur(0), ligueSoccer->leClub(0), ligueSoccer->leClub(2), 8, dateEntree2, unReglement, dateContrat);
			ligueSoccer->vect_club[0]->ajoutJoueurAutonome("Jura", "Gideon", 14, 10, "Akros");
			ligueSoccer->ajouterContrat(ligueSoccer->vect_club[0]->leJoueur(0), ligueSoccer->leClub(0), ligueSoccer->leClub(3), 2, dateEntree3, unReglement, dateContrat);

			ligueSoccer->vect_club[1]->ajoutJoueurNonAutonome("Vess", "Liliana", 10, 12, "Caligo");
			ligueSoccer->ajouterContrat(ligueSoccer->vect_club[1]->leJoueur(0), ligueSoccer->leClub(1), ligueSoccer->leClub(0), 5, dateEntree1, unReglement, dateContrat);
			ligueSoccer->vect_club[1]->ajoutJoueurAutonome("Revane", "Nissa", 12, 10, "Bala Ged");
			ligueSoccer->ajouterContrat(ligueSoccer->vect_club[1]->leJoueur(0), ligueSoccer->leClub(1), ligueSoccer->leClub(2), 9, dateEntree2, unReglement, dateContrat);

			ligueSoccer->vect_club[2]->ajoutJoueurNonAutonome("Wildspeaker", "Garruk", 8, 12, "Unknown");
			ligueSoccer->ajouterContrat(ligueSoccer->vect_club[2]->leJoueur(0), ligueSoccer->leClub(2), ligueSoccer->leClub(0), 9, dateEntree1, unReglement, dateContrat);
			ligueSoccer->vect_club[2]->ajoutJoueurAutonome("Goldmane", "Ajani", 14, 8, "Qasal Valley");
			ligueSoccer->ajouterContrat(ligueSoccer->vect_club[2]->leJoueur(0), ligueSoccer->leClub(2), ligueSoccer->leClub(1), 9, dateEntree2, unReglement, dateContrat);

			ligueSoccer->vect_club[3]->ajoutJoueurNonAutonome("Vol", "Sarkhan", 12, 10, "Tarkir");
			ligueSoccer->ajouterContrat(ligueSoccer->vect_club[3]->leJoueur(0), ligueSoccer->leClub(3), ligueSoccer->leClub(4), 9, dateEntree1, unReglement, dateContrat);

			ligueSoccer->vect_club[4]->ajoutJoueurAutonome("Markov", "Sorin", 10, 8, "Stensia");
			ligueSoccer->ajouterContrat(ligueSoccer->vect_club[4]->leJoueur(0), ligueSoccer->leClub(4), ligueSoccer->leClub(3), 9, dateEntree1, unReglement, dateContrat);

			ligueSoccer->ajouterEntraineur("Tirel", "Elspeth", "Unknown");
			ligueSoccer->lEntraineur(0)->ajouterPalmares("Meilleur entraineur mondial 2014", "1", "1", "2016", ligueSoccer->leClub(0));

			ligueSoccer->ajouterEntraineur("Bolas", "Nicol", "Dominaria");
			ligueSoccer->lEntraineur(0)->ajouterPalmares("Le plus chialeux", "11", "10", "2010", ligueSoccer->leClub(2));
			ligueSoccer->lEntraineur(0)->ajouterPalmares("Meilleur porteur d'eau", "30", "11", "2013", ligueSoccer->leClub(2));

			ligueSoccer->ajouterEntraineur("Nixilis", "Ob", "Shandalar");

			for (int x = 24; x > 20; x--)
			{
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
				clubUn = ligueSoccer->leClub(variableUn);
				clubDeux = ligueSoccer->leClub(variableDeux);
				Rencontre* uneRencontre;
				uneRencontre = new Rencontre(uneDate, clubUn, clubDeux, NULL);
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
				clubUn = ligueSoccer->leClub(variableUn);
				clubDeux = ligueSoccer->leClub(variableDeux);

				Equipe equipeLoc(clubUn, 8, 1, ligueSoccer->vect_club[variableUn]->leJoueur(0));
				Equipe equipeVis(clubDeux, 8, 1, ligueSoccer->vect_club[variableDeux]->leJoueur(0));
				Periode premPer(15, rand() % 5, rand() % 5);
				Periode deuxPer(15, rand() % 5, rand() % 5);
				Resultat result((premPer.leNbButsLocaux() + deuxPer.leNbButsLocaux()), (premPer.leNbButsVisiteurs() + deuxPer.leNbButsVisiteurs()));
				unMatch = new Match(equipeLoc, equipeVis, premPer, deuxPer, result);
				Rencontre* uneRencontre;
				uneRencontre = new Rencontre(uneDate, clubUn, clubDeux, unMatch);
				calendrierRencontres.ajoutRencontre(uneRencontre);
			}

		}
		else
		{
			Exception<string> lexception("fichier club");
			throw lexception;
		}

		file.close();

	}

	catch(Exception<string> lexception)
	{
		cout << "Probleme de lecture du fichier : exception avec le " << lexception.leType() << endl;

		cout << "La ligue hardcoder est appele" << endl;

		ligueHardcoder();
	}

	catch (Exception<int> lexception)
	{
		cout << "Probleme de lecture du fichier : exception numero " << lexception.leType() << endl;

		cout << "La ligue hardcoder est appele" << endl;

		ligueHardcoder();
	}

	system("pause");
}

void Affichage::enregistrerFichier()
{
	system("cls");

	string clubFilename;

	cout << "Par manque de temps, le seul fichier qui sera sauvegarder sera les clubs. Les autres auraient ete fait de maniere analogue." << endl;

	cout << "Veuillez entrer le nom du fichier de club: ";
	cin >> clubFilename;
	cout << endl;

	try
	{
		ofstream file(clubFilename, ios::trunc);

		if (file.is_open())
		{
			for (int i = 0; i < ligueSoccer->leNbClub(); i++)
				file << ligueSoccer->leClub(i)->leNom() << " " << ligueSoccer->leClub(i)->lHistoire() << " " << ligueSoccer->leClub(i)->laCouleur() << " " << ligueSoccer->leClub(i)->laVille() << " " << ligueSoccer->leClub(i)->lAdresse() << endl;
		}
		else
		{
			Exception<string> lexception("fichier club");
			throw lexception;
		}

		file.close();
	}

	catch (Exception<string> lexception)
	{
		cout << "Probleme d'ecriture du fichier : exception avec le " << lexception.leType() << endl;

		cout << "La ligue hardcoder est appele" << endl;

		ligueHardcoder();
	}

	catch (Exception<int> lexception)
	{
		cout << "Probleme de lecture du fichier : exception numero " << lexception.leType() << endl;

		cout << "La ligue hardcoder est appele" << endl;

		ligueHardcoder();
	}
}

void Affichage::ajouterClub()
{
	string nom;
	string histoire;
	string couleur;
	string ville;
	string adresse;

	system("cls");
	cout << "Ajout d'un club" << endl;
	cout << "Entrez un nom : ";
	cin >> nom;			
	cout << "Entrez une histoire : ";
	cin >> histoire; 
	cout << "Entrez une couleur : ";
	cin >> couleur; 
	cout << "Entrez une ville : ";
	cin >> ville; 
	cout << "Entrez une adresse : ";
	cin >> adresse;

	ligueSoccer->ajouterClub(nom,histoire,couleur,ville,adresse);
}

void Affichage::afficherClub()
{
	system("cls");
	int nbClub = ligueSoccer->vect_club.size();

	cout << "Les clubs: " << endl;

	for (int i = 0; i < nbClub; i++)
	{
		cout << "Nom du club : " << ligueSoccer->leClub(i)->leNom() << endl;
		cout << "Histoire du club : " << ligueSoccer->leClub(i)->lHistoire() << endl;
		cout << "Couleur du club : " << ligueSoccer->leClub(i)->laCouleur() << endl;
		cout << "Ville du club : " << ligueSoccer->leClub(i)->laVille() << endl;
		cout << "Adresse du club : " << ligueSoccer->leClub(i)->lAdresse() << endl;
		cout << ligueSoccer->leClub(i)->leNbPalmares() << " Palmares" << endl << endl;
	}
}

void Affichage::supprimerClub()
{
	system("cls");

	int nbClub = ligueSoccer->vect_club.size();
	int choix;
	cout << "Suppression d'un Club" << endl; 

	for (int i = 0; i < nbClub; i++)
	{
		cout << i+1 << ". " << ligueSoccer->vect_club[i]->leNom() << endl;	
	}

	cout << "Entrez le numero du club a supprimer : ";
	cin >> choix;
	choix--;

	ligueSoccer->supprimerClub(choix);

	system("cls");
	cout << "Suppression Confirmee" << endl;
}

void Affichage::ligueHardcoder()
{
	ligueSoccer->ajouterClub("Plaines", "TraverserLesPlaines", "Blanc", "Alara", "123DesPlaines");
	ligueSoccer->ajouterClub("Montagnes", "EscaladerDesMontagnes", "Rouge", "Dominaria", "2424DeLaMontagne");
	ligueSoccer->ajouterClub("Iles", "NagerJusqu'auIles", "Bleu", "Kamigawa", "765DesIles");
	ligueSoccer->ajouterClub("Forets", "ExplorerLesForets", "Vert", "Lorwyn", "34DeLaForet");
	ligueSoccer->ajouterClub("Marais", "CacherLesMarais", "Noir", "Innistrad", "890DesMarais");

	ligueSoccer->leClub(0)->ajoutPalmares("Club de l'annee 2002", "10", "10", "2002");
	ligueSoccer->leClub(0)->ajoutPalmares("Club de l'annee 2004", "10", "10", "2004");
	ligueSoccer->leClub(0)->ajoutPalmares("Club de l'annee 2008", "10", "10", "2008");
	ligueSoccer->leClub(1)->ajoutPalmares("Club de l'annee 2010", "10", "10", "2010");
	ligueSoccer->leClub(1)->ajoutPalmares("Club de l'annee 2013", "10", "10", "2013");
	ligueSoccer->leClub(2)->ajoutPalmares("Club de l'annee 2014", "10", "10", "2014");

	Reglement unReglement(8000, "Quitter l'equipe", 7000, 2000, 5000);
	Date dateEntree1("20", "10", "2016");
	Date dateEntree2("10", "09", "2008");
	Date dateEntree3("30", "04", "1999");
	Date dateContrat("20", "10", "2018");

	ligueSoccer->vect_club[0]->ajoutJoueurAutonome("Beleren", "Jace", 10, 14, "Vryn");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[0]->leJoueur(0), ligueSoccer->leClub(0), ligueSoccer->leClub(1), 10, dateEntree1, unReglement, dateContrat);
	ligueSoccer->vect_club[0]->ajoutJoueurNonAutonome("Naalar", "Chandra", 12, 12, "Kaladesh");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[0]->leJoueur(0), ligueSoccer->leClub(0), ligueSoccer->leClub(2), 8, dateEntree2, unReglement, dateContrat);
	ligueSoccer->vect_club[0]->ajoutJoueurAutonome("Jura", "Gideon", 14, 10, "Akros");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[0]->leJoueur(0), ligueSoccer->leClub(0), ligueSoccer->leClub(3), 2, dateEntree3, unReglement, dateContrat);

	ligueSoccer->vect_club[1]->ajoutJoueurNonAutonome("Vess", "Liliana", 10, 12, "Caligo");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[1]->leJoueur(0), ligueSoccer->leClub(1), ligueSoccer->leClub(0), 5, dateEntree1, unReglement, dateContrat);
	ligueSoccer->vect_club[1]->ajoutJoueurAutonome("Revane", "Nissa", 12, 10, "Bala Ged");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[1]->leJoueur(0), ligueSoccer->leClub(1), ligueSoccer->leClub(2), 9, dateEntree2, unReglement, dateContrat);

	ligueSoccer->vect_club[2]->ajoutJoueurNonAutonome("Wildspeaker", "Garruk", 8, 12, "Unknown");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[2]->leJoueur(0), ligueSoccer->leClub(2), ligueSoccer->leClub(0), 9, dateEntree1, unReglement, dateContrat);
	ligueSoccer->vect_club[2]->ajoutJoueurAutonome("Goldmane", "Ajani", 14, 8, "Qasal Valley");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[2]->leJoueur(0), ligueSoccer->leClub(2), ligueSoccer->leClub(1), 9, dateEntree2, unReglement, dateContrat);

	ligueSoccer->vect_club[3]->ajoutJoueurNonAutonome("Vol", "Sarkhan", 12, 10, "Tarkir");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[3]->leJoueur(0), ligueSoccer->leClub(3), ligueSoccer->leClub(4), 9, dateEntree1, unReglement, dateContrat);

	ligueSoccer->vect_club[4]->ajoutJoueurAutonome("Markov", "Sorin", 10, 8, "Stensia");
	ligueSoccer->ajouterContrat(ligueSoccer->vect_club[4]->leJoueur(0), ligueSoccer->leClub(4), ligueSoccer->leClub(3), 9, dateEntree1, unReglement, dateContrat);

	ligueSoccer->ajouterEntraineur("Tirel", "Elspeth", "Unknown");
	ligueSoccer->lEntraineur(0)->ajouterPalmares("Meilleur entraineur mondial 2014", "1", "1", "2016", ligueSoccer->leClub(0));

	ligueSoccer->ajouterEntraineur("Bolas", "Nicol", "Dominaria");
	ligueSoccer->lEntraineur(0)->ajouterPalmares("Le plus chialeux", "11", "10", "2010", ligueSoccer->leClub(2));
	ligueSoccer->lEntraineur(0)->ajouterPalmares("Meilleur porteur d'eau", "30", "11", "2013", ligueSoccer->leClub(2));

	ligueSoccer->ajouterEntraineur("Nixilis", "Ob", "Shandalar");

	for (int x = 24; x > 20; x--)
	{
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
		clubUn = ligueSoccer->leClub(variableUn);
		clubDeux = ligueSoccer->leClub(variableDeux);
		Rencontre* uneRencontre;
		uneRencontre = new Rencontre(uneDate, clubUn, clubDeux, NULL);
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
		clubUn = ligueSoccer->leClub(variableUn);
		clubDeux = ligueSoccer->leClub(variableDeux);

		Equipe equipeLoc(clubUn, 8, 1, ligueSoccer->vect_club[variableUn]->leJoueur(0));
		Equipe equipeVis(clubDeux, 8, 1, ligueSoccer->vect_club[variableDeux]->leJoueur(0));
		Periode premPer(15, rand() % 5, rand() % 5);
		Periode deuxPer(15, rand() % 5, rand() % 5);
		Resultat result((premPer.leNbButsLocaux() + deuxPer.leNbButsLocaux()), (premPer.leNbButsVisiteurs() + deuxPer.leNbButsVisiteurs()));
		unMatch = new Match(equipeLoc, equipeVis, premPer, deuxPer, result);
		Rencontre* uneRencontre;
		uneRencontre = new Rencontre(uneDate, clubUn, clubDeux, unMatch);
		calendrierRencontres.ajoutRencontre(uneRencontre);
	}
}

void Affichage::afficherJoueur()
{
	system("cls");

	int nbClub = ligueSoccer->vect_club.size();
	int choix;
	cout << "Selection d'un Club pour afficher ses joueurs" << endl; 

	for (int i = 0;i < nbClub; i++)
	{
		cout << i+1 << ". " << ligueSoccer->vect_club[i]->leNom() << endl;	
	}

	cout << "Entrez le numeros du club a afficher les joueurs : ";
	cin >> choix;
	choix--;

	system("cls");

	Club* club = ligueSoccer->leClub(choix);
	int nbJoueurs = club->leNbJoueur();
	
	cout << "Equipe : " << club->leNom() << endl;
	cout << "Nombre de joueurs : " << nbJoueurs << endl;
	
	for (int i = 0; i < nbJoueurs; i++)
	{
		Joueur* pJoueur = club->leJoueur(i);
		Contrat* pContrat = ligueSoccer->leContrat(i);
		Date dateTmp;
		string date;

		dateTmp = pContrat->laDateEntree();
		date = dateTmp.laDateEnTexte();

		cout << i+1 << ". " << pJoueur->lePrenom() << " " << pJoueur->leNom() << endl;
	}

	cout << endl;
}

void Affichage::afficherEntraineurs()
{
	system("cls");
	int nbEntraineurs = ligueSoccer->leNbEntraineur();

	cout << "Liste des entraineurs" << endl;

	cout << "Nombre d'entraineurs : " << nbEntraineurs << endl << endl;

	for (int i = 0; i < nbEntraineurs; i++)
	{
		Entraineur* pEntraineur = ligueSoccer->lEntraineur(i);
		cout << i+1 << ". " << pEntraineur->leNom() << " " << pEntraineur->lePrenom() << endl;
		cout << "Lieu obtention du grade : " << pEntraineur->lelieuObtention() << endl;
		
		int nbPalmares = pEntraineur->leNbPalmares();

		for(int j = 0; j < nbPalmares; j++)
		{
			Palmares* pPalmares = ligueSoccer->lEntraineur(i)->lePalmares(j);
			cout << endl;
			cout << "Palmares" << endl;
			cout << "Titre : " << pPalmares->leTitre() << endl;
			cout << "Date  : " << pPalmares->laDate().laDateEnTexte() << endl;
			cout << "Club  : " << pPalmares->leClub()->leNom() << endl;
		}

		cout << endl;
	}
}

void Affichage::afficherMeilleurEntraineur()
{
	system("cls");

	int nbEntraineurs = ligueSoccer->leNbEntraineur();
	if(nbEntraineurs)
	{
	int nbPalmares=ligueSoccer->lEntraineur(0)->leNbPalmares(),cpt=0,index=0;
	Entraineur* unEntraineur;

	for(int i=0;i<nbEntraineurs;i++)
		{	
		for(int j=0;j<nbEntraineurs;j++)
			{
			if(ligueSoccer->lEntraineur(i)->leNbPalmares() <
			   ligueSoccer->lEntraineur(j)->leNbPalmares() )
				{
				nbPalmares = ligueSoccer->lEntraineur(j)->leNbPalmares();
				index = j;
				break;
				}		
			}	
		}
	unEntraineur = ligueSoccer->lEntraineur(index);

	cout << "Entraineur le plus titre :" << endl;
	cout << unEntraineur->lePrenom() << " " << unEntraineur->leNom() << endl;
	cout << "Avec " << unEntraineur->leNbPalmares() << " palmares " << endl;
	cout << endl;

	}
	else
		cout << "Aucun entraineur trouve" << endl;
}

void Affichage::afficherMeilleurClub()
{
	system("cls");

	int nbClub = ligueSoccer->leNbClub();
	if (nbClub)
	{
		int nbPalmares=ligueSoccer->leClub(0)->leNbPalmares(),cpt=0,index=0;
		Club* unClub;

		for(int i = 0; i < nbClub; i++)
		{	
			for(int j = 0; j < nbClub; j++)
			{
				if(ligueSoccer->leClub(i)->leNbPalmares() < ligueSoccer->leClub(j)->leNbPalmares() )
				{
					nbPalmares = ligueSoccer->leClub(j)->leNbPalmares();
					index = j;
					break;
				}		
			}	
		}
		unClub = ligueSoccer->leClub(index);

		cout << "Club le plus titre" << endl;
		cout << "Il s'agit du club " << unClub->leNom();
		cout << " avec " << unClub->leNbPalmares() << " palmares " << endl;
		cout << endl;
	}
	else
		cout << "Aucuns clubs trouves" << endl;
}

void Affichage::afficherCalendrier()
{
	system("cls");

	cout << "Les rencontres" << endl << endl;

	for (int i = 0; i < calendrierRencontres.leNbRencontre(); i++)
	{
		cout << "Rencontre " << i + 1 << endl;
		cout << "Club local : " << calendrierRencontres.leNomClubLocal(i) << endl;
		cout << "Club visiteur : " << calendrierRencontres.leNomClubVisiteur(i) << endl;
		cout << "Date de l'affrontement : " << calendrierRencontres.laDate(i).laDateEnTexte() << endl;

		if (calendrierRencontres.laRencontre(i)->leMatch() != NULL)
		{
			cout << "Resultat equipe locale : " << calendrierRencontres.laRencontre(i)->leMatch()->leResultatFinal().leNbButsLocaux() << endl;
			cout << "Resultat equipe visiteur : " << calendrierRencontres.laRencontre(i)->leMatch()->leResultatFinal().leNbButsVisiteurs() << endl;
		}
		else
		{
			cout << "Le match n'a pas encore eu lieu" << endl;
		}
		cout << endl;
	}
}

void Affichage::ajouterJoueur()
{
	system("cls");

	int nbClub = ligueSoccer->vect_club.size();
	int choix, ancienClub;
	cout << "Dans quel club voulez-vous ajouter un joueur?" << endl;

	for (int i = 0; i<nbClub; i++)
	{
		cout << i + 1 << ". : " << ligueSoccer->vect_club[i]->leNom() << endl;
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

	cout << endl << "Ajouter un joueur" << endl;
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
	unContrat = new Contrat(ligueSoccer->leClub(choix)->leJoueur(0), ligueSoccer->leClub(choix), ligueSoccer->leClub(ancienClub), dureeContrat, dateEntree, unReglement, dateContrat);

	ligueSoccer->vect_club[choix]->ajoutJoueur(leNom, lePrenom, taille, poids, laVilleNaissance);
	ligueSoccer->vect_contrat.push_back(unContrat);
}

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

		cout << "Un joueur contractant correspondant a votre entree a ete retrouve : " << endl << endl;
		contratTrouve = ligueSoccer->leContrat(indice);
		contratTrouve->leJoueurContractant();
		dateContrat = contratTrouve->laDateEntree();
		clubLibere = contratTrouve->leClubLibere();
		clubContractant = contratTrouve->leClubContractant();
		cout << "Nom du joueur contractant : " << contratTrouve->leJoueurContractant()->lePrenom() << " " << contratTrouve->leJoueurContractant()->leNom() << endl;
		cout << "Date d'entree en vigueur du contrat : " << dateContrat.laDateEnTexte() << endl;
		cout << "Duree du contrat (annees) : " << contratTrouve->laDureeContrat() << endl;
		cout << "Club libere : " << clubLibere->leNom() << endl;
		cout << "Club contractant : " << clubContractant->leNom() << endl << endl;
	}
	else {
		cout << "Aucun joueur contractant trouve correspondant a votre critere de recherche" << endl << endl;
	}

	int choix, indiceNouvelEquipe, annee;
	string jourEntree, moisEntree, anneeEntree, jourContrat, moisContrat, anneeContrat;

	int indiceVieilleEquipe = ligueSoccer->trouverClubJoueur(ligueSoccer->leContrat(indice)->leClubContractant()->leNom());

	float seuil;
	string droits, raison;
	float montantTransfert;
	float montantEncaisse;
	float montantRestant;

	if (ligueSoccer->leContrat(indice)->leJoueurContractant()->briserContrat() == 0)
	{
		cout << "Il s'agit d'un joueur non autonome. Avec les infos precedentes, peut-il toujours mettre fin a son contrat?" << endl;
		cout << "1. Oui" << endl;
		cout << "2. Non" << endl;
		cin >> choix;

		switch (choix)
		{
			case 1:
				for (int i = 0; i<ligueSoccer->leNbClub(); i++)
				{
					cout << i + 1 << ". " << ligueSoccer->vect_club[i]->leNom() << endl;
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
					ligueSoccer->finContrat(ligueSoccer->leContrat(indice)->leJoueurContractant(), ligueSoccer->leClub(indiceNouvelEquipe - 1), ligueSoccer->leClub(indiceVieilleEquipe), annee, Date(jourEntree, moisEntree, anneeEntree), Date(jourContrat, moisContrat, anneeContrat), Reglement(seuil, droits, montantTransfert, montantEncaisse, montantRestant), indiceNouvelEquipe - 1, indiceVieilleEquipe);
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
		cout << "1. Romp son contrat" << endl;
		cout << "2. Arrive a echeance" << endl;
		cin >> choix;

		for (int i = 0; i<ligueSoccer->leNbClub(); i++)
		{
			cout << i + 1 << ". " << ligueSoccer->vect_club[i]->leNom() << endl;
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
				ligueSoccer->ruptureContrat(ligueSoccer->leContrat(indice)->leJoueurContractant(), ligueSoccer->leClub(indiceNouvelEquipe - 1), ligueSoccer->leClub(indiceVieilleEquipe), annee, Date(jourEntree, moisEntree, anneeEntree), Date(jourContrat, moisContrat, anneeContrat), Reglement(seuil, droits, montantTransfert, montantEncaisse, montantRestant), indiceNouvelEquipe - 1, indiceVieilleEquipe, raison);
			break;
		case 2:
			if (indiceVieilleEquipe != 999)
				ligueSoccer->finContrat(ligueSoccer->leContrat(indice)->leJoueurContractant(), ligueSoccer->leClub(indiceNouvelEquipe - 1), ligueSoccer->leClub(indiceVieilleEquipe), annee, Date(jourEntree, moisEntree, anneeEntree), Date(jourContrat, moisContrat, anneeContrat), Reglement(seuil, droits, montantTransfert, montantEncaisse, montantRestant), indiceNouvelEquipe - 1, indiceVieilleEquipe);
			break;
		default:
			cout << "Choix invalide. Veuillez recommencer du debut." << endl;
		}
	}
}

void Affichage::ajouterMatch() {
	system("cls");

	int nbClub = ligueSoccer->vect_club.size();
	int clubLocal, clubVisit;
	cout << "Ajouter une rencontre" << endl;

	for (int i = 0; i<nbClub; i++)
	{
		cout << i + 1 << ". " << ligueSoccer->vect_club[i]->leNom() << endl;
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
			capitaineLoc = ligueSoccer->leClub(clubLocal)->leJoueur(indiceCptLoc);
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
			capitaineVis = ligueSoccer->leClub(clubVisit)->leJoueur(indiceCptVis);
		}
		else {
			flag = 1;
			cout << endl << "Veuillez entrer un prenom valide pour le capitaine : ";
			cin >> prenomCaptVis;
		}
	} while (flag == 1);

	Equipe equipeLoc(ligueSoccer->leClub(clubLocal), nbJoueursLoc, nbGardiensLoc, capitaineLoc);
	Equipe equipeVis(ligueSoccer->leClub(clubVisit), nbJoueursVis, nbGardiensVis, capitaineVis);

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

		uneRencontre = new Rencontre(dateRencontre, ligueSoccer->leClub(clubLocal), ligueSoccer->leClub(clubVisit), unMatch);
		calendrierRencontres.ajoutRencontre(uneRencontre);
	}
	else {
		uneRencontre = new Rencontre(dateRencontre, ligueSoccer->leClub(clubLocal), ligueSoccer->leClub(clubVisit), NULL);
		calendrierRencontres.ajoutRencontre(uneRencontre);
	}
}

void Affichage::afficherRencontresClub()
{
	system("cls");

	string nomClub;
	int nbClub = ligueSoccer->vect_club.size();
	int choix;
	cout << "Afficher les rencontres pour un club" << endl;

	for (int i = 0; i<nbClub; i++)
	{
		cout << i + 1 << ". " << ligueSoccer->vect_club[i]->leNom() << endl;
	}

	cout << endl << "Entrez le numero du club local : ";
	cin >> choix;
	choix--;
	cout << endl;

	nomClub = ligueSoccer->leClub(choix)->leNom();

	for (int i = 0; i < calendrierRencontres.leNbRencontre(); i++) {
		if (calendrierRencontres.leNomClubLocal(i) == nomClub) {
			cout << "Rencontre #" << i + 1 << endl;
			cout << "Club local : " << calendrierRencontres.leNomClubLocal(i) << endl;
			cout << "Club visiteur : " << calendrierRencontres.leNomClubVisiteur(i) << endl;
			cout << "Date de l'affrontement : " << calendrierRencontres.laDate(i).laDateEnTexte() << endl;

			if (calendrierRencontres.laRencontre(i)->leMatch() != NULL) {
				cout << "Resultat equipe locale : " << calendrierRencontres.laRencontre(i)->leMatch()->leResultatFinal().leNbButsLocaux() << endl;
				cout << "Resultat equipe visiteur : " << calendrierRencontres.laRencontre(i)->leMatch()->leResultatFinal().leNbButsVisiteurs() << endl;
			}
			else {
				cout << "Le match n'a pas encore eu lieu ou n'aura pas lieu..." << endl;
			}
		}
	}
}

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


	for (int i = 0; i < calendrierRencontres.leNbRencontre(); i++) {
		if (calendrierRencontres.laDate(i).laDateEnTexte() == date) {
			matchTrouve = 1;
			cout << "Rencontre " << i + 1 << endl;
			cout << "Club local : " << calendrierRencontres.leNomClubLocal(i) << endl;
			cout << "Club visiteur : " << calendrierRencontres.leNomClubVisiteur(i) << endl;
			cout << "Date de l'affrontement : " << calendrierRencontres.laDate(i).laDateEnTexte() << endl;

			if (calendrierRencontres.laRencontre(i)->leMatch() != NULL) {
				cout << "Resultat equipe locale : " << calendrierRencontres.laRencontre(i)->leMatch()->leResultatFinal().leNbButsLocaux() << endl;
				cout << "Resultat equipe visiteur : " << calendrierRencontres.laRencontre(i)->leMatch()->leResultatFinal().leNbButsVisiteurs() << endl;
			}
			else {
				cout << "Le match n'a pas encore eu lieu ou n'aura pas lieu..." << endl;
			}
		}
	}
	if (matchTrouve == 0)
		cout << "Aucun match correspondant a la date entree n'a ete retrouve" << endl;
}

void Affichage::afficherEncaisses()
{
	system("cls");

	string jour, mois, annee;
	float montantEncaisseTotal = 0;
	int choix;
	cout << "Afficher les revenues de transfert pour un club" << endl;

	for (int i = 0; i < ligueSoccer->leNbClub(); i++)
	{
		cout << i + 1 << ". " << ligueSoccer->vect_club[i]->leNom() << endl;
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

	for (int i = 0; i < ligueSoccer->leClub(choix)->leNbContratEchu(); i++) {
		if (ligueSoccer->leClub(choix)->leContratEchu(i)->laDateContrat().lAnnee() > annee)
			montantEncaisseTotal = montantEncaisseTotal + ligueSoccer->leClub(choix)->leContratEchu(i)->leReglement().leMontantEncaisse();
		else if (ligueSoccer->leClub(choix)->leContratEchu(i)->laDateContrat().lAnnee() == annee)
			if (ligueSoccer->leClub(choix)->leContratEchu(i)->laDateContrat().leMois() > mois)
				montantEncaisseTotal = montantEncaisseTotal + ligueSoccer->leClub(choix)->leContratEchu(i)->leReglement().leMontantEncaisse();
			else if (ligueSoccer->leClub(choix)->leContratEchu(i)->laDateContrat().leMois() == mois)
				if (ligueSoccer->leClub(choix)->leContratEchu(i)->laDateContrat().leJour() > jour)
					montantEncaisseTotal = montantEncaisseTotal + ligueSoccer->leClub(choix)->leContratEchu(i)->leReglement().leMontantEncaisse();
	}
	cout << "Montant encaisse par le club apres " << jour << "/" << mois << "/" << annee << ": " << montantEncaisseTotal << "$" << endl;
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
		cout << i + 1 << ". " << ligueSoccer->vect_club[i]->leNom() << endl;
	}

	cout << endl << "Entrez le numero du club acheteur : ";
	cin >> clubAcheteur;
	clubAcheteur--;
	cout << endl << "Entrez le numero du club vendeur : ";
	cin >> clubVendeur;
	clubVendeur--;

	system("cls");

	Club* club = ligueSoccer->leClub(clubVendeur);
	int nbJoueurs = club->leNbJoueur();

	cout << "Equipe : " << club->leNom() << endl;
	cout << "Nombre de joueurs : " << nbJoueurs << endl;

	for (int i = 0; i<nbJoueurs; i++)
	{
		Joueur* pJoueur = club->leJoueur(i);
		Contrat* pContrat = ligueSoccer->leContrat(i);
		Date dateTmp;
		string date;

		dateTmp = pContrat->laDateEntree();
		date = dateTmp.laDateEnTexte();

		cout << i + 1 << ". " << pJoueur->leNom() << " " << pJoueur->lePrenom() << endl;
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
	acheteur = new NegoAcheteur(achMax, achMin, duree, ligueSoccer->leClub(clubAcheteur), msgVendeur, msgAcheteur, flag);
	NegoVendeur* vendeur;
	vendeur = new NegoVendeur(venMax, venMin, duree, ligueSoccer->leClub(clubVendeur), msgVendeur, msgAcheteur, flag, montantNego);

	thread threadAcheteur(DebuterNego, acheteur);
	thread threadVendeur(DebuterNego, vendeur);

	threadAcheteur.join();
	threadVendeur.join();

	int annee, indice, choix;
	string droits, jourEntree, moisEntree, anneeEntree, jourContrat, moisContrat, anneeContrat, raison;
	float seuil, montantTransfert, montantEncaisse, montantRestant;

	montantTransfert = vendeur->getMontantCourant();
	montantEncaisse = montantTransfert * 0.8;
	montantRestant = montantTransfert * 0.2;

	indice = ligueSoccer->trouverJoueurContrat(ligueSoccer->leClub(clubVendeur)->leJoueur(joueurEchange)->lePrenom());
	int indiceVieilleEquipe = clubVendeur--;//ligueSoccer->trouverClubJoueur(ligueSoccer->leContrat(joueurEchange)->leClubContractant()->leNom());

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
			if (ligueSoccer->leContrat(indice)->leJoueurContractant()->briserContrat() == 0)
			{
				if (indiceVieilleEquipe != 999)
					ligueSoccer->finContrat(ligueSoccer->leContrat(indice)->leJoueurContractant(), ligueSoccer->leClub(clubAcheteur), ligueSoccer->leClub(indiceVieilleEquipe), annee, Date(jourEntree, moisEntree, anneeEntree), Date(jourContrat, moisContrat, anneeContrat), Reglement(seuil, droits, montantTransfert, montantEncaisse, montantRestant), clubAcheteur, indiceVieilleEquipe);
			}
			else
			{
				cout << "Il s'agit d'un joueur autonome. Avec les informations precedentes, celui-ci brise-t-il son contrat ou arrive-t-il a echeance?" << endl;
				cout << "1. Romp son contrat" << endl;
				cout << "2. Arrive a echeance" << endl;
				cin >> choix;

				switch (choix)
				{
				case 1:
					cout << endl << "Veuillez entrez la raison du depart : ";
					cin >> raison;

					if (indiceVieilleEquipe != 999)
						ligueSoccer->ruptureContrat(ligueSoccer->leContrat(indice)->leJoueurContractant(), ligueSoccer->leClub(clubAcheteur), ligueSoccer->leClub(indiceVieilleEquipe), annee, Date(jourEntree, moisEntree, anneeEntree), Date(jourContrat, moisContrat, anneeContrat), Reglement(seuil, droits, montantTransfert, montantEncaisse, montantRestant), clubAcheteur, indiceVieilleEquipe, raison);
					break;
				case 2:
					if (indiceVieilleEquipe != 999)
						ligueSoccer->finContrat(ligueSoccer->leContrat(indice)->leJoueurContractant(), ligueSoccer->leClub(clubAcheteur), ligueSoccer->leClub(indiceVieilleEquipe), annee, Date(jourEntree, moisEntree, anneeEntree), Date(jourContrat, moisContrat, anneeContrat), Reglement(seuil, droits, montantTransfert, montantEncaisse, montantRestant), clubAcheteur, indiceVieilleEquipe);
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

	delete msgVendeur;
	delete msgAcheteur;
	delete flag;
}