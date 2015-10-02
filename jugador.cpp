#include "jugador.h"

Jugador::Jugador()
{
    jugadorActual = 'X';
}
char Jugador::getJugadorActual()
{
    return jugadorActual;
}

void Jugador::cambiarJugador()
{
    if(getJugadorActual() == 'X')
    {
        setJugadorActual('O');
    }else{
        setJugadorActual('X');
    }
}

void Jugador::setJugadorActual(char jugadorActual)
{
    this -> jugadorActual = jugadorActual;
}

Jugador::~Jugador()
{
    //dtor
}
