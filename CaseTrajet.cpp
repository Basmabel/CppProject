/*************************************************************************
                           CaseTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "CaseTrajet.h"

//----------------------------------------------------- Méthodes publiques

//Methode Afficher

void CaseTrajet :: Afficher() const {
cout << "Le trajet actuel est " << trajet <<endl;
}//-----Fin de la Méthode Afficher

//Setter pour le trajet suivant
void CaseTrajet:: setSuivant(CaseTrajet *suivant)
{
	trajetSuivant= suivant;

} //----- Fin de la Méthode setSuivant


//Getter pour le trajet suivant
CaseTrajet* CaseTrajet:: getSuivant() const
{
	return trajetSuivant;

}//----- Fin de la Méthode get Suivant


//Getter pour le trajet actuel
const Trajet* CaseTrajet:: getTrajet() const
{
	return trajet;

}//----- Fin de la Méthode getTrajet

//-------------------------------------------- Constructeurs - destructeur

//Constructeur
CaseTrajet::CaseTrajet (const Trajet* trjt)
{
	trajet=trjt;
	trajetSuivant = NULL;
	
#ifdef MAP
    cout << "Appel au constructeur de <CaseTrajet>" << endl;
#endif
}//----- Fin du constructeur CaseTrajet

//Destructeur
CaseTrajet::~CaseTrajet ()
{
delete trajet;
trajetSuivant=NULL;

#ifdef MAP
    cout << "Appel au destructeur de <CaseTrajet>" << endl;
#endif
} //----- Fin du destructeur ~CaseTrajet

