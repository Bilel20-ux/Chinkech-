
#include "Utilisateur.h"

using namespace std;
Utilisateur::Utilisateur() {
	Main main;
	this->main = main;
	numero_carte_joue = 0;
}


void Utilisateur::prendre(Carte carte ) {
	main.Ajouter(carte);

}
int Utilisateur::get_nombre_carte() {
	return this->main.get_nombre();

}
void Utilisateur::jetter() {
	main.jetter(this->numero_carte_joue);
	
	
}
