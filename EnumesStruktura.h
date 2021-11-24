#ifndef ENUMESSTRUKTURA_H_INCLUDED
#define ENUMESSTRUKTURA_H_INCLUDED

/// A Mezo enum, 4 db szimbólumot tartalmaz
enum Mezo{KOR = 'O', IKSZ = 'X', URES = '-', SEMMI = ' '};

///Pont struktúra
struct Pont
{
public:
    int x;            ///@param x - int típus
    int y;            ///@param y - int típus

    ///Pont konstruktor paraméter nélkül
    Pont() : x(0), y(0) {}

    ///Pont 2 paraméterrel
    Pont(int x, int y) : x(x), y(y) {}
};

#endif // ENUMESSTRUKTURA_H_INCLUDED
