/**
*Name : card.cpp
*Purpose : PROI Projekt_2 - zestaw kart
*@author Patrycja Cieplicka
*@version 1.0 11/03/2019
*/

#include <iostream>

using namespace std;

#include "card.h"

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
            return "\u2666";
            //return "Karo";
        case spades :
            return "\u2660";
            //return "Pik";
        case heart :
            return "\u2665";
            //return "Kier";
        case club :
            return "\u2663";
            //return "Zyro";
        default :
            return "Blad";
    }
}

string Card::rankToString() const{                                                              //zamienia wartosc na stringa
    switch (value){
        case Ace :
            return "As";
        case Two :
            return "2";
        case Three :
            return "3";
        case Four :
            return "4";
        case Five :
            return "5";
        case Six :
            return "6";
        case Seven :
            return "7";
        case Eight :
            return "8";
        case Nine :
            return "9";
        case Ten :
            return "10";
        case Jack :
            return "J";
        case Queen :
            return "D";
        case King :
            return "K";
        default :
            return "Blad";
    }
}

ostream&operator <<(ostream &exit, const Card &c ){                                        //przeciazenie operatora << wypisanie klasy karta na ekran
    //exit << "Kolor:" << c.colorToString() << "\tFigura: " << c.rankToString() << endl ;
    exit << c.rankToString() << " " << c.colorToString() << endl ;
    return exit;
};
