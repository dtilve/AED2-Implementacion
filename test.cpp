//#include "CampusSeguro.h"
//#include "Campus.h"
//#include "DiccNombres.h"
#include "DiccAgentes.h"
#include "mini_test.h"

#include <string>
#include <iostream>

using namespace std;
using namespace aed2;

void DiccAgentesModificar(Nat i){
    cout << "Test numero " << i << endl;
    Nat maximo = 4*i+1;
    Nat minimo = i/4;
    DiccAgentes d(minimo,maximo);
    Nat j = 0;
    while (j <= i){
        d.Definir(minimo+j,Posicion(j,j+1));
        j++;
    }
    ASSERT_EQ(d.Definido(minimo+j+1),false);
    ASSERT_EQ(d.Definido(minimo+j-1),true);

    j = 0;
    while(j < i){
        Nat k = 0;
        DiccAgentes::Iterador it = d.CrearIt();
        while(k <= i){
            cout << it.SiguienteClave() << endl;
            it.Sancionar();
            it.Avanzar();
            k++;
        }
        j++;
    }
    cout << endl;

}

void MegaTest(){

    Conj<Nat> c;
    c.AgregarRapido(1);

    Conj<Nat>::Iterador itc = c.CrearIt();
    cout << itc.Siguiente() << endl;

    Nat i = 0;
    while(i <= 0){
        DiccAgentesModificar(36);
        i++;
    }
}

// ---------------------------------------------------------------------

int main(int argc, char **argv)
{
    RUN_TEST(MegaTest);
	return 0;
}
