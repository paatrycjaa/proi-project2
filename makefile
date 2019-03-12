#PLIK MAKEFILE

CC = g++
CFLAGS = -std=c++11
TARGET = deck_of_cards

$(TARGET): main.o deck.o card.o
	$(CC) main.o deck.o card.o -g -o $(TARGET)

main.o: main.cpp deck.h
	$(CC) $(CFLAGS) -c -g main.cpp

deck.o: deck.cpp deck.h card.h
	$(CC) $(CFLAGS) -c -g deck.cpp 

card.o: card.cpp card.h
	$(CC) $(CFLAGS) -c -g card.cpp

clean:
	rm -f *.o $(TARGET)
