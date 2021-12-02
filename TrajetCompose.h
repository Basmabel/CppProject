/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//------ Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H
//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeTrajet.h"
//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Créer un Trajet composé de plusieurs Fractions de Trajets (simple ou composé)
// qui relient une ville de départ à une ville d'arrivée.
//------------------------------------------------------------------------


class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


	void Afficher() const;
	// Mode d'emploi : Affiche les caractéristiques du Trajet composé
	//
	//Contrat: Redéfinitin de la méthode virtuelle pure de la classe mère Trajet
	//

	void AjouterFraction (Trajet *unTrajet);
	// Mode d'emploi : Ajoute une Fraction de Trajet au trajet composé
	//
	// Contrat : Aucun
	//

	const char* getVilleDepart () const;
	// Mode d'emploi : Renvoie la ville de départ
	//
	// Contrat : Aucun
	//

	const char* getVilleArrivee () const;
	// Mode d'emploi : Renvoie la ville d'Arrivée
	//
	// Contrat : Aucun
	//
	
	void SauvegarderTrajetCompose(ofstream &monFichier)const;
	// Mode d'emploi : Permet la sauvegarde des trajets composés dans un fichier
	//
	// Contrat : Aucun
	//
	
	const bool estCompose() const;
	// Mode d'emploi : Renvoie true si le trajet est composé et false si le trajet est simple
	//
	// Contrat : Aucun
	//

//-------------------------------------------- Constructeurs - destructeur

        TrajetCompose (char* villeDep,char* villeArr); //Constructeur
	// Mode d'emploi : définition des attributs de trajet composé à partir
	//                 des Paramètres formels du constructeur
	// Contrat : Aucun
	//

	virtual ~TrajetCompose (); // Destructeur
	// Mode d'emploi : libère les allocations dynamiques réalisées
	//
	// Contrat : Aucun
	//
	
//------------------------------------------------------------------ Protégé

protected:
//----------------------------------------------------- Attributs protégés
	ListeTrajet* FractionTrajet;
};
#endif
