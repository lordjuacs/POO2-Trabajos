#include <iostream>
using namespace std;
#include "CInteger.h"
#include "CNumber.h"
#include "EFE.h"
int main()
{
    CInteger* a = new CInteger(9);
    CInteger* n = new CInteger(3);
    CInteger* c = *a - n;
    CInteger* d = *a / n;

    CInteger* e = new CInteger(10);
    *a^=2;
    cout << e->GetValue() << endl;
    e = *a^n;
    cout << e->GetValue();



    delete a;
    delete n;
    delete c;




    EFE<float>hola;


}
