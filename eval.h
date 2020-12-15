#ifndef EVAL_DEF
#define EVAL_DEF

#include <cstdlib>

#include "pair.h"
#include "stack.h"

bool isChar (char);
// renvoie True ssi l'argument est un charactère

bool valid (int, char**);
// renvoie true ssi il y a le bon nombre de chiffres par rapport au nombre d'opérandes

Pair eval (int, char**);
// renvoie le résultat et true si tout fonctionne et un nombre et false s'il y a un problème
// si l'argument rentré n'est pas valide, le programme ne bloque pas mais l'indique

#endif