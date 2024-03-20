#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    
    // inputs
    int n, m, k;
    cin >> n >> m >> k;

    char arr[n][m];

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> arr[i][j];
        }
    }
    
    // map of classes with varying colors
    // will be pruned in loop
    unordered_map<char, int> cla;
    
    for(int i = 0; i < k; i ++) {
        cla.insert({65+i, i + 1 + 26});
    }
    
    // edge case
    if(n == 1) {
        cout << k;
        return 0;
    }

    char lead;
    char rear;


    for(int i = 0; i < m; i ++) {
        lead = arr[0][i];
        for(int j = 1; j < n; j ++) {
            rear = arr[j][i];
            // cout << "comparing " << lead << cla[lead] << " and " << rear << cla[rear] << endl;

            if(lead != rear && abs(cla[lead] - cla[rear]) != 26) {
               if(cla[lead] > 26) {
                   if(cla[rear] > 26) {
                       cla[rear] = cla[lead] - 26;
                       // cout << "Deleted " << rear << endl;
                  }
                  else if(cla[rear] <= 26) {
                       cla[lead] = cla[rear];
                       // cout << "Deleted " << lead << endl;
                  }
               }
               else if(cla[lead] <= 26 && cla[rear] > 26) {
                   cla[rear] = cla[lead];
                   // cout << "Deleted " << rear << endl;
               }
            }

        }
    }

    int count = 0;
    for(auto i : cla) {
        //cout << i.first << " " << i.second << endl;
        if(i.second > 26)
            count ++;
    }

    cout << count;
}
