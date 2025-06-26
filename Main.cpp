
#include "Main.h"
using namespace std;
Main::Main(vector<Carte> vecteur) {
	main = vecteur;
	nombre_de_cartes = vecteur.size();
	
}
Main::Main() {
	vector<Carte> main;
	this->main = main;
	nombre_de_cartes = 0;

}
void Main::Afficher() {
	for (int i = 0;i < main.size(); i++) {
		main[i].Afficher();
		cout << endl;

	}
	cout << this->nombre_de_cartes << endl;
}
void Main::Ajouter(Carte carte) {
	main.push_back(carte);
	nombre_de_cartes++;


}
int Main::get_nombre() {
	return this->nombre_de_cartes;
}
void::Main::set_nombre_carte(int nombre) {
	this->nombre_de_cartes = nombre;
}
void Main::jetter(int numero) {
	Carte carte_box = main[numero-1];
	for (int i =numero -1 ;i < nombre_de_cartes-1;i++) {

		carte_box = main[i + 1];
		main[i+1] = main[i ];
		main[i] = carte_box;
		
	}
	main.pop_back();
	nombre_de_cartes--;

}

