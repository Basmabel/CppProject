/*************************************************************************
                           ListeTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajet> (fichier ListeTrajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include<cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListeTrajet.h"
#include "Trajet.h"
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

 
//Méthode Ajouter

void ListeTrajet::Ajouter (const Trajet* trj) 
{
	longueur++;
	CaseTrajet *nouveau= new CaseTrajet(trj);
	if(debut==NULL){	// si la liste est vide
		debut = nouveau;		
	} else if(trie){

		CaseTrajet *tmp =debut;
		if(!Comparer(debut-> getTrajet(),trj))		// insertion en début de liste
		{
			nouveau->setSuivant(debut);
			debut=nouveau;
		}else if( debut->getSuivant()==nullptr && Comparer(debut-> getTrajet(),trj))	// si la liste contient un seul élément
		{
			debut ->setSuivant(nouveau);
		}else{
			const Trajet* trj1= tmp->getSuivant()->getTrajet();
			while( tmp->getSuivant() != NULL && Comparer(trj1,trj))
			{
				tmp= tmp->getSuivant();
				if(tmp->getSuivant() != NULL)
				{
					trj1= tmp->getSuivant()->getTrajet();
				}
			}
			nouveau->setSuivant(tmp->getSuivant());
			tmp->setSuivant(nouveau);

		}		
	}
	else {
        CaseTrajet *tmp = debut;
        while(tmp->getSuivant()!= nullptr)
        {
            tmp = tmp->getSuivant();
        }
        tmp->setSuivant(nouveau);
    }
}//----- Fin de la Méthode Ajouter
 

//Méthode Afficher

void ListeTrajet :: Afficher() const
{
    if (debut == NULL)
    {
	cout << "La liste de trajets est vide" << endl;
	
    }else{
    	CaseTrajet *actuel = debut;
    	int i=1;
    	while (actuel != NULL ) 	// tant que nous ne sommes pas encore arrivés à la dernière case de la Liste
    	{
		const Trajet *tr= actuel ->getTrajet();
		cout << "Trajet "<< i << " : ";
		tr-> Afficher();
		cout << endl;
        	actuel = actuel->getSuivant();
        	i++;
    	}
    }  
}//----- Fin de la Méthode Afficher

//getter de debut  et de fin de liste

const Trajet*  ListeTrajet :: getDebutTrajet() const
{
	return debut-> getTrajet();
}//----- Fin de la Méthode getDebutTrajet

const Trajet* ListeTrajet :: getFinTrajet() const
{
	return fin-> getTrajet();
}//----- Fin de la Méthode getFinTrajet

CaseTrajet*  ListeTrajet :: getDebut() const
{
	return debut;
}//----- Fin de la Méthode getDebut

CaseTrajet* ListeTrajet :: getFin() const
{
	return fin;
}//----- Fin de la Méthode getFin

//getter de la taille de la liste
unsigned int ListeTrajet :: getLongueur() const
{
	return longueur;
}

//Méthode Comparer
bool ListeTrajet::Comparer ( const Trajet* trj1, const Trajet* trj2 ) const
{
    int comparaisonDepart = strcmp(trj1->getVilleDepart(), trj2->getVilleDepart());
    int comparaisonArrivee = strcmp(trj1->getVilleArrivee(), trj2->getVilleArrivee());
    return comparaisonDepart < 0 || (comparaisonDepart == 0 && comparaisonArrivee < 0);
} // ----- Fin de compare


//-------------------------------------------- Constructeurs - destructeur

//Constructeur
 ListeTrajet::ListeTrajet (bool choix)  
{
	longueur =0;
	trie=choix;
	debut= NULL;
	fin=NULL; 
	
#ifdef MAP
	cout << "Appel au constructeur de <ListeTrajet>" << endl;
#endif
	
}//----- Fin du constructeur ListeTrajet

//Destructeur
ListeTrajet::~ListeTrajet () 
{	
	CaseTrajet* tmp;
	while (debut != fin)
	{
		tmp = debut;
		debut = tmp->getSuivant();
		delete tmp;
        }
        delete debut;
        
#ifdef MAP
		cout << "Appel au destructeur de <ListeTrajet>" << endl;
#endif
}//----- Fin du Destructeur ~ListeTrajet

