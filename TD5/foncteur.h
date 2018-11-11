/********************************************
* Titre: Travail pratique #5 - foncteur.h
* Date: 4 novembre 2018
* Auteur: Ryan Hardie
*******************************************/
#include <map>

class AjouterDepense {

public : 
	//constructeur
	AjouterDepense(vector<Depense*>& conteneur) : conteneur_(conteneur) {};//check reference
	vector<Depense*>& operator()(Depense* depense) 
	{
		conteneur_.push_back(depense);
		return conteneur_ ;
	}
private : 
	vector<Depense*> conteneur_;
};

class AjouterUtilisateur {

public:
	//constructeur
	AjouterUtilisateur(map<Utilisateur*,double>& conteneur) : conteneur_(conteneur) {};
	map<Utilisateur*, double>& operator()(Utilisateur* utilisateur)
	{
		//verifier les conditions 
		conteneur_.insert(make_pair(utilisateur, utilisateur -> getBalance));//faire attention getBalance ou getTransfert?
		return conteneur_ ;
	}
private:
	map<Utilisateur*, double> conteneur_;
};

class FoncteurIntervalle {
public : 
	//constructeur
	FoncteurIntervalle(double borneInf, double borneSup) : borneInf_(borneInf), borneSup_(borneSup) {};
	bool operator()(pair<Utilisateur*, double> intervalle)
	{ //first prcq on accede utilisateur
		if (intervalle.first->getBalance <= borneSup_ && intervalle.first->getBalance >= borneInf_)
			return true;
		else return false;
	}
private : 
	double borneInf_, borneSup_;

};
