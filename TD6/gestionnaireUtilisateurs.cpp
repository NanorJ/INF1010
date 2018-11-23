/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "gestionnaireUtilisateurs.h"

#include <algorithm>
#include <functional>

vector<double> GestionnaireUtilisateurs::getComptes() const
{
	vector<double> comptes;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); ++it) {
		comptes.push_back(it->second);
	}

	return comptes;
}

bool GestionnaireUtilisateurs::estExistant(Utilisateur * utilisateur) const
{
	int index = -1, i = 0;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); ++it) {
		if (it->first == utilisateur) {
			index = i;
			break;
		}
		i++;
	}
	return (index != -1);
}


Utilisateur* GestionnaireUtilisateurs::trouverUtilisateurParNom(const string& nom) const{
    for(auto it = conteneur_.begin(); it != conteneur_.end(); it++)
        if(it->first->getNom() == nom)
            return it->first;
    throw ExceptionUtilisateurInexistant("Erreur : l'utilisateur n'a pas pu etre trouve. " );
}
void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur * payePar, double montant)
{
	double montantReparti = montant / getNombreElements();
	conteneur_[payePar] += montant - montantReparti;

	for (auto it = conteneur_.begin(); it != conteneur_.end(); ++it) {
		if (it->first != payePar) {
			it->second -= montantReparti;
		}
	}
}

pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMax() const
{
	pair<Utilisateur*, double> it = *max_element(conteneur_.begin(), conteneur_.end(), 
		[](pair< Utilisateur*, double > p1, pair< Utilisateur*, double > p2) {
		return p1.second < p2.second; });

	return it;
}
pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMin() const
{
	pair<Utilisateur*, double> it = *min_element(conteneur_.begin(), conteneur_.end(),
		[](pair< Utilisateur*, double > p1, pair< Utilisateur*, double > p2) {
		return p1.second < p2.second; });

	return it;
}

GestionnaireUtilisateurs& GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p)
{
	conteneur_[p.first] = p.second;
	return *this;
}

Utilisateur* GestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const {
	using namespace std::placeholders;
	auto it = find_if(conteneur_.begin(), conteneur_.end(),
		bind(greater<pair<Utilisateur*, double>>(), _1, pair<Utilisateur*, double>(utilisateur, montant)));
	return it->first;
}

vector<pair<Utilisateur*, double>> GestionnaireUtilisateurs::getUtilisateursEntre(double borneInf, double borneSup) const {
	FoncteurIntervalle intervalle(borneInf, borneSup);
	vector<pair<Utilisateur*, double>> intervalleProduit;
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(intervalleProduit), intervalle);

	return intervalleProduit;
}

int GestionnaireUtilisateurs::getNbUtilisateurs() const {
    return conteneur_.size();
}
