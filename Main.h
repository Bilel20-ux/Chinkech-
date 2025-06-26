#pragma once
#ifndef MAIN_H
#define MAIN_H
#include "Carte.h"
#include<vector>
using namespace std;
class Main {
public:
	vector<Carte> main;
	int nombre_de_cartes;
	// getteur de nombre de carte 
	int get_nombre();
	// constructeur avec parametre
	Main(vector<Carte>);
	// constructeur par defaut 
	Main();
	//  fonction permet dafficher la main
	void Afficher();
	// fonction permet dajouter une carte a une main 
	void Ajouter(Carte);
	// fonction permet de chnager le nombre de carte par main 
	void set_nombre_carte(int);
	//  fonction permet de retirer une carte dun main 
	void jetter(int );
	

};





#endif  MAIN_H
