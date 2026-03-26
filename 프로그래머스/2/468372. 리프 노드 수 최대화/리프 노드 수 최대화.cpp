#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

int solution(int dist_limit, int split_limit) {
    ll D = dist_limit;
    ll S = split_limit;
    
    if(D == 0) return 1;
    
    ll answer = 1;
    
    // 2^i × 3^j <= S인 모든 (i, j) 시도
    for(ll i = 0; i <= 60; i++) {
        ll pow2 = 1LL << i; // 2^i
        if(pow2 > S) break;
        
        for(ll j = 0; j <= 40; j++) {
            ll pow3 = 1;
            for(ll k = 0; k < j; k++) {
                if(pow3 > S / pow2) {
                    pow3 = S + 1;
                    break;
                }
                pow3 *= 3;
            }
            
            if(pow2 * pow3 > S) break;
            
            ll totalLayers = i + j;
            
            ll frontier = 1;
            ll budget = D;
            ll leaves = 0;
            bool done = false;
            
            // i개의 2-층 처리
            for(ll layer = 0; layer < i && !done; layer++) {
                if(budget >= frontier) {
                    budget -= frontier;
                    frontier *= 2;
                } else {
                    // 부분 분배: budget개만 분배
                    ll distributed = budget;
                    ll notDistributed = frontier - distributed;
                    leaves += notDistributed + distributed * 2;
                    done = true;
                }
            }
            
            // j개의 3-층 처리
            for(ll layer = 0; layer < j && !done; layer++) {
                if(budget >= frontier) {
                    budget -= frontier;
                    frontier *= 3;
                } else {
                    // 부분 분배
                    ll distributed = budget;
                    ll notDistributed = frontier - distributed;
                    leaves += notDistributed + distributed * 3;
                    done = true;
                }
            }
            
            // 모든 층을 완전히 처리했으면
            if(!done) {
                leaves = frontier;
            }
            
            answer = max(answer, leaves);
        }
    }
    
    return answer;
}