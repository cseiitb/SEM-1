#include <iostream>

using namespace std;

int main(){
    int i, j, k;
    int rA, cA, rB, cB;
    int A[100][100], B[100][100], C[100][100];
    cout<<"Enter number of rows in matrix A:"<<endl;
    cin>>rA;
    cout<<"Enter number of columns in matrix A:"<<endl;
    cin>>cA;
    cout<<"Enter matrix A:"<<endl;
    for(i=0; i<rA; i++){
        for(j=0; j<cA; j++){
            cin>>A[i][j];
        }
    }
    cout<<"Enter number of rows in matrix B:"<<endl;
    cin>>rB;
    if(rB!=cA){
        cout<<"Error: number of rows in matrix B"
        <<" must be same as number of columns in matrix A"<<endl;
        return -1;
    }
    cout<<"Enter number of columns in matrix B:"<<endl;
    cin>>cB;
    cout<<"Enter matrix B:"<<endl;
    for(i=0; i<rB; i++){
        for(j=0; j<cB; j++){
            cin>>B[i][j];
        }
    }
    //compute matrix multiplication
    for(i=0; i<rA; i++){
        for(j=0; j<cB; j++){
            C[i][j] = 0;
            for(k=0; k<rB; k++){
                C[i][j] = C[i][j] + A[i][k]*B[k][j];
            }
        }
    }
    //display matrix C
    for(i=0; i<rA; i++){
        cout<<endl;
        for(j=0; j<cB; j++){
            cout<<C[i][j]<<"   ";
        }
    }
    return 0;
}
