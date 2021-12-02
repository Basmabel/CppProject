/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H
//--------------------------------------------------- Interfaces utilisées
//#include "ListeTrajet.h"


//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Implémente un trajet entre uneVilleDepart et uneVilleArrive
//
//------------------------------------------------------------------------



class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


	virtual void Afficher() const = 0;
	// Mode d'emploi : Permet d'afficher les caractéristiques d'un Trajet
	//
	// Contrat : c'est une méthode virtuelle pure (=0) on définit ainsi une classe abstraite
	//

	virtual const char* getVilleDepart () const;
	// Mode d'emploi : Renvoie la ville de départ
	//
	// Contrat : Aucun
	//

	virtual const char* getVilleArrivee () const;
	// Mode d'emploi : Renvoie la ville de d'arrivée
	//
	// Contrat : Aucun
	//
	
	virtual const char* getTransport () const;
	// Mode d'emploi : Renvoie le moyen de Transport
	//
	// Contrat : Aucun
	//
	
	virtual void SauvegarderTrajetCompose(ofstream &monFichier) const;
	// Mode d'emploi : Permet la sauvegarde d'un trajet composé
	//
	// Contrat : Aucun
	//
	
	virtual const bool estCompose() const;
	// Mode d'emploi : Renvoie true si le trajet est composé et false si le trajet est simple
	//
	// Contrat : Aucun
	//

//-------------------------------------------- Constructeurs - destructeur
        Trajet (); //Constructeur
	// Mode d'emploi : Constructeur de la classe Trajet
	//
	// Contrat : Aucun
	//

	virtual ~Trajet (); // Destructeur
		// Mode d'emploi : libère toutes les allocations dynamiques effectuées
	//
	// Contrat : Aucun
	//

//------------------------------------------------------------------ PROTECTED

protected:
//----------------------------------------------------- Attributs protégés
	char* villeDepart;
	char* villeArrivee;
	char* Transport;

};

#endif
