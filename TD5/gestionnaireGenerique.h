/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/
#pragma once

#include "foncteur.h"//ask

template <typename T, typename C, typename D, typename FoncteurAjouter>

class GestionnaireGenerique {
	public:
		C getConteneur() const {
			return conteneur_;
		}
		
		void ajouter(T t) {
			FoncteurAjouter foncteur(conteneur_);
			conteneur_ = foncteur(t);
		}
	
		int getNombreElements() const {
			return conteneur_.size();
		}
	
		D getElementParIndex(int i) const {
			return *next(conteneur_.begin(), i);
		}

	protected:
		C conteneur_;

};

