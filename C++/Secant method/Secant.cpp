#include <bits/stdc++.h>

using namespace std;

//Esta función es la F(x), se modifica manualmente
float F(float x){
    // return (3*pow(x,3))-(8*exp(3*x))+100;
    // return exp(-1*x)-x;
    return (2*pow(x,3)) - ((11.7)*pow(x,2)) + ((17.7)*x) - 5;
}

//Esta función calcula el error
float errado(float x, float y){
    // return abs((x-y)/x) * 100;
    return abs(x-y);
}

int main()
{
    int iter = 0;
    float P0 = 0, P1 = 0, Pn = 0, q0 = 0, q1 = 0, e = 0, e1;

    //Ingreso de datos
        cout << "Ingrese la aproximacion inicial P0: ";
        cin >> P0;
        cout << "Ingrese la aproximacion inicial P1: ";
        cin >> P1;
        cout << "Ingrese en numero de iteraciones: ";
        cin >> iter;
        cout << "Ingrese el error: ";
        cin >> e;

    //Proceso
        for(int i=1;i<=iter;i++){
            q0 = F(P0);
            q1 = F(P1);
            Pn = P1 - ( (q1*(P0-P1)) / (q0-q1) );
            e1 = errado(Pn, P1);
            if( e1 < e ){
                cout << "Cumplio con limite de error en n = " << i << " y es: " << Pn << endl;
                return 0;
            }
            P0 = P1;
            P1 = Pn;

            cout << "n = " << i << ": " << Pn << "   Error: " << fixed << e1 << endl;
        }


    return 0;
}