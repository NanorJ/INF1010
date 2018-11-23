/********************************************
* Titre: Travail pratique #5 - gestionnaireGenerique.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/
#pragma once


#include <algorithm>

using namespace  std;

//				T	= Utilisateur* ou Depense*; 
//				C	= map<Utilisateur*, double> ou vector<Depense*>; 
//				D	= pair<Utilisateur*, double> ou Depense*; 
// FoncteurAjouter	= AjouterUtilisateur ou AjouterDepense;
template<typename T, typename C, typename D, typename FoncteurAjouter> 
class GestionnaireGenerique
{
public:
	C getConteneur() const;
	void ajouter(T t);
	int getNombreElements() const;
	D getElementParIndex(int i) const;

protected:
	C conteneur_;
};

template<typename T, typename C, typename D, typename FoncteurAjouter>
inline C GestionnaireGenerique<T, C, D, FoncteurAjouter>::getConteneur() const
{
	return conteneur_;
}

template<typename T, typename C, typename D, typename FoncteurAjouter>
inline void GestionnaireGenerique<T, C, D, FoncteurAjouter>::ajouter(T t)
{
	FoncteurAjouter ajouter(conteneur_);
	conteneur_ = ajouter(t);
}

template<typename T, typename C, typename D, typename FoncteurAjouter>
inline int GestionnaireGenerique<T, C, D, FoncteurAjouter>::getNombreElements() const
{
	return conteneur_.size();
}

template<typename T, typename C, typename D, typename FoncteurAjouter>
inline D GestionnaireGenerique<T, C, D, FoncteurAjouter>::getElementParIndex(int i) const
{
	return *next(conteneur_.begin(), i);
}
