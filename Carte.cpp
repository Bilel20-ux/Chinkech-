#include"Carte.h"

using namespace std;
// constructeur par defaut 
Carte::Carte() {
	signe = Pique;
	couleur = Noir;
	numero = 0;
}
// Constructeur avec Parametres 
Carte::Carte(int  signe, int  couleur, int num) {
	this->signe = static_cast <Signe> (signe);
	this->couleur = static_cast <Couleur>(couleur);
	numero = num;

}
// fonction permet dafficher la carte adequatement 
void Carte::Afficher () const  {
	string signe_msg;
	switch (signe) {
	case Trefle:
		signe_msg = "Trefle";
		break;
	case Pique:
		signe_msg = "Pique";
		break;
	case Carreau:
		signe_msg = "Carreau";
		break;
	case Coeur:
		signe_msg = "Coeur";
		break;

	}
	string couleur = "Noir";
	if (this->couleur == 1) {
		couleur = "Rouge";
	}
	cout << this->numero << "  de  " << signe_msg<<"   " << couleur ;
}
// surchage de loperateur = affectateur 
void Carte::operator = (const  Carte& other)  {
	this->couleur = other.couleur;
	this->numero = other.numero;
	this->signe = other.signe;
}
// surcharge de loperateur different 
bool Carte::operator != (const Carte& other) {
	return (this->couleur != other.couleur || this->numero != other.numero || this->signe != other.signe);
}
// getteur de signe
int Carte::get_signe() {
	return this->signe;

}
// getteur de numero 
int Carte::get_numero() {
	return this->numero;
}
