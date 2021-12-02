/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Trajet.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//Getter
const char* Trajet::getVilleDepart ()const {return nullptr;}

const char* Trajet::getVilleArrivee ()const {return nullptr;}

const char* Trajet::getTransport()const {return nullptr;}


//Méthode estCompose
const bool Trajet::estCompose()const{return false;}

//Méthode SauvegarderTrajetCompose
void Trajet::SauvegarderTrajetCompose(ofstream &monFichier) const{return;}

//Constructeur
Trajet::Trajet ()
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
	
}//----- Fin du constructeur de Trajet

//Destructeur
Trajet::~Trajet ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
}//----- Fin du destructeur de Trajet
