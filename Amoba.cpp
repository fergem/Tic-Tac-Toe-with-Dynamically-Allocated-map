#include "Amoba.h"
#include "memtrace.h"



void Amoba::aJatek()
{

    int x,y;
    do
    {
        if((jatekVege()))
        {
            throw std::logic_error("\nOlyan fajlt adott meg, ahol mar vege van a jateknak, kerem valtoztasson rajta\n");
        }
        p->palyaRajzol();
        std::cout << "Mentessel valo kilepeshez a -1 -1 koordinatat adja meg, mentes nelkulihez a -2 -2 koordinatat\n";
        bool valide = true;
        do
        {
            valide = true;
            try
            {

                std::cout << "Kerem az x koordinatat:\n";
                while(!(std::cin >> x))
                {
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                }
                std::cout << "Kerem az y koordinatat:\n";
                while(!(std::cin >> y))
                {
                    std::cin.clear();
                    std::cin.ignore(256, '\n');
                }

                if(std::cin.eof())
                    std::cin.clear();
                if(x < 0 && y < 0 && x > -3 && y > -3)
                    break;

                jatekosjelenleg.setLepes(y,x);
                p->validLepes(jatekosjelenleg.getLepes());
            }
            catch(std::logic_error& e)
            {
                valide = false;
                std::cout << e.what();
            }


        }while(!(valide));
        if(x < 0 && y < 0 && x > -3 && y > -3)
            break;
        (*p)(jatekosjelenleg.getLepesx(),jatekosjelenleg.getLepesy()) = jatekosjelenleg.getSzimb();
        jatekosValt();
    }while(!(jatekVege()));
    p->palyaRajzol();
    if(x < 0 && y < 0 && x > -3 && y > -3)
    {
        if(x == -1 && y == -1)
        {
            nyert = SEMMI;
            p->palyaRajzol();
            std::cout << "\nA jatek mentve a fent lathato allassal:\n";
            saveJatek("Amobe.txt");
        }
        else
            nyert = SEMMI;
    }
    kiNyert();
}

void Amoba::jatekosValt()
{
    jatekosjelenleg = jatekosjelenleg == j1 ? j2 : j1;
}

void Amoba::kiNyert() const
{
    switch(nyert)
    {
        case URES:
            std::cout << "Dontetlen!\n";
            break;
        case IKSZ:
            std::cout << "X nyert!\n";
            break;
        case KOR:
            std::cout << "O nyert!\n";
            break;
        case SEMMI:
            std::cout << "Nincs vege a jateknak\n";
            break;
    }
}

bool Amoba::jatekVege()
{
    for(size_t i = 0; i < (unsigned int)p->getMeret(); i++)  //A sorokat
    {
        for(size_t j = 0; j < (unsigned int)p->getMeret() - 4; j++)
        {
            if ((*p)(i,j) == URES)
                continue;
            if((*p)(i,j) == (*p)(i,j + 1) && (*p)(i,j) == (*p)(i,j + 2) && (*p)(i,j) == (*p)(i,j + 3) && (*p)(i,j) == (*p)(i,j + 4))
            {
                jatekosValt();
                nyert = jatekosjelenleg.getSzimb();
                return true;
            }
        }
    }

    for(size_t i = 0; i < (unsigned int)p->getMeret() - 4; i++)  //Az oszlopokat
    {

        for(size_t j = 0; j < (unsigned int)p->getMeret() ; j++)
        {
            if ((*p)(i,j) == URES)
                continue;
            if((*p)(i,j) == (*p)(i + 1,j) && (*p)(i,j) == (*p)(i + 2,j) && (*p)(i,j) == (*p)(i + 3,j) && (*p)(i,j) == (*p)(i + 4,j))
            {
                jatekosValt();
                nyert = jatekosjelenleg.getSzimb();
                return true;
            }
        }
    }

    for(size_t i = 0; i < (unsigned int)p->getMeret() - 4; i++)  //Az átlót
    {

        for(size_t j = 0; j < (unsigned int)p->getMeret() - 4; j++)
        {
            if ((*p)(i,j) == URES)
                continue;
            if((*p)(i,j) == (*p)(i + 1,j + 1) && (*p)(i,j) == (*p)(i + 2,j + 2) && (*p)(i,j) == (*p)(i + 3,j + 3) && (*p)(i,j) == (*p)(i + 4,j + 4))
            {
                jatekosValt();
                nyert = jatekosjelenleg.getSzimb();
                return true;
            }
        }
    }

    for(size_t i = 0; i < (unsigned int)p->getMeret() - 4; i++)  //A másik átlót
    {

        for(size_t j = 4; j < (unsigned int)p->getMeret(); j++)
        {
            if ((*p)(i,j) == URES)
                continue;
            if((*p)(i,j) == (*p)(i + 1,j - 1) && (*p)(i,j) == (*p)(i + 2,j - 2) && (*p)(i,j) == (*p)(i + 3,j - 3) && (*p)(i,j) == (*p)(i + 4,j - 4))
            {
                jatekosValt();
                nyert = jatekosjelenleg.getSzimb();
                return true;
            }
        }
    }
    // ha döntetlen
    int ikszekszama = 0;
    int korokszama = 0;
    for(size_t i = 0; i < (unsigned int)p->getMeret(); i++)
    {
        for(size_t j = 0; j < (unsigned int)p->getMeret(); j++)
        {
             if ((*p)(i,j) == IKSZ)
                ikszekszama++;
             else if((*p)(i,j) == KOR)
                korokszama++;
        }
    }
    if((korokszama + ikszekszama) == (p->getMeret() * p->getMeret()))
    {
        nyert = URES;
        return true;
    }
    return false;
}



void Amoba::saveJatek(std::string filename)
{
    std::fstream out;
    out.open(filename, std::fstream::out);
    out << p->getMeret() << std::endl;
    for (size_t i = 0; i < (unsigned int)p->getMeret(); i++)
    {
        for (size_t j = 0; j < (unsigned int)p->getMeret(); j++)
        {
            out << (*p)(i,j);
        }
        out << std::endl;
    }
    out.close();
}

void Amoba::loadJatek(std::string filename)
{
    int segedmeret;
    int uresek = 0;
    int korok = 0;
    int ikszek = 0;
    std::ifstream is(filename);
    if(!is.is_open())
        throw std::logic_error("\nNem lehetett megnyitni a fajlt.\n");
    if(!(is >> segedmeret))
        throw std::logic_error("\nNincs meret megadva ezert nem hozhato letre jatek.\n");
    if(segedmeret < 5)
        throw std::logic_error("\nKisebb meret van megadva, mint 5, ezert nem hozhato letre jatek\n");
    Palya* segedpalya = new Palya(segedmeret);
    for (int i = 0; i < segedmeret; i++)
    {
        for (int j = 0; j < segedmeret; j++)
        {
            is >> (*segedpalya)(i,j);
            if((*segedpalya)(i,j) != KOR &&  (*segedpalya)(i,j) != IKSZ &&  (*segedpalya)(i,j) != URES)
            {
                delete segedpalya;
                throw std::logic_error("\nNem megfelelo adattal van feltoltve a fajl, kerem ellenorizze.");
            }
            if((*segedpalya)(i,j) == URES)
                uresek++;

            if(uresek == (segedmeret*segedmeret))
            {
                delete segedpalya;
                throw std::logic_error("\nNincsenek adatok amivel belehetne tolteni a jatekot.\n");
            }

            if((*segedpalya)(i,j) == KOR)
                korok++;

            else if((*segedpalya)(i,j) == IKSZ)
                ikszek++;
        }

    }
    is.close();

    if(korok == ikszek)
        jatekosjelenleg.setSzimb(KOR);
    else if(korok > ikszek + 1)
    {
        delete segedpalya;
        throw std::logic_error("\nTobb a kor, mint az iksz, ezaltal a jatek unfair, toltse fel ugy hogy egyel tobb legyen a korbol vagy egyenloek legyenek.\n");
    }
    else if(ikszek > korok)
    {
        delete segedpalya;
        throw std::logic_error("\nTobb az iksz mint a kor, ezaltal a jatek unfair, toltse fel ugy hogy egyel tobb legyen a kor, vagy egyenloek legyenek.\n");
    }
    else
        jatekosjelenleg.setSzimb(IKSZ);

    delete p;

    p->setMeret(segedmeret);
    p = segedpalya;
}
