#include <iostream>
#include <string>
using namespace std;

string multiplyStrings(string s1, string s2);

int main() {
    string num1 = "-123";
    string num2 = "456";

    string s1 ="111";
    string s2 ="45";
    
    string product = multiplyStrings(num1, num2);
    string productss12 = multiplyStrings(s1, s2);
    
    cout << "Product: " << product << endl;
    cout << "Product: " << productss12 << endl;
    
    return 0;
}

string multiplyStrings(string s1, string s2) {
    bool isNegative = false;
    
    if ((s1[0] == '-' && s2[0] != '-') || (s1[0] != '-' && s2[0] == '-')) {
        isNegative = true;
    }
    
    if (s1[0] == '-') {
        s1 = s1.substr(1);
    }
    
    if (s2[0] == '-') {
        s2 = s2.substr(1);
    }
    
    int len1 = s1.length();
    int len2 = s2.length();
    string result(len1 + len2, '0');
    
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = len2 - 1; j >= 0; j--) {
            int prod = (s1[i] - '0') * (s2[j] - '0') + (result[i + j + 1] - '0') + carry;
            carry = prod / 10;
            result[i + j + 1] = (prod % 10) + '0';
        }
        result[i] += carry;
    }
    
    size_t pos = result.find_first_not_of('0');
    if (pos != string::npos) {
        result = result.substr(pos);
    } else {
        result = "0";
    }
    
    if (isNegative && result != "0") {
        return "-" + result;
    }
    
    return result;
}