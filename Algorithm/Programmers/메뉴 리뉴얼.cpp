#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
int cnt[27];
unordered_map<string,int> mm;
vector<string> menu[27][21];

void solve(string s,int idx,string made){
    if(made.length()>1){
        mm[made]++;
        cnt[made.length()] = max(cnt[made.length()], mm[made]);
        menu[made.length()][mm[made]].push_back(made);
    }
    
    for(int i=idx;i<s.length();i++){
        made.push_back(s[i]);
        solve(s,i+1,made);
        made.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(string &s : orders){
        sort(s.begin(),s.end());
        solve(s,0,"");
    }
    
    for(int i : course){
        if(cnt[i]>1){
            for(string s : menu[i][cnt[i]]){
                answer.push_back(s);
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
