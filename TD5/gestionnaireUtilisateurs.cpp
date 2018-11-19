/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Auteur: Ryan Hardie
* Modifié par : Nanor Janjikian (1901777) et Stephanie Mansour (1935595)
* Date: 19 novembre 2018
* Description: Ce code contient les méthodes implémentées de gestionnaireUtilisateurs.h
*******************************************/

#include "gestionnaireUtilisateurs.h"
<<<<<<< HEAD
=======
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"

#include <algorithm>
#include <iterator>

using namespace std::placeholders;

vector<double> GestionnaireUtilisateurs::getComptes() const {
	vector<double> compte;
	for (auto& value : conteneur_)
		compte.push_back(value.second);
	return compte;
}
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351

// Retourne true si l’utilisateur existe, sinon faux
bool GestionnaireUtilisateurs::estExistant(Utilisateur* utilisateur) const {
	if (conteneur_.find(utilisateur) != conteneur_.end())
		return true;
	return false;
}

<<<<<<< HEAD
//Methode d'acces
vector<double> GestionnaireUtilisateurs::getComptes() const {
    vector<double> compte;
    for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
        compte.push_back(it->second);
    return compte;
=======
void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur* payePar, double montant) {
	//we can use a find : https://github.com/xavoliva6/INF1010_TP5Final/blob/master/TP5/TP5/gestionnaireUtilisateurs.cpp
	if (estExistant(payePar)) {
		auto payeur = conteneur_.begin();
		auto end = conteneur_.end();
		
		for (auto it = conteneur_.begin(); it != end; it++) {
			if (it->first == payePar)
				payeur = it; // we assign possition it to payeur (cause payeur is empty)
		}

		double montantParPersonne = montant / getNombreElements();
		payeur->second += montant - montantParPersonne; // update compte de payeur

		for (auto it = conteneur_.begin(); it != end; it++) { // compte pour autre utilisateur que le payeur
			if (it != payeur)
				it->second -= montantParPersonne;
		}
	}
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351
}
//Retourner l’élément de la map ayant la valeur de compte la plus élevée
pair<Utilisateur*, double>&  GestionnaireUtilisateurs::getMax() const {
	auto it = conteneur_.begin();
	double max = it->second;
	Utilisateur* nomUtilisateur = it->first;
	
	for (it; it != conteneur_.end(); it++) {
		if (it->second > max) {
			max = it->second;
			nomUtilisateur = it->first;
		}
	}
	
    pair <Utilisateur*, double> pairemax = make_pair(nomUtilisateur, max);
	return pairemax;
}
//Retourner l’élément de la map ayant la valeur de compte la plus faible
pair<Utilisateur*, double>&  GestionnaireUtilisateurs::getMin() const {
	auto it = conteneur_.begin();
	double min = it->second;
	Utilisateur* umin = it->first;
	
	for (it; it != conteneur_.end(); it++) {
		if (it->second < min) {
			min = it->second;
			umin = it->first;
		}
	}
<<<<<<< HEAD
    pair < Utilisateur*, double> pairemin = make_pair(umin, min);
=======
	pair < Utilisateur*, double> pairemin = make_pair(umin, min);
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351
	return pairemin;
}

Utilisateur *  GestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const {
	pair<Utilisateur*, double> personne = make_pair(utilisateur, montant);
	auto suivant = find_if(conteneur_.begin(), conteneur_.end(), bind(greater<pair<Utilisateur*, double>>(), _1, personne));
	return suivant->first;
}

vector<pair<Utilisateur*, double>>  GestionnaireUtilisateurs::getUtilisateursEntre(double borneInf, double borneSup) const {
	vector<pair<Utilisateur*, double>> utilisateurs;
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(utilisateurs), FoncteurIntervalle(borneInf, borneSup));
	return utilisateurs;
<<<<<<< HEAD
}

//Methode de modifications
void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur* payePar, double montant) {
    
    double montantParPersonne = montant / getNombreElements();
    conteneur_[payePar] += montant - montantParPersonne;
    
    for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
        if (it != conteneur_.find(payePar))
            it->second -= montantParPersonne;
    }
=======
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351
}

GestionnaireUtilisateurs&  GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p) {
	if (conteneur_.find(p.first) != conteneur_.end())
		conteneur_[p.first] = p.second;
	return *this;
}
