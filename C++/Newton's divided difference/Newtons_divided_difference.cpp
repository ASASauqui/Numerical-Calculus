#include <bits/stdc++.h>

using namespace std;

//Funciones
    //Esta función crea la tabla
        void crearTable();
    //Esta función regresa la multiplicación de los términos del tipo (x-x0)(x-x1)...(x-xn-1)
        float term(int);  
    //Esta función regresa el valor de la función Pn(x)
        float Pn();  
    //Esta función es la F(x), se modifica manualmente
        float F(float x){
            // return (3*pow(x,3))-(8*exp(3*x))+100;
            return log(x);
        }
    //Esta función calcula la fórmula de la diferencia dividida
        float calcDifDiv(float fa, float fb, float xa, float xb){
            return (fa-fb)/(xa-xb);
        }


//Variables
    bool esFuncion = false;
    int grado = 0, N = 0;
    float table[100001][100], value = 0;

int main()
{
    cout << "Ingrese el valor a evaluar en Pn(x): ";
    cin >> value;
    cout << "Ingrese el numero de grado: ";
    cin >> grado;
    cout << "Ponga 1 si el problema es por una funcion o ponga 0 si es por datos de funcion ya definidos: ";
    cin >> esFuncion;
    cout << "Ingrese la cantidad de datos xi: ";
    cin >> N;
    cout << "Ingrese los datos xi: ";

    if(esFuncion == true){
        for(int i=0;i<N;i++){
            cin >> table[i][0];
            table[i][1] = F(table[i][0]);
        }
    }
    else{
        for(int i=0;i<N;i++){
            cin >> table[i][0];
        }
        cout << "Ingrese los datos de F(xi): ";
        for(int i=0;i<N;i++){
            cin >> table[i][1];
        }
    }
    

    crearTable();

    for(int i=0;i<N;i++){
        for(int j=0;j<N+1;j++){
            cout << setw(20) << table[i][j];
        }
        cout << endl;
    }

    cout << Pn() << endl;

    return 0;
}

void crearTable(){
    int n = N;
    for(int i=2;i<=N;i++){
        for(int j=0;j<n-1;j++){
            table[j][i] = calcDifDiv(table[j+1][i-1], table[j][i-1], table[j+i-1][0], table[j][0]);
        }
        n--;
    }
}

float term(int x){
    float multi = 1;
    for(int i=0;i<x;i++){
        multi = multi * (value - table[i][0]);
    }

    return multi;
}

float Pn(){
    float sum = 0;
    for(int i=1;i<=grado+1;i++){
        sum = sum + table[0][i]*term(i-1); 
    }
    return sum;
}