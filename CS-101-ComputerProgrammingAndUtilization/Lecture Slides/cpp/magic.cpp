#include <iostream>
using namespace std;
int main(){
    int n, i, j, A[20][20], sum, reqSum;
    bool done=false;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    reqSum = n*(n*n+1)/2;
    cout<<"Enter matrix"<<endl;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin>>A[i][j];
        }
    }
    //checking row sum
    for(i=0; i<n; i++){
        sum = 0;
        for(j=0; j<n; j++){
            sum = sum + A[i][j];
        }
        if(sum!=reqSum){
            done = true;
            cout<<"Given matrix is not a magic square matrix."<<endl;
            break;
        }
    }
    //check column sum
    if(!done){
        for(i=0; i<n; i++){
            sum = 0;
            for(j=0; j<n; j++){
                sum = sum + A[j][i];
            }
            if(sum!=reqSum){
                done=true;
                cout<<"Given matrix is not a magic square matrix."<<endl;
                break;
            }
        }
    }
    //check left diagonal sum
    if(!done){
        sum = 0;
        for(i=0; i<n; i++){
            sum = sum + A[i][i];
        }
        if(sum!=reqSum){
            done=true;
            cout<<"Given matrix is not a magic square matrix."<<endl;
        }
    }
    //check right diagonal sum
    if(!done){
        sum = 0;
        for(i=0; i<n; i++){
            sum = sum + A[i][n-i-1];
        }
        if(sum!=reqSum){
            done=true;
            cout<<"Given matrix is not a magic square matrix."<<endl;
        }
    }
    //output result
    if(!done){
        cout<<"Given matrix is a magic square"<<endl;
    }
    return 0;
}
