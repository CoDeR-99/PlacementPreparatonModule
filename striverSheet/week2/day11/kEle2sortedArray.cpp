#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int size= n+m;
        int i=0, j=0;
        int count= 0;
        while(i<n && j<m){
            count++;
            if(arr1[i]<arr2[j]){
                // count++;
                if(count==k){
                    return arr1[i];
                }
                i++;
            }
            else{
                // count++;
                if(count==k){
                    return arr2[j];
                }
                j++;
            }
        }
        while(i<n){
            count++;
            if(count==k){
                return arr1[i];
            }
            i++;
        }
        while(j<m){
            count++;
            if(count==k){
                return arr2[j];
            }
            j++;
        }
        return -1;
    }
};

int main(){
    int n= 5, m=7;
    int k=7;
    int arr1[]= {100, 112, 256, 349, 770};
    int arr2[]= {72, 86, 113, 119, 265, 445, 892};
    Solution obj;
    cout<<k<<"th element: "<<obj.kthElement(arr1, arr2, n, m, k);
    return 0;
}