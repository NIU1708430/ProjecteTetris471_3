#include "Figura.h"

ifstream& operator>> (ifstream& input, Figura& figura)
{
    int intFigura;
    TipusFigura tipusFigura;
    int fila, columna, rotacio;
    input >> intFigura >> fila >> columna >> rotacio;
    switch (intFigura)
    {
        case 1:
        {
            tipusFigura = FIGURA_O;
            break;
        }
        case 2:
        {
            tipusFigura = FIGURA_I;
            break;
        }
        case 3:
        {
            tipusFigura = FIGURA_T;
            break;
        }
        case 4:
        {
            tipusFigura = FIGURA_L;
            break;
        }
        case 5:
        {
            tipusFigura = FIGURA_J;
            break;
        }
        case 6:
        {
            tipusFigura = FIGURA_Z;
            break;
        }
        case 7:
        {
            tipusFigura = FIGURA_S;
            break;
        }
        default:
        {
            tipusFigura = NO_FIGURA;
            break;
        }
    }
    figura.inicialitza(tipusFigura, fila, columna, rotacio);
    return input;
}

void Figura::inicialitza(TipusFigura figura, int fila, int columna, int rotacio)
{
    m_figura = figura;
    m_fila = fila;
    m_columna = columna;
    actualitzaForma();
    for(int i = 0; i < rotacio; i++)
        girHorari();  
}

int Figura::getOffset(int direccio) const
{
    int offset = 0;
    switch (direccio)
    {
        case 0:
        {
            offset = m_offsetDalt;
            break;
        }
        case 1:
        {
            offset = m_offsetDret;
            break;
        }
        case 2:
        {
            offset = m_offsetBaix;
            break;
        }
        case 3:
        {
            offset = m_offsetEsq;
            break;
        }
    }
    return offset;
}

void Figura::girHorari()
{
    
    ColorFigura gridAuxiliar[MAX_ALCADA][MAX_AMPLADA];
    
    for (int i = 0; i < m_longCostat; i++)
        for (int j = 0; j < m_longCostat; j++)
            gridAuxiliar[i][j] = m_forma[j][i];
    
    for (int i = 0; i < m_longCostat; i++)
        for (int j = 0; j < m_longCostat; j++)
            m_forma[i][j] = gridAuxiliar[i][m_longCostat - 1 - j];

    int offsetAux = m_offsetBaix;
    m_offsetBaix = m_offsetDret;
    m_offsetDret = m_offsetDalt;
    m_offsetDalt = m_offsetEsq;
    m_offsetEsq = offsetAux;

}

void Figura::girAntihorari()
{
    ColorFigura gridAuxiliar[MAX_ALCADA][MAX_AMPLADA];
    
    for (int i = 0; i < m_longCostat; i++)
        for (int j = 0; j < m_longCostat; j++)
            gridAuxiliar[i][j] = m_forma[j][i];
            
    for (int i = 0; i < m_longCostat; i++)
        for (int j = 0; j < m_longCostat; j++)
            m_forma[i][j] = gridAuxiliar[m_longCostat - 1 - i][j];
    
    int offsetAux = m_offsetBaix;
    m_offsetBaix = m_offsetEsq;
    m_offsetEsq = m_offsetDalt;
    m_offsetDalt = m_offsetDret;
    m_offsetDret = offsetAux;
}

void Figura::actualitzaForma()
{
    if (m_figura == FIGURA_O)
    {
        m_longCostat = 2;
        m_offsetEsq = 0;
        m_offsetDret = 0;
        m_offsetDalt = 0;
        m_offsetBaix = 0;
    } else if (m_figura == FIGURA_I)
    {
        m_longCostat = 4;
        m_offsetEsq = 0;
        m_offsetDret = 0;
        m_offsetDalt = 1;
        m_offsetBaix = 2;
    } else
    {
        m_longCostat = 3;
        m_offsetEsq = 0;
        m_offsetDret = 0;
        m_offsetDalt = 0;
        m_offsetBaix = 1;
    }
    
    switch(m_figura)
    {
        case FIGURA_O:
        {
            ColorFigura grid[MAX_ALCADA][MAX_AMPLADA] = {{COLOR_GROC, COLOR_GROC, NO_COLOR, NO_COLOR}, {COLOR_GROC, COLOR_GROC, NO_COLOR, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}};
            for (int i = 0; i < MAX_ALCADA; i++)
                for (int j = 0; j < MAX_AMPLADA; j++)
                    m_forma[i][j] = grid[i][j];
            break;
        }
        case FIGURA_I:
        {
            ColorFigura grid[MAX_ALCADA][MAX_AMPLADA] = {{NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}, {COLOR_BLAUCEL, COLOR_BLAUCEL, COLOR_BLAUCEL, COLOR_BLAUCEL}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}};
            for (int i = 0; i < MAX_ALCADA; i++)
                for (int j = 0; j < MAX_AMPLADA; j++)
                    m_forma[i][j] = grid[i][j];
            break;
        }
        case FIGURA_T:
        {
            ColorFigura grid[MAX_ALCADA][MAX_AMPLADA] = {{NO_COLOR, COLOR_MAGENTA, NO_COLOR, NO_COLOR}, {COLOR_MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}};
            for (int i = 0; i < MAX_ALCADA; i++)
                for (int j = 0; j < MAX_AMPLADA; j++)
                    m_forma[i][j] = grid[i][j];
            break;
        }
        case FIGURA_L:
        {
            ColorFigura grid[MAX_ALCADA][MAX_AMPLADA] = {{NO_COLOR, NO_COLOR, COLOR_TARONJA, NO_COLOR}, {COLOR_TARONJA, COLOR_TARONJA, COLOR_TARONJA, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}};
            for (int i = 0; i < MAX_ALCADA; i++)
                for (int j = 0; j < MAX_AMPLADA; j++)
                    m_forma[i][j] = grid[i][j];
            break;
        }
        case FIGURA_J:
        {
            ColorFigura grid[MAX_ALCADA][MAX_AMPLADA] = {{COLOR_BLAUFOSC, NO_COLOR, NO_COLOR, NO_COLOR}, {COLOR_BLAUFOSC, COLOR_BLAUFOSC, COLOR_BLAUFOSC, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}};
            for (int i = 0; i < MAX_ALCADA; i++)
                for (int j = 0; j < MAX_AMPLADA; j++)
                    m_forma[i][j] = grid[i][j];
            break;
        }
        case FIGURA_Z:
        {
            ColorFigura grid[MAX_ALCADA][MAX_AMPLADA] = {{COLOR_VERMELL, COLOR_VERMELL, NO_COLOR, NO_COLOR}, {NO_COLOR, COLOR_VERMELL, COLOR_VERMELL, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}};
            for (int i = 0; i < MAX_ALCADA; i++)
                for (int j = 0; j < MAX_AMPLADA; j++)
                    m_forma[i][j] = grid[i][j];
            break;
        }
        case FIGURA_S:
        {
            ColorFigura grid[MAX_ALCADA][MAX_AMPLADA] = {{NO_COLOR, COLOR_VERD, COLOR_VERD, NO_COLOR}, {COLOR_VERD, COLOR_VERD, NO_COLOR, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}};
            for (int i = 0; i < MAX_ALCADA; i++)
                for (int j = 0; j < MAX_AMPLADA; j++)
                    m_forma[i][j] = grid[i][j];
            break;
        }
        default:
        {
            ColorFigura grid[MAX_ALCADA][MAX_AMPLADA] = {{NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}, {NO_COLOR, NO_COLOR, NO_COLOR, NO_COLOR}};
            for (int i = 0; i < MAX_ALCADA; i++)
                for (int j = 0; j < MAX_AMPLADA; j++)
                    m_forma[i][j] = grid[i][j];
            break;
        }
    }
}