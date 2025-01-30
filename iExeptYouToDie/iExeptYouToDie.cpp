
#include <iostream>
#include <string>


struct StupidIdiotAlert {
    std::string details;
    int code;

    StupidIdiotAlert(std::string seeega, int ode = 0) {
        details = seeega;
        code = ode;
    }
};

void centurion_primera() {
    
    std::cout << "Enter a number, any number, exept 653, i hate that one: ";
    int numer;
    std::cin >> numer;
    std::cout << "\n";

    if (numer == 653) {
        throw StupidIdiotAlert("This absolute moron has failed the simplest task, i say we execute 'em", numer);
    }
    else {
        std::cout << "Good job, you win!" <<numer << std::endl;
    }
}

int main()
{
    //Пример

    try {
        centurion_primera();
    }
    catch (StupidIdiotAlert lmao) {

        std::cout << "Honest developer reaction: \n" << lmao.details << std::endl;
        std::cout << "funni numbr :   " << lmao.code << std::endl << std::endl << "<<stdendl" << std::endl << std::endl;

    }
    
}

