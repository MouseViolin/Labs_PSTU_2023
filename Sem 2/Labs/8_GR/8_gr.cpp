#include <iostream>
#include <numbers>
#include <stdio.h>
#include <string>
#include <ctime>

using namespace std;

struct Student{
    string lastName;
    string firstName;
    string patronymic;
    string classes;
    string numPhone;
    string math;
    string phis;
    string rus;
    string lit;
    
};


int main(){
    int k;
    cin >> k;
    
    Student human[k];
    Student humanOutFile[k];
    
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
        if (tmp == 0) str = '2';
        else str = tmp + 0x30;
        return str + '\n';
    };
    
    
    auto structWrite = [&human, &randStr, &randScore](int i){
        srand((unsigned int)time(nullptr) + (unsigned int)clock());
        human[i].lastName = 'F' +  randStr();
        human[i].firstName = 'N' + randStr();
        human[i].patronymic = 'O' + randStr();
        human[i].classes = randScore(rand()%12);
        human[i].numPhone = [](){
            string numPh = "7";
            for (int i = 0; i < 10; i++) numPh += rand() % 10 + 0x30;
            return numPh; }();
        human[i].math = randScore(rand()%6);
        human[i].phis = randScore(rand()%6);
        human[i].rus = randScore(rand()%6);
        human[i].lit = randScore(rand()%6);
    };
    
    
    
    for (int i(0); i < k; i++) structWrite(i);
    
    FILE *fp;
    fp = fopen( "/Users/user/Documents/Labs_PSTU_2023/Sem 2/Labs/8_GR/t.txt" , "wb");
    if (fp==NULL){fputs ("fopen error",fp);fclose (fp);}
    
    for(int j(0); j<k;j++)
    {
        fwrite(&human[j], sizeof(Student),1,fp);
    }
    fclose(fp);

    FILE * pFile;
    
    string str;
    pFile = fopen ( "/Users/user/Documents/Labs_PSTU_2023/Sem 2/Labs/8_GR/t.txt" , "rb" );
 
    int i = 0;
    while(!feof(pFile)&&i<=k)
    {
        fread(&humanOutFile[i], sizeof(Student),1,pFile);
    i++;
    }
    fclose(pFile);
    int dis = 0;
    for (int i(0); i < k; i++) {
        if (humanOutFile[i].math == "2\n") {
            for (int j(i); j < k; j++) {
                humanOutFile[i] = humanOutFile[i+1];
            }
            dis++;
        }
    }
    
    fp = fopen( "/Users/user/Documents/Labs_PSTU_2023/Sem 2/Labs/8_GR/t.txt" , "wb");
    if (fp==NULL){fputs ("fopen error",fp);fclose (fp);}
    
    for(int j(0); j<k - dis;j++)
    {
        fwrite(&humanOutFile[j], sizeof(Student),1,fp);
    }
    fclose(fp);

    
}
