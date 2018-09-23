/***********************************************************************
* Titre: Travail pratique #1 - groupe.cpp
* Date: 24 janvier 2018
* Auteur: Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Desciption: Ce code contient les méthodes implémentées de groupe.h
************************************************************************/
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

#include "groupe.h"
//implémentation du constructeur par défault
Groupe::Groupe() {
	nom_ = "unknown";
	totalDepenses_ = 0.0;
	listeUtilisateurs_ = nullptr;
	nombreDepenses_ = 0;
	nombreUtilisateurs_ = 0;
	tailleTabUtilisateurs_ = 5;
	tailleTabDepenses_ = 10;
	listeDepenses_ = nullptr;
	comptes_ = nullptr;
	listeTransferts_ = nullptr;
	nombreTransferts_ = 0;
}
//implémentation du constructeur par paramètres
//ajout de const avant le titre parce qu'il est constant (ne change pas)
Groupe::Groupe(const string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs) {
	nom_ = nom;
	totalDepenses_ = 0.0;
	nombreDepenses_ = 0;
	nombreUtilisateurs_ = 0;
	tailleTabDepenses_ = tailleTabDepenses;
	tailleTabUtilisateurs_ = tailleTabUtilisateurs;
	comptes_ = nullptr;
	listeTransferts_ = nullptr;
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
	listeDepenses_ = new Depense*[tailleTabDepenses_];
	nombreTransferts_ = 0;
}
//Implementation du destructeur 
Groupe::~Groupe() {
		delete[] listeUtilisateurs_;
		listeUtilisateurs_ = nullptr;
		delete[] listeDepenses_;
		listeDepenses_ = nullptr;
		delete comptes_;
		comptes_ = nullptr;
		delete[] listeTransferts_;
		listeTransferts_ = nullptr;
}
//implémentation des méthodes d'accès (const : on est en train d'accéder)
string Groupe::getNom() const {
	return nom_;
}

unsigned int Groupe::getNombreDepenses() const {
	return nombreDepenses_;
}

double Groupe::getTotal() const {
	return totalDepenses_;
}
//implémentation des méthodes de modifications 
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}
//Implementation methode ajout dépense
void Groupe::ajouterDepense(Depense* uneDepense, Utilisateur* payePar) {
	//assigner une depense pour chaque utilisateur
	payePar->ajouterDepense(uneDepense);
	if (nombreDepenses_ == tailleTabDepenses_) {
		// Si nombre depense est egal a taille depense doubler taille
		int nouvelleTaille = tailleTabDepenses_ * 2;
		Depense** nouvelleListeDepenses = new Depense*[nouvelleTaille];
		// Copier les dépenses
		for (unsigned int i = 0; i < nombreDepenses_; i++)
			nouvelleListeDepenses[i] = listeDepenses_[i];
		//liberer le tableau 
		delete[] listeDepenses_;
		// assigner la nouvelle liste et la nouvelle capacité
		listeDepenses_ = nouvelleListeDepenses;
		tailleTabDepenses_ = nouvelleTaille;
	}
	// Ajouter nouvelle depense
	listeDepenses_[nombreDepenses_++] = uneDepense;
}
//implementation methode ajout utilisateur 
void Groupe::ajouterUtilisateur(Utilisateur *unUtilisateur) {
	if (nombreUtilisateurs_ == tailleTabUtilisateurs_) {
		// Si nombre depense est egal a taille depense doubler taille
		int nouvelleTaille = tailleTabUtilisateurs_ * 2;
		Utilisateur** nouvelleListeUtilisateurs = new Utilisateur*[nouvelleTaille];
		// Copier les dépenses
		for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
			nouvelleListeUtilisateurs[i] = listeUtilisateurs_[i];
		//liberer le tableau 
		delete[] listeUtilisateurs_;
		// assigner la nouvelle liste et la nouvelle capacité
		listeUtilisateurs_ = nouvelleListeUtilisateurs;
		tailleTabUtilisateurs_ = nouvelleTaille;
	}
	// Ajouter nouvelle depense
	listeUtilisateurs_[nombreUtilisateurs_++] = unUtilisateur;
}
//implementation methode calculer total 
void Groupe::calculerTotalDepenses() {
	//pour chaque utilisateur on calcul le nombre total de depense
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
		listeUtilisateurs_[i]->calculerTotal();
		totalDepenses_ += listeUtilisateurs_[i]->getTotal();
	}
	comptes_ = new double[nombreUtilisateurs_];
	//calculer la moyenne des depenses de tout les utilisateurs
	double moyenneDepenses = totalDepenses_ / nombreUtilisateurs_;

	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
		comptes_[i] = listeUtilisateurs_[i]->getTotal() - moyenneDepenses;
}
//implementation methode equilibrer compte
void Groupe::equilibrerComptes() {
	listeTransferts_ = new Transfert*[nombreUtilisateurs_];
	for (unsigned int k = 0; k < nombreUtilisateurs_; k++) {
		if (comptes_[k] != 0) {
			//deux for loop pour comparer l'utilisateur aux restes et non juste avec celui à coté
			for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
				for (unsigned int j = 0; j < nombreUtilisateurs_; j++) {
					if (comptes_[i] != comptes_[j]) {
						if (comptes_[i] != 0 && comptes_[j] != 0) {
							if (comptes_[i] > 0 && comptes_[j] < 0) {
								if (fabs(comptes_[j]) <= comptes_[i]) {
									//ajout de nouv. transfert dans la liste de transfert
									listeTransferts_[nombreTransferts_++] = new Transfert(fabs(comptes_[j]), listeUtilisateurs_[j], listeUtilisateurs_[i]);
									comptes_[i] += comptes_[j];
									comptes_[j] = 0;
								}
								else {
									listeTransferts_[nombreTransferts_++] = new Transfert(fabs(comptes_[i]), listeUtilisateurs_[i], listeUtilisateurs_[j]);
									comptes_[j] += comptes_[i];
									comptes_[i] = 0;
								}
							}
						}
					}
				}
			}
		}
	}

}

//implementation methode afficher groupe
void Groupe::afficherGroupe() const {

	cout << " " << nom_ << " a coute un total pour le groupe de : " << totalDepenses_ << " voici les depenses :" <<endl;
	for (unsigned int i = 0; i < nombreUtilisateurs_; i++)
		listeUtilisateurs_[i]->afficherUtilisateur();

	if (nombreTransferts_ == 0) {
		cout <<endl<< "Soit les comptes suivants :"<<endl;
		for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
			cout << " " << listeUtilisateurs_[i]->getNom() << " : " << comptes_[i] << endl;
		}
	}
	else {
		cout << endl<<"Pour equilibrer : "<<endl;
		for (unsigned int i = 0; i < nombreTransferts_; i++) {
			listeTransferts_[i]->afficherTransfert();
		}
	}
}