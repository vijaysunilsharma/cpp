#include <iostream>
using namespace std ;

class comp {
    private :
                float rez, imz ;
    public :
                comp (){
                }

                comp (float r, float i) {
                rez = r ;
                imz = i ;
                }

                void setdata (float r, float i) {
                rez = r ;
                imz = i ;
                }

                void display (){
                    cout << "\n number is " << rez << "+ i "<< imz ;
                }

                comp operator + (comp var1) {
                comp temp ;
                temp.rez = rez + var1.rez ;
                temp.imz = imz + var1.imz ;
                return temp ;
                }

                comp operator * (comp var1){
                comp temp ;
                temp.rez = (rez * var1.rez) - (imz * var1.imz);
                temp.imz = (rez* var1.imz) + (imz *  var1.rez) ;
                return temp ;
                }

} ;

int main (){
    comp num1, num2, num3, num4 ;
    float real, imag ;
    cout << "Enter num1 real and imaginary: \t" ;
    cin >> real >> imag ;
    num1.setdata( real, imag) ;
    cout << "Enter num2 real and imaginary: \t" ;
    cin >> real >> imag ;
    num2.setdata( real, imag) ;
    num3 = num1 + num2 ;
    num3.display();
    num4 = num1 * num2 ;
    num4.display() ;
    return 0 ;
}
