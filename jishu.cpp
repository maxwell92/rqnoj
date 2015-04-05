#include <iostream>

using namespace std;

int main() {
    int k,n;
    int i;
    double tmp=0.0,pre = 0.0;

    cin>>k;

    if(k > 15 || k <1) {
        cout<<"error input"<<endl;
    }

    for(i=1;;i++) {
       pre = pre + 1.0/i;
        tmp = 1.0/(i+1);
        if( pre <= k && (pre + tmp) > k) {
            break;
        }
    }
    n = i + 1;
    cout<<n;

    return 0;
}
