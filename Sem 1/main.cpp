#include <iostream>
using namespace std;

int neg_str(int arr[3][3], int num, int size){
    bool flag = 1;
    
    for (int i = 0; i < size; i++) {
        if (arr[num][i] < 0 ) {
            flag = 0;
            break;
        }
    }
    if (!flag) {
        for (int k = num; k < size-1 ; k++) {
            
            for (int j = 0; j < size; j++) {
                arr[k][j] = arr[k+1][j];
            }
            
        }
        for (int j = 0; j < size; j++) {
            arr[size-1][j] = 0;
        }
        return -1;
    } else {return 0;}
    
}

int main() {
    int size;
    
    cin >> size;
    int arr[3][3]= {{-1,2,0},{1,-1,1},{3,2, 1}};
    for (int i = 0; i < size; i++) {
        i += neg_str(arr, i , size);
    }
    
    for (int i = 0; i < size; cout << endl, i++)
        for (int j = 0; j < size;cout << arr[i][j] << " ", j++);
    
    
    
    
    
    
    
    
    
    return 0;
}
