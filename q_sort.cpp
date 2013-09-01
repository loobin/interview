#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
/** \brief 让左边的数小于等于mid_value，右边的数大于等于mid_value，
 *         分别对左，右两边序列排序。
 * \key point: 注意等号的取舍  
 * \param 
 * \return 
 *
 */     

void q_sort(int *a,int left,int right)
{
    int l = left;
    int r = right;
    int mid_value = a[(l+r)>>1];
    while(l < r){
        while(a[l] < mid_value) l++;  // 不取等号，反例mid_value最大。
        while(a[r] > mid_value) r--;
        if(l <= r)         // 取等号,反例1 2 
            swap(a[l++],a[r--]);
    }
    if(left < r)
        q_sort(a,left,r);
    if(l < right)
        q_sort(a,l,right);
}
int a[100000];
int main()
{
    int n;
    while( cin >> n){
        for(int i = 0; i < n; i++)
            cin >> a[i];
        q_sort(a,0,n-1);
        for(int i = 0; i < n; i++)
            cout << a[i] << " " ;
        cout << endl;
    }
    return 0;
}
