#include "Runable.h"
//#include "Runable.h"
#include <iostream>
using namespace std;
 void Runable::run()
 {
    cout << "run" << endl;
 }


int Runable::hashCode()
{
    return 5;
}
// 

int main()
{
    Runable runable;
    // runable.run();
    int hashCOde = runable.hashCode();
    cout << "hashCode:" << hashCOde<<endl;
    return 0;
}