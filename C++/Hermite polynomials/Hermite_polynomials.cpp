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
            return log(x);
        }
    //Esta función es la derivada de F(x), se modifica manualmente
        float F1(float x){
            return 1/x;
        }
    //Esta función calcula la fórmula de la diferencia dividida
        float calcDifDiv(float fa, float fb, float xa, float xb){
            return (fa-fb)/(xa-xb);
        }


//Variables
    bool esFuncion = false;
    int N = 0;
    float table[100001][100], value = 0;

int main()
{
    cout << "Ingrese el valor a aproximar en la funcion Pn(x): ";
    cin >> value;
    cout << "Ponga 1 si el problema es por una funcion o ponga 0 si es por datos de funcion ya definidos: ";
    cin >> esFuncion;
    cout << "Ingrese la cantidad de datos xi: ";
    cin >> N;
    cout << "Ingrese los datos xi: ";

    if(esFuncion == true){
        for(int i=0;i<N*2;i+=2){
            cin >> table[i][0];
            table[i+1][0] = table[i][0];
            table[i][1] = table[i+1][1] = F(table[i][0]);
        }
    }
    else{
        for(int i=0;i<N*2;i+=2){
            cin >> table[i][0];
            table[i+1][0] = table[i][0];
        }
        cout << "Ingrese los datos de F(xi): ";
        for(int i=0;i<N*2;i+=2){
            cin >> table[i][1];
            table[i+1][1] = table[i][1];
        }
    }

    cout << "Ingrese 1 si tiene la funcion para calcular la derivada de F(xi) o 0 si las va a ingresar manualmente: ";
    cin >> esFuncion;

    if(esFuncion == true){
        for(int i=0;i<N*2;i+=2){
            table[i][2] = F1(table[i][0]);
        }
    }
    else{
        cout << "Ingrese los datos de la derivada de F(xi): ";
        for(int i=0;i<N*2;i+=2){
            cin >> table[i][2];
        }
    }
    

    

    crearTable();

    for(int i=0;i<N*2;i++){
        for(int j=0;j<(N*2)+1;j++){
            cout << setw(20) << table[i][j];
        }
        cout << endl;
    }

    cout << Pn() << endl;

    return 0;
}

void crearTable(){
    int n = N*2;
    for(int i=2;i<=(N*2)+1;i++){
        if(i==2){
            for(int j=1;j<n-1;j+=2){
                table[j][i] = calcDifDiv(table[j+1][i-1], table[j][i-1], table[j+i-1][0], table[j][0]);
            }
        }
        else{
            for(int j=0;j<n-1;j++){
                table[j][i] = calcDifDiv(table[j+1][i-1], table[j][i-1], table[j+i-1][0], table[j][0]);
            }
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
    for(int i=1;i<=(N*2)+2;i++){
        sum = sum + table[0][i]*term(i-1); 
    }
    return sum;
}