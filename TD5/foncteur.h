/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/

#include <map>

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
			auto end = conteneur_.end();
			for (auto it = conteneur_.begin(); it != end; it++) {
				if (it->first == utilisateur) {
					cout << "L'utilisateur existe deja." << endl;
					return conteneur_;//sortira directement de la classe sans avoir inserer la cle utilisateur
				}
			}
			if (dynamic_cast<UtilisateurRegulier*>(utilisateur)->getPossedeGroupe() == 1 && dynamic_cast<UtilisateurRegulier*>(utilisateur))
				conteneur_.insert(make_pair(utilisateur, 0));
			else
				cout << "Erreur : L'utilisateur " << utilisateur->getNom() << " n'est pas un utilisateur premium et est deja dans un groupe." << endl;

			if (dynamic_cast<UtilisateurPremium*>(utilisateur) && dynamic_cast<UtilisateurPremium*>(utilisateur)->getJoursRestants() >= 0) 
				conteneur_.insert(make_pair(utilisateur, 0));
			else	
				cout << "Erreur : L'utilisateur " << utilisateur->getNom() << " doit renouveler son abonnement premium" << endl;
			
			return conteneur_;
		}
	private:
		map<Utilisateur*, double> conteneur_;
};


class FoncteurIntervalle {
	public:
		//constructeur
		FoncteurIntervalle(double borneInf, double borneSup) : borneInf_(borneInf), borneSup_(borneSup) {};
		bool operator()(pair<Utilisateur*, double> intervalle) { 
			if (intervalle.first->getBalance <= borneSup_ && intervalle.first->getBalance >= borneInf_) // .second?
				return true;
			else return false;
		}
	private:
		double borneInf_, borneSup_;
};
