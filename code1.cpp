/*1. 별 찍기

BOJ 10992 “별 찍기 - 17”과 같은 문제입니다. 첫 줄은 꼭짓점 하나, 마지막 줄은 2N-1개의 별, 중간 줄은 양 끝 별만 출력하는 형태입니다.

문제

정수 N이 주어진다.
높이가 N인 속이 빈 삼각형 모양을 별 *로 출력하라.

입력
N
출력

별 모양을 출력한다.

예제 입력
4
예제 출력
   *
  * *
 *   *
*******    */

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    if(n==1){
      cout<<"*\n";
    }

   for(int i = 1; i<=n ; i++){
      if(i==1){
         for(int j=1;j<=n-1;j++){
            cout<<" ";
         }
         cout<<"*\n";

      }
      else if (i==n){
         for(int j=1;j<=2*n-1;j++){
            cout<<"*";
         }
         cout<<"\n";
      }
      else {
         for(int j=1;j<=n-i;j++){
            cout<<" ";
         }
         cout<<"*";
         for(int j=1;j<=2*i-3;j++){
            cout<<" ";
         }
         cout<<"*\n";
      }
      
   }
 return 0;
   }
