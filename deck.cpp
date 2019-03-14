/**
*Name : deck.cpp
*Purpose : PROI Projekt_2 - zestaw kart
*@author Patrycja Cieplicka
*@version 1.0 11/03/2019
*/

#include <iostream>

using namespace std;

#include "deck.h"
#include <string>


Deck::Deck(){                                                                                       //konstruktor

};

Deck::~Deck(){                                                                                      //destruktor

};

void Deck::addCard(Card newCard){                                                                   //dodaje karte do talii (talia jako tablica kart)
    for(size_t i =0; i< deck.size(); i++){
        if (newCard.getColor() == deck[i].getColor() && newCard.getRank() == deck[i].getRank()){    //sprawdzenie czy karta
            cout << "Nie mozna dodac karty, ktora jest juz w zestawie" << endl;
            return;
        }
    }
    deck.push_back(newCard);
}

Card Deck::findOldest() const{                                                                      //znajduje najstarsza karte w talii
    Card temp(Card::Ace, Card::diamond);
    for( size_t i = 0; i< deck.size(); i++){
        if(temp.getRank() < deck[i].getRank()){
            if(temp.getColor() < deck[i].getColor()){
                temp = deck[i];
            }
        }
    }
    return temp;
};

Card Deck::findYoungest() const{                                                                    //znajduje najmlodsza karte w talii
    Card temp(Card::King, Card::club);
    for( size_t i = 0; i< deck.size(); i++){
        if(temp.getRank() > deck[i].getRank()){
            if(temp.getColor() > deck[i].getColor()){
                temp = deck[i];
            }
        }
    }
    return temp;
};

bool Deck::ifCardInDeck(Card c) const{                                                              //sprawdza czy dana karta wystepuje w talii
    for (size_t i = 0; i < deck.size(); i++){
         if (c.getColor() == deck[i].getColor() && c.getRank() == deck[i].getRank()){
                return true;
            }
    }
    return false;
}

/*
Deck Deck::operator+(const Deck & two){                                                   //przeciazenie operatora + -> dodawanie dwóch obiektow talii (nie dupluja sie)
    Deck temp = *this;
    for (size_t i = 0; i < two.deck.size(); i++){                                                   //zwraca nowa wartosc
        if (! this->ifCardInDeck(two.deck[i])){
            temp.deck.push_back(two.deck[i]);
        }
    }
    return temp;
}

Deck Deck::operator+=(const Deck &two){                                                   //przeciazenie operatora + -> dodawanie dwóch obiektow talii (nie dupluja sie)
    for (size_t i = 0; i < two.deck.size(); i++){                                                   //zwraca nowa wartosc
        if (! this->ifCardInDeck(two.deck[i])){
            this->deck.push_back(two.deck[i]);
        }
    }
    return *this;
}*/





Deck operator+(const Deck &one, const Deck &two){                                                   //przeciazenie operatora + -> dodawanie dwóch obiektow talii (nie dupluja sie)
    Deck temp = one;
    for (size_t i = 0; i < two.deck.size(); i++){                                                   //zwraca nowa wartosc
        if (! one.ifCardInDeck(two.deck[i])){
            temp.deck.push_back(two.deck[i]);
        }
    }
    return temp;
}

Deck operator += (Deck &one, const Deck &two){                                                       //przeciazenie operatora += -> dodawanie dwoch obiektow talii (nie dupluje sie)
    for (size_t i = 0; i < two.deck.size(); i++){                                                   //nadpisuje wartosc pierwszego obiektu
        if (! one.ifCardInDeck(two.deck[i])){
            one.deck.push_back(two.deck[i]);
        }
    }
    return one;
}

ostream &operator <<(ostream &exit, const Deck &d ){                                                //przeciazenie operatora << -> wypisanie obiektu talii na ekran
    for (size_t i = 0; i< d.deck.size(); i++){
        exit << d.deck[i];
    };
    return exit;
};



