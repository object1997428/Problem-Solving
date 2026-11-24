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
using namespace std;
#define endl '\n'

int N;
stack<int> s1;
queue<int> q1;

int main() {
    //freopen("input.txt", "r", stdin);
    
    cin>>N;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        q1.push(x);
    }

    for(int i=1;i<=N;i++){


        if(!q1.empty()&&q1.front()==i){
            q1.pop(); continue;
        }
        else{
            if(!s1.empty()&&s1.top()==i){
                s1.pop(); continue;
            }
            else {
                while(!q1.empty()&&q1.front()!=i){
                    s1.push(q1.front());
                    q1.pop();
                }
            }
        }
        if(q1.empty()){
            cout<<"Sad"<<endl;
            exit(0);
        }
        q1.pop();
    }
    cout<<"Nice"<<endl;
    
    
    return 0;
}