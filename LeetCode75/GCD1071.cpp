#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.length() > str2.length()) {
            string strtmp = str1;
            str1 = str2;
            str2 = strtmp;
        }
        
        for(int i = 1; i < str1.length(); i ++) {
            string div = str1.substr(0, str1.length() / i);
            printf("Now comparing : %s and %s\n", div.c_str(), str2.c_str());
            if(isDivisor(div, str2)) {
                return div;
            }
        }
        return "";
    }

    bool isDivisor(string divisor, string str) {
        //by length
        if(str.length() % divisor.length() != 0) {
            cout << "Length cut!\n";
            return false;
        }
        else {
            int cnt = str.length() / divisor.length();
            cout << "divisor - " << divisor << " : ";
            for(int i = 0; i < cnt; i ++) {
                printf("substr(%lu, %lu) : ", i * divisor.length(), (i + 1) * divisor.length());
                cout << str.substr(i * divisor.length(), divisor.length()) << " next ";
                if(!(str.substr(i * divisor.length(), divisor.length()) == divisor)) {
                    cout << "\nFalsified\n";
                    return false;
                }
            }
            cout << "\n";
        }

        return true;
        //are all the parts of the divided length equal?
    }
};

int main() {
    Solution teehee;
    cout << teehee.gcdOfStrings("AA", "A");

    cout << "Did it run??";

    return 0;
}
