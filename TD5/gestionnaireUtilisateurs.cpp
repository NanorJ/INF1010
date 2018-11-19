/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Auteur: Ryan Hardie
* Modifié par : Nanor Janjikian (1901777) et Stephanie Mansour (1935595)
* Date: 19 novembre 2018
* Description: Ce code contient les méthodes implémentées de gestionnaireUtilisateurs.h
*******************************************/

#include "gestionnaireUtilisateurs.h"

// Retourne true si l’utilisateur existe, sinon faux
bool GestionnaireUtilisateurs::estExistant(Utilisateur* utilisateur) const {
	if (conteneur_.find(utilisateur) != conteneur_.end())
		return true;
	return false;
}

//Methode d'acces
vector<double> GestionnaireUtilisateurs::getComptes() const {
    vector<double> compte;
    for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
        compte.push_back(it->second);
    return compte;
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
    pair < Utilisateur*, double> pairemin = make_pair(umin, min);
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
}

//Methode de modifications
void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur* payePar, double montant) {
    
    double montantParPersonne = montant / getNombreElements();
    conteneur_[payePar] += montant - montantParPersonne;
    
    for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
        if (it != conteneur_.find(payePar))
            it->second -= montantParPersonne;
    }
}

GestionnaireUtilisateurs&  GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p) {
	if (conteneur_.find(p.first) != conteneur_.end())
		conteneur_[p.first] = p.second;
	return *this;
}
