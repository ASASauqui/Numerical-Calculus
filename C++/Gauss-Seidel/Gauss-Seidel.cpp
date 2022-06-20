#include <bits/stdc++.h>

using namespace std;

//Variables
    int N = 0, K = 0;
    float mat[10001][10001], X[10001];

//Funciones
    void despeje(int&);

int main()
{
    memset(mat,0,sizeof(mat));
    memset(X,0,sizeof(X));

    cout << "Ingrese la cantidad de variables: ";
    cin >> N;
    cout << "Ingrese el numero de iteraciones: ";
    cin >> K;

    cout << "Ingrese la matriz:" << endl;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N+1;j++){
            cin >> mat[i][j];
        }
    }

    cout << "Ingrese los valores iniciales:" << endl;
    for(int i=0;i<N;i++){
        cin >> X[i];
    }

    for(int i=0;i<K;i++){
        cout << "Iteracion No." << i+1 << endl;
        for(int j=0;j<N;j++){
            despeje(j);
            cout << "x" << j+1 << "=  " << X[j] << endl;
        }
        cout << endl;
    }

    cout << "Soluciones:" << endl;
    for(int i=0;i<N;i++){
        cout << "x" << i+1 << "=  " << X[i] << endl;
    }

    return 0;
}

void despeje(int &j){
    X[j] = mat[j][N];
    for(int i=0;i<N;i++){
        if(i != j){
            X[j] += (-1*mat[j][i]) * X[i];
        }
    }
    X[j] /= mat[j][j];
}