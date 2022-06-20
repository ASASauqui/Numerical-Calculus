#include <bits/stdc++.h>

using namespace std;

//Esta función es la F(x), se modifica manualmente
float F(float x){
    // return (667.38/x)*(1-exp(-0.146843*x))-40;   //Bisección 1
    // return (5*pow(x,3))-(5*pow(x,2))+(6*x)-2; //Bisección 2
    // return 2*pow(x,2)-1;
    // return pow(x,2)-10;
    return pow(x,4)-(2*pow(x,3))-(4*pow(x,2))+(4*x)+4;
}

//Esta función calcula el error
float errado(float x, float y){
    return abs((x-y)/x) * 100;
}

int main()
{
    //Iteraciones
        int iter = 0;
    //Variables que requieren de punto decimal
        float a = 0, b = 0, p = 0, p1 = 0, fp = 0, e = 0, e1 = 0;

    //Ingreso de datos
        cout << "Ingrese los extremos a y b: ";
        cin >> a >> b;
        cout << "Ingrese el numero de iteraciones: ";
        cin >> iter;
        cout << "Ingrese el error: ";
        cin >> e;


    //Verificar si puede haber una raíz
        if( F(a)*F(b) > 0 ){
            cout << "No existe raiz, ya que los puntos tienen el mismo signo" << endl;
            return 0;
        }
    //Proceso
        float fa = 0;
        for(int i=1;i<=iter;i++){
            p = (a+b)/2;
            fp = F(p);
            fa = F(a);

            e1 = errado(p,p1);
            if( fp == 0 || e1 <= e ){
                cout << "Cumplio con limite de error en n = " << i << " y es: " << p << endl;
                return 0;
            }

            if( fa*fp > 0 ){
                a = p;
            }
            else if( fa*fp < 0 ){
                b = p;
            }

            cout << "n = " << i << ": " << p << "   Error: " << fixed << e1 << endl;
            cout << endl << endl;

            p1 = p;
        }


    return 0;
}