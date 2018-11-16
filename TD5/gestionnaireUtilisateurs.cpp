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
	unsigned int index = 0;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		compte.push_back(getElementParIndex(index).second);
		index++;
	}
	return compte;
}

bool GestionnaireUtilisateurs::estExistant(Utilisateur* utilisateur) const {
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		if (it->first == utilisateur)
			return true;
	}
	return false;
}

void GestionnaireUtilisateurs::mettreAJourComptes(Utilisateur* payePar, double montant) {
	
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
	double min = it->second;//initialisation de la valeur max a la valeur du compte du premier utilisateur
	Utilisateur* umin = it->first;
	
	for (it; it != conteneur_.end(); it++) { //parcourir le conteneur (map)
		//chercher la valeur de compte la plus basse 
		if (it->second < min) {
			min = it->second;//sauvegarde dans la variable max la valeur de compte superieur apres la comparaison
			umin = it->first;//sauvegarde dans la variable umax l'adresse de l'utilisateur adequat
		}
	}
	//apres avoir parcouru le conteneur ,pour la valeur max qui correspond a un utilisateur  creer une paire
	pair < Utilisateur*, double> pairemin = make_pair(umin, min);
	return pairemin;
}

Utilisateur *  GestionnaireUtilisateurs::getUtilisateurSuivant(Utilisateur* utilisateur, double montant) const {
	pair<Utilisateur*, double> p = make_pair(utilisateur, montant);
	auto trouve = find_if(conteneur_.begin(), conteneur_.end(), bind(equal_to<pair<Utilisateur*, double>>(), _1, p));
	trouve++; //prend la position de l'iterateur trouve ++
	
	//Chercher l'iterateur correspondant et le dereferenceer pour le comparer avec le pointeur d'utilisateur
	if (estExistant(trouve->first))
		return trouve->first;	//Retourner l'utilisateur suivant puisqu'il existe
	
	else { //Afficher un message d'erreur et retourner l'utilisateur courant
		cout << "Erreur!L'utilisateur " << trouve->first->getNom() << "est le dernier utilisateur de la liste.Il n'y aucun autre qui le suit ." << endl;
		return trouve->first;
	}
}

vector<pair<Utilisateur*, double>>  GestionnaireUtilisateurs::getUtilisateursEntre(double borneInf, double borneSup) const {
	vector<pair<Utilisateur*, double>> utilisateurentre;
	copy_if(conteneur_.begin(), conteneur_.end(), back_inserter(utilisateurentre), FoncteurIntervalle(borneInf, borneSup));//on fait un "push_back' de l"element dans le conteneur si le predicat p est vrai
	return utilisateurentre;
}

GestionnaireUtilisateurs&  GestionnaireUtilisateurs::setCompte(pair<Utilisateur*, double> p) {
	//verifier que l'utilisateur existe
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
