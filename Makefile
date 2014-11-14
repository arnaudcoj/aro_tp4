CC      = gcc                              
CFLAGS  = -Wall -Werror -ansi -pedantic -std=c99          
CFLAGS += -g
EXEC 	=  testAnalyseur afficheVoisins graphe2visu parcours
LIB = graphe.c

all: $(EXEC)

%: %.c
	$(CC) $(CFLAGS) $(LIB) -o $@ $<

ps:test.dot test-no.dot
	dot -Tps test.dot -o test.ps
	dot -Tps test-no.dot -o test-no.ps

test:graphe2visu q4-no.grp
	./graphe2visu q4-no.grp testq4
	./graphe2visu q2.grp testq2

clean:
	rm -rf *.o *.ps testq4.dot testq2.dot *~ testAnalyseur afficheVoisins graphe2visu
