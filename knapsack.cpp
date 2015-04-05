#include <iostream>
using namespace std;

class Knapsack {
    private:

/*
//  this is the general elements:
        unsigned int m,n;
        unsigned int V[][];
        unsigned int val[];
        unsigned int w[];
*/
    unsigned int m,n;
//    unsigned int *v,*val,*w;
/*
    int **v =  new int[10][15];
    int *val = new int[10];
    int *w = new int[10];
*/

    int V[5][11];
    int val[4];
    int w[4];


    public:
        Knapsack();
        ~Knapsack();
        int max(int,int);
        int Solveit();
        int ShowMatrix();
};

Knapsack::Knapsack() {
    int i,j;

    m = 10;
    n = 4;


    for(i=0;i<n+1;i++) {
        for(j=0;j<m+1;j++) {
            V[i][j] = 0;
        }
    }

    for(i=0;i<n;i++) {
        val[i] = 0;
        w[i] = 0;
    }

    val[0] = 10;
    val[1] = 40;
    val[2] = 30;
    val[3] = 50;

    w[0] = 5;
    w[1] = 4;
    w[2] = 6;
    w[3] = 3;
}

Knapsack::~Knapsack() {

}


int Knapsack::max(int a,int b) {
    int max;

    max = a>b?a:b;

    return max;
}

int Knapsack::Solveit() {
    int i,j;

    for(i=0;i<m+1;i++) {
        V[0][i] = 0;
    }

    for(j=0;j<n+1;j++) {
        V[j][0] = 0;
    }

    int item,weight;

    for(item=1;item<n+1;item++) {
        for(weight=1;weight<m+1;weight++) {
            if(w[item-1] <= weight) {
                V[item][weight] = max(V[item - 1][weight - w[item - 1]] + val[item-1] , V[item - 1][weight]);
            }
            else {
                V[item][weight] = V[item - 1][weight];
            }

        }
    }
    int maxval=0;
    for(item = 1;item<n+1;item++) {
        for(weight = 1;weight<m+1;weight++) {
            if(maxval > V[item][weight]) {
                maxval = V[item][weight];
                i = item;
                j = weight;
            }
        }
    }
    cout<<"Max Value is "<<maxval<<endl;
    return 0;
}

int Knapsack::ShowMatrix() {
    int i,j;

    cout<<"weights:"<<endl;
    for(i=0;i<n;i++) {
        cout<<w[i]<<" ";
    }
    cout<<endl;
    cout<<"values:"<<endl;
    for(i=0;i<n;i++) {
        cout<<val[i]<<" ";
    }
    cout<<endl;
    cout<<"Matrix:"<<endl;
    for(i=0;i<n+1;i++) {
        for(j=0;j<m+1;j++) {
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



int main() {
    class Knapsack one;

    one.Solveit();
    one.ShowMatrix();
    one.~Knapsack();
    return 0;
}

