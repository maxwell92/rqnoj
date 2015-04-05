#include <iostream>

using namespace std;

int main() {
    int t_size,a_size;
    int n;
    int min=10000,sum=0;
    int t_sum=0,a_sum=0;

    cin>>t_size>>a_size;
    if(t_size<1 || t_size>21 || a_size<1 || a_size>79) {
        cout<<"error input";
        return -1;
    }

    cin>>n;
    if(n<1 || n>1000) {
        cout<<"error input";
        return -1;
    }

    int *t = new int[n],*a = new int[n],*w = new int[n];

    int i;
    for(i=1;i<=n;i++) {
        cin>>t[i]>>a[i]>>w[i];
    }

    int j,k;
/*
    for(i=1;i<=n;i++) {
        t_sum = 0;
        a_sum = 0;

            /*t_sum = t_sum + t[i];
            a_sum = a_sum + a[i];
            sum = sum + w[i];*
            for(j=i;j<=n;j++) {
                /*t_sum = t_sum + t[j];
                a_sum = a_sum + a[j];
                sum = sum + w[j];*
                t_sum = t_sum + t[j];
                a_sum = a_sum + a[j];
                sum = sum + w[j];
/*                if(t_sum < t_size) {
                    continue;
                }
                else {
                    if(a_sum < a_size) {
                        continue;
                    }
                    else {
                        if(sum < min) {
                            min = sum;

                        }
                    }
                }
*
                if(t_sum >= t_size && a_sum >= a_size) {

                }
                else {
                    continue;
                }
            }

    }
*/
    for(i=1;i<=n;i++) {
        t_sum = 0;
        a_sum = 0;
        sum = 0;
        t_sum = t_sum + t[i];
        a_sum = a_sum + a[i];
        sum = sum + w[i];

        for(j=1;j<=n;j++) {
            if(j == i) {
                continue;
            }
            t_sum = t_sum + t[j];
            a_sum = a_sum + a[j];
            sum = sum + w[j];

        }

        t_sum = t_sum + t[i];
        a_sum = a_sum + a[i];
        sum = sum + w[i];



    }


    cout<<sum;


}
