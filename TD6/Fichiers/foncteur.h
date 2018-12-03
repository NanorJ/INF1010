#pragma once

#include <algorithm>
#include <set>
#include <map>

#include "depense.h"
#include "utilisateurRegulier.h"
#include "utilisateurPremium.h"



class AjouterDepense
{
public:
	AjouterDepense(vector<Depense*> &conteneur): conteneur_(conteneur) {
	}

	vector<Depense*>& operator() (Depense* depense) {
		conteneur_.push_back(depense);
		return conteneur_;
	};

private:
	vector<Depense*> &conteneur_;
};


class AjouterUtilisateur
{
public:
	AjouterUtilisateur(map<Utilisateur*, double>& conteneur) : conteneur_(conteneur) {
	}

	map<Utilisateur*, double>& operator() (Utilisateur* utilisateur) {
		UtilisateurRegulier* utilisateurRegulier = dynamic_cast<UtilisateurRegulier*>(utilisateur);
		UtilisateurPremium* utilisateurPremium = dynamic_cast<UtilisateurPremium*>(utilisateur);

		if (utilisateurRegulier != nullptr) {
			if (!utilisateurRegulier->getPossedeGroupe()) {
				utilisateurRegulier->setPossedeGroupe(true);
			}
			else {
				cout << "Erreur : L'utilisateur " << utilisateur->getNom() << " n'est pas un utilisateur premium et est deja dans un groupe." << endl;
				return conteneur_;
			}
		}
		else {
			if (utilisateurPremium != nullptr && utilisateurPremium->getJoursRestants() <= 0) {
				cout << "Erreur : L'utilisateur " << utilisateur->getNom() << " doit renouveler son abonnement premium" << endl;
				return conteneur_;
			}
		}
		conteneur_.insert(pair<Utilisateur*, double>(utilisateur, 0));

		return conteneur_;
	};

private:
	map<Utilisateur*, double>& conteneur_;
};

class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup) : borneSup_(borneSup), borneInf_(borneInf) {};

	bool operator() (const pair<Utilisateur*, double> & p)
	{
		return ((p.second >= borneInf_) && (p.second <= borneSup_));

	}
private:
	double borneInf_, borneSup_;
};



/*template<typename T>
class FoncteurEgal
{
public:
	FoncteurEgal(T* t) {
		t_ = t;
	}

	bool operator() (const pair<int, T*>& tAComparer) const {
		return tAComparer.second == t_;
	}

private:
	T * t_;
};

class FoncteurGenerateurId
{
public:
	FoncteurGenerateurId() {
		id_ = 0;
	}

	int operator() () {
		return  id_++;
	}

private:
	int id_;
};

class FoncteurDiminuerPourcent
{
public:
	FoncteurDiminuerPourcent(int pourcentage) {
		pourcentage_ = pourcentage;
	}

	void operator() (const pair<int, Produit*>& p) {
		double nouveauPrix = p.second->Produit::obtenirPrix() * (1 - (pourcentage_ / 100.0));
		p.second->modifierPrix(nouveauPrix);
	}

private:
	int pourcentage_;
};

class FoncteurIntervalle
{
public:
	FoncteurIntervalle(double borneInf, double borneSup) : borneSup_(borneSup), borneInf_(borneInf) {};

	bool operator() (const pair<int, Produit*> & p)
	{
		return ((p.second->obtenirPrix() >= borneInf_) && (p.second->obtenirPrix() <= borneSup_));

	}
private:
	double borneInf_, borneSup_;
};

class AjouterDepense {
public:
	AjouterDepense(vector<Depense*> depenses) : multimap_(multimap) {};

	multimap<int, Produit*>& operator() (Produit* produit) {
		multimap_.insert(pair<int, Produit*>(produit->obtenirReference(), produit));
		return multimap_;
	};
private:
	multimap<int, Produit*> &multimap_;
};

class SupprimerProduit {
public:
	SupprimerProduit(multimap<int, Produit*>& multimap) : multimap_(multimap) {};

	multimap<int, Produit*>& operator() (Produit* produit) {
		FoncteurEgal<Produit> fonteurComparaison(produit);
		auto position = find_if(multimap_.begin(), multimap_.end(), fonteurComparaison);
		if (position != multimap_.end())
			multimap_.erase(position);
		return multimap_;
	};
private:
	multimap<int, Produit*> &multimap_;
};

class AjouterUsager {
public:
	AjouterUsager(set<Usager*>& set) : set_(set) {};

	set<Usager*>& operator() (Usager* usager) {
		set_.insert(usager);
		return set_;
	};
private:
	set<Usager*>& set_;
};

class SupprimerUsager {
public:
	SupprimerUsager(set<Usager*>& set) : set_(set) {};

	set<Usager*>& operator() (Usager* usager) {
		auto position = set_.find(usager);
		if (position != set_.end())
			set_.erase(position);
		return set_;
	};
private:
	set<Usager*>& set_;
};*/
