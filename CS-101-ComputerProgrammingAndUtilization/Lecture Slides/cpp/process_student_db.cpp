#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct studentinfo{
    int roll;
    char name[30];
    int batch;
    float marks;
};
int main(){
    struct studentinfo s;
    int rec_size;
    rec_size = sizeof(struct studentinfo);
    cout<<"Size of student info record is: "<<rec_size<<endl;
    int r, recnum, found =0; long POS;
    FILE *fp;
    fp = fopen("files\\studentdb", "rb+");
    if(fp==NULL){
        cout<<"Could not open database."<<endl;
        return -1;
    }
    int count =0; found =0;
    rewind(fp);
    cout<<"----------"<<endl;
    cout<<"Initial database:"<<endl;
    fread(&s, rec_size, 1, fp);
    do{
        printf("%5d %30s %3d %5.2f \n", s.roll, s.name,s.batch, s.marks);
        fread(&s, rec_size, 1, fp);
    }while(!feof(fp));
    cout<<"----------"<<endl;
    rewind(fp);
    cout<<"Searching sequentially for marks of roll 10105"<<endl;
    r=10105; found=0;
    POS = ftell(fp);
    do{
        fread(&s, rec_size, 1, fp);
        if(s.roll==r){
            found = POS/rec_size + 1;
            cout<<"Found roll "<<r<<" at record no. "<<found<<endl;
            cout<<"The name and marks are:"<<endl;
            printf("%s %5.2f", s.name, s.marks);
            break;
        }
        else{
            POS = ftell(fp);
            //fread(&s, rec_size, 1, fp);
        }
    }while(!feof(fp));
    if(found==0){
        cout<<"Roll no. not found in database"<<endl;
    }
    cout<<endl<<"----------"<<endl;
    cout << "demonstrating direct access to records" << endl;
    cout << "read and display 6th record"<< endl<< endl;
    recnum=6;
    POS=(recnum-1)*rec_size;
    fseek(fp, POS, SEEK_SET);
    fread(&s, rec_size, 1, fp);
    cout<<"Record starting at byte position "<<POS<<" is: "<<endl;
    printf("%5d %30s %3d %5.2f \n", s.roll, s.name,s.batch, s.marks);
    cout << "Record Number is: " << recnum << endl;
    cout << " -------------"<<endl;
    cout << "read and update Nilamani Raut's marks" << endl;
    cout << "Nilamani's roll number is 10108"<< endl;
    r = 10108; found=0;
    rewind(fp);
    POS = ftell(fp);
    do{
        fread(&s, rec_size, 1, fp);
        if(s.roll==r){
            found = POS/rec_size + 1;
            cout<<"Found roll "<<r<<" at record no. "<<found<<endl;
            cout<<"The name and marks are:"<<endl;
            printf("%s %5.2f", s.name, s.marks);
            s.marks = 93.5;
            fseek(fp, POS, SEEK_SET);
            fwrite(&s, rec_size, 1, fp);
            fseek(fp, POS, SEEK_SET);
            fread(&s, rec_size, 1, fp);
            cout<<endl<<"Updated record is: "<<endl;
            printf("%5d %30s %3d %5.2f \n", s.roll, s.name,s.batch, s.marks);
            break;
        }
        else{
            POS = ftell(fp);
            //fread(&s, rec_size, 1, fp);
        }
    }while(!feof(fp));
    if(found==0){
        cout<<"Roll no. not found in database"<<endl;
    }
    rewind(fp);
    cout<<"----------"<<endl;
    cout<<"Final database:"<<endl;
    fread(&s, rec_size, 1, fp);
    do{
        printf("%5d %30s %3d %5.2f \n", s.roll, s.name,s.batch, s.marks);
        fread(&s, rec_size, 1, fp);
    }while(!feof(fp));
    cout<<"----------"<<endl;
    fclose(fp);
    return 0;
}
