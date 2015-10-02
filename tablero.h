#ifndef TABLERO_H
#define TABLERO_H

#include "jugador.h"

class Tablero
{
    public:
        Tablero();
        virtual ~Tablero();
        void iniciarTablero();
        void dibujarTablero();
        bool esGanador();
        bool esEmpate();
        Jugador* jugador;
        void setJugadorTablero(int fila, int columna);
        char getJugadorTablero(int fila, int columna);
        bool verificarLimites(int fila, int columna);
        bool posicionOcupada(int fila, int columna);
        protected:
    private:
        char tablero[3][3];
};

#endif // TABLERO_H
