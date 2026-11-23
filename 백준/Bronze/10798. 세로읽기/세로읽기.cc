#include <iostream>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
#define endl '\n'

string arr[5];
int M;

int main() {
    //freopen("input.txt", "r", stdin);
    for(int i=0;i<5;i++) {
        cin>>arr[i];
        M=max(M,(int)arr[i].size());
    }
    

    for(int i=0;i<M;i++){
        for(int j=0;j<5;j++){
            if(i<arr[j].size()) cout<<arr[j][i];
        }
    }
    
    return 0;
}