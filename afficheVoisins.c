#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "graphe.h"

int main(int argc, char *argv[]) {

  tNomSommet nom;
  tGraphe graphe;
  int i;
  int nbVoisins;
  int maxVoisins;
  maxVoisins = 0;

  if (argc<2) {
    halt("Usage : %s FichierGraphe\n", argv[0]);
  }

  
  graphe = grapheAlloue();
  
  grapheChargeFichier(graphe,  argv[1]);

  /*
    affiche les sommets sans voisins,
    calcule le nombre de voisins max
  */
  printf("Liste des sommets sans voisins :\n");
  
  for(i=0; i < grapheNbSommets(graphe); i++) {
    nbVoisins =grapheNbVoisinsSommet(graphe, i);
    if(nbVoisins == 0)
      {
	grapheRecupNomSommet(graphe, i, nom);
	printf("- %s\n", nom);
      }
    else
	if(nbVoisins > maxVoisins)
	  maxVoisins = nbVoisins;
  }

  /*
    affiche les sommets avec [maxVoisins] voisins
  */
  printf("Liste des sommets avec %d voisins (le maximum) :\n", maxVoisins);
  
  for(i=0; i < grapheNbSommets(graphe); i++) {
    nbVoisins =grapheNbVoisinsSommet(graphe, i);
    if(nbVoisins == maxVoisins)
      {
	grapheRecupNomSommet(graphe, i, nom);
	printf("- %s\n", nom);
      }
  }
  
  grapheLibere(graphe);

  exit(EXIT_SUCCESS);
}
