#ifndef JATEKOS_H_INCLUDED
#define JATEKOS_H_INCLUDED

#include "EnumesStruktura.h"

/// Generikus t�mb oszt�ly statikus m�rettel
/// @param lepese - Pont t�pus
/// @param szimb - Mezo t�pus

class Jatekos
{
    Pont lepese;
    Mezo szimb;
public:
    /// Egy param�teres konstruktor
    /// @param sz - Mezo t�pus�
    Jatekos(Mezo sz) :szimb(sz) {};

    /// Egyenl� oper�tor
    /// @param rhs - jobb oldali operandus (Jatekos)
    /// @return egy Jatekos t�pus
    Jatekos& operator=(const Jatekos& rhs) {lepese = rhs.lepese; szimb = rhs.szimb; return *this;}

    /// Egyenl�s�g vizsg�lat
    /// @param rhs - jobb oldali operandus (Jatekos)
    /// @return true - ha a szimb�lumok azonosak akkor true, egy�bk�nt false
    bool operator==(const Jatekos& rhs) const
    {
        if(szimb == rhs.szimb)
            return true;
        else
            return false;
    }

    /// a Jatekos szimbolumat allitja be
    /// @param m - Mezo t�pus
    void setSzimb(Mezo m) {szimb = m;}

    ///Be�ll�tja a Jatekos l�p�s�t
    ///@param x - az x koordin�ta
    ///@param y - az y koordin�ta
    void setLepes(const int x,const int y){lepese.x = x - 1; lepese.y = y - 1;}

    ///@return - int t�pus
    int getLepesx() const {return lepese.x;}

    ///@return - int t�pus
    int getLepesy() const {return lepese.y;}

    ///@return - Pont t�pus
    Pont getLepes() const {return lepese;}

    ///@return - Mezo t�pus
    Mezo getSzimb() const {return szimb;}
};



#endif // JATEKOS_H_INCLUDED
