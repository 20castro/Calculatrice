// Classe de piles d'entiers

#ifndef STACK_DEF
#define STACK_DEF

#include <iostream>

class Stack{

    public:
        Stack (const int);

    public:
        bool isEmpty (); // renvoie true ssi la pile est vide
        void incr (); // incrémente la longueur de la pile
        void decr (); // la décrémente
        int pop (); // enlève un élément de le pile et le renvoie
        void push (int); // ajouter un élément à la pile

    public:
        const int getFirstInt (); // obtenir le premier élément de la pile
        const int getTop (); // obtenir la longueur de la pile
        void print (); // affichage

    protected:
        int* pile;
        int top; // nombre d'éléments dans la pile
        const int length;
};

#endif