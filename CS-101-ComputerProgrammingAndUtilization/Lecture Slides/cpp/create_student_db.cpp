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
    char linestr[80], outstr[80];
    char sroll[6], sname[30], sbatch[4], smarks[10];
    int sr; char sn[30]; int sb; float sm;
    int i, j, k, N=0;
    FILE *fpin, *fpout;
    fpin = fopen("files\\csv_data.txt", "r");
    if(fpin==NULL){
        cout<<"Could not open file."<<endl;
        return -1;
    }
    fpout = fopen("files\\studentdb", "wb");
    if(fpout==NULL){
        cout<<"Could not create output file."<<endl;
        return -1;
    }
    // read a line from input file
    fgets(linestr, 79, fpin);
    while(!feof(fpin)){
        i=0; k=0;
        while((sroll[i++]=linestr[k++])!=',');
        sroll[i-1] = '\0';
        i=0;
        while((sname[i++]=linestr[k++])!=',');
        i--;
        while(i<30){
            sname[i++]=' ';
        }
        sname[i-1] = '\0';
        i=0;
        while((sbatch[i++]=linestr[k++])!=',');
        sbatch[i-1]='\0';
        i=0;
        while((smarks[i++]=linestr[k++])!='\0');
        sscanf (sroll, "%d", &sr);
        strcpy(sn, sname);
        sscanf(sbatch,"%d", &sb);
        sscanf(smarks, "%f", &sm);
        sprintf(outstr, "%5d %30s %3d %5.2f\n",sr,sn,sb,sm);
        s.roll = sr;
        strcpy(s.name, sn);
        s.batch = sb;
        s.marks = sm;
        fwrite(&s, rec_size, 1, fpout);
        cout<<ftell(fpout)<<endl;
        printf("%s", outstr);
        fgets(linestr, 79, fpin);
        N=N+1;
    }
    cout<<"Input file has been read and printed"<<endl;
    cout<<"Output file studentdb created"<<endl;
    cout<<N<<" records written to the output file"<<endl;
    fclose(fpin); fclose(fpout);
    return 0;
}
