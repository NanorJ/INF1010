/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

//typename : type generique de variables
template <typename T, typename C, typename D, typename FoncteurAjouter>

//gestionnaire Depense et Utilisateur herite de Gestionnaire Generique donc on doit specifier les type dans les templates : GG< T,C , specifier ...D , , > 

class GestionnaireGenerique {
public:
	C getConteneur() const 
	{
		return conteneur_;
	}
	void ajouter(T t)
	{
		FoncteurAjouter(t);
	}
	int getNombreElements() const 
	{
		return 
	}
	D getElementParIndex(int i) const;

private:
	C conteneur_;

	};

