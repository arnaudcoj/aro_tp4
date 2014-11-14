#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"
#include "sys/wait.h"
#include <assert.h>

void parcoursLargeur(tGraphe graphe);

int main (int argc, char **argv)
{
  tGraphe graphe;
  graphe = grapheAlloue();
  assert(argc != 1);
  grapheChargeFichier(graphe, argv[1]);
  parcoursLargeur(graphe);
  grapheLibere(graphe);

  return 0;
}

void parcoursLargeur(tGraphe graphe)
{

}
