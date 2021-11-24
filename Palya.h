#ifndef PALYA_H_INCLUDED
#define PALYA_H_INCLUDED

#include "EnumesStruktura.h"
#include "memtrace.h"

/// Palya osztály
class Palya
{
    int meret;         /// meret - int típusú, mérete a pályának
    char** palya;      /// palya - char** típusú dinamikusan foglalt tömb
public:
    /// Egy paraméteres konstruktor
    /// @param x - int típusú
    Palya(int x);

    /// Palya destruktor
    ~Palya();

    /// Lerajzolja a pályát
    void palyaRajzol();

    /// @return int típus
    int getMeret() const{return meret;}

    /// Meret setter
    /// @param x - int típus
    void setMeret(const int x) {meret = x;}

    /// Megnézi hogy az adott ponton van-e már IKSZ vagy KOR szimbólum a pályán, valid-e a lépés
    /// @param Pont - egy Pont
    /// @return true, ha van üres, ha nincs akkor throwol
    bool validLepes(const Pont pont) const;

    /// operator()
    /// @param x,y - int típusúak
    /// @return a pálya x,y koordintáján lévõ karakterrel tér vissza
    char& operator () (const int x,const int y) const {return palya[x][y];}
};



#endif // PALYA_H_INCLUDED
