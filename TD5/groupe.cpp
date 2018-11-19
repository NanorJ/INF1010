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

<<<<<<< HEAD
map<Utilisateur*, double>  Groupe::getUtilisateurs() const {
=======
// TODO : √Ä modifier 
///changed from vector<Utilisateur*>
map<Utilisateur*, double>  Groupe::getUtilisateurs() const {
	/*vector<Utilisateur*>utilisateurs;
	for (auto it : gestionnaireUtilisateurs_->getConteneur())//parcourt le conteneur
		utilisateurs.push_back(it.first);
	return utilisateurs;*/
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351
	return gestionnaireUtilisateurs_->getConteneur();
}

vector<Transfert*> Groupe::getTransferts() const {
	return transferts_;
}

<<<<<<< HEAD
=======
// TODO : √Ä modifier : ///error coming from here (18 and 19)
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351
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
<<<<<<< HEAD
		auto min = gestionnaireUtilisateurs_->getMin();
		auto max = gestionnaireUtilisateurs_->getMax();

		// On cherche lequel des deux a la dette la plus grande
		if (-min.second <= max.second && min.second != 0 && max.second != 0) {
			if (min.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(-min.second, min.first, max.first);
=======
		auto paireMin = gestionnaireUtilisateurs_->getMin();
		auto paireMax = gestionnaireUtilisateurs_->getMax();


		// On cherche lequel des deux a la dette la plus grande
		if (-paireMin.second <= paireMax.second && paireMin.second != 0 && paireMax.second != 0) {
			if (paireMin.first->getMethodePaiement() == Interac) {
				TransfertInterac* transfert = new TransfertInterac(-paireMin.second, paireMin.first, paireMax.first);
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
<<<<<<< HEAD
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
=======
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
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351
				transferts_.push_back(transfert);
				transfert->effectuerTransfert();
			}
			else {
<<<<<<< HEAD
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
=======
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
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351
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
<<<<<<< HEAD
		os << "\t- " << *(utilisateur.first)<<endl;
=======
		os << "\t- " << *(utilisateur.first);
	os << endl;
>>>>>>> 2e0a03edff7db9ac333d5ef6a06baa6c92ea4351

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
