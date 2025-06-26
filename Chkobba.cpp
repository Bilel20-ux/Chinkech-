#include "Chkobba.h"

using namespace std;
Chkobba::Chkobba() {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 10;j++) {
			
			if (i < 2) {
				Carte carte{ i,0,j + 1 };
				jeux.push_back(carte);
			}
			else {
				Carte carte{ i,1,j + 1 };
				jeux.push_back(carte);
			}
			
		}
	}
}
void Chkobba::Afficher() const  {
	for (int i = 0;i< 40;i++) {
		jeux[i].Afficher();
	}
	cout << "nombre de carte est " << this->jeux.size()<< endl;

}
void Chkobba::melanger()  {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> distrib(51,100);
	int random_number = distrib(gen);
	for (int i = 0;i < random_number;i++) {
		random_device random;
		mt19937 generateur(random());
		uniform_real_distribution<> distrib1(0, 39);
		int random_carte1 = distrib1(generateur);
		int random_carte2 = distrib1(generateur);
		Carte stock{ 0, 0, 0 };
		stock = jeux[random_carte1];
		jeux[random_carte1] = jeux[random_carte2];
		jeux[random_carte2] = stock;

	
	}
}
void Chkobba::operator =( const Chkobba& Chkobba) {
	for (int i = 0;i < 40;i++) {
		this->jeux.push_back(Chkobba.jeux[i]);

	}

}