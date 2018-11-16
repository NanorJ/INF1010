/********************************************
* Titre: Travail pratique #5 - groupe.cpp
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include "groupe.h"
#include <functional>
#include <algorithm>
using namespace std::placeholders;

// Constructeurs
Groupe::Groupe() {
	nom_ = "";
	gestionnaireDepenses_ = new GestionnaireDepenses();
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::Groupe(const string& nom) : nom_(nom) {
	gestionnaireDepenses_ = new GestionnaireDepenses();
	gestionnaireUtilisateurs_ = new GestionnaireUtilisateurs();
}

Groupe::~Groupe() {
	vector<Depense*> depenses = gestionnaireDepenses_->getConteneur();
	for (int i = 0; i < depenses.size(); i++) {
		delete depenses[i];
	}
	for (int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
	}

	delete gestionnaireDepenses_;
	delete gestionnaireUtilisateurs_;
}

// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

// TODO : À modifier :
vector<Depense*> Groupe::getDepenses() const {
	return gestionnaireDepenses_->getConteneur();
}

// TODO : À modifier :
vector<Utilisateur*> Groupe::getUtilisateurs() const {
	vector<Utilisateur*>tabUtilisateur;

	for (pair<Utilisateur*, double>element : gestionnaireUtilisateurs_->getConteneur())//parcourt le conteneur
		tabUtilisateur.push_back(element.first);

	return tabUtilisateur;
}

vector<Transfert*> Groupe::getTransferts() const {
	return transferts_;
}

// TODO : À modifier :
vector<double> Groupe::getComptes() const {
	return comptes_; //why long 
}

double Groupe::getTotalDepenses() const {
	return gestionnaireDepenses_->getTotalDepenses();
}

GestionnaireUtilisateurs * Groupe::getGestionnaireUtilisateurs() {
	return gestionnaireUtilisateurs_;
}

GestionnaireDepenses * Groupe::getGestionnaireDepenses() {
	return gestionnaireDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(double montant, Utilisateur* payePar, const string& nom, const string& lieu) {
	if (!gestionnaireUtilisateurs_->estExistant(payePar)) 
		return *this;

	Depense* depense = new Depense(nom, montant, lieu);
	gestionnaireDepenses_->ajouter(depense);

	gestionnaireUtilisateurs_->mettreAJourComptes(payePar, montant);
	*payePar += depense;

	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur) {
	gestionnaireUtilisateurs_->ajouter(utilisateur);
	comptes_.push_back(0);
	return *this;
}

// TODO : À modifier :
void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (int i = 0; i < gestionnaireUtilisateurs_->getNombreElements(); i++) {
			if (gestionnaireUtilisateurs_->getComptes()[i] > max) {
				max = gestionnaireUtilisateurs_->getComptes()[i];
				indexMax = i;
			}
			if (gestionnaireUtilisateurs_->getComptes()[i] < min) {
				min = gestionnaireUtilisateurs_->getComptes()[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max && min != 0 && max != 0) {
			if (gestionnaireUtilisateurs_->getElementParIndex(indexMin).first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(-min, gestionnaireUtilisateurs_->getElementParIndex(indexMin).first, gestionnaireUtilisateurs_->getElementParIndex(indexMax).first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(-min, gestionnaireUtilisateurs_->getElementParIndex(indexMin).first, gestionnaireUtilisateurs_->getElementParIndex(indexMax).first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			auto indexmax = gestionnaireUtilisateurs_->getElementParIndex(indexMax);
			indexmax.second += min;
			gestionnaireUtilisateurs_->setCompte(make_pair(indexmax.first, indexmax.second));

			auto indexmin = gestionnaireUtilisateurs_->getElementParIndex(indexMin);
			indexmin.second = 0;
			gestionnaireUtilisateurs_->setCompte(make_pair(indexmin.first, 0));
		}
		else if (-min > max  && min != 0 && max != 0) {
			if (gestionnaireUtilisateurs_->getElementParIndex(indexMin).first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(max, gestionnaireUtilisateurs_->getElementParIndex(indexMin).first, gestionnaireUtilisateurs_->getElementParIndex(indexMax).first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(max, gestionnaireUtilisateurs_->getElementParIndex(indexMin).first, gestionnaireUtilisateurs_->getElementParIndex(indexMax).first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			auto indexmax = gestionnaireUtilisateurs_->getElementParIndex(indexMax);
			indexmax.second = 0;
			gestionnaireUtilisateurs_->setCompte(make_pair(indexmax.first, 0));

			auto indexmin = gestionnaireUtilisateurs_->getElementParIndex(indexMin);
			indexmin.second += max;
			gestionnaireUtilisateurs_->setCompte(make_pair(indexmin.first, indexmin.second));
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= gestionnaireUtilisateurs_->getNombreElements() - 1) {
			calcul = false;
		}
	}

}

// Methode d'affichage
// TODO : À modifier :
ostream & operator<<(ostream& os, const Groupe& groupe) {
	os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	
	auto conteneur = groupe.gestionnaireUtilisateurs_->getConteneur();
	for (auto it = conteneur.begin(); it != conteneur.end(); it++) {
		os << "\t- " << *it->first;
	}
	os << endl;

	if (groupe.transferts_.size() != 0) {
		os << "Transferts :" << endl;
		for (int i = 0; i < groupe.transferts_.size(); i++)
			os << "\t" << *(groupe.transferts_[i]);
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
		for (int i = 0; i < groupe.comptes_.size(); i++) {
			os << groupe.gestionnaireUtilisateurs_->getElementParIndex(i).first->getNom() << " : " << groupe.comptes_[i] << endl;
		}
	}

	os << endl;
	return os;
}
