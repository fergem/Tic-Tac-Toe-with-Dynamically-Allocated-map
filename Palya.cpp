#include <iostream>
#include "Palya.h"
#include "memtrace.h"


Palya::Palya(int x)
{
    this->meret = x;

    palya = new char*[x];
    for (size_t i = 0; i < (unsigned int)meret; i++)
    {
       palya[i] = new char[x];
    }

    for(size_t i = 0; i < (unsigned int)meret; i++)
        for(size_t j = 0; j < (unsigned int)meret; j++)
        {
            palya[i][j] = URES;
        }
}


void Palya::palyaRajzol()
{
    int sorr = 1;
    int oszlopp = 1;
    std::cout << "  ";
    for(size_t i = 0; i < (unsigned int)meret; i++)
    {
        if(sorr <= meret)
        {
            if(sorr < 10)
                std::cout << "   " << sorr << "  ";
            else
                std::cout << " " << sorr << "  ";
        }
        sorr++;
    }
    std::cout << "\n  -";
    for(size_t i = 0; i < (unsigned int)meret; i++)
    {
        std::cout << "------";
    }
    std::cout << "\n";
	for (size_t i = 0; i < (unsigned int)meret; i++)
    {
        if(oszlopp <= meret)
        {
            if(oszlopp < 10)
                std::cout << " " << oszlopp << "|  ";
            else
                std::cout << oszlopp << "|  ";
        }
		for (size_t j = 0; j < (unsigned int)meret; j++)
		{
            if (j < (unsigned int)meret - 1)
            {
                std::cout << palya[i][j] << "  |  ";
			}
			else
            {
				std::cout << palya[i][j] << "  |\n  ";
				for(size_t i = 0; i < (unsigned int)meret; i++)
                    {
                        std::cout << "------";
                    }
                std::cout << "-\n";
			}
		}
		oszlopp++;
    }
	std::cout << "\n";
}


bool Palya::validLepes(Pont pont) const
{
    if(pont.x >= 0 && pont.y >= 0 && pont.x < meret && pont.y < meret && palya[pont.x][pont.y] == URES)
    {
        return true;
    }
    else
    {
        throw std::logic_error("Rossz lepes\n");
    }
}


Palya::~Palya()
{
    for (int i = 0; i < meret; i++)
    {
        delete[] palya[i];
    }
    delete[] palya;
}
