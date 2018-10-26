/***********************************************************************************
* Titre: Travail pratique #3 - groupe.cpp
* Auteur: Wassin khene & David Dratwa
* Modifié par: Nanor Janjikian (1901777) et Stéphanie Mansour (1935595)
* Date: 22 octobre 2018
* Description: Ce code contient les méthodes implémentées de groupe.h
************************************************************************************/

#include "groupe.h"

// Constructeurs
Groupe::Groupe() {
	nom_ = "";
}

Groupe::Groupe(const string& nom) : nom_(nom) {
}

Groupe::~Groupe() {
	for (unsigned int i = 0; i < transferts_.size(); i++)
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

// Methodes d'ajout et prend en paramètre un utilisateur (celui qui paie la dépense) et un vecteur d'utilisateur(ceux avec qui la dépense sera partagée)
Groupe& Groupe::ajouterDepense(Depense* depense, Utilisateur* payePar, vector<Utilisateur*> payePour) {
	
	bool payeParPresent = false;
	bool payePourPresentent = true;
	unsigned int j = 0;
	unsigned int i = 0;
	//Verifier que tous les utilisateurs concernés soient là
	//Verifie que la dépense soit bien une DepenseGroupe
	while ((payeParPresent == false) && (i < utilisateurs_.size())){
		if (utilisateurs_[i]->getNom() == payePar->getNom())
			payeParPresent = true;
		i++;
	}

	if (payeParPresent == false)
		payePourPresentent = false;
	
	
	while ((payePourPresentent == true) && (j < payePour.size())) {
		i = 0;
		while (i < utilisateurs_.size()){
			if (utilisateurs_[i]->getNom() == payePour[j]->getNom())
				payePourPresentent = true;
			i++;
		}
		j++;
	}
	//Ajoute la dépense aux utilisateurs concernés
	//Mets à jour les comptes des utilisateurs concernés
	if ((depense->getType() == groupe) && (payePourPresentent == true)){
		static_cast<DepenseGroupe*>(depense)->setNombreParticipants(unsigned int(payePour.size() + 1));
		depenses_.push_back(static_cast<DepenseGroupe*>(depense));
		(*payePar) += depense;

		int k = 0;
		while (payePar->getNom() != utilisateurs_[k]->getNom())
			k++;
		comptes_[k] = depense->getMontant() - static_cast<DepenseGroupe*>(depense)->getMontantPersonnel();

		for (unsigned int i = 0; i < payePour.size(); i++) {
			*payePour[i] += depense;
			//Ajoute la dépense au groupe
			k = 0;
			while (payePour[i]->getNom() != utilisateurs_[k]->getNom())
				k++;
			comptes_[k] -= static_cast<DepenseGroupe*>(depense)->getMontantPersonnel();
		}
	}
	//Sinon affiche une erreur
	else
		cout << "\nErreur: Vous tentez d'ajouter une depense individuelle au groupe ou alors les personnes impliquees dans la depense groupe ne sont pas dans le groupe \n";
	return *this;
}

//opérateur += ajoute un utilisateur* (vérifier si l’ajout est possible en respectant la logique des abonnements premium)
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

//Ajouter l’intérêt aux utilisateurs ayant le rôle de donneur dans les transferts
void Groupe::equilibrerComptes() {
	
	bool calcul = true;
	unsigned int count = 0;
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
//Mettre à jour le total dépense de tous les utilisateurs (en utilisant la méthode déjà implémentée) et du groupe
void Groupe::calculerTotalDepense() {
	for (unsigned int i = 0; i < utilisateurs_.size(); i++)
		utilisateurs_[i]->calculerTotalDepenses();

	for (unsigned int i = 0; i < depenses_.size(); i++)
		totalDepenses_ += depenses_[i]->getMontant();
}

// Methode d'affichage de l'opérateur << affiche les utilisateurs, les transferts et les comptes
ostream & operator<<(ostream& os, const Groupe& groupe) {
	os << "\nL'evenement nomme : " << groupe.nom_ << " a coute un total (en terme de depenses groupes) : "
		<< groupe.getTotalDepenses() << " $, voici les utilisateurs et toute leurs depenses : \n";

	for (unsigned int i = 0; i < groupe.utilisateurs_.size(); i++)
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

		for (unsigned int i = 0; i < groupe.transferts_.size(); i++)
			os << "\t" << *(groupe.transferts_[i]);
	}
	else
		os << "Les comptes ne sont pas equilibres" << endl << endl;
	
	return os;
}
