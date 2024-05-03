#include "Joc.h"

void Joc::inicialitza(const string& nomFitxer)
{
    ifstream input;
    input.open(nomFitxer);
    input >> m_figura >> m_tauler;
    input.close();
}

bool Joc::giraFigura(DireccioGir direccio)
{
    bool gir = true;
    
    if (direccio == GIR_HORARI)
    {
        m_figura.girHorari();
        if(m_tauler.colisio(m_figura))
        {
            m_figura.girAntihorari();
            gir = false;
        }
    }
    else
    {
        m_figura.girAntihorari();
        if (m_tauler.colisio(m_figura))
        {
            m_figura.girHorari();
            gir = false;
        }
    }
    
    return gir;
}

bool Joc::mouFigura(int dirX)
{
    bool mov = true;
    
    if (dirX > 0)
    {
        m_figura.movDreta();
        if (m_tauler.colisio(m_figura))
        {
            m_figura.movEsquerra();
            mov = false;
        }
    }
    else
    {
        m_figura.movEsquerra();
        if (m_tauler.colisio(m_figura))
        {
            m_figura.movDreta();
            mov = false;
        }
    }
    
    return mov;
}

int Joc::baixaFigura()
{
    int nFilesCompletes = 0;

    m_figura.baixa();

    if (m_tauler.colisio(m_figura))
    {
        m_figura.puja();

        //La figura ja está al seu lloc final i s'afegeix al tauler de forma definitiva
        int i = m_figura.getFila() - 1, j = m_figura.getColumna() - 1;
        for (int y = m_figura.getOffset(0); y < m_figura.getLongCostat() - m_figura.getOffset(2); y++)
            for (int x = m_figura.getOffset(3); x < m_figura.getLongCostat() - m_figura.getOffset(1); x++)
                if (m_figura.getBloc(y, x) != NO_COLOR)
                    m_tauler.setBloc(i + y, j + x, m_figura.getBloc(y, x));

        //S'esborra la figura ara que és part del tauler per evitar que surti duplicada al utilitzar la funció escriuTauler
        m_figura.inicialitza(NO_FIGURA, m_figura.getFila(), m_figura.getColumna(), 0);

        //Es comprova si hi ha alguna fila completa i, en cas d'haver-hi, s'elimina i s'afegeix un punt
        bool filaCompleta = true;
        for (i = 0; i < MAX_FILA; i++)
        {
            filaCompleta = true;
            j = 0;
            while (j < MAX_COL && filaCompleta)
            {
                if (m_tauler.getBloc(i, j) == COLOR_NEGRE)
                    filaCompleta = false;
                j++;
            }
            if (filaCompleta)
            {
                for (int y = i; y > 0; y--)
                    for (int x = 0; x < MAX_COL; x++)
                        m_tauler.setBloc(y, x, m_tauler.getBloc(y - 1, x));
                    for (int x = 0; x < MAX_COL; x++)
                        m_tauler.setBloc(0, x, COLOR_NEGRE);
                nFilesCompletes++;
            }
        }
    }
    return nFilesCompletes;
}

void Joc::escriuTauler(const string& nomFitxer)
{
    //Es crea una cópia del tauler per no imprimir la figura al real
    ColorFigura tauler[MAX_FILA][MAX_COL];
    m_tauler.getTauler(tauler);

    //S'afegeix la figura al tauler fals per tal que aparegui al fitxer
    int i = m_figura.getFila() - 1, j = m_figura.getColumna() - 1;
    for (int y = m_figura.getOffset(0); y < m_figura.getLongCostat() - m_figura.getOffset(2); y++)
        for (int x = m_figura.getOffset(3); x < m_figura.getLongCostat() - m_figura.getOffset(1); x++)
            if (m_figura.getBloc(y, x) != NO_COLOR)
                tauler[i + y][j + x] = m_figura.getBloc(y, x);

    ofstream output;
    output.open(nomFitxer);
    if (output.is_open())
    {
        for (int i = 0; i < MAX_FILA; i++)
        {
            for (int j = 0; j < MAX_COL; j++)
                output << tauler[i][j] << " ";
            output << endl;
        }
        output.close();
    }
}