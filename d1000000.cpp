problem : 
url : https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a46471

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){

    int T;
    cin >> T;
    for(int t=1; t<=T; t++){  
        
        int n;
        cin >> n;
        int dnum[1000001]={0,};
        int max = 0;
        for(int i=0; i<n; i++){
            int s;
            cin>>s;
            dnum[s]++;
            if(s>max){
                max = s;
            }
        }

        int zero = 0;
        for(int i=1; i<=max; i++){
            if(dnum[i]==0){
                zero++;
            }
            else{
                if(dnum[i] > zero){
                    zero = 0;
                }
                if(zero >= dnum[i]){
                    zero -= dnum[i];
                    zero++;
                }
            }
        }
        
        cout << "Case #" << t<< ": ";
        cout << max -zero << endl;
    }
    
    return 0;
}
