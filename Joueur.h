#pragma once
#ifndef JOUEUR_H
#define JOUEUR_H
#include"Utilisateur.h"
#include <iostream>
using namespace std;
class Joueur : public Utilisateur {
	string name;
	
public :
	// foction permet dafficher la main du joueur et son nom 
	virtual void Afficher () override;
	// constructeur avec parametre
	Joueur(string);
	// fonction permet au joueur de jouer 
	virtual  Carte jouer(deque<deque<Carte>>) override;
	// getteur de nom 
	string get_nom() override;

};



#endif  JOUEUR_H
