/********************************************
* Titre: Travail pratique #5 - groupe.cpp
* Auteur: Ryan Hardie
* Modifié par : Nanor Janjikian (1901777) et Stephanie Mansour (1935595)
* Date: 19 novembre 2018
* Description: Ce code contient les méthodes implémentées de groupe.h
*******************************************/

#include "groupe.h"
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
	for (auto depense : gestionnaireDepenses_->getConteneur()) 
		delete depense;

	for (auto transfert : transferts_)
		delete transfert;

	delete gestionnaireDepenses_;
	delete gestionnaireUtilisateurs_;
}

// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

vector<Depense*> Groupe::getDepenses() const {
	return gestionnaireDepenses_->getConteneur();
}

map<Utilisateur*, double>  Groupe::getUtilisateurs() const {
	return gestionnaireUtilisateurs_->getConteneur();
}

vector<Transfert*> Groupe::getTransferts() const {
	return transferts_;
}

vector<double> Groupe::getComptes() const {
	return gestionnaireUtilisateurs_->getComptes();
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

//Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(double montant, Utilisateur* payePar, const string& nom, const string& lieu) {
    if (!gestionnaireUtilisateurs_->estExistant(payePar)){
		return *this;
    }
    
	Depense* depense = new Depense(nom, montant, lieu);
	gestionnaireDepenses_->ajouter(depense);
	
    *payePar += depense;
	gestionnaireUtilisateurs_->mettreAJourComptes(payePar, montant);

	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* utilisateur) {
	gestionnaireUtilisateurs_->ajouter(utilisateur);
	return *this;
}

void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	while (calcul) {
		auto min = gestionnaireUtilisateurs_->getMin();
		auto max = gestionnaireUtilisateurs_->getMax();

		// On cherche lequel des deux a la dette la plus grande
		if (-min.second <= max.second && min.second != 0 && max.second != 0) {
			if (min.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(-min.second, min.first, max.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(-min.second, min.first, max.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			max.second += min.second;
			min.second = 0;
		}
		else if (-min.second > max.second  && min.second != 0 && max.second != 0) {
			if (min.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(max.second, min.first, max.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(max.second, min.first, max.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			max.second = 0;
			min.second += max.second;
		}

		gestionnaireUtilisateurs_->setCompte(max);
		gestionnaireUtilisateurs_->setCompte(min);
		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min.second == max.second) {
			count++;
		}
		if (count >= gestionnaireUtilisateurs_->getNombreElements() - 1) {
			calcul = false;
		}
	}

}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe) {
	os << "\nGroupe " << groupe.nom_ << ".\nCout total: " << groupe.getTotalDepenses() << "$ \nUtilisateurs:    \n\n";
	
	for (auto utilisateur : groupe.gestionnaireUtilisateurs_->getConteneur())
		os << "\t- " << *(utilisateur.first)<<endl;

	if (groupe.transferts_.size() != 0) {
		os << "Transferts :" << endl;
		for (auto transfert : groupe.transferts_) 
			os << "\t" << *(transfert);
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
		for (auto utilisateur : groupe.gestionnaireUtilisateurs_->getConteneur())
			os << utilisateur.first->getNom() << " : " << utilisateur.second << endl;
	}

	os << endl;
	return os;
}
