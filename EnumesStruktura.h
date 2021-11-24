#ifndef ENUMESSTRUKTURA_H_INCLUDED
#define ENUMESSTRUKTURA_H_INCLUDED

/// A Mezo enum, 4 db szimb�lumot tartalmaz
enum Mezo{KOR = 'O', IKSZ = 'X', URES = '-', SEMMI = ' '};

///Pont strukt�ra
struct Pont
{
public:
    int x;            ///@param x - int t�pus
    int y;            ///@param y - int t�pus

    ///Pont konstruktor param�ter n�lk�l
    Pont() : x(0), y(0) {}

    ///Pont 2 param�terrel
    Pont(int x, int y) : x(x), y(y) {}
};

#endif // ENUMESSTRUKTURA_H_INCLUDED
