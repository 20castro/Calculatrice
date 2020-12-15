#include "eval.h"

bool isChar (char c){
    return 48 <= c and c <= 57;
}

bool valid (int argc, char** argv){
    int tab [] = {0, 0};
    // nombre d'opérandes et des opérateurs hors '!'
    for (int j = 1; j < argc; j++){
        // on initalise j à 1 car le premier argument est l'exécutable
        const char* c = argv [j];
        char v = c [0];
        if (isChar (v))
            (tab [0])++;
        else{
            switch (v)
            {
            case '!':
                break;
            default:
                (tab [1])++;
                break;
            }
        }
    }
    bool a = (tab [0] == 1 and tab [1] == 0);
    bool b = (tab [0] > 1 and tab [1] == tab [0] - 1);
    return (a or b);
}

Pair eval (int argc, char** argv){
    Stack stack (argc);
    Pair p (valid (argc, argv));
    for (int j = 1; j < argc; j++){
        // on initalise j à 1 car le premier argument est l'exécutable
        const char* c = argv [j];
        char v = c [0];
        if (not p.getBool ()){ // si on siat qu'il y a un problème, on s'arrête tout de suite
            break;
        }
        if (isChar (v)) // cas dans lequel on ajoute une variable
            stack.push (atoi (c));
        else if (v == '!'){ // cas d'une opéartion unaire
            stack.push (- stack.pop ());
        }
        else if (stack.getTop () > 1){ // cas d'une opéartion binaire
            switch (v)
            {
            case 'x':{
                stack.push (stack.pop () * stack.pop ());
                break;
            }
            case '/':{
                int denominateur = stack.pop ();
                if (denominateur == 0){
                    std::cout << "Division par zéro" << std::endl;
                    p.setFalse ();
                }
                else{
                    stack.push (stack.pop () / denominateur);
                }
                break;
            }
            case '+':{
                stack.push (stack.pop () + stack.pop());
                break;
            }
            case '-':{
                int soustraire = stack.pop (); // afin de faire la soustraction dans le bon sens
                stack.push (stack.pop () - soustraire);
                break;
            }
            default:{
                p.setFalse ();
                break;
            }
            }
        }
        else{ // cas invalide
            p.setFalse ();
        }
    }
    if (p.getBool () and stack.getTop () == 1){
        p.setInt (stack.getFirstInt ());
    }
    else{
        p.setFalse ();
    }
    return p;
}