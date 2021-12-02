/*************************************************************************
                           CaseTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <CaseTrajet> (fichier CaseTrajet.h) ----------
#if ! defined ( CASETRAJET_H )
#define CASETRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <CaseTrajet>
//  Implémente une Case ainsi que le pointeur sur la Case suivante dans ListeTrajet.
//------------------------------------------------------------------------

class CaseTrajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	
	void Afficher() const ;
	// Mode d'emploi : Affiche le contenue de la Case de Trajet et appelle
	//                 leur méthode affichage

	void setSuivant(CaseTrajet *suivant);
	// Mode d'emploi : Set la case suivante à la valeure rentrée en paramètre
	//

	CaseTrajet* getSuivant() const;
	// Mode d'emploi : Renvoie la case suivante
	//

	const Trajet* getTrajet() const;
	// Mode d'emploi : Renvoie le trajet stocké dans la CaseTrajet
	//

//-------------------------------------------- Constructeurs - destructeur
	CaseTrajet(const Trajet* trjt); //Constructeur
	// Mode d'emploi : Création d'une Case de trajet à partir du Trajet
	//		   donné en paramètre.

	virtual ~CaseTrajet (); // Destructeur
	// Mode d'emploi : Libération mémoire de CaseTrajet et de ses attributs
	//

//------------------------------------------------------------------ PROTECTED

protected:
	const Trajet* trajet;
	CaseTrajet *trajetSuivant;
};
#endif
