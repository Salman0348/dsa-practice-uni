#include<iostream>
using namespace std;
        const int MAX = 2E31-1;
        const int MIN = -2E31;
   int reverse(int x) {
        int rvs=0;

        while(x != 0){
            int dig;
          dig = x%10;
          if((rvs>MAX/10)||(rvs<MIN/10)){
              return 0;
          }
          rvs = (rvs*10)+dig;
          x=x/10; 
        }
        return rvs;
    }
int main(){
    int b = reverse(123);
    cout<<b;
}