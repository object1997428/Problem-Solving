#include <iostream>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
#define endl '\n'

unordered_map<int,int> m1,m2;
int N,M;
int arrA[200001], arrB[200001];

int main() {
    //freopen("input.txt", "r", stdin);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>arrA[i];
        m1[arrA[i]]++;
    }

    for(int i=0;i<M;i++){
        cin>>arrB[i];
        if(m1[arrB[i]]==1){
            m2[arrB[i]]++;
        }
    }

    // minus 찾기
    int minus=0;
    for(int i=0;i<N;i++){
        if(m2[arrA[i]]==1) minus++;
    }

    for(int i=0;i<M;i++){
        if(m2[arrB[i]]==1) minus++;
    }

    cout<<N+M-minus<<endl;
    
    
    
    return 0;
}