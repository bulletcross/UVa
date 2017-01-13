#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int head[20000];
int knight[20000];

int main(){
    bool doom;
    int temp_sum,sum;
    int head_sum,knight_sum;
	while(1){
		doom = false;
		cin >> n >> m;
		head_sum=0;
        knight_sum=0;
		if(n==0 && m==0){
			break;
		}
		else{
			for(int i=0;i<n;i++){
				cin >> head[i];
				head_sum+=head[i];
			}
			for(int i=0;i<m;i++){
				cin >> knight[i];
				knight_sum+=knight[i];
			}
			if(head_sum > knight_sum || n>m){
				doom = true;
			}
			else{
				vector<int> head_vector(head,head+n);
				vector<int> knight_vector(knight,knight+m);
				sort(head_vector.begin(),head_vector.end());
				sort(knight_vector.begin(),knight_vector.end());
				vector<int>::iterator iit = knight_vector.begin();
				sum = 0;
				for(vector<int>::iterator it = head_vector.begin(); it!=head_vector.end();it++){
                    if(iit == knight_vector.end()){
                        doom = true;
                        break;
                    }
					while(*iit < *it){
                        iit++;
                        if(iit == knight_vector.end()){
                            doom = true;
                            break;
                        }
					}
					if(doom){
                        break;
					}
					else{
                        sum+=*iit;
                        iit++;
					}
				}
			}
		}
		if(doom){
			cout << "Loowater is doomed!\n";
		}
		else{
			cout << sum << '\n';
		}
	}
	return(0);
}
