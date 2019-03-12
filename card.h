/**
*Name : card.h
*Purpose : PROI Projekt_2 - zestaw kart
*@author Patrycja Cieplicka
*@version 1.0 11/03/2019
*/

#ifndef CARD_H_
#define CARD_H_

#include <iostream>

//Klasa reprezentujaca karte do gry

class Card{

public:

    enum Color {diamond, heart, spades, club};                                                          // karo, kier, pik, trefl
    enum Rank {Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};       // as, jedynka, dwojka, trojka, czworka, piatka, szostka, siodemka, osemka, dziewiatka, dziesiatka, jop, dama, krol

    Card(Rank val, Color col);                                                                          //konstruktor
    ~Card();                                                                                            //destruktor

    Color getColor() const;                                                                             //zwraca kolor karty
    Rank getRank() const;                                                                               //zwraca figure karty
    std::string colorToString() const;                                                                  //zamienia kolor na stringa
    std::string rankToString() const;                                                                   //zamienia figure na stringa

    friend std::ostream & operator <<(std::ostream &exit, const Card &c );                              //zaprzyjazniona funkcja -> przeciazenie operatora << (wypisywanie na ekran klasy karta)


private:
    Rank value;                                                                                         //figura karty
    Color color;                                                                                        //kolor karty

};





#endif //CARD_H_
