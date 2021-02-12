#include <string>
#include <vector>

using namespace std;
int ad[360000];

int getSec(string s){
    int res=0;
    res += stoi(s.substr(0,2))*3600+stoi(s.substr(3,2))*60+stoi(s.substr(6,2));
    return res;
}

string getStr(int n){
    string res="";
    int sec = n % 60;
    n/=60;
    int minutes = n % 60;
    n/=60;
    int hour = n;
    if(hour<10) res+="0";
    res+=to_string(hour);
    res+=":";
    if(minutes<10) res+="0";
    res+=to_string(minutes);
    res+=":";
    if(sec<10) res+="0";
    res+=to_string(sec);
    return res;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    for(string s : logs){
        int start = getSec(s.substr(0,8));
        int end = getSec(s.substr(9,8));
        for(int i=start;i<end;i++) ad[i]++;
    }
    
    int N = getSec(play_time);
    int len = getSec(adv_time);
    long long sum=0;
    long long maxSum=0;
    for(int i=0;i<len;i++){
        sum+=ad[i];
    }
    maxSum=sum;
    int j=len;
    int idx;
    while(j<=N){
        sum+=ad[j];
        sum-=ad[j-len];
        if(sum > maxSum){
            idx = j-len+1;
            maxSum = sum;
        }
        j++;
    }
    answer = getStr(idx);
    return answer;
}
