#include <iostream>

using namespace std;
int uniquePaths(int m, int n) {
        int N= m+n-2;
        int R= (n<m)? n-1:m-1;
        double num= 1, dem= 1;
        for(int i=1; i<=R; i++){
            num= num*N--;
        }
        while(R>0){
            dem= dem*R--;
        }
        return num/dem;
    }




int main()
{
    cout<<uniquePaths(10, 10);

    return 0;
}
