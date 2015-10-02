#include <iostream>
#include "tablero.h"
#include <windows.h>

using namespace std;

void dibujarCabecera()
{
    cout << "*****************************************" << endl;
    cout << "*\tTic Tac Toe: The Game \t\t*" << endl;
    cout << "*\t\t         By: Dariel Cruz*" << endl;
    cout << "*****************************************\n" << endl;
}

int main()
{
    dibujarCabecera();
    Tablero* tablero = new Tablero();
    while(!tablero -> esGanador() && !tablero -> esEmpate()){
        tablero -> dibujarTablero();
        int fila = 0, columna = 0;
        cout << "\nEn cual fila desea jugar " << tablero -> jugador -> getJugadorActual() << " : ";
        cin >> fila;
        cout << "En cual columna desea jugar " << tablero -> jugador -> getJugadorActual() << " : ";
        cin >> columna;
        fila--;
        columna--;
        if(!tablero -> posicionOcupada(fila, columna) && tablero -> verificarLimites(fila, columna)){
            tablero -> setJugadorTablero(fila, columna);
            system("cls");
            dibujarCabecera();
        }else{
            system("cls");
            dibujarCabecera();
            cout << "Valor invalido, pruebe con otros\n" << endl;
        }
    }
    cout << endl;
    tablero -> dibujarTablero();
    return 0;
}
