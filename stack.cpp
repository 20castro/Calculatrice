#include "stack.h"

Stack::Stack (const int len) : pile (new int [len]), top (0), length (len){}

bool Stack::isEmpty (){
    return top == 0;
}

void Stack::incr (){
    top++;
}

void Stack::decr (){
    top--;
}

int Stack::pop (){
    decr ();
    return pile [top];
}

void Stack::push (int e){
    pile [top] = e;
    incr ();
}

const int Stack::getFirstInt (){
    return pile [0];
}

const int Stack::getTop (){
    return top;
}

void Stack::print (){
    std::cout << '[';
    for (int k = 0; k < top; k++){
        std::cout << pile [k];
        if (k < top - 1){
            std::cout << ' ';
        }
    }
    std::cout << ']';
}