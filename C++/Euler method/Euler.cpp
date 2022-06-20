#include <bits/stdc++.h>

using namespace std;

//Variables
    vector<float> y(1000, 0);
    float a = 0, b = 0, h = 0, t = 0; 
    int N = 0;

//Funciones
    float f(float, float);
    float errado(float x, float y);

int main()
{
    //Ingresar valores
        cout << "Ingresa los extremos a y b: ";
        cin >> a >> b;

        cout << "Ingresa la condicion inicial y(0) = ";
        cin >> y[0];

        cout << "Ingresa las iteraciones del algoritmo: ";
        cin >> N;

    //Calcular valores iniciales
        h = (b-a)/N;
        t = a;

    //Iteraciones
        cout << endl;
        for(int i=1;i<=N;i++){
            y[i] = y[i-1] + (h * f(t, y[i-1]));
            t = a + (i * h);

            cout << "It = " << i << endl;
            cout << "t = " << t << endl;
            cout << "Error = " << errado(y[i], y[i-1]) << endl;
            cout << "y(" << i << ") = " << y[i] << endl << endl;
        }


    return 0;
}

float f(float tn, float yn){
    // return yn - pow(tn, 2) + 1;
    // return ((-2)*pow(tn,3)) + (12*pow(tn,2)) + ((-20)*tn) + 8.5;
    // return (-5*yn) + (5*pow(tn,2)) + (2*t);
    return (tn*exp(3*tn)) - (2*yn);
}

float errado(float x, float y){
    // return abs((x-y)/x) * 100;
    return abs(x-y);
}