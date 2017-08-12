#include<iostream>
using namespace std ;
#define SIZE 2

class matrix {
    private :
        int arr[SIZE] [SIZE] ;

    public :
        matrix (){
            for (int row = 0 ; row < SIZE ; row++) {
                for(int col = 0 ; col < SIZE ; col++){
                    arr [row][col] = 0 ;
                }
            }
        }

        void input (){
            for (int row = 0 ; row < SIZE ; row++) {
                for(int col = 0 ; col < SIZE ; col++){
                    int temp ;
                    cout << row + 1 << " row " << col+1 << " col " ;
                    cin >> temp ;
                    arr [row][col] = temp ;
                }
            }

        }

        void display (){
            for (int row = 0 ; row < SIZE ; row++) {
                cout << "\n" ;
                for(int col = 0 ; col < SIZE ; col++){
                   cout << arr [row][col] << "\t" ;
                }
            }
        }

        matrix operator + (matrix m){
            matrix temp ;
            for (int row = 0 ; row < SIZE ; row++) {
                for(int col = 0 ; col < SIZE ; col++){
                    temp.arr [row][col] = arr[row][col] + m.arr[row][col] ;
                }
            }
            return temp ;

        }

        matrix operator * (matrix m){
            matrix temp ;
            for(int row1 = 0 ; row1 < SIZE ; row1++){
                for (int col2 = 0 ; col2 < SIZE ; col2++){
                    int col1 = 0 , row2 = 0 ;
                    for(int var = 0 ; var < SIZE; var++){
                        temp.arr[row1][col2] += arr[row1][col1] * m.arr[row2][col2] ;
                        col1++ ;
                        row2++ ;
                    }
                }
            }
            return temp ;
        }

} ;

int main (){
    matrix m1 , m2, m3 ;
    cout << "\n Enter first matrix \n" ;
    m1.input() ;
    m1.display() ;
    cout << "\n Enter second matrix \n" ;
    m2.input() ;
    m2.display() ;
    m3 = m1 * m2 ;
    cout << "\nthird matrix is \n" ;
    m3.display() ;
}
