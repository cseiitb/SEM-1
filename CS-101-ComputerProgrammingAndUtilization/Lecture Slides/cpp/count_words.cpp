#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    char sentence[200];
    int i, numwords=0;
    cout<<"Enter a sentence: "<<endl;
    gets(sentence);
    for(i=0; ; i++){
        if(sentence[i]=='\0'){
            numwords++;
            cout<<endl;
            break;
        }
        if(sentence[i]==' '){
            numwords++;
            cout<<endl;
        }
        else{
            cout<<sentence[i];
        }
    }
    cout<<"Given sentence has "<<numwords<<" words."<<endl;
    return 0;
}
