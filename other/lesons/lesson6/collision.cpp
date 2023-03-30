#include <iostream>

struct Atom;
void collision(Atom, Atom);

struct Atom {
    int charge;
    double mass;
};

int main(){
    Atom* periodic_table = new Atom[10];

    return 0;
}