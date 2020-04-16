/*

     Auteur : Mohamed Fouad Serradj
     Generateur de fichier test pour TP3
     INF3105 - Structures de données et algorithmes


     Ce programme vise simplement a generer des fichiers text pour le TP3
     INF3105. Ce code ne vise ni de pres ou de loin a l'elaboration du TP3
     Lui meme.
     Le format epouse celui mentione dans l'enonce du TP3.

     Le format de nom du fichier de sortie est le suivant :
     test-nombre de date-nombre de quartier-nombre de foyer.text

     Stay safe et bonne chance
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void implementerFoyer(ofstream& file, int nbrFoyer){
  int id, revenu, nbrPersonne;

  for (int i = 1; i <= nbrFoyer; i++ ){
    id = (rand() % 9000 ) + 1000;
    revenu = ( rand() % 95000 ) + 5000;
    nbrPersonne = ( rand() % 8 ) + 1;

    file << id << "  " << revenu << " " << nbrPersonne << std::endl;
  }
}

void implementerQuartier(ofstream& file, int nbrQuartier, int nbrFoyer){
  for(int i = 1; i <= nbrQuartier; i++ ){
    file << "Quartier" << i << std::endl;
    file << ";" << std::endl;
    implementerFoyer(file, nbrFoyer);
    file << ";" << std::endl ;
  }
}

void testVille(ofstream& file, int nbrDate, int nbrQuartier, int nbrFoyer){
  int annee,mois,jours;
  for(int i = 1; i <= nbrDate; i++){
    annee = (rand() % 15) + 2010;
    mois = (rand() % 12) + 1;
    jours = (rand() % 28) + 1;
    file << "DATE " << annee << "-" << mois << "-" << jours << std::endl;
    file << ";"<<std::endl;
    implementerQuartier(file,nbrQuartier, nbrFoyer);
  }
}



int main(int argc, char const *argv[]) {

  int nbrDate, nbrQuartier, nbrFoyer;
  std::ofstream file ;

  std::cout << "Combien de date voulez vous avoir ?" << std::endl;
  std::cin >> nbrDate;
  std::cout << "Combien de quartier par date voulez vous avoir ?" << std::endl;
  std::cin >> nbrQuartier;
  std::cout << "Combien de Foyer par quartier voulez vous avoir ?" << std::endl;
  std::cin >> nbrFoyer;

  file.open("./test" + std::to_string(nbrDate)+"-"+ std::to_string(nbrQuartier)+"-"+ std::to_string(nbrFoyer)+".txt");
  std::cout << "Fichier en cours de generation.." << std::endl;
  estVille(file,nbrDate,nbrQuartier,nbrFoyer);
  std::cout << ".." << std::endl;
  std::cout << "Fichier de test produit." << std::endl;
  file.close();
  return 0;

}
