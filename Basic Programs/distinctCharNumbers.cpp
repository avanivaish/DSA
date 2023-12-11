#include <iostream>
#include <unordered_set>

using namespace std;

bool hasRepeatedCharacters(int number) {
    unordered_set<char> uniqueChars;
    string strNumber = to_string(number);

    for (char digit : strNumber) {
        if (uniqueChars.find(digit) != uniqueChars.end()) {
            return true;  // Repeated character found
        }
        uniqueChars.insert(digit);
    }

    return false;  // No repeated characters found
}

void distinctCharacterNumbers(int L, int R) {
    for (int num = L; num <= R; ++num) {
        if (!hasRepeatedCharacters(num)) {
            cout << num << " ";
        }
    }
}

int main() {
    // Test case
    int L = 10;
    int R = 27;

    distinctCharacterNumbers(L, R);

    return 0;
}
