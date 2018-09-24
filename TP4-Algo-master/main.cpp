#include <iostream>
#include "node.hpp"
#include "crdtree.hpp"
using namespace std;


void Testarbre(){
    CRDTree<int> Bre (0);
    for(unsigned i (0); i<8 ; ++i){
        Bre.Add(i, Bre.GetRacine());
    }
    Bre.Show(Bre.GetRacine());
}


int main(int argc, char *argv[])
{

    return 0;
}
