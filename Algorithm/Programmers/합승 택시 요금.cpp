#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int dist[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 123456789;
    memset(dist,123456789,sizeof(dist));
    for(int i=1;i<=n;i++) dist[i][i]=0;
    for(int i=0;i<fares.size();i++){
        int start = fares[i][0];
        int end = fares[i][1];
        int fee = fares[i][2];
        
        dist[start][end] = fee;
        dist[end][start] = fee;
    }
 
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(i==j || i==k || j==k) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        answer = min(answer,dist[s][i]+dist[i][a]+dist[i][b]);
    }
    
    return answer;
}
