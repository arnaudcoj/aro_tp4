#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"
#include "sys/wait.h"

void graphe2visu(tGraphe graphe, char *outfile);
void writeGraph(tGraphe graphe, FILE *fic);
void writeDiGraph(tGraphe graphe, FILE *fic);

int main (int argc, char **argv)
{
  tGraphe graphe;
  graphe = grapheAlloue();
  grapheChargeFichier(graphe, "q4-no.grp");
  graphe2visu(graphe, "debug");
  grapheLibere(graphe);
  return 0;
}

/* Necessaire pour la macro WEXITSTATUS */
void graphe2visu(tGraphe graphe, char *outfile) {
  FILE *fic;
  char commande[80];
  char dotfile[80]; /* le fichier dot pour creer le ps */
  int ret;
  /* on va creer un fichier pour graphviz, dans le fichier "outfile".dot */
  strcpy(dotfile, outfile);
  strcat(dotfile, ".dot");
  fic = fopen(dotfile, "w");
  if (fic==NULL)
    halt ("Ouverture du fichier %s en ecriture impossible\n", dotfile);
  
  if(grapheEstOriente(graphe))
    writeDiGraphe(graphe, fic);
  else
    writeGraphe(graphe, fic);

  fclose(fic);
  sprintf(commande, "dot -Tps %s -o %s", dotfile, outfile);
  ret = system(commande);
  if (WEXITSTATUS(ret))
    halt("La commande suivante a echoue\n%s\n", commande);
}

void writeDiGraph(tGraphe graphe, FILE *fic) 
{
  tArc arc;
  int i;
  fprintf(fic, "digraph {\n");
  for(i = 0; i < grapheNbArcs(graphe); i++)
    {
      arc = grapheRecupArcNumero(graphe, i);
      fprintf(fic, "%s -> %s;\n", grapheRecupNomSommet(arc.orig), grapheRecupNomSommet(arc.dest));
    }
  fprintf(fic, "}\n");
}

void writeGraph(tGraphe graphe, FILE *fic) 
{
  int i;
  fprintf(fic, "graph {\n");
  for(i = 0; i < grapheNbArcs(graphe); i++)
    {
      arc = grapheRecupArcNumero(graphe, i);
      fprintf(fic, "%s -> %s;\n", grapheRecupNomSommet(arc.orig), grapheRecupNomSommet(arc.dest));
    }
  fprintf(fic, "}\n");
}

