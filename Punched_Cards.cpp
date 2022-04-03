//  problem : Punched Cards
//  url : https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4621b

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T; 
    for(int t=1; t<=T; t++){
        int r;
        int c;
        cin >> r >> c;
        cout << "Case #"<<t<< ":" << endl;
        for(int i=0; i<2*r+1; i++){
            for(int j=0; j<2*c+1; j++){
                if((i==0 && j==0) | (i==0 && j==1)| (i==1 && j==0)){
                    cout << ".";
                    continue;
                }
                if(i%2 == 0 ){
                    if(j%2 == 0){
                        cout << "+";
                    }
                    if(j%2 != 0){
                        cout << "-";
                    }
                }
                if(i%2 != 0){
                    if(j%2 == 0){
                        cout << "|";
                    }
                    if(j%2 != 0){
                        cout << ".";
                    }
                }
            }
            cout << endl;
        }
    }

    return 0;
}
