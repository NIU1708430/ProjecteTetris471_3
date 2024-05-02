#include "Tauler.h"

ifstream& operator>> (ifstream& input, ColorFigura& tile)
{
    int intTile;
    input >> intTile;
    switch(intTile)
    {
        case 0:
        {
            tile = COLOR_NEGRE;
            break;
        }
        case 1:
        {
            tile = COLOR_GROC;
            break;
        }
        case 2:
        {
            tile = COLOR_BLAUCEL;
            break;
        }
        case 3:
        {
            tile = COLOR_MAGENTA;
            break;
        }
        case 4:
        {
            tile = COLOR_TARONJA;
            break;
        }
        case 5:
        {
            tile = COLOR_BLAUFOSC;
            break;
        }
        case 6:
        {
            tile = COLOR_VERMELL;
            break;
        }
        case 7:
        {
            tile = COLOR_VERD;
            break;
        }
        default:
        {
            tile = NO_COLOR;
            break;
        }
    }
    return input;
}

ifstream& operator>> (ifstream& input, Tauler& tauler)
{
    ColorFigura grid[MAX_FILA][MAX_COL];

    for (int i = 0; i < MAX_FILA; i++)
        for (int j = 0; j < MAX_COL; j++)
            input >> grid[i][j];

    tauler.inicialitza(grid);
    return input;
}

void Tauler::inicialitza(const ColorFigura tauler[MAX_FILA][MAX_COL])
{
    for (int i = 0; i < MAX_FILA; i++)
        for (int j = 0; j < MAX_COL; j++)
            m_tauler[i][j] = tauler[i][j];
}

void Tauler::getTauler(ColorFigura tauler[MAX_FILA][MAX_COL]) const
{
    for (int i = 0; i < MAX_FILA; i++)
        for (int j = 0; j < MAX_COL; j++)
            tauler[i][j] = m_tauler[i][j];
}

bool Tauler::colisio(const Figura& figura)
{
    int i = figura.getFila() - 1, j = figura.getColumna() - 1;
    bool choca = false;
    
    //Es comprova que la figura no surti del tauler
    if (i < 0 - figura.getOffset(0) || j < 0 - figura.getOffset(3) || i + figura.getLongCostat() - figura.getOffset(2) > MAX_FILA || j + figura.getLongCostat() - figura.getOffset(1) > MAX_COL)
        choca = true;
    
    //Es comprova que la figura no es fusioni amb altres blocs del tauler
    int x = figura.getOffset(3), y = figura.getOffset(0);
    while (!choca && y < figura.getLongCostat() - figura.getOffset(2))
    {
        while(!choca && x < figura.getLongCostat() - figura.getOffset(1))
        {
            if (figura.getBloc(y, x) != NO_COLOR && m_tauler[i + y][j + x] != COLOR_NEGRE)
                choca = true;
            x++;
        }
        x = 0;
        y++;
    }
    
    return choca;
}