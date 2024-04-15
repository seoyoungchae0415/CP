#include<iostream>
#include<string>

using namespace std;
int main() {

    //inputs
    string word1, word2;
    string input;
    char quotationmark = '"';
    getline(cin, input);

    //parse string into word1 and word2
    int q1 = input.find(quotationmark);
    int q2 = input.substr(q1 + 1).find(quotationmark);
    int q3 = input.substr(q1 + q2 + 2).find(quotationmark);
    int q4 = input.substr(q1 + q2 + q3 + 3).find(quotationmark);  
    q2 += q1 + 1;
    q3 += q2 + 1;
    q4 += q3 + 1;

    word1 = input.substr(q1 + 1, q2 - q1 - 1);
    word2 = input.substr(q3 + 1, q4 - q3 - 1);

    for(int i = 0; i < max(word1.length(), word2.length()); i ++){
        if(i < word1.length())
            cout << word1[i];
        if(i < word2.length())
            cout << word2[i];
    }
    return 0;
}
