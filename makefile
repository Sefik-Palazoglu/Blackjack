# .h files are in $(INCDIR)
INCDIR = ./include
# .cpp files are in $(SRC)
SRC = ./source
# .a files are in $(LIB)
LIB = ./library
# .o and .exe files are in current folder

all:	blackjack.exe

blackjack.exe:	blackjack.o $(LIB)/libblackjack.a
	g++ blackjack.o -L $(LIB) -lblackjack -o blackjack.exe

blackjack.o:	$(SRC)/blackjack.cpp $(INCDIR)/card.h $(INCDIR)/deck.h $(INCDIR)/player.h $(INCDIR)/game.h
	g++ -c -I $(INCDIR) $(SRC)/blackjack.cpp

$(LIB)/libblackjack.a: card.o deck.o player.o game.o
	ar rcs $(LIB)/libblackjack.a card.o deck.o player.o game.o

game.o:	$(SRC)/game.cpp $(INCDIR)/deck.h $(INCDIR)/player.h $(INCDIR)/game.h
	g++ -c -I $(INCDIR) $(SRC)/game.cpp

deck.o:	$(SRC)/deck.cpp $(INCDIR)/deck.h $(INCDIR)/card.h
	g++ -c -I $(INCDIR) $(SRC)/deck.cpp

player.o:	$(SRC)/player.cpp $(INCDIR)/deck.h $(INCDIR)/player.h $(INCDIR)/card.h
	g++ -c -I $(INCDIR) $(SRC)/player.cpp

card.o:	$(SRC)/card.cpp $(INCDIR)/card.h 
	g++ -c -I $(INCDIR) $(SRC)/card.cpp