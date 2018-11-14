/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/
#include "foncteur.h"
// typename : type generique de variables
template <typename T, typename C, typename D, typename FoncteurAjouter>

//gestionnaire Depense et Utilisateur herite de Gestionnaire Generique donc on doit specifier les type dans les templates : GG< T,C , specifier ...D , , > 

class GestionnaireGenerique {
	public:
		C getConteneur() const {
			return conteneur_;
		}
		//i would rather do a template here for FoncteurAjouter
	
		void ajouter(T t, FoncteurAjouter foncteur) {
			FoncteurAjouter foncteur(t);; //help
			conteneur_ = foncteur;
		}
	
		int getNombreElements() const {
			unsigned compteur = 0;
			auto end = conteneur_.end();
			for (auto it = conteneur_.begin(); it != end; it++)
				compteur++;
			return compteur;
		}
	
		D getElementParIndex(int i) const {
			return *position(conteneur_.begin(), i);
		}

	protected:
		C conteneur_;
};