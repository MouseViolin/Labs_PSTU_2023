#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int spaces =(n/2)-1;
    int after_edge = 0;
//     начало первого горизонтального ребра с учетом смещения
    for (int j = 0; j < spaces; j++)
    {
        cout << "  ";
    }
    spaces--;
    cout << "*";
//     заполнение первого горизонтального ребра
    for (int j = 0; j < n-2; j++)
    {
        cout << " *";
    }
    cout << "  *";
    cout << endl;
//      ребра по диагонали
    for (int i = 0; i < n/2-2; i++)
    {
        for (int j = 0; j < spaces; j++)
        {
            cout << "  ";
        }
        spaces--;
        after_edge += 2;
        cout << "*";
        for (int j = 0; j < n-1; j++)
        {
            cout << "  ";
        }
        cout << "*";
//        заднее вертикальное ребро
        for (int j = 0; j < after_edge; j++)
        {
            cout << " ";
        }
        cout << "*";
        cout << endl;
    }
//    переднее верхнее ребро
    cout << "* ";
    for (int j = 0; j < n-2; j++)
    {
        cout << "* ";
    }
    cout << "*";
//    продолжение заднего вертикального ребра
    for (int j = 0; j < after_edge+2; j++)
    {
        cout << " ";
    }
    cout << " *";
    cout << endl;
//    передняя грань с задним ребром ДО начала ребра по вертикали
    for (int i = 0; i < n/2-1; i++)
    {
        cout << "*";
        for (int j = 0; j < n-2; j++){
            cout << "  ";
        }
        cout << " *";
        for (int j = 0; j < after_edge+2; j++)
        {
            cout << " ";
        }
        cout << " *";
        cout << endl;
    }
//    передняя грань с задним ребром ПОСЛЕ начала ребра по вертикали
    for (int i = 0; i < n/2-1; i++)
    {
        cout << "*";
        for (int j = 0; j < n-2; j++){
            cout << "  ";
        }
        cout << " *";
        
        for (int j = 0; j < after_edge+2; j++)
        {
            cout << " ";
        }
            
        cout << " *";
        after_edge -= 2;
        cout << endl;
    }
//    последнее горизонтальное ребро
    for (int j = 0; j < n; j++)
    {
        cout << "* ";
    }
    cout << endl;
    return 0;
}




