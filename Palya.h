#ifndef PALYA_H_INCLUDED
#define PALYA_H_INCLUDED

#include "EnumesStruktura.h"
#include "memtrace.h"

/// Palya oszt�ly
class Palya
{
    int meret;         /// meret - int t�pus�, m�rete a p�ly�nak
    char** palya;      /// palya - char** t�pus� dinamikusan foglalt t�mb
public:
    /// Egy param�teres konstruktor
    /// @param x - int t�pus�
    Palya(int x);

    /// Palya destruktor
    ~Palya();

    /// Lerajzolja a p�ly�t
    void palyaRajzol();

    /// @return int t�pus
    int getMeret() const{return meret;}

    /// Meret setter
    /// @param x - int t�pus
    void setMeret(const int x) {meret = x;}

    /// Megn�zi hogy az adott ponton van-e m�r IKSZ vagy KOR szimb�lum a p�ly�n, valid-e a l�p�s
    /// @param Pont - egy Pont
    /// @return true, ha van �res, ha nincs akkor throwol
    bool validLepes(const Pont pont) const;

    /// operator()
    /// @param x,y - int t�pus�ak
    /// @return a p�lya x,y koordint�j�n l�v� karakterrel t�r vissza
    char& operator () (const int x,const int y) const {return palya[x][y];}
};



#endif // PALYA_H_INCLUDED
