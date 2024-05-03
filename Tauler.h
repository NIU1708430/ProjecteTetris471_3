#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
    void getTauler(ColorFigura tauler[MAX_FILA][MAX_COL]) const;
    bool colisio(const Figura& figura);
    void inicialitza(const ColorFigura tauler[MAX_FILA][MAX_COL]);
    void setBloc(int i, int j, ColorFigura color) { m_tauler[i][j] = color; }
    ColorFigura getBloc(int i, int j) const { return m_tauler[i][j]; }
private:
    ColorFigura m_tauler[MAX_FILA][MAX_COL];
};

ifstream& operator>> (ifstream& input, ColorFigura& tile);
ifstream& operator>> (ifstream& input, Tauler& tauler);
#endif