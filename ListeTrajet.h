/*************************************************************************
                           ListeTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ListeTrajet> (fichier ListeTrajet.h) ----------
#if ! defined ( LISTETRAJET_H )
#define LISTETRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include "CaseTrajet.h"
//--------------------------------------------------- Constantes
const unsigned int TAILLE=10;

//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajet>
// Implémente une Liste de pointeur de CaseTrajet pour les stocker
//------------------------------------------------------------------------

class ListeTrajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	void Ajouter(const Trajet* trj);
	// Mode d'emploi : Ajoute *trj à la liste de trajets en le triant par ordre alphabétique
	//

	void Afficher() const;
	// Mode d'emploi : Parcourt la liste de pointeur de trajet et appelle
	//                 leur méthode affichage

	CaseTrajet* getDebut() const ;
	// Mode d'emploi : Renvoie la case de début de la liste de trajets
	//

	CaseTrajet* getFin() const;
	// Mode d'emploi : Renvoie la case de fin de la liste de trajets
	//

	const Trajet* getDebutTrajet() const ;
	// Mode d'emploi : Renvoie le Trajet du début de la liste de trajets
	//

	const Trajet* getFinTrajet() const;
	// Mode d'emploi : Renvoie le Trajet de fin de la liste de trajets
	//

	unsigned int getLongueur() const;
	// Mode d'emploi : Renvoie la longueur de la liste de trajets
	//

//-------------------------------------------- Constructeurs - destructeur
        ListeTrajet (bool choix); //Constructeur
	// Mode d'emploi : Création d'une Liste de Trajet.
	// Le constructeur prend en paramètre un bool pour faire le choix d'ordonner la liste ou pas
	// Dans TrajetCompose, il n'y a aucun interet à avoir une liste ordonnée de trajets simple

	virtual ~ListeTrajet (); // Destructeur
	// Mode d'emploi : Libération mémoire de ListeTrajet et de ses attributs
	//

//------------------------------------------------------------------ PROTECTED

protected:
//----------------------------------------------------- Méthodes protégées
	bool Comparer ( const Trajet* trj1, const Trajet* trj2 ) const;
	// Mode d'emploi :Compare les Trajets entrés en paramètre par ordre
	//		  alphabétique sur villeDepart, puis VilleArrivee.

//----------------------------------------------------- Attributs protégés
	CaseTrajet *debut, *fin;
	unsigned int longueur;
	bool trie;
};
#endif
