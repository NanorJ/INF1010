/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
********************************************/

#include "gestionnaireUtilisateurs.h"
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

bool GestionnaireUtilisateurs::estExistant(Utilisateur* utilisateur) const {
	if (conteneur_.find(utilisateur) != conteneur_.end())
		return true;
	return false;
}

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
}

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

GestionnaireUtilisateurs&  GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p) {
	if (conteneur_.find(p.first) != conteneur_.end())
		conteneur_[p.first] = p.second;
	return *this;
}
