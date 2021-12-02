/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------ Constante globale
const int MAX =40;

//----------------------------------------------------- Méthodes publiques

//Méthode MenuAffichage()
void Catalogue::MenuAffichage()
{
		cout<<"Bienvenue dans votre catalogue de recherche de trajets!"<<endl;
		char choix = '0';
		do
		{
			cout << "         Catalogue         " << endl;
			cout << "Que Voulez vous faire?"<< endl;
  			cout << "1. Ajouter un trajet simple au Catalogue" << endl;
			cout << "2. Ajouter un trajet composé au Catalogue" << endl;
  			cout << "3. Afficher le contenu du Catalogue de trajets" << endl;
  			cout << "4. Rechercher un Trajet dans le Catalogue" << endl;
  			cout << "5. Importer le contenu d'un fichier dans le catalogue" << endl;
  			cout << "6. Sauvegarder le contenu de tout le catalogue" << endl;
  			cout << "7. Sauvegarder tous les trajets simples du catalogue" << endl;
  			cout << "8. Sauvegarder tous les trajets composés du catalogue" << endl;
  			cout << "9. Sauvegarder les trajets selon leur ville de départ/d'arrivée" << endl;
  			cout << "E. Quitter le Catalogue" << endl;
			cout << "Veuillez entrer votre choix sous forme de nombre"<< endl;
  			cin >> choix;
  			//Variables
  			string ligne;
			switch (choix)
        	{
                case '1':   //Ajouter un trajet simple au Catalogue
                    AjouterTrajetSimple();
                	break;
            	case '2':   //Ajouter un trajet composé au Catalogue
                	AjouterTrajetCompose();
                	break;
            	case '3':   //Afficher le contenu du Catalogue de trajets
                	Afficher();
                	break;
            	case '4':   //Rechercher un Trajet dans le Catalogue
                	Rechercher();
                	break;
                case '5':   //Importer le contenu d'un fichier dans le catalogue
                {
					string monFichier("Trajet.txt");
                	ifstream monFlux(monFichier.c_str()); //Lecture du fichier
					if (monFlux.is_open()) //Si le fichier est ouvert
					{
						while ( getline (monFlux,ligne) ) //Afficher la ligne
						{
							if(ligne.find("TC") != string::npos)
							{	        
								catalogue ->Ajouter(ImporterTrajetCompose(ligne));
							}
							else if(ligne.find("TS")!= string::npos)
							{
								catalogue ->Ajouter(ImporterTrajetSimple(ligne));	        	
							}
						}
						monFlux.close(); //Fermer le fichier
                	}
                	break;
                }
                case '6':   //Sauvegarder le contenu de tout le catalogue
                {		
                    string monFichier("contenu_catalogue.txt");
                	ofstream monFlux(monFichier.c_str()); //Ecriture du fichier
                	if (monFlux.is_open())
					{
						CaseTrajet* caseT= catalogue->getDebut();
						bool rentre= false;
						while (caseT!=nullptr) //Parcours du catalogue
						{ 	
							if(!((caseT -> getTrajet()) -> estCompose()))
							{
								const Trajet* t=(caseT->getTrajet());
								SauvegarderTrajetSimple(monFlux,t);
								monFlux << " " <<endl;
								rentre=true;
							}
							else if((caseT -> getTrajet()) -> estCompose())
							{
								const Trajet* t=(caseT->getTrajet());
								t->SauvegarderTrajetCompose(monFlux);
								monFlux << " " <<endl;
								rentre=true;
							}
							caseT=caseT->getSuivant();
						}
						if(!rentre)
						{
							cout<<"Rien à sauvegarder"<<endl;
						}
						monFlux.close();
					}
                	break;
				}
                case '7':   //Sauvegarder tous les trajets simples du catalogue
                {
                	ofstream monFichier2("trajets_simples.txt"); //Ecriture du fichier
                	if (monFichier2.is_open())
					{
						CaseTrajet* caseT= catalogue->getDebut();
						bool rentre=false;
						while (caseT!=nullptr) //Parcours du catalogue
						{ 	
							if(!(( caseT -> getTrajet()) -> estCompose()))
							{	
								const Trajet* t=(caseT->getTrajet());
								SauvegarderTrajetSimple(monFichier2,t);
								monFichier2 << " " <<endl;
								rentre=true;
							}
							caseT= caseT->getSuivant();
						}
						if(!rentre){
							cout << "Rien à sauvegarder"<<endl;
						}
						monFichier2.close();
					}
                	break;
				}
                case '8':   //Sauvegarder tous les trajets composés du catalogue
                {
                    ofstream monFichier3("trajets_composes.txt"); //Ecriture du fichier
                	if (monFichier3.is_open())
					{
						CaseTrajet* caseT= catalogue->getDebut();
						bool rentre= false;
						while (caseT!=nullptr) //Parcours du catalogue
						{ 	
						    if( (caseT -> getTrajet()) -> estCompose() )
						    {
								const Trajet* t=(caseT->getTrajet());
								t->SauvegarderTrajetCompose(monFichier3);
								monFichier3 << " " <<endl;
								rentre=true;
							}
							caseT=caseT->getSuivant();
						}
						if(!rentre){
							cout<<"Rien à sauvegarder"<<endl;
						}
						monFichier3.close();
					}
                	break;
				}
                case '9':   //Sauvegarder les trajets selon leur ville de départ ou d'arrivée
                {
                    ofstream monFichier9("trajets_villes.txt");
                	if (monFichier9.is_open())
					{
                		SauvegarderVille(monFichier9);
                		monFichier9 << " " <<endl;
                		monFichier9.close();
                	}
                    break;
                }
            	case 'E':   //Quitter le catalogue
                	cout << "A bientot pour votre prochain voyage ;)" << endl;
					break;
				default:
               		cout << "Valeur rentrée incompréhensible. Veuillez saisir : '1' , '2' , '3' , '4' ou '5' " << endl;
					break;
			}
		}
		while(choix!='E');
}

//Méthode ImporterTrajetSimple
TrajetSimple* Catalogue :: ImporterTrajetSimple(string ligne)
{
    //Syntaxe d'un trajet simple dans le fichier texte // TS:paris$lyon;bus
	size_t posDebut1 = ligne.find_first_of(':'); 
	size_t posFin1 = ligne.find_first_of('$');
	int taille1 = posFin1 - posDebut1; //Taille de la ville de départ

	string villeDep = ligne.substr(posDebut1+1, taille1-1);
	char* villeDepart = new char[villeDep.length()+1];
	strcpy(villeDepart,villeDep.c_str()); //Récuperer la ville de départ
	
	
	size_t posDebut2 = ligne.find_first_of('$');
	size_t posFin2 = ligne.find_first_of(';');
	int taille2 = posFin2 - posDebut2; //Taille de la ville d'arrivée
	
	string villeArr = ligne.substr(posDebut2+1,taille2-1);
	char* villeArrivee = new char[villeArr.length()+1];
	strcpy(villeArrivee,villeArr.c_str()); //Récupérer la ville d'arrivée
	
	size_t posDebut3 = ligne.find_first_of(';');
	size_t posFin3 = ligne.find_first_of('?');
	int taille3 = posFin3 - posDebut3; //Taille du transport
	
	string transp =ligne.substr(posDebut3+1,taille3);
	char* transport = new char[transp.length()+1];
	strcpy(transport,transp.c_str()); //Récuperer le transport
	
	TrajetSimple *ts= new TrajetSimple(villeDepart,villeArrivee,transport);
	//Suppression des cases mémoire allouées
	delete [] villeDepart;
	delete [] villeArrivee;
	delete [] transport;
	return ts;

}

//Méthode ImporterTrajeCompose
TrajetCompose* Catalogue :: ImporterTrajetCompose(string ligne)
{
    //Syntaxe d'un trajet composé dans le fichier texte // TC/2&paris!lyon:TS:paris$toulouse;avion?TS:toulouse$lyon;avion?
	size_t posNbTrajet = ligne.find_first_of('/');
	string nombreTrajet= ligne.substr(posNbTrajet+1,1);
	stringstream tmp(nombreTrajet);
	int nbTrajet= 0;
	tmp>> nbTrajet;
	size_t posDebut1 = ligne.find_first_of('&');
	size_t posFin1 = ligne.find_first_of('!');
	int taille1 = posFin1 - posDebut1; //Taille de la ville de départ
	
	string villeDep = ligne.substr(posDebut1+1, taille1-1);
	char* villeDepart = new char[villeDep.length()+1];
	strcpy(villeDepart,villeDep.c_str()); //Récuperer la ville de départ
	
	size_t posDebut2 = ligne.find_first_of('!');
	size_t posFin2 = ligne.find_first_of(':');
	int taille2 = posFin2 - posDebut2; //Taille de la ville d'arrivée
	
	string villeArr = ligne.substr(posDebut2+1,taille2-1);
	char* villeArrivee = new char[villeArr.length()+1];
	strcpy(villeArrivee,villeArr.c_str()); //Récuperer la ville d'arrivée
	
	TrajetCompose *tc = new TrajetCompose(villeDepart,villeArrivee);
	int i=0;
	int pos = posFin2+1;
	while(i<nbTrajet) //Récuperer toutes les fractions de trajets simples composant le trajet composé
	{
		size_t posDebutTS = ligne.find(':',pos);
		size_t posFinTS = ligne.find('?',pos);
		int tailleTS = posFinTS - posDebutTS;
		
		string TS = ligne.substr(posDebutTS,tailleTS);
		char* TSimple = new char[TS.length()+1];
		strcpy(TSimple,TS.c_str());
		tc -> AjouterFraction(ImporterTrajetSimple(TSimple));
		i++;
		pos = posFinTS+1 ;
		delete [] TSimple;
	}
	//Suppression des cases mémoire allouées
	delete [] villeDepart;
	delete [] villeArrivee;
	return tc;
}

//Méthode SauvegarderTrajetSimple
void Catalogue :: SauvegarderTrajetSimple(ofstream &monFichier, const Trajet *t)
{
	monFichier << "TS:"<< t->getVilleDepart() << "$" << t->getVilleArrivee() << ";" << t -> getTransport() << "?";	
}

//Méthode SauvegarderVille
void Catalogue :: SauvegarderVille(ofstream &monFichier) const
{
	cout<<"Vous voulez sauvegarder un trajet selon:"<<endl;
	bool verifie = false;
	char choix = '0';
  	cout << "1. Ville de départ" << endl;
	cout << "2. Ville d'arrivée" << endl;
	cin >> choix;
	switch(choix)
	{
		case '1': //Ville de départ
		{
        	cout <<"Veuillez choisir la ville de départ des trajets que vous souhaitez sauvegarder"<< endl;
    		char villeDep[MAX];
    		cin >> villeDep;
    		unsigned int i =0;
			CaseTrajet *tmp= catalogue->getDebut();
			while(i< catalogue->getLongueur())
			{
				if(strcmp(tmp->getTrajet()-> getVilleDepart(),villeDep)==0) // on vérifie que les villes de départ sont égales à celles présentes dans le catalogue
				{
					if(!(tmp->getTrajet()-> estCompose())){
						monFichier << "TS:"<< tmp->getTrajet()->getVilleDepart() << "$" << tmp->getTrajet()->getVilleArrivee() << ";" << tmp->getTrajet() -> getTransport() << "?";
						monFichier << "\n";
					}
					else if((tmp->getTrajet()-> estCompose()))
					{
						(tmp->getTrajet())->SauvegarderTrajetCompose(monFichier);
						monFichier << "\n";
					}
					verifie = true;
				}
				i++;
				tmp = tmp -> getSuivant();
			}
			if(verifie == false)
			{
			    cout << "\n";
			    cout << "La ville de départ que vous avez choisi n'existe pas" << endl;
			    cout << "\n";
			}
			break;
		}
		
		case '2': //Ville d'arrivée
		{
            cout <<"Veuillez choisir la ville d'arrivée des trajets que vous souhaitez sauvegarder"<< endl;
    		char villeArr[MAX];
    		cin >> villeArr;
    		unsigned int i =0;
			CaseTrajet *tmp= catalogue->getDebut();
			while(i< catalogue->getLongueur())
			{
				if(strcmp(tmp->getTrajet()-> getVilleArrivee(),villeArr)==0) // on vérifie que les villes d'arrivées sont égales à celles présentes dans le catalogue
				{
					if(!(tmp->getTrajet()-> estCompose()))
					{
						monFichier << "TS:"<< tmp->getTrajet()->getVilleDepart() << "$" << tmp->getTrajet()->getVilleArrivee() << ";" << tmp->getTrajet() -> getTransport() << "?";
						monFichier << "\n";
					}else if((tmp->getTrajet()-> estCompose()))
					{
						(tmp->getTrajet())->SauvegarderTrajetCompose(monFichier);
						monFichier << "\n";
					}
					verifie = true;
				}
				i++;
				tmp = tmp -> getSuivant();
			}
    		if(verifie == false)
    		{
    		    cout << "\n";
				cout << "La ville d'arrivée que vous avez choisi n'existe pas" << endl;
				cout << "\n";
			}
			break;
		}
		default:
            cout << "Valeur rentrée incompréhensible. Veuillez saisir : '1' , '2'"  << endl;
            break;
	}
}//----- Fin de la méthode SauvegarderVille

//Méthode Afficher
void Catalogue::Afficher () const

{
	cout<< "Le catalogue comporte : " << catalogue->getLongueur() << " Trajet(s)." << endl;
	CaseTrajet* caseT= catalogue->getDebut();
	cout<<" ______________________________________________________________________________"<<endl;
	while (caseT!=nullptr) { 	//Parcours du catalogue

		const Trajet* t=(caseT->getTrajet());
		cout<<" "<<endl;
		cout<< "	";
		t->Afficher();
		caseT=caseT->getSuivant();
	}
	cout<<" ______________________________________________________________________________"<<endl;	

}//----- Fin de la méthode Afficher



//Méthode Rechercher sans transport

void Catalogue::Rechercher()
{
    bool verifie = false;
	cout << "*--Nous allons procéder à la Recherche d'un trajet--*" << endl;
	cout <<"Veuillez entrer la ville de départ du trajet que vous souhaitez rechercher"<< endl;
    char villeDep[MAX];
    cin >> villeDep;
    cout <<"Veuillez entrer la ville d'Arrivée du trajet que vous souhaitez rechercher"<< endl;
    char villeArr[MAX];
    cin >> villeArr;
	unsigned int i =0;
	CaseTrajet *tmp= catalogue->getDebut();
	while(i< catalogue->getLongueur())
	{
		if(strcmp(tmp->getTrajet()-> getVilleDepart(),villeDep)==0 && strcmp(tmp->getTrajet()->getVilleArrivee(),villeArr)==0) 	// on vérifie que les villes de départ et d'arrivée entrées sont égales à celles présentes dans le catalogue
		{
			cout << "Le trajet recherché est le suivant :" << endl;
			cout << " " <<endl;
			tmp ->getTrajet()-> Afficher();
			cout << " " <<endl;
			verifie = true;
		}
		i++;
		tmp = tmp -> getSuivant();
	}
	if(verifie == false)
	{
		cout << "Le trajet recherché n'est pas disponible " << endl;
	}
}//----- Fin de la méthode Rechercher

//Méthode AjouterTrajetSimple

void Catalogue:: AjouterTrajetSimple ()
{
	cout << "**--Nous Allons procéder à l'ajout d'un trajet simple--**" << endl;
	cout <<" Veuillez entrer votre ville de départ"<< endl;
    char villeDepart[MAX];
	cin >> villeDepart;
	cout <<" Veuillez entrer votre ville d'arrivée"<< endl;
	char villeArrivee[MAX];
	cin >> villeArrivee;
	cout <<" Veuillez entrer votre moyen de transport"<< endl;
	char moyenTransport[MAX];
	cin >> moyenTransport;
	TrajetSimple *ts = new TrajetSimple(villeDepart, villeArrivee,moyenTransport);
	catalogue->Ajouter(ts);
}//----- Fin de la Méthode AjouterTrajetSimple

//Méthode AjouterTrajetCompose
void Catalogue:: AjouterTrajetCompose ()
{
	cout << "**--Nous allons procéder à l'ajout d'un trajet composé--**" << endl;
	cout <<" Veuillez entrer votre ville de départ"<< endl;
    char trajetComposeDep[MAX];
    cin >> trajetComposeDep;
    cout << " Veuillez entrer votre ville d'Arrivée" << endl;
    char trajetComposeArr[MAX];
    cin >> trajetComposeArr;
	TrajetCompose* tc = new TrajetCompose (trajetComposeDep,trajetComposeArr);
    cout <<" De combien de fractions est composé votre trajet? (veuillez répondre par un chiffre)" << endl;
    int  Fraction = 0;
    cin >> Fraction;
    int i=0;
    while(i<Fraction)
    {
        cout << "**--Vous allez entrer les informations concernant votre fraction de trajet numéro : "<< i+1<< " --**"<< endl; 
        cout <<" Veuillez entrer votre ville de départ"<< endl;
        char trajetComposeFracDep[MAX];
        cin >> trajetComposeFracDep;
        cout << " Veuillez entrer votre ville d'arrivée" << endl;
        char trajetComposeFracArr[MAX];
        cin >> trajetComposeFracArr;
        cout <<" Veuillez entrer votre moyen de transport"<< endl;
        char TrajetComposeFracTrsp[MAX];
        cin >> TrajetComposeFracTrsp;
        TrajetSimple* ts2 = new TrajetSimple(trajetComposeFracDep,trajetComposeFracArr,TrajetComposeFracTrsp);
        tc->AjouterFraction(ts2);
        i++;
    }
    catalogue->Ajouter(tc);
}

//-------------------------------------------- Constructeurs - destructeur

//Constructeur
Catalogue::Catalogue ( )
{
	catalogue = new ListeTrajet(true);
	
#ifdef MAP
	cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin du constructeur de Catalogue

//Destructeur
Catalogue::~Catalogue ( )
{
	delete catalogue;

#ifdef MAP
	cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin du destructeur de Catalogue
