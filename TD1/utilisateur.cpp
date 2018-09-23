#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

#include "utilisateur.h"

Utilisateur::Utilisateur() {
	nom_ = "unknown";
	tailleTabDepense_ = 5;
	nombreDepenses_ = 0;
	totalDepense_ = 0.0;
	listeDepenses_ = nullptr;
}

Utilisateur::Utilisateur(const string& nom) {
	nom_ = nom;
	listeDepenses_ = new Depense*[tailleTabDepense_];
}

Utilisateur::~Utilisateur() {
	delete[] listeDepenses_;
}

string Utilisateur::getNom() const {
	return nom_;
}

unsigned int Utilisateur::getNombreDepense() const {
	return nombreDepenses_;
}

double Utilisateur::getTotal() const {
	return totalDepense_;
}

void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

void Utilisateur::ajouterDepense(Depense* uneDepense) {
	if (nombreDepenses_ == tailleTabDepense_) {
		int nouvelleTaille = tailleTabDepense_ * 2;
		Depense** newListeDepenses = new Depense*[nouvelleTaille];

		for (int i = 0; i < nombreDepenses_; i++)
			newListeDepenses[i] = listeDepenses_[i];

		delete[] listeDepenses_;

		listeDepenses_ = newListeDepenses;
		tailleTabDepense_ = nouvelleTaille;
	}
	listeDepenses_[nombreDepenses_++] = uneDepense;
}

void Utilisateur::calculerTotal() {
	for (int i = 0; i < nombreDepenses_; i++)
		totalDepense_ += listeDepenses_[i]->getMontant();
}

void Utilisateur::afficherUtilisateur() const {
	cout << "\n Utilisateur : " << nom_ << " a d\202pens\202 pour un total de : " << totalDepense_ << "\n Liste de d\202penses : " << endl;
	for (int i = 0; i < nombreDepenses_; i++)
		listeDepenses_[i]->afficherDepense();
}