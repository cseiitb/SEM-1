#include <iostream>
#include <cstring>
using namespace std;
int main(){
    char Word[100];
    int length=0;
    cout<<"Enter a word: "<<endl;
    cin>>Word;
    length = strlen(Word);
    cout<<"Length: "<<length<<endl;
    return 0;
}
