/**
*Name : main.c
*Purpose : PROI Projekt_2 - zestaw kart
*@author Patrycja Cieplicka
*@version 1.0 11/03/2019
*/

#include <iostream>
#include "deck.h"


using namespace std;

int main(){

    Deck deck;                                                                          //deklaracja dwoch pustych talii
    Deck decktwo;

    deck.addCard(Card(Card::Ace, Card::diamond));                                       //dodawanie kart do kazdej z talii
    deck.addCard(Card(Card::Jack, Card::spades));
    deck.addCard(Card(Card::Ace, Card::diamond));

    decktwo.addCard(Card(Card::Ace, Card::diamond));
    decktwo.addCard(Card(Card::King, Card::spades));


    cout << "talia pierwsza\n" << deck << endl;                                         //wypisanie talii na ekran ->przeciazenie <<
    cout << "talia druga\n" << decktwo << endl;
    cout << "Najstarsza karta z talii pierwszej\n" << deck.findOldest() << endl;        //zwrocenie najstarszej katry i najmlodszej karty w taliach
    cout << "Najmlodsza karta z talii pierwszej\n" << deck.findYoungest() << endl;
    cout << "Najstarsza karta z talii drugiej\n" << decktwo.findOldest() << endl;
    cout << "Najstarsza karta z talii drugiej\n" << decktwo.findYoungest() << endl;

    cout << "Suma dwoch talii\n" << deck + decktwo << endl;                             //sumowanie dwoch talii -> przeciazenie operatora + (nowa zmienna zwracana)
    deck += decktwo;                                                                    //sumowanie dwoch talii -> przeciazenie operatora += (dodanie do istniejacej zmiennej i nadpisanie jej)
    cout << deck << endl;

    return 0;
}
