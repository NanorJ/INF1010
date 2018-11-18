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

// TODO : À modifier :
vector<Depense*> Groupe::getDepenses() const {
	return gestionnaireDepenses_->getConteneur();
}

// TODO : À modifier 
///changed from vector<Utilisateur*>
map<Utilisateur*, double>  Groupe::getUtilisateurs() const {
	/*vector<Utilisateur*>utilisateurs;
	for (auto it : gestionnaireUtilisateurs_->getConteneur())//parcourt le conteneur
		utilisateurs.push_back(it.first);
	return utilisateurs;*/
	return gestionnaireUtilisateurs_->getConteneur();
}

vector<Transfert*> Groupe::getTransferts() const {
	return transferts_;
}

// TODO : À modifier : ///error coming from here (18 and 19)
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
	return *this;
}

// TODO : À modifier :
void Groupe::equilibrerComptes() {

	bool calcul = true;
	int count = 0;
	while (calcul) {
		auto paireMin = gestionnaireUtilisateurs_->getMin();
		auto paireMax = gestionnaireUtilisateurs_->getMax();


		// On cherche lequel des deux a la dette la plus grande
		if (-paireMin.second <= paireMax.second && paireMin.second != 0 && paireMax.second != 0) {
			if (paireMin.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(-paireMin.second, paireMin.first, paireMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(-paireMin.second, paireMin.first, paireMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}

			paireMax.second += paireMin.second;
			paireMin.second = 0;
		}
		else if (-paireMin.second > paireMax.second  && paireMin.second != 0 && paireMax.second != 0) {
			if (paireMin.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(paireMax.second, paireMin.first, paireMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
				TransfertPaypal* transfert = new TransfertPaypal(paireMax.second, paireMin.first, paireMax.first);
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			paireMin.second += paireMax.second;
			paireMax.second = 0;
		}

		gestionnaireUtilisateurs_->setCompte(paireMax);
		gestionnaireUtilisateurs_->setCompte(paireMin);
		// On incremente le nombre de comptes mis a 0
		count++;
		if (-paireMin.second == paireMax.second) {
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
	
	for (auto utilisateur : groupe.gestionnaireUtilisateurs_->getConteneur())
		os << "\t- " << *(utilisateur.first);
	os << endl;

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
