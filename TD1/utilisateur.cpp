#include "depense.h"
#include "utilisateur.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Utilisateur::Utilisateur()
{
	nom_ = "";
	tailleTabDepense_ = 5;
	nombreDepenses_ = 0;
	totalDepense_ = 0.0;
	listeDepenses_ = nullptr;
}

Utilisateur::Utilisateur(string& nom)
{
	nom_ = nom;
}

Utilisateur::  ~Utilisateur()
{
	if (listeDepenses_ != nullptr) {
		delete listeDepenses_;
		listeDepenses_ = nullptr;
	}
}

string Utilisateur::getNom() const
{
	return nom_;
}

unsigned int Utilisateur::getNombreDepense() const
{
	return nombreDepenses_;
}

double Utilisateur::getTotal() const
{
	return totalDepense_;
}

void Utilisateur::setNom(string& nom)
{
	nom_ = nom;
}

void Utilisateur::ajouterDepense(Depense* uneDepense)
{
	if (nombreDepenses_ > -tailleTabDepense_) {
		int nouvelleTaille = (tailleTabDepense_ > 0) ? tailleTabDepense_ * 2 : 5;
		Depense** newListeDepenses = new Depense*[nouvelleTaille];

		for (int i = 0; i < nombreDepenses_; i++) {
			nouvelleListeDepenses[i] = listeDepenses_[i];
		}
		delete[] listeDepenses_;
		listeDepenses_ = nouvelleListeDepenses; //pourquoi on fait pas de boucle ici
		tailleTabDepense_ = nouvelleTaille;

	}
	listeDepenses_[nombreDepenses_++] = uneDepense;
}

void Utilisateur::calculerTotal()
{
	double depense;
	for (int i = 0; i <= tailleTabDepense_; i++) //pouruqoi tailleTabDepense et pas nombreDepense_ puisque le tableau n'est pas necessairement remplis
	{
		totalDepense_ += (listeDepenses_[i]-> getMontant());
	}
}

void Utilisateur::afficherUtilisateur() const
{
	cout << "Utilisateur" << nom_ << endl;
	//cout << "tailleTabDepense:" << tailleTabDepense_ << endl;
	//cout << "nombre de depense:" << nombreDepenses_ << endl;
	cout << "total de depense:" << setprecision(2) << totalDepense_ << endl;
	for (int i = 0; i < nombreDepenses_; i++) {
		listeDepenses_[i]->afficherDepense();
	}
}

