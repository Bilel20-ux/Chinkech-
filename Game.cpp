#include"Game.h"
Game::Game  ()  {
	for (int i = 0; i < 4; ++i) {
		table.emplace_back();
	}


}
void Game::commencer() {
	
	this->chkobba.melanger(); // melnager la carte 
	cout << "donner le nombrre de joueur quils vont jouer " << endl;
	cin >> this->nombre_de_joueur; // nombre de joueur dans le game 
	while (nombre_de_joueur > 4) {
		cout << "redonner un autre nombre inferieur ou egale a 4" << endl;
		cin >> this->nombre_de_joueur; // nombre de joueur dans le game 
	}
	for (int i = 0;i < nombre_de_joueur;i++) {
		string name;
		cout << "donner le nom du joueur numero " << i + 1 << endl;
		cin >> name;
		
		this->joueurs.push_back( new Joueur(name));
	}
	nombre_de_bot = 4 - nombre_de_joueur; // terminer le jeu avec les bots 
	for (int i = 0;i < nombre_de_bot;i++) {
		;
		this->joueurs.push_back(new Bot(i+1));
	}
	distribuer();// distribuer les cartes sur les utilisateurs 
	bool termine = false;// un booleen si le game est termine 
	int i = 0;
	while (termine == false) {
		
		if (i > 3 && termine == false) {
			i = 0;
			

		}
		if (dynamic_cast<Joueur*>(joueurs[i])) {
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			Afficher_table();
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

		}
		Carte carte_joue = joueurs[i]->jouer(this->table);
		if (dynamic_cast<Joueur*>(joueurs[i])) {
			while (verif_carte(carte_joue) != true) {
				cout << "Carte incorrect rejouer" << endl;
				carte_joue = joueurs[i]->jouer(this->table);

			}

		}
	
		
		Carte passe = {0,0,0};
		if (carte_joue != passe) { // si le joueur a passe il ne va pas jetter une carte donc le ombre de carte ne va pas diminuer 
			joueurs[i]->jetter();
			deposer(carte_joue);

		}
		
		
		
		if (joueurs[i]->get_nombre_carte() == 0) {
			termine = true;
		}
		else {
			i++;
		}
		
		
		
	}
	cout << "le joueur gagnant est " << joueurs[i]->get_nom() << endl;
}
void Game::distribuer() {
	for (int i = 0;i < 40;i++) {
		int modulo = i % 4;
		switch (modulo) {
		  case 0:
			joueurs[0]->prendre(chkobba.jeux[i]);
			break;

		   case 1:
			joueurs[1]->prendre(chkobba.jeux[i]);
			break;
		

			case 2:
			joueurs[2]->prendre(chkobba.jeux[i]);
			break;

			case 3:
				joueurs[3]->prendre(chkobba.jeux[i]);

				break;
		}
	}

}
bool Game::verif_carte(Carte carte) {
	int numero_carte = carte.get_numero();
	Carte passe = { 0,0,0 };
	if (carte != passe) {
		if (numero_carte == 5) {
			return true;
		}
		else if (numero_carte != 5 && table[carte.get_signe()].size() == 0) {
			return false;
		}
		else if (numero_carte > 5) {
			int carte_verif = table[carte.get_signe()].front().get_numero();
			return (carte_verif == numero_carte - 1);

		}
		else {
			int carte_verif = table[carte.get_signe()].back().get_numero();
			return (carte_verif == numero_carte + 1);
		}
	}
	return true;
}
void Game::deposer(Carte carte) {
	int numero_carte = carte.get_numero();
	if (numero_carte == 5) {
		table[carte.get_signe()].push_back(carte);

	}
	else if (numero_carte < 5) {
		table[carte.get_signe()].push_back(carte);
	}
	else {
		table[carte.get_signe()].push_front(carte);
	}
}
void Game::Afficher_table() {
	for (int i = 0;i < 4;i++) {
		if (table[i].size() == 10) {
			continue;
		}
		switch (i) {
		case 0:
			cout << "pique: ";
			break;
		case 1:
			cout << "trefle:   ";
			break;
		case 2:
			cout << "coeur:   ";
			break;
		case 3:
			cout << "carreau:   ";
			break;
		}

		for (int j = 0;j < table[i].size();j++) {
			cout << table[i][j].get_numero();
			cout << "   ";

		}
		cout << endl;
	}
}