/**
*Name : shell.h
*Purpose : PROI Projekt_2 - zestaw kart
*@author Patrycja Cieplicka
*@version 1.0 11/03/2019
*/

#ifndef SHELL_H_
#define SHELL_H_

#include "deck.h"
#include "shell.h"

class Shell {

public:

Shell();
~Shell();
void printStart();
void clearBufor();
void action(Deck* one, Deck* two);
void addDecks(Deck* one, Deck* two);
void addDecksChange(Deck* one, Deck* two);
int howMany();
void youngest(Deck *one, Deck *two);
void oldest(Deck *one, Deck *two);
void addCardToDeck(Deck* one, Deck* two);
void readWhatAdd(Deck* temp);
void printDecks(Deck* one, Deck* two);

private:
    Deck* one;
    Deck* two;

};


#endif // SHELL_H_
