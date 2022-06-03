#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void generateUniqueArray(int a[][5], int rows, int col){
    srand(time(0));
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < col; c++){
            a[r][c] = rand() % 29 + 10;
        }
    }

}

void print2DArray(int a[][5], int rows, int col){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < col; c++){
               cout << a[r][c] << " ";
        }
        cout << endl;
    }
}

void sortRows(int a[][5], int rows, int col){
    for(int r = 0; r < rows; r++){
        int t;

        for(int i = 0; i < col; i++){
            for(int c = 0; c < col -1; c++){
                if(a[r][c] > a[r][c+1]){
                    t = a[r][c];
                    a[r][c] = a[r][c+1];
                    a[r][c+1] = t;
                }
            }
        }
    }

}

void attach(int a[][5], int b[], int rows, int col){
    for(int c = 0; c < col; c++){
        for(int r = 0; r < rows; r++){
            b[(c * rows) + r] = a[r][c];

        }
    }

}

void print1DArray(int b[], int rows, int col){
    cout << "Concatenate colums of the array with sorted rows in an 1-D array\n";
    for(int c = 0; c < col; c++){
        for(int r = 0; r < rows; r++){
            cout << b[(c * rows) + r] << " ";

        }
    }

}


int main(){
    const int r = 4;
    const int c = 5;
    int a[r][c];
    int b[r * c];


    generateUniqueArray(a, r, c);
    cout << "20 unique 2-digit random positive integers < 40" << endl;
    print2DArray(a, r, c);
    sortRows(a, r, c);
    cout << "Array with sorted rows\n";
    print2DArray(a,r,c);
    attach(a, b, r, c);
    print1DArray(b, r ,c);
}
