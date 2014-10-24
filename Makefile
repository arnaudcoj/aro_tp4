CC      = gcc                              
CFLAGS  = -Wall -Werror -ansi -pedantic -std=c99          
CFLAGS += -g

all:testAnalyseur afficheVoisins

testAnalyseur:testAnalyseur.c graphe.c
	$(CC) $(CFLAGS) -o testAnalyseur testAnalyseur.c graphe.c

afficheVoisins:afficheVoisins.c graphe.c
	$(CC) $(CFLAGS) -o afficheVoisins afficheVoisins.c graphe.c

clean:
	rm -rf *.o *.ps *~ testAnalyseur afficheVoisins
