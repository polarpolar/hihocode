#include <iostream>
#include <string>
using namespace std;

void getNext(string chain, int *Next, int mode_len) {
    int match_pos = -1;
    
    Next[0] = 0;
    for (int i = 1; i < mode_len; i++){
        if (chain[++match_pos] == chain[i]) {
            Next[i] = Next[i-1] + 1;
        }else if (chain[i] == chain[0]) {
            Next[i] = 1;
            match_pos = 0;
        }else {
            Next[i] = 0;
            match_pos = -1;
        }
    }
}

int main(void) {
    string mode_chain, ori_chain;
    
    getline(cin, mode_chain);
    
    int mode_len = mode_chain.length();
    int *Next = (int*)malloc(mode_len * sizeof(int));
    
    getNext(mode_chain, Next, mode_len);

    for (int i = 0; i < mode_len; i++){
        cout << Next[i];
    }    
    cout << endl;
}