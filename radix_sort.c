#include<stdio.h>
int radixsort(int a[],int n);
int countsort(int a[],int n,int pos);
int max(int a[],int n);
int main(){
    int a[14]={622,500,499,312,276,799,611,543,412,389,212,176,7,2};
    int n=14,count[10],b[14],i;
    radixsort(a,n);
    for(int i=0;i<n;i++){
            printf("\n%d\n",a[i]);
        }
}
int radixsort(int a[],int n){
        int m=max(a,n);
        int pos;
        for(pos=1;(m/pos)>0;pos*=10){
            countsort(a,n,pos);
        }
}
int countsort(int a[],int n,int pos){
        int count[10],i=0,k=10,b[14];
        for(i=0;i<10;i++){
                count[i]=0;
        }
        for(i=0;i<n;i++){
            ++count[(a[i]/pos)%10];
        }
        for(i=1;i<k;i++){
            count[i]=count[i]+count[i-1];
        }
        for(i=n-1;i>=0;i--){
            b[--count[(a[i]/pos)%10]]=a[i];
        }
        for(i=0;i<n;i++){
            a[i]=b[i];
        }
}
int max(int a[],int n){
            int m=0;
            m=a[0];
            for(int i=1;i<n;i++){
                if(a[i]>m){
                    m=a[i];
                }
            }
            return m;
}