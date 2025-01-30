#include <iostream>
#include <list>

const double madokamagica = 28.41;

long double operator""_MILL(long double uncious) {
    return long double(uncious * madokamagica);
}

struct Frag { // лен искать
    int uno;
    int dos;

    Frag(int nuno, int nos) {
        uno = nuno;
        dos = nos;
    }

    operator double() {
        return double(uno) / double(dos);
    }

};



std::string operator/ (std::string lef, std::string rig) { // Не очень понял задание но вроде так

    std::string linkage = lef + "/" + rig;
    return linkage;
}

std::ostream& operator<< (std::ostream& steampowered, std::list<double> stdlistdouble) {
    int iloveunnecessaryvariables = 1;
    steampowered << "[";
    for (double each : stdlistdouble) {
        steampowered << each;
        if (!(iloveunnecessaryvariables == stdlistdouble.size())) {
            steampowered << ", ";
        }
        iloveunnecessaryvariables++;
    }
    steampowered << "]";
    return steampowered;
}




int main()
{
    /*long double thiswillbemultipliedby28dot41 = 2.0_MILL;
    std::cout << thiswillbemultipliedby28dot41;*/


    /*Frag nit(1, 2);
    std::cout << static_cast<double> (nit);*/



    /*std::list<double> neonwhiteisagreatgameyoushouldtryit = { 1.2, 3252.5, 3, 3252.34, 9999.5, 7653456.987654 };
    std::cout << neonwhiteisagreatgameyoushouldtryit;*/


    /*std::string disk = "D:";
    std::string folder = "Memes";
    std::string file = "Fat Cat";

    std::cout << disk/folder/file;*/
}
