#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

#include "groupe.h"

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

Groupe::Groupe(const string& nom, unsigned int tailleTabDepenses, unsigned int tailleTabUtilisateurs) {
	nom_ = nom;
	tailleTabDepenses_ = tailleTabDepenses;
	tailleTabUtilisateurs_ = tailleTabUtilisateurs;
	comptes_ = new double[nombreUtilisateurs_];
	listeTransferts_ = new Transfert*[nombreUtilisateurs_];
	listeUtilisateurs_ = new Utilisateur*[tailleTabUtilisateurs_];
	listeDepenses_ = new Depense*[tailleTabDepenses_];
}

Groupe::~Groupe() {
	delete[]  listeUtilisateurs_;
	delete[] listeDepenses_;
	delete[] comptes_;
	delete[]  listeTransferts_;
}

string Groupe::getNom() const {
	return nom_;
}

unsigned int Groupe::getNombreDepenses() const {
	return nombreDepenses_;
}

double Groupe::getTotal() const {
	return totalDepenses_;
}

void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

void Groupe::ajouterDepense(Depense* uneDepense, Utilisateur* payePar) {
	payePar->ajouterDepense(uneDepense);
	if (nombreDepenses_ == tailleTabDepenses_) {
		int nouvelleTaille = tailleTabDepenses_ * 2;
		Depense** newListeDepenses = new Depense*[nouvelleTaille];

		for (int i = 0; i < nombreDepenses_; i++)
			newListeDepenses[i] = listeDepenses_[i];

		delete[] listeDepenses_;

		listeDepenses_ = newListeDepenses;
		tailleTabDepenses_ = nouvelleTaille;
	}
	listeDepenses_[nombreDepenses_++] = uneDepense;
}

void Groupe::ajouterUtilisateur(Utilisateur *unUtilisateur) {
	if (nombreUtilisateurs_ == tailleTabUtilisateurs_) {
		int nouvelleTaille = tailleTabUtilisateurs_ * 2;
		Utilisateur** newListeUtilisateurs = new Utilisateur*[nouvelleTaille];

		for (int i = 0; i < nombreUtilisateurs_; i++)
			newListeUtilisateurs[i] = listeUtilisateurs_[i];

		delete[] listeUtilisateurs_;

		listeUtilisateurs_ = newListeUtilisateurs;
		tailleTabUtilisateurs_ = nouvelleTaille;
	}
	listeUtilisateurs_[nombreUtilisateurs_++] = unUtilisateur;
}

void Groupe::calculerTotalDepenses() {
	for (int i = 0; i < nombreUtilisateurs_; i++) {
		listeUtilisateurs_[i]->calculerTotal();
		totalDepenses_ += listeUtilisateurs_[i]->getTotal();
	}
	double moyenneDepenses = totalDepenses_ / nombreUtilisateurs_;

	for (int i = 0; i < nombreUtilisateurs_; i++)
		comptes_[i] = listeUtilisateurs_[i]->getTotal() - moyenneDepenses;
}

void Groupe::equilibrerComptes() {
	for (int g = 0; g < nombreUtilisateurs_; g++) {
		if (comptes_[g] != 0) {
			for (unsigned int i = 0; i < nombreUtilisateurs_; i++) {
				for (unsigned int j = 0; j < nombreUtilisateurs_; j++) {
					if (comptes_[i] != comptes_[j]) {
						if (comptes_[i] != 0 && comptes_[j] != 0) {
							if (comptes_[i] > 0 && comptes_[j] < 0) {
								if (abs(comptes_[j]) <= comptes_[i]) {
									listeTransferts_[nombreTransferts_++] = new Transfert(abs(comptes_[j]), listeUtilisateurs_[j], listeUtilisateurs_[i]);
									comptes_[i] += comptes_[j];
									comptes_[j] = 0;
								}
								else {
									listeTransferts_[nombreTransferts_++] = new Transfert(abs(comptes_[i]), listeUtilisateurs_[i], listeUtilisateurs_[j]);
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


void Groupe::afficherGroupe() const {

	cout << " " << nom_ << " a cout\202 un total pour le groupe de : " << totalDepenses_ << " voici les d\202penses : \n";
	for (int i = 0; i < nombreUtilisateurs_; i++)
		listeUtilisateurs_[i]->afficherUtilisateur();

	if (nombreTransferts_ == 0) {
		cout << "\n Soit les comptes suivants : \n";
		for (int i = 0; i < nombreUtilisateurs_; i++) {
			cout << " " << listeUtilisateurs_[i]->getNom() << " : " << comptes_[i] << endl;
		}
	}
	else {
		cout << "\n Pour \202quilibrer : \n";
		for (int i = 0; i < nombreTransferts_; i++) {
			listeTransferts_[i]->afficherTransfert();
		}
	}
}