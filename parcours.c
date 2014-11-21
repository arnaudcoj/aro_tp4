#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"
#include "sys/wait.h"
#include <assert.h>

/* Couleurs */
typedef enum {ROUGE=0, BLEU=1, VERT=2} tCouleur;
typedef tCouleur *tTabCouleurs;

void parcoursLargeur(tGraphe graphe, tNumeroSommet depart, tTabCouleurs sommetsParcourus);

int main (int argc, char **argv)
{
  tGraphe graphe;
  tNumeroSommet depart;
  tTabCouleurs sommetsParcourus;
  graphe = grapheAlloue();
  assert(argc == 3);
  grapheChargeFichier(graphe, argv[1]);
  sommetsParcourus = malloc(grapheNbSommets(graphe)*sizeof(tCouleur));
  depart = grapheChercheSommetParNom(graphe, argv[2]);
   parcoursLargeur(graphe, depart, sommetsParcourus);
  grapheLibere(graphe);
  free(sommetsParcourus);
  return 0;
}

void parcoursLargeur(tGraphe graphe, tNumeroSommet depart, tTabCouleurs sommetsParcourus)
{
  int i;
  tFileSommets file = fileSommetsAlloue();
  tNumeroSommet x, y;
  tNomSommet nom;
  for(i = 0; i < grapheNbSommets(graphe); i++)
    sommetsParcourus[i] = BLEU;
  sommetsParcourus[depart] = VERT;
  fileSommetsEnfile(file, depart);
  while(!fileSommetsEstVide(file))
    {
      x = fileSommetsDefile(file);
      grapheRecupNomSommet(graphe, x, nom);
      printf("sommet parcouru : %s\n", nom);
      for(i = 0; i < grapheNbVoisinsSommet(graphe, x); i++)
	{
	  y = grapheVoisinSommetNumero(graphe, x, i);
	  if(sommetsParcourus[y] == BLEU)
	    {
	      sommetsParcourus[y] = VERT;
	      fileSommetsEnfile(file, y);
	    }
	}
      sommetsParcourus[x] = ROUGE;
    }
    fileSommetsLibere(file);
  return;
}
