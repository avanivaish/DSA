//FIND UNIQUE ELEMENT WHERE OTHER ELEMENTS RE PRESENT THRICE
#include<iostream>
using namespace std;

int uniqueThree(int arr[], int n);

int main() {
    int n = 11;
    int arr[] = {1, 2, 2, 1, 3, 2, 3, 3, 1, 4, 4};
    int unique = uniqueThree(arr, n);
    cout << "The unique element that appears once is: " << unique << endl;

    return 0;
}

// Helper function to check if a bit is set at a specific position
bool getBit(int num, int pos) {
    return ((num & (1 << pos)) != 0);
}

int setBit(int num, int pos) {
    return (num | (1 << pos));
}

int uniqueThree(int arr[], int n) {
    int result = 0;

    // Iterate through each bit position (assuming 32-bit integers)
    for (int i = 0; i < 32; i++) {
        int sum = 0;

        // Count the number of elements with a set bit at the current position
        for (int j = 0; j < n; j++) {
            if (getBit(arr[j], i)) {
                sum++;
            }
        }

        // If the sum is not a multiple of 3, set the bit in the result
        if (sum % 3 != 0) {
            result = setBit(result, i);
        }
    }

    return result;
}