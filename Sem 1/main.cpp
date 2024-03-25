#include <iostream>
#include <numbers>
#include <stdio.h>
#include <string>
#include <ctime>

using namespace std;

struct Student{
    struct name{
        string lastName;
        string firstName;
        string patronymic;
    };
    int classes;
    long numPhone;
    struct score{
        string math;
        string phis;
        string rus;
        string lit;
    };
    
};


int main(){
    int k;
    cin >> k;
    
    Student human[k];
    Student::name name[k];
    Student::score score[k];
    
    auto randStr = [](){
        srand((unsigned int)time(nullptr) + (unsigned int)clock());
        string str;
        static const char absd[] = "abcdefghijklmnopqrstuvwxyz";
        for (int i(0); i < rand()%8 + 3; i++) {
            str += absd[rand()%26];
        }
        return str + '\n';
    };
    
    
    auto randScore = [](int tmp){
        string str;
        if (tmp == 0) str = '1';
        else str = tmp + 0x30;
        return str + '\n';
    };
    
    
    auto structWrite = [&human , &name, &score, &randStr, &randScore](int i){
        srand((unsigned int)time(nullptr) + (unsigned int)clock());
        name[i].lastName = 'F' +  randStr();
        name[i].firstName = 'N' + randStr();
        name[i].patronymic = 'O' + randStr();
        human[i].classes = rand() %11;
        human[i].numPhone = []() -> long {
            long numPh = 7;
            for (int i = 0; i < 10; i++) numPh = numPh * 10 + rand() % 10;
            return numPh; }();
        score[i].math = randScore(rand()%6);
        score[i].phis = randScore(rand()%6);
        score[i].rus = randScore(rand()%6);
        score[i].lit = randScore(rand()%6);
    };
    
    
    
    for (int i(0); i < k; i++) structWrite(i);
    
    FILE *fp;
    fp = fopen( "/Users/user/Documents/Labs_PSTU_2023/Sem 2/Labs/8_GR/t.txt" , "wb");
    if (fp==NULL){fputs ("fopen error",fp);fclose (fp);}
    
    for(int j(0); j<k;j++)
    {
        fwrite(&name, sizeof(Student::name),1,fp);
        fprintf(fp, "%li\n" , human[j].numPhone );
        fprintf(fp, "%i\n" , human[j].classes );
        fwrite(&score, sizeof(Student::score),1,fp);
        
        
    }
    fclose(fp);
    
    for (int i(0); i < k; i++) {
        cout << human[i].numPhone << endl;
        cout << name[i].lastName;
        cout << name[i].firstName;
        cout << name[i].patronymic;
        cout << score[i].math;
        cout << score[i].phis;
        
    }
    FILE * pFile;
    char  buffer[200];
    char  buffe[200];
    string str;
    pFile = fopen ( "/Users/user/Documents/Labs_PSTU_2023/Sem 2/Labs/8_GR/t.txt" , "rb" );
    int n = 256;
    auto clearBuf = [&buffer](int i = 0){
        while (buffer[i] == '\0' || buffer[i] == '\t' || buffer[i] == '\x06' || buffer[i] == '\b' || buffer[i] == '\a') {
            buffer[i] = ' ';
            i++;
        }
    };
    fgets(buffer, n , pFile);
    cout << string(buffer) << endl;
    fgets(buffer, n , pFile);
    clearBuf();
    cout << string(buffe) << endl;
    fgets(buffer, n , pFile);
    clearBuf();
    cout << string(buffer) << endl;
    fgets(buffer, n , pFile);
    clearBuf();
    cout << string(buffer) << endl;
    
    
    
//    long lSize;

//    char b[100];
//    size_t result;
//
//
//    fpos_t position;
//    pFile = fopen ( "/Users/user/Documents/Labs_PSTU_2023/Sem 2/Labs/8_GR/t.txt" , "r" );
//    if (pFile==NULL) {fputs ("File error",stderr); exit (1);}
//
//    // obtain file size:
//    fseek (pFile , 0 , SEEK_END);
//    lSize = ftell (pFile);
//    rewind (pFile);
//
//    // allocate memory to contain the whole file:
//    buffer = (char*) malloc (sizeof(char)*lSize);
//    if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}
//
//    // copy the file into the buffer:
//    result = fread (buffer,1,9,pFile);
//    fsetpos (pFile, &position);
////    if (result != lSize) {fputs ("Reading error",stderr); exit (3);}
//    lSize = ftell (pFile);
//    printf("%s", buffer);
//    fread (&lSize,1,9,pFile);
//
//    printf("%s", buffer);
//    int i(0);
//    while(!feof(pFile)&&i<=10)
//    {
//     fread(&name, sizeof(Student::name),1,pFile);
//    i++;
//    }
//    // terminate
//    fclose (pFile);
//
}
