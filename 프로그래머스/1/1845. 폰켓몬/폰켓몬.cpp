#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <climits>
#include <cmath>
#include <cassert>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;




int N;
int solution(vector<int> nums)
{
    N=nums.size();
    
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    
    
    
    int answer = min(N/2, (int)nums.size());
    return answer;
}