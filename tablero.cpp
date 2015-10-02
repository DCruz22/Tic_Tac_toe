#include "tablero.h"
#include "jugador.h"
#include <iostream>

using namespace std;

Tablero::Tablero()
{
    iniciarTablero();
    jugador = new Jugador();
}

void Tablero::iniciarTablero()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            this -> tablero[i][j] = ' ';
        }
    }
}
void Tablero::setJugadorTablero(int fila, int columna)
{
    tablero[fila][columna] = jugador -> getJugadorActual();
    jugador -> cambiarJugador();
}

bool Tablero::esGanador()
{
    char jugador = tablero[0][0];

    //verificacionHorizontal
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tablero[i][j] == ' '){
                break; break;
            }
            if(jugador != tablero[i][j]){
                break; break;
            }
            jugador = tablero[i][j];
            if(j == 2){
                cout << "\n Ha ganado el jugador " << jugador << endl;
                return true;
            }
        }
    }

    //verificacionVertical
    jugador = tablero[0][0];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tablero[j][i] == ' '){
                break; break;
            }
            if(jugador != tablero[j][i]){
                break; break;
            }
            jugador = tablero[j][i];
            if(j == 2){
                cout << "\n Ha ganado el jugador " << jugador << endl;
                return true;
            }
        }
    }

    //verficacionVerticalPorLaIzquierda
    jugador = tablero[0][0];
    for(int i = 0; i < 3; i++){
        if(tablero[i][i] == ' '){
            break;
        }
        if(jugador != tablero[i][i]){
            break;
        }
        jugador = tablero[i][i];
        if(i == 2){
            cout << "\n Ha ganado el jugador " << jugador << endl;
            return true;
        }
    }

    //verficacionVerticalPorLaDerecha
    jugador = tablero[0][2];
    for(int i = 2; i >= 0; i--){
        if(tablero[2-i][i] == ' '){
            break;
        }
        if(jugador != tablero[2-i][i]){
            break;
        }
        jugador = tablero[2-i][i];
        if(i == 0){
            cout << "\n Ha ganado el jugador " << jugador << endl;
            return true;
        }
    }

    return false;
}

bool Tablero::esEmpate()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (tablero[i][j] == ' '){
                return false;
            }
        }
    }
    cout << "Hay un empate" << endl;
    return true;
}
char Tablero::getJugadorTablero(int fila, int columna)
{
    return this -> tablero[fila][columna];
}

bool Tablero::verificarLimites(int fila, int columna)
{
    return (fila <= 2 && fila >= 0) && (columna <= 2 && columna >= 0);
}
bool Tablero::posicionOcupada(int fila, int columna)
{
    return this -> getJugadorTablero(fila, columna) != ' ';
}

void Tablero::dibujarTablero()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << " " << tablero[i][j];
            if(j < 2){
                cout << " |";
            }
        }
        cout << endl;
        if(i < 2){
            cout << " _________" << endl;
        }
    }
}

Tablero::~Tablero()
{
    //dtor
}
