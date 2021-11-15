#include <iostream>
using namespace std;

int main()
{
    int size(0),length_(10);
    int *delp;
    int* array = new int[length_];
    char x;
    while(true){
        cin.get(x);
        if (x == ' ') continue; if(x == '\n') break;
        else{
            if (size == length_){delp = array;length_ *= 10;array = new int[length_];for(int i(0);i<size;++i) array[i] = delp[i];delete []delp;}
            array[size] = x - '0';
            ++size;
        }
    }

    int** Mat = new int*[size];
    Mat[0] = array;
    for(int row(1);row<size;++row){
        Mat[row] = new int[size];
        for(int col(0);col<size;++col){
            cin >> Mat[row][col];
        }
    }

    for(int row(0);row<size;++row){
        for(int col(0);col<size;++col){
            cout << Mat[row][col] << ' ';
        }
        cout << '\n';
    }
    
    for(int i(0);i<size;++i) delete [] Mat[i];
    delete []Mat;
    return 0;
}
