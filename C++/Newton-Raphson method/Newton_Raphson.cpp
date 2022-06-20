#include <bits/stdc++.h>

using namespace std;

//Esta función es la F(x), se modifica manualmente
float F(float x){
    // return (2*pow(x,3)) - ((11.7)*pow(x,2)) + ((17.7)*x) - 5;
    return pow(x,2)-6;
}

//Esta función es la primera derivada de la F(x), se modifica manualmente
float Dx(float x){
    // return (6*pow(x,2)) - ((23.4)*x) + 17.7;
    return 2*x;
}

//Esta función calcula el error
float errado(float x, float y){
    return abs((x-y)/x) * 100;
}

int main()
{
    int iter = 0;
    float aprox = 0, Pn = 0, Px = 0, Pdx = 0, e = 0, e1;

    //Ingreso de datos
        cout << "Ingrese la aproximacion inicial: ";
        cin >> aprox;
        cout << "Ingrese en numero de iteraciones: ";
        cin >> iter;
        cout << "Ingrese el error: ";
        cin >> e;

    //Proceso
        for(int i=1;i<=iter;i++){
            Px = F(aprox);
            Pdx = Dx(aprox);
            Pn = aprox - (Px/Pdx);
            e1 = errado(Pn, aprox);
            if( e1 < e ){
                cout << "Cumplio con limite de error en n = " << i << " y es: " << Pn << endl;
                return 0;
            }
            aprox = Pn;
            cout << "n = " << i << ": " << Pn << "   Error: " << fixed << e1 << endl;
        }


    return 0;
}