#include <bits/stdc++.h>

using namespace std;

//Funciones
    //Esta función es la F(x), se modifica manualmente
        float F(float x){
            // return sqrt(1+(1/x));
            return 1/(2*(sqrt(2*x)))+x;
            // return x + (1/2*(sqrt(2*x)));
        }
    //Esta función regresa el error
        float errado(float x, float y){
            return abs((x-y)/x) * 100;
        }


//Variables
    int N = 0;
    float P0 = 0, table[10000], err[1000];

int main()
{
    memset(table, 0, sizeof(table));
    memset(err, 0, sizeof(err));

    cout << "Ingrese la cantidad de P0 (valor inicial): ";
    cin >> P0;
    cout << "Ingrese el numero de iteraciones: ";
    cin >> N;

    //Iteraciones
        table[0] = P0;
        for(int i=1;i<N;i++){
            table[i] = F(table[i-1]);
            err[i] = errado(table[i],  table[i-1]);
        }

    //Impresión
        for(int i=0;i<N;i++){
            cout << i << ":   " << table[i] << "   error:  " << err[i] << endl;
        }


    return 0;
}