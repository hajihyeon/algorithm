/* 
    problem : Inversions Organize
    url : https://codingcompetitions.withgoogle.com/codejamio/round/00000000009d9870/0000000000a33e95
 */

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
    int array[2][2] = {0,0,0,0};
    int N=0;
    scanf("%d", &N);

    for(int i=0; i<2*N; i++){
        char input[205];
        cin >> input;
        for(int j=0; j<2*N; j++){
            if(input[j] == 'I'){
                array[i/N][j/N]++;
            }
        }
    }

        int sum = 0;
        if(array[0][0]>array[1][1]){
            sum +=array[0][0]-array[1][1]; 
        }else{
            sum +=array[1][1]-array[0][0]; 
        }
        if(array[0][1]>array[1][0]){
            sum +=array[0][1]-array[1][0]; 
        }else{
            sum +=array[1][0]-array[0][1]; 
        }
        cout << "Case #" << t << ": " << sum << endl;
    }
    return 0;
}