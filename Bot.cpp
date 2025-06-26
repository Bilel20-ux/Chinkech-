#include"Bot.h"
// constructeur par defaut 
Bot::Bot() : Utilisateur(){
	this->num = 0;
	nombre_carte_carreau, nombre_carte_coeur, nombre_carte_pique, nombre_carte_trefle = 0;
}
// constructeur avec parametres 
Bot::Bot(int numero) :Utilisateur() {
	this->num = numero;
}
/*-------------------------------------------------------------------------------------------------
   fonction permet dafficher le bot 
   entree:   
   sortie:    
   -------------------------------------------------------------------------------------------------*/

void Bot::Afficher() {
	cout << " la main du robot numero  " << this->num << endl;
	this->main.Afficher();
}
/*-----------------------------------------------------------------------------------------------------
fonction permet le bot de jouer un tour 
entree: un deque de double dimension (la table du jeu)
sortie: une carte 
-------------------------------------------------------------------------------------------------------*/
Carte Bot::jouer(deque<deque<Carte>> game ) {
	
		Main carte_possible = this->carte_a_jouer(game);
		
		if (carte_possible.main.empty() == false) {
			numero_carte_joue = this->get_numero_carte_jouer(carte_possible.main[0]);
		
			return carte_possible.main[0];


		}
		return Carte{ 0,0,0 };
}
/*  ------------------------------------------------------------------------------------------------------
Fonction permet d avoir seulement les cartes qu on peut les jouer 
       entre: la table du jeu 
	   sortie: Main Valide
	------------------------------------------------------------------------------------------------------*/
Main Bot::carte_a_jouer(deque<deque<Carte> > table) {
	Main carte_possible; 
	for (int i = 0;i < this->main.nombre_de_cartes;i++) {
		if (main.main[i].get_numero() == 5) {
			carte_possible.Ajouter(main.main[i]);

		}
		else {
			Carte carte_a_verifier = main.main[i];
			int signe = main.main[i].get_signe();
			int numero = main.main[i].get_numero();
			if (table[signe].empty()==false&&(numero - table[signe].front().get_numero() == 1 || numero - table[signe].back().get_numero() == -1)) {
				carte_possible.Ajouter(carte_a_verifier);
			}
		}
	}
	return carte_possible;
}
/*---------------------------------------------------------------------------------------------------
fonction qui pemet de connaitre lordre de la carte joue dans la main 
    entree: la carte joue 
	sortie: lordre de la carte 
	-------------------------------------------------------------------------------------------------*/
int Bot::get_numero_carte_jouer(Carte carte) {
	bool trouve = false;
	int i = 0;
	
	while (trouve == false) {
		Carte carte_a_verifer = main.main[i];
		if (carte != carte_a_verifer) {
			i++;

		}
		else {
			trouve = true;
		}
	}
	return i+1;
}
/* --------------------------------------------------------------------------------------------------------
fonction qui pemet davoir le nom du bot 
  entre:  
  sortie: nom du bot 
  --------------------------------------------------------------------------------------------------------*/
string Bot::get_nom() {
	string numero = to_string(this->num);
	return "le bot numero " + numero;
}