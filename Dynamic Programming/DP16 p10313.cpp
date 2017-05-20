#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){
	string input;
	int N,L1,L2;
	while(getline(cin,input)){
		stringstream ss(input);
		vector<int> input_int(3,-1);
		int index = 0;
		while(ss >> input_int[index]){
			index++;
		}
		vector<int> denom(input_int[0]);
		for(int i=0;i<input_int[0];i++){
			denom[i] = i+1;
		}
		int ret;
		//Case 1: Only N
		if(index==1){
			N = input_int[0];
			vector<int> DP(N+1,0);
			DP[0] = 1;
			for(int i=0;i<N;i++){
				for(int j=1;j<=N;j++){
					if(j-denom[i]>=0){
						DP[j]+=DP[j-denom[i]];
					}
				}
			}
			ret = DP[N];
		}
		//Case 2: N and L1
		else if(index==2){
			N = input_int[0];
			L1 = input_int[1];
			vector<vector<int> > DP(N+1,vector<int>(L1+1,0));
			
		}
		//Case 3: N, L1, L2
		else{
			N = input_int[0];
			L1 = input_int[1];
			L2 = input_int[2];
		}
	}

	return 0;
}
