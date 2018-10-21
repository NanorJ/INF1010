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
	for (int i = 0; i < transferts_.size(); i++)
		delete transferts_[i];
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
	bool payePourPresentent = true;
	int j = 0;
	int i = 0;

	while ((payeParPresent == false) && (i < utilisateurs_.size())){
		if (utilisateurs_[i]->getNom() == payePar->getNom())
			payeParPresent = true;
		i++;
	}

	if (payeParPresent == false)
		payePourPresentent = false;
	
	i = 0;
	while ((payePourPresentent == true) && (j < payePour.size())) {
		while (i < utilisateurs_.size()){
			if (utilisateurs_[i]->getNom() == payePour[j]->getNom())
				payePourPresentent = true;
			i++;
		}
		j++;
	}

	if ((depense->getType() == groupe) && (payePourPresentent == true)){
		static_cast<DepenseGroupe*>(depense)->setNombreParticipants(unsigned int(payePour.size() + 1));
		depenses_.push_back(static_cast<DepenseGroupe*>(depense));
		(*payePar) += depense;

		int k = 0;
		while (payePar->getNom() != utilisateurs_[k]->getNom())
			k++;
		comptes_[k] = depense->getMontant() - static_cast<DepenseGroupe*>(depense)->getMontantPersonnel();

		for (int i = 0; i < payePour.size(); i++) {
			*payePour[i] += depense;
			
			k = 0;
			while (payePour[i]->getNom() != utilisateurs_[k]->getNom())
				k++;
			comptes_[k] = static_cast<DepenseGroupe*>(depense)->getMontantPersonnel();
		}
	}
	else
		cout << "\nErreur: Vous tentez d'ajouter une depense individuelle au groupe ou alors les personnes impliquees dans la depense groupe ne sont pas dans le groupe \n";
	return *this;
}


Groupe& Groupe::operator+=(Utilisateur* utilisateur) {
	bool estAjouter = true;
	if (utilisateur->getType() == Regulier) {
		if (static_cast<UtilisateurRegulier*>(utilisateur)->estGroupe() == true) {
			estAjouter = false;
			cout << "\nErreur : L'utilisateur " << utilisateur->getNom()
				<< " n'est pas souscrit a un abonnement premium, et fait deja partie d'un groupe\n";
		} else static_cast<UtilisateurRegulier*>(utilisateur)->setEtatGroupe(true);
	}
	if (utilisateur->getType() == Premium) {
		if (static_cast<UtilisateurPremium*>(utilisateur)->getJoursRestants() == 0) {
			estAjouter = false;
			cout << "\nErreur : L'utilisateur " << utilisateur->getNom()
				<< " doit renouveler abonnement premium";
		} else estAjouter = true;
	}
	if (estAjouter == true) {
		comptes_.push_back(0.0);
		utilisateurs_.push_back(utilisateur);
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
				utilisateurs_[indexMin]->ajouterInteret(0.05 * -min);
			else {
				static_cast<UtilisateurPremium*>(utilisateurs_[indexMin])->calculerTaux();
				double taux = static_cast<UtilisateurPremium*>(utilisateurs_[indexMin])->getTaux();
				utilisateurs_[indexMin]->ajouterInteret(taux * -min);
			}
		}
		else if (-min > max  && min != 0 && max != 0) {
			transferts_.push_back(new Transfert(max, utilisateurs_[indexMin], utilisateurs_[indexMax]));
			comptes_[indexMax] = 0;
			comptes_[indexMin] += max;

			if (utilisateurs_[indexMin]->getType() == Regulier)
				utilisateurs_[indexMin]->ajouterInteret(0.05 * max);
			else {
				static_cast<UtilisateurPremium*>(utilisateurs_[indexMin])->calculerTaux();
				double taux = static_cast<UtilisateurPremium*>(utilisateurs_[indexMin])->getTaux();
				utilisateurs_[indexMin]->ajouterInteret(taux * max);
			}
		}

		// On incremente le nombre de comptes mis a 0
		count++;
		if (-min == max)
			count++;
		if (count >= utilisateurs_.size() - 1)
			calcul = false;
	}
	
}

void Groupe::calculerTotalDepense() {
	for (int i = 0; i < utilisateurs_.size(); i++)
		utilisateurs_[i]->calculerTotalDepenses();

	for (int i = 0; i < depenses_.size(); i++)
		totalDepenses_ += depenses_[i]->getMontant();
}

// Methode d'affichage
ostream & operator<<(ostream& os, const Groupe& groupe) {
	os << "\n\nL'evenement nomme : " << groupe.nom_ << " a coute un total (en terme de depenses groupees) : "
		<< groupe.getTotalDepenses() << "$, voici les utilisateurs et toute leur depenses : \n";

	for (int i = 0; i < groupe.utilisateurs_.size(); i++)
	{
		if (groupe.utilisateurs_[i]->getType() == Regulier)
			os << *(static_cast<UtilisateurRegulier*>(groupe.utilisateurs_[i]));
		else
			os << "\n" << *(static_cast<UtilisateurPremium*>(groupe.utilisateurs_[i]));
	}
	os << endl;

	if (groupe.transferts_.size() != 0)
	{
		os << "Les transferts suivants ont"
			<< " ete realiser pour equilibrer  : " << endl;

		for (int i = 0; i < groupe.transferts_.size(); i++)
			os << "\t" << *(groupe.transferts_[i]);
	}
	else
		os << "Les comptes ne sont pas equilibres" << endl << endl;
	
	return os;
}
