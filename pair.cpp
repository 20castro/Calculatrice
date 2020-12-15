#include "pair.h"

Pair::Pair (bool b) : res (0), valid (b){}

void Pair::setFalse (){
    valid = false;
}

void Pair::setInt (int val){
    res = val;
}

void Pair::increase (int ajout){
    res += ajout;
}

bool Pair::getBool (){
    return valid;
}

int Pair::getInt (){
    return res;
}

