#pragma once
#ifndef BOT_H
#define BOT_H
#include<iostream>
#include"Utilisateur.h"
using namespace std;
class Bot : public Utilisateur {
	int num;
	int nombre_carte_pique;
	int nombre_carte_carreau;
	int nombre_carte_trefle;
	int nombre_carte_coeur;

public :
	Bot();
	Bot(int);
	virtual void Afficher() override;
	 virtual Carte jouer(deque<deque<Carte>>) override;
	 /*   Fonction permet d avoir seulement les cartes qu on peut les jouer
	   entre: la table du jeu
	   sortie: Main Valide  */
	 Main carte_a_jouer(deque<deque<Carte>>);
	 int get_numero_carte_jouer(Carte);
	virtual  string get_nom() override;

};








#endif  BOT_H
