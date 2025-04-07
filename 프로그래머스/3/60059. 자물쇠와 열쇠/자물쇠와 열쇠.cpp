#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <climits>
#include <cmath>
#include <cassert>
#pragma warning(disable:4996)
using namespace std;
typedef pair<int,int> pii;
int N,M;
vector<vector<int>> lock,key;
vector<pii> lockv,keyv;//

void changePivot(vector<pii>& v,int first){
    int piv=-1;
    for(int i=0;i<v.size();i++){
        if(v[i].first==0&&v[i].second==0){
            piv=i; break;
        }
    }
    if(first) piv=0;
    else piv=(piv+1)%v.size(); //piv바꿔주기
    int my=v[piv].first,mx=v[piv].second;
    for(int i=0;i<v.size();i++){
        v[i].first-=my;
        v[i].second-=mx;
    }
}

void rotate(vector<pii>& v){
    int maxyx=INT_MIN;
    for(int i=0;i<v.size();i++){
        maxyx=max(maxyx,v[i].first);
        maxyx=max(maxyx,v[i].second);
    }
    for(int i=0;i<v.size();i++){
         v[i]={v[i].second,maxyx-v[i].first};
    }
}

void init(){
    for(int i=0;i<N;i++)for(int j=0;j<N;j++){
        if(lock[i][j]==0){
            lockv.push_back({i,j});
        }
    }
    sort(lockv.begin(),lockv.end());
     for(int i=0;i<M;i++)for(int j=0;j<M;j++){
        if(key[i][j]==1){
            keyv.push_back({i,j});
        }
    }
    sort(keyv.begin(),keyv.end());
    changePivot(keyv,1);//어쩌피 [0]={0,0};
    sort(keyv.begin(),keyv.end());
    assert(keyv[0].first==0&&keyv[0].second==0);
}

bool find(){
    for(int i=0;i<lockv.size();i++){
        int sy=lockv[i].first, sx=lockv[i].second;
        for(int w=0;w<4;w++){
            if(!(keyv[0].first==0&&keyv[0].second==0)){
                    cout<<keyv[0].first<<" "<<keyv[0].second<<endl;
                }
            for(int j=0;j<keyv.size();j++){
                int chk=1; int cnt=0;
                
                for(int k=0;k<keyv.size();k++){
                    int y=sy+keyv[k].first, x=sx+keyv[k].second;
                    if(y<0||x<0||y>=N||x>=N) continue;
                    if(lock[y][x]==1){
                        chk=0;
                        break;
                    }
                    else cnt++;
                }
                if(chk&&cnt==lockv.size()){
                    return true;
                }
                //cout<<"피봇 바뀜!"<<endl;
                changePivot(keyv,0); 
                sort(keyv.begin(),keyv.end());
            }//key pivot
            //cout<<"회전!"<<endl;
            rotate(keyv);
            sort(keyv.begin(),keyv.end());
            changePivot(keyv,0); 
        }//w
    }
    return false;
}

bool solution(vector<vector<int>> _key, vector<vector<int>> _lock) {
    key=_key; lock=_lock; N=lock.size(), M=key.size();
    init();
    if(keyv.size()<lockv.size()) return false;
    if(lockv.size()==0) return true;
    
    
    return find();
}