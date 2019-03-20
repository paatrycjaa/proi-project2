/**
*Name : main.c
*Purpose : PROI Projekt_2 - zestaw kart
*@author Patrycja Cieplicka
*@version 1.0 11/03/2019
*/

#include "shell.h"
#include <cstdlib>

using namespace std;

int main(){
    srand(time(NULL));

    Shell program;
    program.action();

    return 0;
}
