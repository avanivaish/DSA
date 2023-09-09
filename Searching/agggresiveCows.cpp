#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool isPossible(const vector<int> &stalls, int k, int mid);
int aggressiveCows(vector<int> &stalls, int k);

int main(){
    int n = 3;
    int k = 2;
    vector<int> arr = {1, 2, 3};
    cout << aggressiveCows(arr, k) << endl;
    return 0;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int n = stalls.size();
    int e = stalls[n - 1];
    int ans = -1;
    int mid;

    while(s <= e) {
        mid = s + (e - s) / 2;
        if(isPossible(stalls, k, mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

bool isPossible(const vector<int> &stalls, int k, int mid) {
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i = 0; i < stalls.size(); i++) {
        if(stalls[i] - lastPos >= mid) {
            cowCount++;
            if(cowCount == k) {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}
