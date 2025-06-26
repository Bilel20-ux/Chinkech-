#include"Joueur.h"


Joueur::Joueur(string name) :Utilisateur () {
	
	this->name = name;
	Main main;
	this->main = main;

}void Joueur::Afficher ()  {
	cout << " la main de " << this->name << endl;
	this->main.Afficher();
}
Carte Joueur::jouer(deque<deque<Carte>> game) {
	cout << "voici la main de:  " << this->name << endl;
	main.Afficher();
	int numero;
	cout << "donner le numero de carte que tu veux la jouer  si vous voulez passer entrer 0" << endl;
	cin >> numero;
	while (numero > main.nombre_de_cartes) {
		cout << "voici la main de:  " << this->name << endl;
		main.Afficher();

		cout << "carte indisponible entrer un choix correcte " << endl;
		cin >> numero;

	}
	if (numero == 0) {
		return Carte{ 0,0,0 };

	}
	else {
		numero_carte_joue = numero;
		return main.main[numero-1];
	}
}
string Joueur::get_nom() {
	return this->name;
}