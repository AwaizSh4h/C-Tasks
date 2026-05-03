#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//Using Hashing- O(n) Time and O(n) Spac

bool checkEqual(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    if (n != m)
        return false;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]]++;

    for (int i = 0; i < n; i++) {
        if (mp.find(b[i]) == mp.end())
            return false;

        if (mp[b[i]] == 0)
            return false;
      
        mp[b[i]]--;
    }
    return true;
}

int main() {
    vector<int> a = { 3, 5, 2, 5, 2 };
    vector<int> b = { 2, 3, 5, 5, 2 };

    if (checkEqual(a, b))
        cout << "true";
    else
        cout << "false";
    return 0;
}