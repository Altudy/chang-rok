#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

map<string,vector<int>> m;

void solve1(string s){
    string tmpArr[4][2]={
        {"-"},{"-"},{"-"},{"-"}
    };
    int score=0;
    istringstream iss(s);
    iss >> tmpArr[0][1] >> tmpArr[1][1] >> tmpArr[2][1] >> tmpArr[3][1] >> score;
    
    string info="";
    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int l=0;l<2;l++){
                   info = tmpArr[0][i] +tmpArr[1][j]+tmpArr[2][k]+tmpArr[3][l];
                    m[info].push_back(score);
                }
            }
        }
    }
}

int solve2(string s){
    
    int res=0;
    
    string query[4];
    string trash="";
    int score=0;
    istringstream iss(s);
    iss >> query[0] >> trash >> query[1] >> trash >> query[2] >> trash >> query[3] >> score;
    
    string queryString="";
    for(int i=0;i<4;i++) queryString +=query[i];
    
    vector<int> queryScore = m[queryString];
    
    res = queryScore.end() - lower_bound(queryScore.begin(),queryScore.end(),score);
    
    return res;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(string s : info){
        solve1(s);
    }
    for(auto &mm : m){
        sort(mm.second.begin(),mm.second.end());
    }
    for(string s : query){
        answer.push_back(solve2(s));
    }
    
    return answer;
}
