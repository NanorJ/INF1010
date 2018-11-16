/********************************************
* Titre: Travail pratique #5 - gestionnaireUtilisateurs.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "gestionnaireUtilisateurs.h"
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"
#include <vector>//no se 
#include <iterator>//iteratorsssssssss?

vector<double> GestionnaireUtilisateurs:: getComptes() const{
	vector<double>compte;
	unsigned int index = 0;
	//parcourir avec un iterator conteneur pour les utilisateurs
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		//on accede second: la valeur dedans
		compte.push_back(getElementParIndex(index).second);
		index++;
	}
	return compte;
}

int GestionnaireUtilisateurs:: estExistant(Utilisateur* utilisateur) const{
	//on veut parcourir le conteneur 
	auto fin = conteneur_.end();
	for (auto i = conteneur_.begin(); i != fin; i++) {
		//on cherche le first (cle) et verfie si sont pareilles
		if (i->first == utilisateur)
			return true;
	}
	return false;
}
void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur* payePar, double montant){
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
pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMax() const{
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
pair<Utilisateur*, double>& GestionnaireUtilisateurs::getMin() const{
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
Utilisateur * GestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const{
	pair<Utilisateur*, double> p = make_pair(utilisateur, montant);
	auto trouve = find_if(conteneur_.begin(), conteneur_.end(), bind(equal_to<pair<Utilisateur*, double>>(), _1, p));
	trouve++; 
	if (estExistant(trouve->first))
		return trouve->first;	
	else { 
		cout << "Erreur!L'utilisateur " << trouve->first->getNom() << "est le dernier utilisateur de la liste.Il n'y aucun autre qui le suit ." << endl;
		return trouve->first;
	}
}
vector<pair<Utilisateur*, double>> GestionnaireUtilisateurs::getUtilisateursEntre(double borneInf, double borneSup) const{
	vector<pair<Utilisateur*, double>> utilisateurentre;
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(utilisateurentre), FoncteurIntervalle(borneInf, borneSup));
	return utilisateurentre;
}
GestionnaireUtilisateurs & GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p){
	if (estExistant(p.first)) {
		//parcourir le conteneur a la recherche de l'utilisateur
		double montant = p.second;
		for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {//parcourir le conteneur
			if (it->first == p.first)
				it->second = p.second;
		}
	}
	return *this;
}
