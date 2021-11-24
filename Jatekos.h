#ifndef JATEKOS_H_INCLUDED
#define JATEKOS_H_INCLUDED

#include "EnumesStruktura.h"

/// Generikus tömb osztály statikus mérettel
/// @param lepese - Pont típus
/// @param szimb - Mezo típus

class Jatekos
{
    Pont lepese;
    Mezo szimb;
public:
    /// Egy paraméteres konstruktor
    /// @param sz - Mezo típusú
    Jatekos(Mezo sz) :szimb(sz) {};

    /// Egyenlõ operátor
    /// @param rhs - jobb oldali operandus (Jatekos)
    /// @return egy Jatekos típus
    Jatekos& operator=(const Jatekos& rhs) {lepese = rhs.lepese; szimb = rhs.szimb; return *this;}

    /// Egyenlõség vizsgálat
    /// @param rhs - jobb oldali operandus (Jatekos)
    /// @return true - ha a szimbólumok azonosak akkor true, egyébként false
    bool operator==(const Jatekos& rhs) const
    {
        if(szimb == rhs.szimb)
            return true;
        else
            return false;
    }

    /// a Jatekos szimbolumat allitja be
    /// @param m - Mezo típus
    void setSzimb(Mezo m) {szimb = m;}

    ///Beállítja a Jatekos lépését
    ///@param x - az x koordináta
    ///@param y - az y koordináta
    void setLepes(const int x,const int y){lepese.x = x - 1; lepese.y = y - 1;}

    ///@return - int típus
    int getLepesx() const {return lepese.x;}

    ///@return - int típus
    int getLepesy() const {return lepese.y;}

    ///@return - Pont típus
    Pont getLepes() const {return lepese;}

    ///@return - Mezo típus
    Mezo getSzimb() const {return szimb;}
};



#endif // JATEKOS_H_INCLUDED
