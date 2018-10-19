/********************************************
* Titre: Travail pratique #2 - groupe.cpp
* Date: 16 septembre 2018
* Auteur: Wassim Khene & David Dratwa
*******************************************/

#include "groupe.h"

// Constructeurs

Groupe::Groupe() {
	nom_ = ""; 
}
Groupe::Groupe(const string& nom) : nom_(nom) {
}

Groupe::~Groupe() {
	for (int i = 0; i < transferts_.size(); i++) {
		delete transferts_[i];
	}
}


// Methodes d'acces
string Groupe::getNom() const {
	return nom_;
}

vector<DepenseGroupe*> Groupe::getDepenses() const {
	return depenses_;
}

vector<Utilisateur*> Groupe::getUtilisateurs() const {
	return utilisateurs_;
}

vector<Transfert*> Groupe::getTransferts() const {
	return transferts_;
}


double Groupe::getTotalDepenses() const {
	return totalDepenses_;
}

// Methodes de modifications
void Groupe::setNom(const string& nom) {
	nom_ = nom;
}

// Methodes d'ajout
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour) {
	bool payeParPresent = false;
	int i = 0;
	while ((payeParPresent == false) && (i < utilisateurs_.size())) {
		if (utilisateurs_[i] == payePar)
			payeParPresent = true;
		i++;
	}

	bool payePourExistent = true;
	if (payeParPresent == false)
		payePourExistent = false;

	int j = 0;
	while ((payePourExistent == true) && (j < payePour.size()))
	{
		i = 0;
		payeParPresent = false;
		while ((payeParPresent == false) && (i < utilisateurs_.size()))
		{
			if (utilisateurs_[i]->getNom() == payePour[j]->getNom())
				payeParPresent = true;

			i++;
		}
		j++;
		if ((payeParPresent == false) && (i < utilisateurs_.size()))
			payePourExistent = false;
	}



	/*for (int i = 0; i < payePour.size(); i++) {
		int j = 0;
		while (payePour[i] != this->utilisateurs_[j] && j < payePour.size()) {
			payePourExistent = false;
			j++;
		}
		if (j < payePour.size()) payePourExistent = true;
	}
	
	if (payePourExistent) {
		if (depense->getType() == groupe) {
			payePar->get
		}
	}*/
}


Groupe& Groupe::operator+=(Utilisateur* utilisateur) {
	bool estAjouter = true;
	if (utilisateur->getType() == Regulier) {
		if (static_cast<UtilisateurRegulier*>(utilisateur)->estGroupe() == true)
			estAjouter = false;
		else
			static_cast<UtilisateurRegulier*>(utilisateur)->setEtatGroupe(true);
	}
	if (utilisateur->getType() == Premium) {
		if (static_cast<UtilisateurPremium*>(utilisateur)->getJoursRestants() == 0)
			estAjouter = false;
		else estAjouter = true;
	}
	if (estAjouter == true) {
		comptes_.push_back(0.0);
		utilisateurs_.push_back(utilisateur);
	}
	else {
		cout << "\nErreur	:	" << utilisateur->getNom()
			<< " n'est pas souscrit a un abonnement premium, et est deja groupe";
	}
	return *this;
}


void Groupe::equilibrerComptes() {
	
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
		if (-min <= max && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(-min, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] += min;
			comptes_[indexMin] = 0;

			if (utilisateurs_[indexMin]->getType() == Regulier)
				utilisateurs_[indexMin]->ajouterInteret(0.05 * abs(min));
			else {
				double taux = static_cast<UtilisateurPremium*>(utilisateurs_[indexMin])->getTaux();
				utilisateurs_[indexMin]->ajouterInteret(taux * abs(min));
			}
		}

		else if (-min > max  && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;

			if (utilisateurs_[indexMin]->getType() == Regulier)
				utilisateurs_[indexMin]->ajouterInteret(0.05 * max);
			else {
				double taux = static_cast<UtilisateurPremium*>(utilisateurs_[indexMin])->getTaux();
				utilisateurs_[indexMin]->ajouterInteret(taux * max);
			}
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

void Groupe::calculerTotalDepense() {
	for (int i = 0; i < utilisateurs_.size(); i++)
		utilisateurs_[i]->calculerTotalDepenses();

	//totalDepenses_ = 0.0; // why
	for (int i = 0; i < depenses_.size(); i++)
		totalDepenses_ += depenses_[i]->getMontant();
}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe)
{
	
}
