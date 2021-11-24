#include <iostream>

using namespace std;

#include "Palya.h"
#include "Amoba.h"
#include "Jatekos.h"
#include "memtrace.h"
#include "gtest_lite.h"

int main()
{
    int x = 3;
    int y = 0;
    bool beker = true;
    do
    {
    switch(x)
    {
        case 1:
            {
                TEST(Jatekos, Inicializalas)
                {
                    Jatekos j1(KOR);
                    EXPECT_EQ(KOR,j1.getSzimb());
                } END

                TEST(Jatekos, Lepes)
                {
                    Jatekos j2(IKSZ);
                    j2.setLepes(1,2);
                    EXPECT_EQ(1,j2.getLepesx() + 1);
                    EXPECT_EQ(2,j2.getLepesy() + 1);
                } END

                TEST(Palya, Inicializalas)
                {
                    Palya palya(10);
                    EXPECT_EQ(10,palya.getMeret());
                    palya.palyaRajzol();
                } END

                TEST(Palya, Validlepes)
                {
                    Palya palya(7);
                    palya(2,6) = KOR;
                    palya(5,1) = IKSZ;
                    Pont p1(2,6);
                    Pont p2(5,1);

                    EXPECT_ANY_THROW(palya.validLepes(p1));
                    EXPECT_ANY_THROW(palya.validLepes(p2));
                } END

                TEST(Amoba, Fajlbol olvasas)
                {
                    Jatekos j1(IKSZ);
                    Jatekos j2(KOR);
                    Amoba a(j1,j2);

                    EXPECT_ANY_THROW(a.loadJatek("_Nemletezo.txt"));
                    EXPECT_ANY_THROW(a.loadJatek("_Kicsimeret.txt"));
                    EXPECT_ANY_THROW(a.loadJatek("_Nincsmeret.txt"));
                    EXPECT_ANY_THROW(a.loadJatek("_Rosszadat.txt"));
                    EXPECT_ANY_THROW(a.loadJatek("_Nincsadat.txt"));
                    EXPECT_ANY_THROW(a.loadJatek("_Tobbiksz.txt"));
                    EXPECT_ANY_THROW(a.loadJatek("_Tobbkor.txt"));
                    a.loadJatek("_Ikszjon.txt");
                    EXPECT_EQ(IKSZ,a.getJatekosjelenleg().getSzimb());
                    a.loadJatek("_Maregyiknyert.txt");
                    EXPECT_ANY_THROW(a.aJatek());
                } END

                TEST(Amoba, Jatekos valtas)
                {
                    Jatekos j1(KOR);
                    Jatekos j2(IKSZ);
                    Amoba a(j1,j2,5);
                    EXPECT_EQ(KOR,a.getJatekosjelenleg().getSzimb());
                    a.jatekosValt();
                    EXPECT_EQ(IKSZ,a.getJatekosjelenleg().getSzimb());
                } END

                TEST(Amoba, Jatekvegevizszint)
                {
                    Jatekos j1(KOR);
                    Jatekos j2(IKSZ);
                    int meret = 10;
                    Palya* palya = new Palya(meret);
                    for(size_t i = 0; i < (unsigned int)palya->getMeret() - 5; i++)
                    {
                        (*palya)(0,i) = IKSZ;
                    }
                    Amoba a(j1,j2,meret,palya);
                    EXPECT_TRUE(a.jatekVege());
                } END

                TEST(Amoba, Jatekvegeoszlop)
                {
                    Jatekos j1(KOR);
                    Jatekos j2(IKSZ);
                    int meret = 10;
                    Palya* palya = new Palya(meret);
                    for(size_t i = 0; i < (unsigned int)palya->getMeret() - 5; i++)
                    {
                        (*palya)(i,0) = IKSZ;
                    }
                    Amoba a(j1,j2,meret,palya);
                    EXPECT_TRUE(a.jatekVege());
                } END

                TEST(Amoba, Jatekvegeatlo)
                {
                    Jatekos j1(KOR);
                    Jatekos j2(IKSZ);
                    int meret = 10;
                    Palya* palya = new Palya(meret);
                    for(size_t i = 0; i < (unsigned int)palya->getMeret() - 5; i++)
                    {
                        (*palya)(i,i) = IKSZ;
                    }
                    Amoba a(j1,j2,meret,palya);
                    EXPECT_TRUE(a.jatekVege());
                } END

                TEST(Amoba, Jatekvegenegativatlo)
                {
                    Jatekos j1(KOR);
                    Jatekos j2(IKSZ);
                    int meret = 10;
                    Palya* palya = new Palya(meret);
                    for(size_t i = 0; i < (unsigned int)palya->getMeret() - 5; i++)
                    {
                         for(size_t j = 0; j < (unsigned int)palya->getMeret() - 5; j++)
                                if((i + j) == ((unsigned int)palya->getMeret() - 6))
                                    (*palya)(i,j) = IKSZ;
                    }

                    Amoba a(j1,j2,meret,palya);
                    EXPECT_TRUE(a.jatekVege());
                } END

            }
            x = 3;
            break;
        case 2:
            {
                std::cout << "\nHa szeretne betolteni mentett jatekot nyomja meg az 1-es billentyut.\n";
                std::cout << "Ha nem szeretne, akkor a 2-es billentyut.\n";
                do
                {
                    beker = true;
                    try
                    {
                        while(!(std::cin >> y))
                        {
                            std::cin.clear();
                            std::cin.ignore(256, '\n');
                        }
                        if(std::cin.eof())
                            std::cin.clear();
                        if(y < 1 || y > 2)
                        {
                            throw std::logic_error("Nem megfelelo szám\n");
                        }
                    }
                    catch(std::logic_error& e)
                    {
                        beker = false;
                        std::cout << e.what();
                    }
                }while(!(beker));
            }
            switch(y)
            {
                case 1:
                    {
                        Jatekos j1(KOR);
                        Jatekos j2(IKSZ);
                        Amoba a(j1,j2);
                        a.loadJatek("Amobe.txt");
                        a.aJatek();
                    }
                    break;
                case 2:
                    {
                        int sor;
                        bool jo = true;
                        do
                        {
                            jo = true;
                            try
                            {
                                std::cout << "Kerek egy meretet,ami 4-nel nagyobb egesz szam(pl:5): " << std::endl;
                                while(!(std::cin >> sor))
                                {
                                    std::cin.clear();
                                    std::cin.ignore(256, '\n');
                                }
                                if(std::cin.eof())
                                    std::cin.clear();
                                if(sor < 5)
                                {
                                    throw std::logic_error("Kicsi meret\n");
                                }
                            }
                            catch(std::logic_error& e)
                            {
                                jo = false;
                                std::cout << e.what();
                            }
                        }while(!jo);
                        Jatekos j1(KOR);
                        Jatekos j2(IKSZ);
                        Amoba a(j1,j2,sor);
                        a.aJatek();
                    }
                    break;
            }
            x = 3;
            break;

        case 3:
            std::cout << "\nTeszteleshez nyomja meg az 1-es billentyut            KILEPESHEZ -1-et irjon be\n";
            std::cout << "Jatekhoz nyomja meg a 2-es billentyut\n";
            do
            {
                beker = true;
                try
                {
                    while(!(std::cin >> x))
                    {
                        std::cin.clear();
                        std::cin.ignore(256, '\n');
                    }
                    if(std::cin.eof())
                        std::cin.clear();
                    if(x == -1)
                        break;
                    if(x < 1 || x > 2)
                    {
                        throw std::logic_error("Nem megfelelo szam\n");
                    }
                }
                catch(std::logic_error& e)
                {
                    beker = false;
                    std::cout << e.what();
                }
            }while(!(beker));
            break;
    }
    }while(x!=-1);
    return 0;
}
