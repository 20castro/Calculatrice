#include "eval.h"

int main (int argc, char** argv){
    Pair pair = eval (argc, argv);
    if (pair.getBool ()){
        std::cout << pair.getInt () << std::endl;
    }
    else{
        std::cout << "Entrée non valide" << std::endl;
    }
    return 0;
}