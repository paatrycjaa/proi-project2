/**
*Name : shell.cpp
*Purpose : PROI Projekt_2 - zestaw kart
*@author Patrycja Cieplicka
*@version 1.0 11/03/2019
*/

#include "shell.h"
#include <limits>

using namespace std;

Shell::Shell(){
    cout << "Wygeneruj dwie talie" << endl;
    cout << "Talia pierwsza" << endl;
    Deck* one = new Deck(howMany());
    cout << "Talia druga" << endl;
    Deck* two = new Deck(howMany());
    delete one;
    delete two;
}

Shell::~Shell(){
    //delete one;
    //delete two;
}

void Shell::printStart(){
    cout << "ZESTAW KART" << endl;
    cout << "Naciśnij: " << endl;
    cout << "1 - aby dodać talie do siebie (+)" << endl;
    cout << "2 - aby dodać jedną talię do drugiej talii (=+) " << endl;
    cout << "3 - aby znaleźć najmłodszą kartę w talii" << endl;
    cout << "4 - aby znaleźć najstarszą kartę w talii" << endl;
    cout << "5 - aby wydrukować talie" << endl;
    cout << "6 - aby dodać kartę do talii" << endl;
    cout << "7 - aby wyjsc z programu" << endl;
}

void Shell::clearBufor(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Shell::howMany(){
    cout << "Wpisz liczbę kart w talii (od 1 do 52) - zatwierdzając enterem"<< endl;
    int number;
    while (!(cin >> number) || number < 1 || number > 52 || cin.peek() != '\n'){
        cout << "Wpisz liczbę z przedziału 1-52" << endl;
        clearBufor();
    }
    return number;
}

void Shell::addDecksChange(Deck* one, Deck *two){
    cout << "Wpisz 1, aby dodać talia piersza += talia druga" << endl;
    cout << "Wpisz 2, aby dodać talia druga += talia pierwsza" << endl;
    int number;
    while (!(cin >> number) || number < 1 || number > 2 || cin.peek() != '\n'){
        cout << "Wpisz cyfrę 1 lub 2" << endl;
        clearBufor();
    }
    if (number == 1){
        *one += *two;
        cout << *one << endl;
    }
    else{
        *two += *one;
        cout << *two << endl;
    }
}

void Shell::addDecks(Deck* one, Deck *two){
    cout << "Suma dwoch talii:" << endl;
    cout << *one + *two << endl;
}

void Shell::oldest(Deck *one, Deck *two){
    cout << "Wpisz 1, aby znaleźć najstarszą kartę w talii pierwszej" << endl;
    cout << "Wpisz 2, aby znaleźć najstarszą kartę w talii drugiej" << endl;
    int number;
    while (!(cin >> number) || number < 1 || number > 2 || cin.peek() != '\n'){
        cout << "Wpisz cyfrę 1 lub 2" << endl;
        clearBufor();
    }
    if (number == 1)
        cout << one->findOldest() << endl;
    else
        cout << two->findOldest() << endl;
}


void Shell::youngest(Deck *one, Deck *two){
    cout << "Wpisz 1, aby znaleźć najmłodszą kartę w talii pierwszej" << endl;
    cout << "Wpisz 2, aby znaleźć najmłodszą kartę w talii drugiej" << endl;
    int number;
    while (!(cin >> number) || number < 1 || number > 2 || cin.peek() != '\n'){
        cout << "Wpisz cyfrę 1 lub 2" << endl;
        clearBufor();
    }
    if (number == 1)
        cout << one->findYoungest() << endl;
    else
        cout << two->findYoungest() << endl;
}

void Shell::addCardToDeck(Deck* one, Deck* two){
    cout << "Wpisz 1, aby dodać do pierwszej talii" << endl;
    cout << "Wpisz 2, aby dodać do drugiej talii" << endl;
    int number;
    while (!(cin >> number) || number < 1 || number > 2 || cin.peek() != '\n'){
        cout << "Wpisz cyfrę 1 lub 2" << endl;
        clearBufor();
    }
    switch(number){
        case 1:
            readWhatAdd(one);
            break;
        case 2:
            readWhatAdd(two);
            break;
        default:
            cout << "Blad" << endl;
            break;
    }

}

void Shell::readWhatAdd(Deck* temp){
    int col;
    int val;
    cout << "Podaj kolor karty" << endl;
    while (!(cin >> col) || col < 0 || col > 3 || cin.peek() != '\n'){
        cout << "Podaj cyfrę całkowitą w przedziale 0-3" << endl;
        clearBufor();
    }
    cout << "Podaj wartosc karty" << endl;
    while (!(cin >> val) || val < 1 || val > 13 || cin.peek() != '\n'){
        cout << "Podaj cyfrę całkowitą w przedziale 1-13" << endl;
        clearBufor();
    }
    temp->addCard(Card(Card::Rank(val), Card::Color(col)));
}

void Shell::printDecks(Deck* one, Deck* two){
    cout << "Wpisz 1, aby wypisać pierwszą talię" << endl;
    cout << "Wpisz 2, aby wypisać drugą talię" << endl;
    int number;
    while (!(cin >> number) || number < 1 || number > 2 || cin.peek() != '\n'){
        cout << "Wpisz cyfrę 1 lub 2" << endl;
        clearBufor();
    }
    if (number == 1)
        cout << *one << endl;
    else
        cout << *two << endl;
}


void Shell::action(Deck* one, Deck* two){
    int c;
    int process = 1;
    while(process){
        cin >> c;
        switch(c){
            case 1:
                addDecks(one, two);
                printStart();
                break;
            case 2:
                addDecksChange(one, two);
                printStart();
                break;
            case 3:
                oldest(one, two);
                printStart();
                break;
            case 4:
                youngest(one, two);
                printStart();
                break;
            case 5:
                printDecks(one, two);
                printStart();
                break;
            case 6:
                addCardToDeck(one, two);
                printStart();
                break;
            case 7:
                process = 0;
                break;
            default:
                cout << "Wpisz cyfre w przedziale 1-7" << endl;
                break;
        }
    }
    cout <<"end";
}


