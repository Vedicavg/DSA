#include <iostream>
#include <set>
#include <string>
using namespace std;

// Your provided function
int countSubstr(string& s, int k) {
    int maxCnt=0, n=s.length();
    for(int i=0; i<n; i++) {
        string st = "";
        st += s[i];
        int cnt = 1, d = 1;
        set<char> hash;
        hash.insert(s[i]);
        int j = i;
        while(j < n && d <= k) {
            st += s[j];
            cout << st << endl;
            if(hash.find(s[j]) == hash.end()) {  // If char does not exist in hash
                d++;
                hash.insert(s[j]);
            }
            if(d == k) cnt++;
        }
        maxCnt += cnt;
    }
    return maxCnt;
}

int main() {
    // Input string and k value
    string s = "abca";
    int k = 2;

    // Call the function
    int result = countSubstr(s, k);
    
    // Output the result
    cout << "Total number of valid substrings: " << result << endl;
    
    return 0;
}
