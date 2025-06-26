#pragma once
#ifndef CHKOBBA_H
#define CHKOBBA_H
#include<vector>
#include"Carte.h"
#include<iostream>
#include <random>
using namespace std;
class Chkobba {
public:
	vector <Carte> jeux;
	const int nombre_carte = 40;

	Chkobba();// constructeur

	void melanger()  ;// permet de melanger la carte 
	// permet dafficher tous les cartes de la chkobba 
	void Afficher() const ;
	// surcharge d'affectateur 
	void operator =(const  Chkobba&);


};



#endif CHKOBBA_H