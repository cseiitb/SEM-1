#include <iostream>
using namespace std;
int main(){
    char Word[100];
    int i, length=0;
    cout<<"Enter a word: "<<endl;
    cin>>Word;
    for (i=0; i< 100; i++){
        if(Word[i]=='\0'){
            break;
        }
        length++;
    }
    cout<<"Length: "<<length<<endl;
    return 0;
}
