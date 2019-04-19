#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int i, numwords=0, numchars=0;
    char sentence[500], words[100][50];
    cout<<"Enter a sentence: "<<endl;
    gets(sentence);
    for(i=0; ; i++){
        if(sentence[i]=='\0'){
            words[numwords][numchars]='\0';
            numwords++;
            break;
        }
        if(sentence[i]==' '){
            if(sentence[i+1]!=' '){
                words[numwords][numchars]='\0';
                numwords++;
                numchars=0;
            }
            continue;
        }
        else{
            words[numwords][numchars] = sentence[i];
            numchars++;
        }
    }
    cout<<"Total number of words found: "<<numwords<<endl;
    //output array of words
    for(i=0; i< numwords; i++){
        cout<<words[i]<<endl;
    }
    return 0;
}
