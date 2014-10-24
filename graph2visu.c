#include "sys/wait.h"

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
    {
      fprintf(fic, "digraph {\n", origine, destination);
      
    }
  else
    {
      fprintf(fic, "graph {\n", origine, destination);
      
    }
  

  fclose(fic);
  sprintf(commande, "dot -Tps %s -o %s", dotfile, outfile);
  ret = system(commande);
  if (WEXITSTATUS(ret))
    halt("La commande suivante a echoue\n%s\n", commande);
}
