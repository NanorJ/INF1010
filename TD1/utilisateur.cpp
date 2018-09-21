#include "utilisateur.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//constructeur par default
Utilisateur::Utilisateur()
{
	nom_ = "";
	tailleTabDepense_ = 5;
	nombreDepenses_ = 0;
	totalDepense_ = 0.0;
	listeDepenses_ = nullptr;
}

//constructeur par parametres
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
	if (listeDepenses_ == nullptr)
	{
		tailleTabDepense_ = 5;
		listeDepenses_ = new Depense*[tailleTabDepense_];
	}
	else if (tailleTabDepense_ == nombreDepenses_)
	{
		tailleTabDepense_ += 5;
		Depense** nouvelleListeDepenses = new Depense*[tailleTabDepense_];

		for (int i = 0; i <= nombreDepenses_; i++) {
			nouvelleListeDepenses[i] = listeDepenses_[i];
		}
		delete[] listeDepenses_;
		listeDepenses_ = nouvelleListeDepenses;
	}
	listeDepenses_[nombreDepenses_++] = uneDepense;
}

void Utilisateur::calculerTotal()
{
	double depense;
	for (int i = 0; i <= nombreDepenses_; i++)
	{
		//depense = listeDepenses_[i]; TO DO
		//totalDepense_ += depense;
	}
}

void Utilisateur::afficherUtilisateur() const
{
	cout << "Utilisateur" << nom_ << endl;
	cout << "nombre de depense:" << nombreDepenses_ << endl;
	cout << "total de depense:" << setprecision(2) << totalDepense_ << endl;
	for (int i = 0; i < nombreDepenses_; i++) {
		listeDepenses_[i]->afficherDepense();
	}
}