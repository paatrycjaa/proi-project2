/**
*Name : shell.cpp
*Purpose : PROI Projekt_2 - zestaw kart
*@author Patrycja Cieplicka
*@version 1.0 11/03/2019
*/

#include <iostream>
#include <limits>
#include "shell.h"

using namespace std;

//konstruktor - generuje losowo dwie talie kart w zaleznosci od wpisanej przez uzytkownika liczby
Shell::Shell(){
    cout << "ZESTAW KART" << endl;
    cout << "Wygeneruj dwie talie - wpisz liczbę z przedziału 1-52 (standardowa liczba kard w talii)" << endl;
    cout << "Talia pierwsza" << endl;
    one = new Deck(getInt(1,52));
    cout << "Wylosowana talia pierwsza" << endl;
    cout << *one << endl;
    cout << "Talia druga" << endl;
    two = new Deck(getInt(1,52));
    cout << "Wylosowana talia druga" << endl;
    cout << *two << endl;
    printStart();
}

//destruktor - zwalnia pamiec wygenerowanych talii
Shell::~Shell(){
    delete one;
    delete two;
}

//Instrukcja obslugi programu
void Shell::printStart() const{
    cout << "Naciśnij: " << endl;
    cout << "1 - aby dodać talie do siebie (+)" << endl;
    cout << "2 - aby dodać jedną talię do drugiej talii (=+) " << endl;
    cout << "3 - aby znaleźć najstarszą kartę w talii" << endl;
    cout << "4 - aby znaleźć najmłodszą kartę w talii" << endl;
    cout << "5 - aby wydrukować talie" << endl;
    cout << "6 - aby dodać kartę do talii" << endl;
    cout << "7 - aby wyjsc z programu" << endl;
}


int Shell::getInt(int x1, int x2) const{                                                                  //metoda wczytująca liczbę całkowitą z podanego przedziału
    int number;                                                                                     //sprawdza poprawność wprowadzonych danych, prosi o ponowne wpisanie w przypadku bledu
    while (!(cin >> number) || number < x1 || number > x2 || cin.peek() != '\n'){
        cout << "Wpisz liczbę z przedziału "<< x1 <<"-"<< x2 << endl;
        clearBufor();
    }
    return number;
}


void Shell::clearBufor() const{                                                                           //metoda czyszcząca bufor
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void Shell::addDecksChange(){                                                                       //metoda pozwalajaca na dodanie (+=) talii
    cout << "Wpisz 1, aby dodać talia piersza += talia druga" << endl;                              //wczytuje ktora talia ma byc nadpisana
    cout << "Wpisz 2, aby dodać talia druga += talia pierwsza" << endl;
    if (getInt(1,2) == 1){
        *one += *two;
        cout << *one << endl;
    }
    else{
        *two += *one;
        cout << *two << endl;
    }
}

void Shell::addDecks() const{                                                                             //metoda pozwalajaca na dodanie (+) dwoch talii
    cout << "Suma dwoch talii:" << endl;
    cout << *one + *two << endl;                                                                    //dodawanie jest naprzemienne
}

void Shell::oldest() const{                                                                               //metoda pozwalajaca na znalezienie najstarszej karty
    cout << "Wpisz 1, aby znaleźć najstarszą kartę w talii pierwszej" << endl;
    cout << "Wpisz 2, aby znaleźć najstarszą kartę w talii drugiej" << endl;
    if (getInt(1,2) == 1)                                                                           //wczytanie, w której talii szukamy najstarszej karty
        cout << one->findOldest() << endl;
    else
        cout << two->findOldest() << endl;
}


void Shell::youngest() const{                                                                             //metoda pozwalajaca na znalezienie najmlodszej karty
    cout << "Wpisz 1, aby znaleźć najmłodszą kartę w talii pierwszej" << endl;
    cout << "Wpisz 2, aby znaleźć najmłodszą kartę w talii drugiej" << endl;
    if (getInt(1,2) == 1)                                                                           //wczytanie, w której talii szukamy najmlodszej karty
        cout << one->findYoungest() << endl;
    else
        cout << two->findYoungest() << endl;
}

void Shell::addCardToDeck(){                                                                        //meotda pozwalajaca na wczytanie danych podanych przez uzytkownika
    cout << "Podaj kolor karty, którą chcesz dodać" << endl;                                        //oraz dodanie odpowiedniej karty do wybranej talii
    cout << "0 - karo, 1 - trefl, 2 - kier, 3 - pik" << endl;
    int col = getInt(0,3);
    cout << "Podaj wartosc karty, którą chcesz dodać" << endl;
    cout << " 1 - As, 2 - Dwojka... 10 - Dziesiątka, 11 - Walet, 12 - Dama, 13 - Krol" << endl;
    int val = getInt(1,13);
    cout << "Wpisz 1, aby dodać do pierwszej talii" << endl;
    cout << "Wpisz 2, aby dodać do drugiej talii" << endl;

    if(getInt(1,2)==1){                                                                             //wczytanie, do ktorej talii dodajemy karte
        one->addCard(Card(Card::Rank(val), Card::Color(col)));
    }
    else
        two->addCard(Card(Card::Rank(val), Card::Color(col)));

}

void Shell::printDecks() const{                                                                           //metoda pozwalajaca na wydrukowanie talii
    cout << "Wpisz 1, aby wypisać pierwszą talię" << endl;
    cout << "Wpisz 2, aby wypisać drugą talię" << endl;
    if (getInt(1,2)==1)                                                                             //wczytanie, która talię drukujemy
        cout << *one << endl;
    else
        cout << *two << endl;
}


void Shell::action(){                                                                               //metoda pozwalająca na obsługę menu przez użytkownika
    int process = 1;
    while(process){
        switch(getInt(1,7)){
            case 1:                                                                                 // 1 - dodanie dwóch talii do siebie (+)
                addDecks();
                printStart();
                break;
            case 2:                                                                                 // 2 - dodanie jednej talii do drugiej (+=)
                addDecksChange();
                printStart();
                break;
            case 3:                                                                                 // 3 - znalezienie najstarszej karty w wybranej talii
                oldest();
                printStart();
                break;
            case 4:
                youngest();                                                                         // 4 - znalezienie najmłodszej karty w wybranej talii
                printStart();
                break;
            case 5:                                                                                 // 5 - wydrukowanie wybranej talii
                printDecks();
                printStart();
                break;
            case 6:                                                                                 // 6 - dodanie karty do wybranej talii
                addCardToDeck();
                printStart();
                break;
            case 7:
                process = 0;
                break;
            default:
                cout << "Blad" << endl;
                break;
        }
    }
}


