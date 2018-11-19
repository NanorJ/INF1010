/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Auteur: Ryan Hardie
* Modifie par : Nanor Janjikian (1901777) et Stephanie Mansour (1935595)
* Date: 19 novembre 2018
*******************************************/
#pragma once

#include "foncteur.h"

template <typename T, typename C, typename D, typename FoncteurAjouter>

class GestionnaireGenerique {
	public:
        //Methode d'acces
		C getConteneur() const {
			//retourne le conteneur_ du gestionnaire
			return conteneur_;
		}
	
        unsigned long getNombreElements() const {
			//ajouter pointeur dans le conteneur � l�aide d�un foncteur d�ajout FoncteurAjouter 
			return conteneur_.size();
        }
    
        D getElementParIndex(int i) const {
			//retournee nombre d��l�ments contenus dans le conteneur_
            return *next(conteneur_.begin(), i);
        }
    
        //Methode d'ajout
		void ajouter(T t) {
			//retourner l��l�ment du conteneur se situant � l�index i pass� par param�tre
			FoncteurAjouter foncteur(conteneur_);
			foncteur(t);
		}

	protected:
		C conteneur_;
};
