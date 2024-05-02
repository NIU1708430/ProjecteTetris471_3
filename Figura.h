#ifndef FIGURA_H
#define FIGURA_H

#include <fstream>
using namespace std;

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;


typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    Figura() { m_figura = NO_FIGURA; }
    Figura(TipusFigura figura, int fila, int columna) { m_figura = figura; m_fila = fila; m_columna = columna; }
    ~Figura() {}
    
    void inicialitza(TipusFigura figura, int fila, int columna, int rotacio);
    TipusFigura getFigura() const { return m_figura; }
    ColorFigura getBloc(int i, int j) const { return m_forma[i][j]; }
    int getFila() const { return m_fila; }
    int getColumna() const { return m_columna; }
    int getLongCostat() const { return m_longCostat; }
    int getOffset(int direccio) const;
    void girHorari();
    void girAntihorari();
    void movEsquerra() { m_columna--; }
    void movDreta() { m_columna++; }
    void baixa() { m_fila++; }
    void puja() { m_fila--; }
    void actualitzaForma();
private:
    TipusFigura m_figura;
    int m_fila;
    int m_columna;
    int m_longCostat;
    int m_offsetEsq;
    int m_offsetDret;
    int m_offsetDalt;
    int m_offsetBaix;
    ColorFigura m_forma[MAX_ALCADA][MAX_AMPLADA];
};

ifstream& operator>> (ifstream& input, Figura& figura);

#endif