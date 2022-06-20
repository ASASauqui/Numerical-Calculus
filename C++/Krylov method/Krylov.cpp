#include <bits/stdc++.h>

using namespace std;

//Variables
    long long int N = 0;
    vector<vector<double> > mat(1000, vector<double> (1000,0)), Ay(1000);
    vector<double> ini(1000, 0); 

//Funciones
    //Regresa una matrix (1 x N)
        vector<double> multiMat(){
            vector<double> x(1000, 0);
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    x[i] += ini[j] * mat[i][j];
                }
            }

            return x;
        }
    //Realiza el método de Krylov
        void krylov(){
            for(long long int i=1;i<=N;i++){
                ini = multiMat();
                Ay[i] = ini;;
            }
        }


int main()
{
    //Ingreso de valores
        cout << "Ingrese el tamano de su matriz n x n: ";
        cin >> N;
        cout << "Ingrese su matriz n x n para encontrar el polinomio caracteristico: " << endl;
        for(long long int i=0;i<N;i++){
            for(long long int j=0;j<N;j++){
                cin >> mat[i][j];
            }
        }
        cout << "Ingrese su vector inicial: " << endl;
        for(long long int i=0;i<N;i++){
            cin >> ini[i];
        }

    //Lamado de la función
        Ay[0] = ini;
        krylov();
        cout << endl << endl;

    //Impresión
        for(long long int i=N;i>=0;i--){
            if(i!=N){
                cout << "b" << i << " * ";
            }
            cout << "(";
            for(long long int j=0;j<N;j++){
                cout << Ay[i][j] << " ";
            }
            cout << ")" << endl;
        }

    return 0;
}