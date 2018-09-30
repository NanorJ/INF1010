/***************************************************************************
* Titre: Travail pratique #2 - groupe.cpp
* Auteur: Wassim Khene
* Modifié par : Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date: 2 octobre 2018
* Description: Ce code contient les méthodes implémentées de groupe.h
*************************************************************************/

#include "groupe.h"

// Implémentation du constructeur par défault
Groupe::Groupe() :
	nom_("") {
}
//Implémentation du constructeur par paramètres
Groupe::Groupe(const string& nom) :nom_(nom) {	

}

//Implémentation du desctructeurs
Groupe::~Groupe() {

}

//implementation methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

double Groupe::getTotalDepenses() const {
	double total = 0;
	for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
		total +=utilisateurs_[i]->getTotalDepenses();
	}
	return total;
}
//implementation des Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}
//implementation des Methodes d'ajout
Groupe Groupe::ajouterDepense(Depense* depense, Utilisateur* utilisateur) {
	utilisateur->operator+=(depense);
	depenses_.push_back(depense);
	return *this;
}

Groupe& Groupe::operator+=(Utilisateur* unUtilisateur) {
	utilisateurs_.push_back(unUtilisateur);
	return *this;
}
//implementation de la methode calculer comptes
void Groupe::calculerComptes()
{
	double moyenne = getTotalDepenses() / utilisateurs_.size();
	for ( unsigned int i = 0; i < utilisateurs_.size(); i++) {
		comptes_.push_back((utilisateurs_[i]->getTotalDepenses()) - moyenne);
	}
}
//implementation de la methode equilibrer comptes
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
		for (unsigned int i = 0; i < utilisateurs_.size(); i++) {
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
		if (unsigned int(count) >= utilisateurs_.size() - 1) {
			calcul = false;
		}
	}
}
//Méthodes d'affichage à l'aide des opérateurs 
ostream& operator<<(ostream& os, const Groupe& groupe) {
	os << "L'evenement " << groupe.getNom()
		<< " a coute un total de " << groupe.getTotalDepenses()
		<< " :  \n\n";

	for (unsigned int i = 0; i < groupe.utilisateurs_.size(); i++) {
		os << *groupe.utilisateurs_[i];
	}

	if (groupe.transferts_.size() != 0) {
		os << "Les transferts suivants ont ete realise pour equilibrer  : " << endl;
		for (unsigned int i = 0; i < groupe.transferts_.size(); i++) {
			os << "\t" << *groupe.transferts_[i];
		}
	}
	else {
		os << "Les comptes ne sont pas equilibres" << endl << endl;
	}
	return os;
}