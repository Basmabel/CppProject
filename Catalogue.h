/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H
#include <cstring>

//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------------------
// Role de la classe <Catalogue>
//Implemente le catalogue de trajets :les méthodes d'Ajout
//la  Recherche de trajets et l'affichage de Trajet
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	void MenuAffichage();
	//Mode d'emploi : Gère l'interface Homme Machine à  travers un menu de choix
	//

	void AjouterTrajetSimple();
	// Mode d'emploi : Ajoute un trajet simple au catalogue en faisant appelle à 
	//                 la méthode Ajouter dans ListeTrajet.

	void AjouterTrajetCompose();
	// Mode d'emploi : Ajoute un trajet composé au catalogue en faisant appelle à 
	//                 la méthode Ajouter dans ListeTrajet.

	void Rechercher();
	// Mode d'emploi : Recherche un trajet dans le catalogue à  partir d'une ville
	//                 de départ et ville d'arrivé saisies par l'utilisateur.

	void Afficher () const;
	// Mode d'emploi : Affiche le contenue du catalogue.
	//
	
	TrajetSimple* ImporterTrajetSimple(string ligne);
	// Mode d'emploi : Permet d'importer un trajet simple à partir d'un fichier.
	//
	
	TrajetCompose* ImporterTrajetCompose(string ligne);
	// Mode d'emploi : Permet d'importer un trajet composé à partir d'un fichier.
	//
	
	void SauvegarderTrajetSimple(ofstream &monFichier,const Trajet *t);
	// Mode d'emploi : Permet de sauvegarder un trajet simple dans un fichier.
	//
	
	void SauvegarderVille(ofstream &monFichier) const;
	// Mode d'emploi : Permet de sauvegarder des trajets simples ou composés à 
	//                  partir de la ville de départ ou de la ville d'arrivée.
	

//-------------------------------------------- Constructeurs - destructeur
    Catalogue (); //Constructeur
	// Mode d'emploi : crée une liste de trajets "catalogue"
	//

	virtual ~Catalogue(); // Destructeur
	// Mode d'emploi : delete la liste catalogue pour libérer la mémoire.
	//
	
	
//------------------------------------------------------------------ PROTECTED
	
protected:
//----------------------------------------------------- Attributs protégés
	ListeTrajet *catalogue;
};
#endif
