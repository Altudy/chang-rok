#include <string>
#include <vector>
using namespace std;

void stageOne(string &new_id){
    for(int i=0;i<new_id.length();i++){
        if('A'<=new_id[i]&&new_id[i]<='Z') new_id[i] = new_id[i]+32;
    }
}

void stageTwo(string &new_id){
    string tmp="";
    for(int i=0;i<new_id.length();i++){
        if('a'<=new_id[i]&&new_id[i]<='z' || '0'<=new_id[i]&&new_id[i]<='9' || new_id[i]=='-'
          || new_id[i]=='_' || new_id[i]=='.') tmp+=new_id[i];
    }
    new_id = tmp;
}

void stageThree(string &new_id){
    string tmp="";
    tmp+=new_id[0];
    for(int i=1;i<new_id.length();i++){
        if(new_id[i]=='.' && new_id[i-1]=='.') continue;
        else tmp+=new_id[i];
    }
    new_id = tmp;
}

void stageFour(string &new_id){
    if(new_id[0]=='.') new_id = new_id.substr(1);
    if(new_id[new_id.length()-1]=='.') new_id = new_id.substr(0,new_id.length()-1);
}

void stageFive(string &new_id){
    if(new_id.length()==0) new_id = "a";
}

void stageSix(string &new_id){
    if(new_id.length()>=16) new_id = new_id.substr(0,15);
    if(new_id[new_id.length()-1]=='.') new_id = new_id.substr(0,new_id.length()-1);
}

void stageSeven(string &new_id){
    int len = new_id.length();
    while(len<=2){
        new_id = new_id + new_id[len-1];
        len++;
    }
}
string solution(string new_id) {
    stageOne(new_id);
    stageTwo(new_id);
    stageThree(new_id);
    stageFour(new_id);
    stageFive(new_id);
    stageSix(new_id);
    stageSeven(new_id);
    return new_id;
}
