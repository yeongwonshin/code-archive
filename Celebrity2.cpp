#include <iostream>
#include <cassert>

/**
 * @brief Asks person A if they know person B.
 * @param a The number of person A.
 * @param b The number of person B.
 * @return true if A knows B, otherwise returns false.
 */
bool ask_a_to_know_b(int a, int b) {
    int result;
    std::cout << "? " << a << ' ' << b << std::endl;
    std::cin >> result;
    assert(result == 0 || result == 1);
    return result;
}

/**
 * @brief Verifies if person x is a celebrity.
 * @param x The number of the person to verify, or -1 if there is no celebrity.
 * @return true if the answer is correct, otherwise returns false.
 */
bool answer(int x) {
    int result;
    std::cout << "! " << x << std::endl;
    std::cin >> result;
    assert(result == 0 || result == 1);
    return result;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    // TODO: write your logic here!
    // You can use the functions `ask_a_to_know_b` and `answer`.
    // Any invocation of print functions rather than `ask_a_to_know_b`
    // and `answer` will result in 0 points for this question.
    if(n<=0){ 
        answer(-1);
        return 0;
    }
    int * eliminatedBy = new int[n+1]();
    unsigned char * knownType = new unsigned char[n+1]();
    
    int * current = new int[n];
    int * next = new int[n];

    auto play_match = [&](int a, int b)-> int{
         bool knows = ask_a_to_know_b(a,b);
         if (knows){
            eliminatedBy[a]= b;
            knownType[a]=1;
            return b;
         }
         else { 
              eliminatedBy[b] = a;
              knownType[b]=2;
              return a;
         }
    };
    int p=1;
    while(p<=n/2) p*=2;//p는 n 이하의 가장 큰 2의 거듭제곱을 구하기 위한 코드
    
    int preliminaryMatches = n-p;
    int currentCount = 0;
    for(int i =0;i<preliminaryMatches;i++){
        int a = 2*i+1;
        int b = 2*i+2;
        current[currentCount++]= play_match(a,b);
    }
    for(int person = 2*preliminaryMatches+1;person<=n;person++){
        current[currentCount++]=person;
    }
    while(currentCount>1){
        int nextCount = 0;
        for(int i =0;i<currentCount;i+=2){
             int a = current[i];
             int b = current[i+1];
             next[nextCount++]= play_match(a,b);
        }
        int *temp = current;
        current = next;
        next=temp;
        currentCount=nextCount;
    }
    
    int candidate=current[0];
    for(int i=1; i<=n;i++){
        if(i==candidate) continue;
   bool candidateDoesNotKnowI =
        (eliminatedBy[i] == candidate && knownType[i] == 2);
//후보가 i를 모르는지 검사
    if (!candidateDoesNotKnowI) {
        if (ask_a_to_know_b(candidate, i)) {
 
            delete[] eliminatedBy;
            delete[] knownType;
            delete[] current;
            delete[] next;

            answer(-1);
            return 0;
        }
    }
    bool iKnowsCandidate = (eliminatedBy[i]==candidate&&knownType[i]==1);
    //i가 후보를 아는지 검사
    if(!iKnowsCandidate){
        if(!ask_a_to_know_b(i, candidate)){
            delete[] eliminatedBy;
            delete[] knownType;
            delete[] current;
            delete[] next;
            answer(-1);
            return 0;
        }
    }
    }
    delete[] eliminatedBy;
    delete[] knownType;
    delete[] current;
    delete[] next;
    
    answer(candidate);
    return 0;
}
