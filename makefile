#PLIK MAKEFILE

CC = g++
CFLAGS = -std=c++11
TARGET = deck_of_cards

$(TARGET): main.o shell.o deck.o card.o
	$(CC) main.o shell.o deck.o card.o -g -o $(TARGET)

main.o: main.cpp shell.h
	$(CC) $(CFLAGS) -c -g main.cpp

shell.o: shell.cpp shell.h deck.h
	$(CC) $(CFLAGS) -c -g shell.cpp

deck.o: deck.cpp deck.h card.h
	$(CC) $(CFLAGS) -c -g deck.cpp 

card.o: card.cpp card.h
	$(CC) $(CFLAGS) -c -g card.cpp

clean:
	rm -f *.o $(TARGET)
