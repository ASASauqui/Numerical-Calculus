#include <bits/stdc++.h>

using namespace std;

//Variables
    vector<float> y(1000, 0);
    float a = 0, b = 0, h = 0, t = 0; 
    float k1 = 0, k2 = 0, k3 = 0, k4 = 0, aux = 0;
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
            aux = f(t, y[i-1]);
            k1 = h * aux;
            
            aux = f(t + (h/2), y[i-1] + (k1/2));
            k2 = h * aux;

            aux = f(t + (h/2), y[i-1] + (k2/2));
            k3 = h * aux;

            aux = f(t + h, y[i-1] + k3);
            k4 = h * aux;

            y[i] = y[i-1] + ((k1 + 2*k2 + 2*k3 + k4)/6);
            // y[i] = y[i-1] + (float(1)/float(6))*(k1 + 2*k2 + 2*k3 + k4);
            t = a + (i * h);

            // cout << "k1: " << k1 << endl;
            // cout << "k2: " << k2 << endl;
            // cout << "k3: " << k3 << endl;
            // cout << "k4: " << k4 << endl;
            // cout << endl;

            cout << "It = " << i << endl;
            cout << "t = " << t << endl;
            cout << "Error = " << errado(y[i], y[i-1]) << endl;
            cout << "y(" << i << ") = " << y[i] << endl << endl;
        }


    return 0;
}

float f(float tn, float yn){
    // return yn - pow(tn, 2) + 1;
    // return yn - pow(tn,2) + 1;
    // return pow(tn,2) - (3*yn);
    return (tn*exp(3*tn)) - (2*yn);
}

float errado(float x, float y){
    // return abs((x-y)/x) * 100;
    return abs(x-y);
}