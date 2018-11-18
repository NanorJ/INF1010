/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#pragma once
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"
#include <map>
#include <vector>
#include<functional>


class AjouterDepense {
	public:
		//constructeur
		AjouterDepense(vector<Depense*>& conteneur) : conteneur_(conteneur) {};//check reference
		vector<Depense*>& operator()(Depense* depense) {
			conteneur_.push_back(depense);
			return conteneur_;
		}
	private:
		vector<Depense*> conteneur_;
};

class AjouterUtilisateur {
	public:
		//constructeur
		AjouterUtilisateur(map<Utilisateur*, double>& conteneur) : conteneur_(conteneur) {};
		map<Utilisateur*, double>& operator()(Utilisateur* utilisateur) {
			if (dynamic_cast<UtilisateurPremium*>(utilisateur) != nullptr) {
				if (dynamic_cast<UtilisateurPremium*>(utilisateur)->getJoursRestants() > 0)
					conteneur_.insert(make_pair(utilisateur, 0));
				else
					cout << "Erreur : L'utilisateur " << utilisateur->getNom() << " doit renouveler son abonnement premium" << endl;
			}
			else {
				if (dynamic_cast<UtilisateurRegulier*>(utilisateur)->getPossedeGroupe() == false) {
					conteneur_.insert(make_pair(utilisateur, 0));
					dynamic_cast<UtilisateurRegulier*>(utilisateur)->setPossedeGroupe(true);
				}
				else
					cout << "Erreur : L'utilisateur " << utilisateur->getNom() << " n'est pas un utilisateur premium et deja dans un groupe." << endl;
			}
			return conteneur_;
		}
	private:
		map<Utilisateur*, double>& conteneur_;
};


class FoncteurIntervalle {
	public:
		//constructeur
		FoncteurIntervalle(double borneInf, double borneSup) : borneInf_(borneInf), borneSup_(borneSup) {};
		bool operator()(pair<Utilisateur*, double> intervalle) { 
			return (intervalle.second <= borneSup_ && intervalle.second >= borneInf_);
		}
	private:
		double borneInf_, borneSup_;
};
