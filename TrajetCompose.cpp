/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//-------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include "ListeTrajet.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//Méthode AjouterFraction
void TrajetCompose :: AjouterFraction(Trajet *unTrajet)
{
	FractionTrajet->Ajouter(unTrajet);

} //----- Fin de la méthode AjouterFraction


//Getter de VilleDepart et VilleArrivee
const char* TrajetCompose:: getVilleDepart () const
{
	return villeDepart;
	
}//----- Fin de la méthode getVilleDepart

const char* TrajetCompose:: getVilleArrivee() const
{
	return villeArrivee;

}//----- Fin de la méthode getVilleArrivee

//Méthode Afficher
void TrajetCompose::Afficher () const
{
	cout << "Trajet de " <<villeDepart <<" vers "<< villeArrivee <<" de "<<FractionTrajet->getLongueur()<<" Fractions de trajets"<<endl;
	cout<< "	Le trajet est composé de :"<<endl;
	CaseTrajet *tr = FractionTrajet->getDebut();
	if(tr!=nullptr) {
		const Trajet* ts=(tr->getTrajet());
		cout<<"		- Trajet de : "<<ts->getVilleDepart()<<" vers "<<ts-> getVilleArrivee() <<" en "<<ts->getTransport()<<endl;
		tr=tr->getSuivant();
	}
	while (tr!=nullptr) {
		const Trajet* ts=(tr->getTrajet());
		cout<<"		- Trajet de : "<<ts->getVilleDepart()<<" vers "<<ts->getVilleArrivee()<<" en "<< ts->getTransport()<<endl;
		tr=tr->getSuivant();
	}
	cout<<" "<<endl;
}//----- Fin de la méthode Afficher

//Méthode estCompose
const bool TrajetCompose :: estCompose() const
{
	return true;
}

//Méthode SauvegarderTrajetCompose
void TrajetCompose :: SauvegarderTrajetCompose(ofstream &monFichier) const
{
	monFichier << "TC/" << FractionTrajet -> getLongueur() << "&" << getVilleDepart() << "!" << getVilleArrivee() << ":";

	CaseTrajet* caseT= FractionTrajet -> getDebut();
	while (caseT!=nullptr) { 	//Parcours du catalogue
		const Trajet* ts =(caseT->getTrajet());
		monFichier << "TS:"<< ts->getVilleDepart() << "$" << ts->getVilleArrivee() << ";" << ts -> getTransport() << "?";	
		caseT=caseT->getSuivant();
	}
}


//-------------------------------------------- Constructeurs - destructeur

//Constructeur
TrajetCompose::TrajetCompose (char* villeDep,char* villeArr) 
{
	villeDepart= new char[strlen(villeDep)+1];
	villeArrivee= new char[strlen(villeArr)+1];
	strcpy(villeDepart,villeDep);
	strcpy(villeArrivee,villeArr); 
	FractionTrajet = new ListeTrajet(true);

#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

}//----- Fin du constructeur TrajetCompose

//Destructeur
TrajetCompose::~TrajetCompose () 
{
	delete[] villeDepart;
	delete[] villeArrivee;
	delete FractionTrajet;
	
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin du destructeur ~TrajetCompose 


