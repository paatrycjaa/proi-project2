/**
*Name : deck.h
*Purpose : PROI Projekt_2 - zestaw kart
*@author Patrycja Cieplicka
*@version 1.0 11/03/2019
*/

#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include "card.h"

class Deck {

public:
    Deck();                                                                     //konstruktor
    Deck(int numberOfCards);
    ~Deck();                                                                    //destruktor
    friend std::ostream & operator <<(std::ostream &exit, const Deck &d );      //zaprzyjazniona funkcja -> przeciazenie operatora << (wypisywanie na ekran)
    bool addCard(Card newCard);                                                 //dodaje katre do talii
    Card findOldest() const;                                                    //znajduje najstarsza karte w talii
    Card findYoungest() const;                                                  //znajduje najmlodsza karte w talii
    bool ifCardInDeck(Card c) const;
    //Deck operator+(const Deck & two);
    //Deck operator+=(const Deck &two);                                            //sprawdza czy karta znajduje sie juz w talii

    friend Deck operator + (const Deck &one, const Deck &two);                    //zaprzyjazniona funkcja -> przeciazenie operatora + (dodawanie talii) -> zwraca nowa zmienna
    friend Deck operator += ( Deck &one, const Deck &two);                       //zaprzyjazniona funkcja -> przeciazenie operatora += (dodawanie talii) -> do obecnej talii

private:
    std::vector<Card> deck;                                                     //talia jako wektor kart
};



#endif // DECK_H_
