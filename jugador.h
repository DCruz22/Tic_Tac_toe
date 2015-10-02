#ifndef JUGADOR_H
#define JUGADOR_H


class Jugador
{
    public:
        Jugador();
        virtual ~Jugador();
        char getJugadorActual();
        void setJugadorActual(char jugadorActual);
        void cambiarJugador();
    protected:
    private:
        char jugadorActual;
};

#endif // JUGADOR_H
