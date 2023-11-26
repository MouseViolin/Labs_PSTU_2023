#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;
    int spaces =(n/2)-1;
    int before = 0;
        
    for (int j = 0; j < spaces; j++)
    {
        cout << "  ";
    }
    spaces--;
    cout << "*";
    
    for (int j = 0; j < n-2; j++)
    {
        cout << " *";
    }
    cout << "  *";
    cout << endl;
    
    for (int i = 0; i < n/2-2; i++)
    {
        for (int j = 0; j < spaces; j++)
        {
            cout << "  ";
        }
        spaces--;
        before += 2;
        cout << "*";
        for (int j = 0; j < n-1; j++)
        {
            cout << "  ";
        }
        cout << "*";
        for (int j = 0; j < before; j++)
        {
            cout << " ";
        }
        cout << "*";
        cout << endl;
            
    }
    cout << "* ";
    for (int j = 0; j < n-2; j++)
    {
        cout << "* ";
    }
    cout << "*";
    for (int j = 0; j < before+2; j++)
    {
        cout << " ";
    }
    cout << " *";
    cout << endl;
    for (int i = 0; i < n/2-1; i++)
    {
        cout << "*";
        for (int j = 0; j < n-2; j++){
            cout << "  ";
        }
        cout << " *";
        for (int j = 0; j < before+2; j++)
        {
            cout << " ";
        }
        cout << " *";
        cout << endl;
    }
    for (int i = 0; i < n/2-1; i++)
    {
        cout << "*";
        for (int j = 0; j < n-2; j++){
            cout << "  ";
        }
        cout << " *";
        
        for (int j = 0; j < before+2; j++)
        {
            cout << " ";
        }
            
        cout << " *";
        before -= 2;
        cout << endl;
    }
            
    for (int j = 0; j < n; j++)
    {
        cout << "* ";
    }
    cout << endl;
    return 0;
}


