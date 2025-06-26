#pragma once
#ifndef CARTES_H
#define CARTES_H
#include <iostream>
#include <string>
enum Signe {
	Pique ,
	 Trefle,
	 Coeur,
	 Carreau,


};
enum Couleur {
	Noir,
	Rouge
};
class Carte {
	Signe signe;
	Couleur couleur;
	int numero;
public:
	//Constructeur avec parametre
	Carte(int ,int , int);
	// constructeur par defaut 
	Carte();
	// fonction qui permet dafficher la carte 
	void Afficher() const;
	// surcharge d affectateur
	void operator =(const  Carte&) ;
	// surrcharge de signe nest pas egale 
	bool operator != (const Carte&);
	// getteur de signe 
	int  get_signe();
	// getteur de numero 
	int  get_numero();
	
	

};


#endif CARTES_H
