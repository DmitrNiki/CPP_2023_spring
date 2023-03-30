#include <iostream>

void empty_func(){
    struct {
        int charge;
        double mass;
    } Li, Pb;
    Li.charge = 4;
    Li.mass = 7;
    std::cout << Pb.mass << ' ' << Pb.charge << std::endl;
    std::cout << &Pb.mass << ' ' << &Pb.charge << std::endl;
    std::cout << Li.mass << ' ' << Li.charge << std::endl;
    std::cout << &Li.mass << ' ' << &Li.charge << std::endl;
    std::cout << ((&Li.mass) - (&Pb.mass)) << std::endl;
}

struct Atom {
    int charge;
    double mass;
}Li, Pb;

int main(){
    Atom* periodic_table = new Atom[10];
    // periodic_table->mass = 100;/*(*periodic_table).mass = 100;*/ 
    delete periodic_table;
    /*Atom He;
    He.charge = 2;
    He.mass = 4;*/
    /*Li.mass = 7;
    Li.charge = 4;*/
    // empty_func();
    return 0;
}