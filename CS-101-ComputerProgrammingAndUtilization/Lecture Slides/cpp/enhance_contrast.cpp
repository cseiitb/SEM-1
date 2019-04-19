#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int i, j, min=0, M, N;
    int image[500][500], newimage[500][500];
    int histogram[256], cdf[256], equaliser[256];
    cout<<"Give the image size height and width:"<<endl;
    cin>>M>>N;
    cout<<"Enter the given image: "<<endl;
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            cin>>image[i][j];
        }
    }
    //initialize histogram, cdf and equliser
    for(i=0; i<256; i++){
        histogram[i]=0;
        cdf[i]=0;
        equaliser[i]=0;
    }
    //calculate histogram
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            histogram[image[i][j]]++;
        }
    }
    //calculate cdf
    cdf[0]= histogram[0];
    for(i=1; i<256; i++){
        cdf[i] = cdf[i-1] + histogram[i];
    }
    //find minimum index with non-zero value
    min = 255;
    for(i=0; i<256; i++){
        if(cdf[i]!=0){
            min = i;
            break;
        }
    }
    //find equaliser
    for(i=0; i<256; i++){
        equaliser[i]= round((float)(cdf[i]- cdf[min])/((M*N)-cdf[min])*255);
    }
    //find and output new image
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            newimage[i][j] = equaliser[image[i][j]];
            cout<<newimage[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
