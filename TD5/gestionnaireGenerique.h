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
		
		void ajouter(T t) {
			FoncteurAjouter foncteur(conteneur_);
			conteneur_ = foncteur(t);
		}
	
		int getNombreElements() const {
			//on a fait un size
			/*unsigned compteur = 0;
			auto end = conteneur_.end();
			for (auto it = conteneur_.begin(); it != end; it++)
				compteur++;*/
			return conteneur_.size();
		}
	
		D getElementParIndex(int i) const {
			return *position(conteneur_.begin(), i);
		}

	protected:
		C conteneur_;

};

