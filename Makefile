LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
C=./Classes/
H=Headers
Objs= main.o Deck.o Card.o Display.o Controller.o Model.o Player.o
class= $(C)main.cpp $(C)Deck.cpp $(C)Card.cpp $(C)Display.cpp $(C)Controller.cpp $(C)Model.cpp $(C)Player.cpp

all: main

main: $(objs)
	g++ -o Blackjack -I$(H) $(class) $(LIBS)

main.o: $(C)main.cpp
	g++ -c -I$(H) $(C)main.cpp

Card.o: $(C)Card.cpp
	g++ -c -I$(H) $(C)Card.cpp

Deck.o: $(C)Deck.cpp
	g++ -c -I$(H)  $(C)Deck.cpp

Display.o:  $(C)Display.cpp
	g++ -c -I$(H) $(C)Display.cpp

Controller.o: $(C)Controller.cpp
	g++ -c -I$(H) $(C)Controller.cpp

Model.o: $(C)Model.cpp
	g++ -c -I$(H) $(C)Model.cpp

Player.o: $(C)Player.cpp
	g++ -c -I$(H) $(C)Player.cpp

.PHONY: clean run

clean:
	rm *.o

run:
	./Blackjack
