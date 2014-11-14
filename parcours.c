#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"
#include "sys/wait.h"
#include <assert.h>

/* Couleurs */
typedef enum {ROUGE=0, BLEU=1, VERT=2} tCouleur;
typedef tCouleur *tTabCouleurs;

void parcoursLargeur(tGraphe graphe, tNumeroSommet depart, int *sommetsParcourus);

int main (int argc, char **argv)
{
  tGraphe graphe;
  tNumeroSommet depart;
  tTabCouleurs sommetsParcourus;
  sommetsParcourus = malloc(grapheNbSommets(graphe)*sizeof(tCouleur));
  graphe = grapheAlloue();
  assert(argc != 1);
  grapheChargeFichier(graphe, argv[1]);
  depart = grapheChercheSommetParNom(graphe, argv[2]);
  parcoursLargeur(graphe, depart, sommets);
  grapheLibere(graphe);

  return 0;
}

void parcoursLargeur(tGraphe graphe, tNumeroSommet depart, int *sommetsParcourus)
{
  
}
