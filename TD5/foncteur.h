/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Auteur: Ryan Hardie
* Modifié par : Nanor Janjikian (1901777) et Stephanie Mansour (1935595)
* Date: 19 novembre 2018
*******************************************/
#pragma once
#include "utilisateurPremium.h"
#include "utilisateurRegulier.h"

#include <map>
#include <vector>
#include <functional>


class AjouterDepense {
	public:
		//Constructeur
		AjouterDepense(vector<Depense*>& conteneur) : conteneur_(conteneur) {};
    
        //Operateurs
		vector<Depense*>& operator()(Depense* depense) {
			conteneur_.push_back(depense);
			return conteneur_;
		}
    
	private:
		vector<Depense*>& conteneur_;
};

class AjouterUtilisateur {
	public:
		//Constructeur
		AjouterUtilisateur(map<Utilisateur*, double>& conteneur) : conteneur_(conteneur) {};
    
        //Operateurs
		map<Utilisateur*, double>& operator()(Utilisateur* utilisateur) {
			//on verifie si l'utilisateur existe, est premiuim ou regulier et est dans groupe
			if (dynamic_cast<UtilisateurRegulier*>(utilisateur) != nullptr) {
				if (dynamic_cast<UtilisateurRegulier*>(utilisateur)->getPossedeGroupe() == false) {
					conteneur_.insert(pair<Utilisateur*,double>(utilisateur, 0.0));
					dynamic_cast<UtilisateurRegulier*>(utilisateur)->setPossedeGroupe(true);
				}
				else
					cout << "Erreur : L'utilisateur " << utilisateur->getNom() << " n'est pas un utilisateur premium et est deja dans un groupe." << endl;
			}

			else {
				if (dynamic_cast<UtilisateurPremium*>(utilisateur)->getJoursRestants() > 0)
					conteneur_.insert(pair<Utilisateur*, double>(utilisateur, 0.0));
				else
					cout << "Erreur : L'utilisateur " << utilisateur->getNom() << " doit renouveler son abonnement premium" << endl;
			}
			return conteneur_;
		}
	private:
		map<Utilisateur*, double>& conteneur_;
};


class FoncteurIntervalle {
	public:
		//Constructeur
		FoncteurIntervalle(double borneInf, double borneSup) : borneInf_(borneInf), borneSup_(borneSup) {};
    
        //Methode qui verifie si le compte associe à la paire est compris entre les bornes
		bool operator()(pair<Utilisateur*, double> intervalle) { 
			//on utilise second pour avoir la valeure
			if (intervalle.second <= borneSup_ && intervalle.second >= borneInf_)
				return true;
			return false;
        }
	private:
    double borneInf_, borneSup_;
};
