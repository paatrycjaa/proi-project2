/**
*Name : card.cpp
*Purpose : PROI Projekt_2 - zestaw kart
*@author Patrycja Cieplicka
*@version 1.0 11/03/2019
*/

#include <iostream>

using namespace std;

#include "card.h"
#include <string>

Card::~Card(){                                                                                  //destruktor

};

Card::Card(Rank val, Color col) :value(val), color(col) {                                       //konstruktor, podanie wartosci jakie ma miec karta

};

Card::Color Card::getColor() const{                                                             //zwraca kolor karty
    return color;
}

Card::Rank Card::getRank() const{                                                               //zwraca figure karty
    return value;
}

string Card::colorToString() const{                                                             //zamienia kolor na stringa
    switch (color){
        case diamond :
            return "Karo";
        case spades :
            return "Pik";
        case heart :
            return "Kier";
        case club :
            return "Pik";
        default :
            return "Blad";
    }
}

string Card::rankToString() const{                                                              //zamienia wartosc na stringa
    switch (value){
        case Ace :
            return "As";
        case Two :
            return "Dwojka";
        case Three :
            return "Trojka";
        case Four :
            return "Czworka";
        case Five :
            return "Piatka";
        case Six :
            return "Szostka";
        case Seven :
            return "Siodemka";
        case Eight :
            return "Osemka";
        case Nine :
            return "Dziewiatka";
        case Ten :
            return "Dziesiatka";
        case Jack :
            return "Walet";
        case Queen :
            return "Dama";
        case King :
            return "Krol";
        default :
            return "Blad";
    }
}

ostream&operator <<(ostream &exit, const Card &c ){                                        //przeciazenie operatora << wypisanie klasy karta na ekran
    exit << "Kolor:" << c.colorToString() << "\tFigura: " << c.rankToString() << endl ;
    return exit;
};
