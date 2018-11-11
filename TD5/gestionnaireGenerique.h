/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/
#include"foncteur.h"//can we add this?
//typename : type generique de variables
template <typename T, typename C, typename D, typename FoncteurAjouter>

//gestionnaire Depense et Utilisateur herite de Gestionnaire Generique donc on doit specifier les type dans les templates : GG< T,C , specifier ...D , , > 

class GestionnaireGenerique {
public:
	C getConteneur() const 	{
		return conteneur_;//du gestionnaire?
	}
	//i would rather do a template here for FoncteurAjouter
	void ajouter(T t)	{
		FoncteurAjouter(t); //help
	}
	int getNombreElements() const 	{
		return conteneur_.size() ;//??? this make sense?
		//idk if we can do size or we do a counter
	}
	D getElementParIndex(int i) const {
		// Cette méthode retourne un objet de type D qui peut être soit Depense* soit pair<Utilisateur*, double>
		//since we dont know i put auto 
		auto position = conteneur_.begin();//placing position at the beginning
		position += i; // adding i to get the position wanted 
		return *position;//getting le contenu de l'iterateur position 
	}

protected:
	C conteneur_;

	};

