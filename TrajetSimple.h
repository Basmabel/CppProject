/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Implemente un trajet direct entre une uneVilleDepart et uneVilleArrive
// avec moyen de Transport.
//------------------------------------------------------------------------


class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

       
	void Afficher() const;
	// Mode d'emploi : Affiche les caractéristiques du trajet simple
	//
	// Contrat : Redéfinitin de la méthode virtuelle pure de la classe 
	//           mère Trajet

	const char* getVilleDepart () const;
	// Mode d'emploi : Renvoie la ville de départ
	//
	// Contrat : Aucun
	//

	const char* getVilleArrivee () const;
	// Mode d'emploi : Renvoie la ville d'arrivee
	//
	// Contrat : Aucun
	//

	const char* getTransport () const;
	// Mode d'emploi : Renvoie le moyen de transport
	//
	// Contrat : Aucun
	//
	
	const bool estCompose() const;
	// Mode d'emploi : Renvoie true si le trajet est composé et false si le trajet est simple
	//
	// Contrat : Aucun
	//
	
//-------------------------------------------- Constructeurs - destructeur
	TrajetSimple (char* villeDep,char* villeArr,char* trpt); //Constructeur
	// Mode d'emploi : définition des attributs de trajet simple à partir
	//                 des Paramètres formels du constructeur
	// Contrat : Aucun
	//

	virtual ~TrajetSimple (); // Destructeur
	// Mode d'emploi : libère les allocations dynamiques réalisées
	//
	// Contrat : Aucun
	//

//------------------------------------------------------------------ Protégé
	
protected:
//Les attributs de cette classe sont hérités de la classe mère: Trajet	
};
#endif
