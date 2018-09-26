#include <iostream>
#include "node.hpp"
#include "crdtree.hpp"
using namespace std;


void Testarbre(){
    cout << "début" << endl;
    CRDTree<int> Bre (0);

    Bre.Show();

    //Bre.Add(1);
    //Bre.Add(2);
    //Bre.Add(3);

    Bre.Show();
}


int main(void)
{
    Testarbre();
    return 0;
}
