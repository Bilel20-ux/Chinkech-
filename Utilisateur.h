#pragma once
#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include "Main.h"
#include<string>
#include"Chkobba.h"
#include<deque>

using namespace std;

/*class utilisateur :
il a comme attribut une main de 10 cartes 
*/
class Utilisateur {
protected:
	Main main;
	int numero_carte_joue;
	
	
public:
	    // constructeur par defautr 
	    Utilisateur();
		// fonction permet dafficher lutilisateur 
		virtual void Afficher() =0;
		// fonction permet lutilisateur de prendre une carte 
		void prendre(Carte);
		// fonction permet a lutilisateur de jouer un tour 
		virtual Carte jouer(deque<deque<Carte>>) = 0;
		// fonction permet davoi le nombre de carte de lutilisateur 
		int get_nombre_carte();
		// fonction permet lutilisateur de jetter une carte 
		void jetter();
		// getteur du nom de lutilisateur 
		virtual string get_nom() = 0;
	
};

#endif UTILISATEUR-H
