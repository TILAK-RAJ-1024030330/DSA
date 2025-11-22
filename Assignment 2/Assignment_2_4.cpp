#include <iostream>
#include <string>
using namespace std;

void concatenateStrings() {
    string str1 = "Hello, ";
    string str2 = "World!";

    string result = str1 + str2;
    cout << "(a) Concatenation Result: " << result << endl;
}

void reverseString() {
    string str = "ReverseMe";
    int n = str.length();

    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    cout << "(b) Reversed String: " << str << endl;
}

void deleteVowels() {
    string str = "Programming Is Fun";
    string result = "";
    for (char c : str) {

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {

            continue;
        }
         else {

            result += c;
        }
    }
    cout << "(c) String without Vowels: " << result << endl;
}

void sortStringsAlphabetical() {

    string arr[] = {"banana", "apple", "cherry", "date"};
    int n = 4;

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "(d) Sorted Strings: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void convertToLowercase() {
    char upperChar = 'H';
    char lowerChar;

    if (upperChar >= 'A' && upperChar <= 'Z') {

        lowerChar = upperChar + ('a' - 'A');
    } 
    else {

        lowerChar = upperChar; 
    }

    cout << "(e) Uppercase '" << upperChar << "' converted to Lowercase: '" << lowerChar << "'" << endl;
}

int main() {
    concatenateStrings();
    reverseString();
    deleteVowels();
    sortStringsAlphabetical();
    convertToLowercase();

    return 0;
}
