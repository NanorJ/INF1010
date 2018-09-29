/***************************************************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene
* Modifié par : Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date: 2 octobre 2018
* Description: Ce code contient les méthodes implémentées de groupe.h
*************************************************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() :
	nom_("")
	//nombreDepenses_(0),
	//nombreUtilisateurs_(0),
	//tailleTabUtilisateurs_(5),
	//tailleTabDepenses_(10),
	//depenses_(new Depense*[tailleTabDepenses_]),
	//utilisateurs_(new Utilisateur*[tailleTabUtilisateurs_]),
	//comptes_(new double[nombreUtilisateurs_]),
	//transferts_(new Transfert*[nombreUtilisateurs_]),
	//nombreTransferts_(0)
{
}

Groupe::Groupe(const string& nom) :nom_(nom) {
		
	//tailleTabUtilisateurs_(tailleTabUtilisateurs),
	//tailleTabDepenses_(tailleTabDepenses),
	//depenses_(new Depense*[tailleTabDepenses]),
	//utilisateurs_(new Utilisateur*[tailleTabUtilisateurs]),
	//comptes_(new double[nombreUtilisateurs_]),
	//transferts_(new Transfert*[nombreUtilisateurs_]),
	

}


Groupe::~Groupe() {
	
}


// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}


double Groupe::getTotalDepenses() const {
	double total = 0;
	for (int i = 0; i < depenses_.size(); i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe Groupe::ajouterDepense(Depense* depense, Utilisateur* utilisateur) {
	utilisateur->operator+=(depense);
	depenses_.push_back(depense);
	return *this;

}

Groupe& Groupe::operator+=(Utilisateur* unUtilisateur) {
	utilisateurs_.push_back(unUtilisateur);
	return *this;
}

void Groupe::calculerComptes()
{
	double moyenne = getTotalDepenses() / utilisateurs_.size();
	for (int i = 0; i < utilisateurs_.size(); i++) {
		comptes_.push_back((utilisateurs_[i]->getTotalDepenses()) - moyenne);
	}
}

void Groupe::equilibrerComptes() {
	calculerComptes();
	bool calcul = true;
	int count = 0;
	while (calcul) {
		double max = 0;
		double min = 0;
		int indexMax = 0;
		int indexMin = 0;

		// On cherche le compte le plus eleve et le moins eleve
		for (int i = 0; i < utilisateurs_.size(); i++) {
			if (comptes_[i] > max) {
				max = comptes_[i];
				indexMax = i;
			}
			if (comptes_[i] < min) {
				min = comptes_[i];
				indexMin = i;
			}
		}

		// On cherche lequel des deux a la dette la plus grande
		if (-min <= max) {
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;
		}
		else {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max) {
			count++;
		}
		if (count >= utilisateurs_.size() - 1) {
			calcul = false;
		}
	}
}


// Methode d'affichage
//void Groupe::afficherGroupe() const {
//	cout << "L'evenement " << nom_ << " a coute un total de " << getTotalDepenses() << " :  \n\n";
//	for (int i = 0; i < nombreUtilisateurs_; i++) {
//		utilisateurs_[i]->afficherUtilisateur();
//	}
//	cout << endl;
//
//	if (nombreTransferts_ != 0) {
//		cout << "Les transferts suivants ont ete realiser pour equilibrer  : " << endl;
//		for (int i = 0; i < nombreTransferts_; i++) {
//			cout << "\t";
//			transferts_[i]->afficherTransfert();
//		}
//	}
//	else {
//		cout << "Les comptes ne sont pas equilibres" << endl << endl;
//	}
//	cout << endl;
//}

ostream& operator<<(ostream& os, const Groupe& groupe) {
	os << "L'evenement " << groupe.getNom()
		<< " a coute un total de " << groupe.getTotalDepenses()
		<< " :  \n\n";

	for (int i = 0; i < groupe.utilisateurs_.size(); i++) {
		os << "\t\t" << groupe.utilisateurs_[i];
	}

	if (groupe.transferts_.size() != 0) {
		os << "Les transferts suivants ont ete realiser pour equilibrer  : " << endl;
		for (int i = 0; i < groupe.transferts_.size(); i++) {
			os << "\t" << groupe.transferts_[i];
		}
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
	}
	return os;
}