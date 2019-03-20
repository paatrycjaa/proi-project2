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
    void printStart() const;
    void clearBufor() const;
    void action();
    void printDecks() const;
    int getInt(int x1, int x2) const;

private:
    Deck* one;
    Deck* two;

    void addDecks() const;
    void addDecksChange();
    void youngest() const;
    void oldest() const;
    void addCardToDeck();
};


#endif // SHELL_H_
