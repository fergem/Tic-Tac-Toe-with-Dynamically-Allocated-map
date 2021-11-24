#ifndef AMOBA_H_INCLUDED
#define AMOBA_H_INCLUDED

#include <math.h>
#include "Jatekos.h"
#include "Palya.h"
#include "memtrace.h"

/// Amoba class
class Amoba
{
    Jatekos j1;                /// j1 - egyes Jatekos
    Jatekos j2;                /// j2 - kettes Jatekos
    Jatekos jatekosjelenleg;   /// jatekosjelenleg - a soron következő Jatekos
    Mezo nyert;                /// nyert - a nyertes játékosnak Mezo szimbóluma
    Palya* p;                  /// p - a dinamikusan foglalt Palya
public:
    /// Amoba konstruktor
    /// @param j1 - egyes Jatekos
    /// @param j2 - kettes Jatekos
    /// @param meret - int ,a Palya mérete, ha nincs megadva szám eredeti értéke 5
    /// @param palya - a dinamikusan foglalt Palya, ha nincs megadva előre létrehozott Palya nullptr
    Amoba(Jatekos& j1, Jatekos& j2, int meret = 5, Palya* palya = nullptr): j1(j1),j2(j2),jatekosjelenleg(j1), nyert(URES)
    {
        if(palya == nullptr)
        {
            this->p = new Palya(meret);
        }
        else if(palya != nullptr)
        {
            this->p = palya;
        }
    }
    /// Amoba destruktror
    ~Amoba(){delete p;};

    /// Ez a függvény bonyolítja le a játékot
    void aJatek();

    /// Vált a játékosok között
    void jatekosValt();

    /// Kiírja, hogy ki a nyertes, esetleg ha nincs akkor azt is
    void kiNyert() const;

    /// @return - jatekosjelenleg
    Jatekos getJatekosjelenleg() const {return jatekosjelenleg;}

    /// Eldönti, hogy vége van-e a játéknak
    /// @return - true, ha nyert valaki vagy döntetlen, false ha nem
    bool jatekVege();

    /// Elmenti a játékot
    /// @param filename - std::string
    void saveJatek(std::string filename); // ez fogja a játékot fájlba menteni

    /// Betölti a játékot , esetleg ha valami probléma van throwol
    /// @param filename - std::string
    void loadJatek(std::string filename); // ez fogja a játékot beolvasni
};

#endif // AMOBA_H_INCLUDED
