/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Auteur: Ryan Hardie
* Modifie par : Nanor Janjikian (1901777) et Stephanie Mansour (1935595)
* Date: 19 novembre 2018
*******************************************/
#pragma once

<<<<<<< HEAD
#include "foncteur.h"
=======
#include "foncteur.h"//ask
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351

template <typename T, typename C, typename D, typename FoncteurAjouter>

class GestionnaireGenerique {
	public:
        //Methode d'acces
		C getConteneur() const {
			//retourne le conteneur_ du gestionnaire
			return conteneur_;
		}
	
<<<<<<< HEAD
        unsigned long getNombreElements() const {
			//ajouter pointeur dans le conteneur à l’aide d’un foncteur d’ajout FoncteurAjouter 
			return conteneur_.size();
        }
    
        D getElementParIndex(int i) const {
			//retournee nombre d’éléments contenus dans le conteneur_
            return *next(conteneur_.begin(), i);
        }
    
        //Methode d'ajout
		void ajouter(T t) {
			//retourner l’élément du conteneur se situant à l’index i passé par paramètre
			FoncteurAjouter foncteur(conteneur_);
			foncteur(t);
=======
		int getNombreElements() const {
			return conteneur_.size();
		}
	
		D getElementParIndex(int i) const {
			return *next(conteneur_.begin(), i);
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351
		}

	protected:
		C conteneur_;
};
