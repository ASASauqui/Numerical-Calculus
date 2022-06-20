#include <bits/stdc++.h>

using namespace std;

//Funciones
    //Esta función es la F(x), se modifica manualmente
        float F(float x){
            // return sqrt(1+(1/x));
            return log(x);
        }
    //Esta función evalúa el Polinomio de Lagrange
        void Lagrange();
    //Esta función calcula las multiplicaciones de las diferencias de la forma (x-x0).../(xi-x0)...
        float term(int);


//Variables
    bool esFuncion;
    int N = 0;
    float P0 = 0, value = 0, res = 0, table[10000][2], sumatoria[1000];

int main()
{
    memset(table, 0, sizeof(table));
    memset(sumatoria, 0, sizeof(sumatoria));

    cout << "Ingrese el valor a evaluar en P(x): ";
    cin >> value;
    cout << "Ingrese el grado del Polinomio de Lagrange: ";
    cin >> N;
    cout << "Ponga 1 si el problema es por una funcion o ponga 0 si es por datos de funcion ya definidos: ";
    cin >> esFuncion;

    cout << "Ingrese los datos xi: ";
    for(int i=0;i<N+1;i++){
        cin >> table[i][0];
    }

    if(esFuncion == true){
        for(int i=0;i<N+1;i++){
            table[i][1] = F(table[i][0]);
        }
    }
    else{
        cout << "Ingrese los datos de F(xi): ";
        for(int i=0;i<N+1;i++){
            cin >> table[i][1];
        }
    }

    Lagrange();

    //Impresión de la tabla
        for(int i=0;i<N+1;i++){
            cout << table[i][0] << ":   " << table[i][1] << endl;
        }
        cout << endl;

    //Impresión de la sumatoria
        cout << "P(" << value << ")" << " = ";
        for(int i=0;i<N+1;i++){
            cout << sumatoria[i];
            if(i < N){
                cout << " + ";
            }
        }
        cout << endl;

    cout << res << endl;
   
    return 0;
}

void Lagrange(){
    for(int i=0;i<N+1;i++){
        sumatoria[i] = term(i) * table[i][1];
        res += term(i) * table[i][1];
    }
}

float term(int j){
    float up = 1, down = 1;
    for(int i=0;i<N+1;i++){
        if(i != j){
            up *= (value - table[i][0]);
            down *= (table[j][0] - table[i][0]);
        }
    }

    return up/down;
}