#include <bits/stdc++.h>

using namespace std;

//Variables
    int n = 0, k = 0;
    vector<vector<float> > A(1000, vector<float> (1000,0)), Bn(1000, vector<float> (1000,0)), I(1000, vector<float> (1000,0));
    vector<vector<float> > a(1000, vector<float> (1000,0)), b(1000, vector<float> (1000,0)), c(1000, vector<float> (1000,0));
    vector<float> bn(1000);

//Funciones
    vector<vector<float> > multiMat(vector<vector<float> > &, vector<vector<float> > &);
    vector<vector<float> > sumMat(vector<vector<float> > &, vector<vector<float> > &);
    vector<vector<float> > multiUniMat(float &, vector<vector<float> >);
    float tr(vector<vector<float> > &);
    void printMat(vector<vector<float> > &);

int main()
{
    //Ingresar tamaño de matriz n y repeticiones k
        cout << "Ingrese el tamano de la matriz (n x n): ";
        cin >> n;
        k = n;

    //Ingresar matriz
        cout << "Ingrese su matriz A de tamano n x n:" << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> A[i][j];
            }
        }

    //Iniciar valores iniciales
        //Matriz identidad
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i == j){
                        I[i][j] = 1;
                    }
                }
            }
        
        //b0 = 1
            bn[n] = 1;
    

    //Iteraciones
        cout << endl;
        for(int i=1;i<=k;i++){
            //B[k] = AB[k-1] + b[n-k+1]I
                a = multiMat(A, Bn);
                b = multiUniMat(bn[n-i+1], I);
                Bn = sumMat(a, b);

            //b[n-k] = (-1/k) * tr(AB[k])
                c = multiMat(A, Bn);
                bn[n-i] = (-1) * tr(c);
                bn[n-i] = bn[n-i] / i;

            //Impresión de la iteración, de b[k-1] y de la matriz Bn
                cout << "It = " << i << endl;
                cout << "b" << n-i << " = " << bn[n-i] << endl;
                printMat(Bn);
                cout << endl;
        }

    //Impresión del polinomio característico
        cout << "El polinomio caracteristico es: " << endl;
        for(int i=n; i>=0; i--){
            cout << bn[i] << "  ";
        }


    return 0;
}

vector<vector<float> > multiMat(vector<vector<float> > &mat1, vector<vector<float> > &mat2){
    vector<vector<float> > mat3(n, vector<float> (n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int l=0; l<n; l++){
                mat3[i][j] += mat1[i][l] * mat2[l][j];
            }
        }
    }

    return mat3;
}

vector<vector<float> > sumMat(vector<vector<float> > &mat1, vector<vector<float> > &mat2){
    vector<vector<float> > mat3(n, vector<float> (n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    return mat3;
}

vector<vector<float> > multiUniMat(float &x, vector<vector<float> > mat){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j] = x * mat[i][j];
        }
    }

    return mat;
}

float tr(vector<vector<float> > &mat){
    float x = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j){
                x += mat[i][j];
            }
        }
    }

    return x;
}

void printMat(vector<vector<float> > &mat){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}