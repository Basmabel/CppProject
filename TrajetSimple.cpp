/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;
//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "Trajet.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//Méthode Afficher
void TrajetSimple :: Afficher ( void ) const
{
cout << "Trajet de "<< villeDepart<< " vers "<< villeArrivee<< " en "<< Transport<< endl;
}//------Fin de la Méthode Afficher

//Getter de la ville de depart
const char* TrajetSimple :: getVilleDepart () const
{
return villeDepart;
} //----- Fin de le Méthode GetVilleDepart

//Getter de la ville d'arrivée
const char* TrajetSimple :: getVilleArrivee () const
{
return villeArrivee;
} //----- Fin de le Méthode GetVilleArrivee

//Getter du moyen de transport
const char* TrajetSimple :: getTransport () const
{
return Transport;
} //----- Fin de le Méthode GetTransport

//Méthode estCompose
const bool TrajetSimple :: estCompose() const 
{
	return false;
}

//-------------------------------------------- Constructeurs - destructeur

//Constructeur
TrajetSimple::TrajetSimple (char* villeDep,char* villeArr,char* trpt)
{
	villeDepart= new char[strlen(villeDep)+1];
	villeArrivee= new char[strlen(villeArr)+1];
	Transport= new char[strlen(trpt)+1];
	strcpy(villeDepart,villeDep);
	strcpy(villeArrivee,villeArr); 
	strcpy(Transport, trpt);
	
#ifdef MAP
	cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
}//----- Fin du constructeur TrajetSimple
 
//Destructeur
TrajetSimple::~TrajetSimple () 
{
delete[] villeDepart;
delete[] villeArrivee;
delete[] Transport;

#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de destructeur ~TrajetSimple
