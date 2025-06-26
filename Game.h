#pragma once
#ifndef GAME_H
#define GAME_h
#include<iostream>
#include<string>
#include<vector>
#include<deque>
using namespace std;
#include"Utilisateur.h"
#include"Joueur.h"
#include"Bot.h"
class Game {
	deque<deque<Carte>> table  ;
	vector<Utilisateur*> joueurs;
	Chkobba chkobba;
	int nombre_de_joueur;
	int nombre_de_bot;
public :
	// constucteur par defaut 
	Game();
	// fonction qui declenche le jeu 
	void commencer();
	// fonction permet de dstribuer les cartes sur les utilisateurs 
	void distribuer();
	// fonction permet de verifier si la carte joue est valide 
	bool verif_carte(Carte);
	// fonction permet de deposer la carte joue sur la table de jeu 
	void deposer(Carte);
	// fonction permet dafficher tous les cartes joues 
	void Afficher_table();
	

};




#endif  GAME_H

