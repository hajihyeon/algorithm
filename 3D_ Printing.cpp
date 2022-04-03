// problem : 3D printing
// url : https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4672b

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){

    int T;
    cin >> T;
    for(int t=1; t<=T; t++){    
        unsigned int max[4]={1000001,1000001,1000001,1000001};
        
        for(int i=0; i<3; i++){
            for(int j=0; j<4; j++){
                unsigned int input;
                cin >> input;
                if(input<=max[j]){
                    max[j]=input;
                }
            }
        }
        
        unsigned int sum = 0;
        for(int i=0; i<4; i++){
            sum +=max[i];
        }

        if(sum > 1000000){
            for(int i=0; i<4; i++){
                int diff = sum - 1000000;
                if(diff <= max[i]){
                    sum -= diff;
                    max[i] = max[i]-diff;
                    break;
                }else{
                    sum -= max[i];
                    max[i] = 0;
                }
            }
        }
        
        cout << "Case #" << t<< ": ";
        
        if(sum != 1000000){
            cout << "IMPOSSIBLE" << endl;
        }else{
            for(int i=0; i<4; i++){
                cout << max[i] <<" ";  
            }
            cout << endl;
        }
    }
    
    return 0;
}


