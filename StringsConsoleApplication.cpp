// StringsConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int mystrcmp(const char* str1, const char* str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0') {
            return 0;
        }
        str1++;
        str2++;
    }

    if (*str1 > *str2) {
        return 1;
    }
    else {
        return -1;
    }
}

int StringToNumber(char* str) {
    int number = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        number = number * 10 + (str[i] - '0');
    }
    return number;
}

char* NumberToString(int number) {
    char* string = (char*)malloc(sizeof(char) * 10);
    int i = 0;
    while (number > 0) {
        string[i++] = (number % 10) + '0';
        number /= 10;
    }
    string[i] = '\0';
    reverse(string, string + i);
    return string;
}

char* Uppercase(char* str1) {
    char* uppercase_str = (char*)malloc(sizeof(char) * strlen(str1) + 1);
    int i = 0;
    while (str1[i] != '\0') {
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            uppercase_str[i] = str1[i] - 'a' + 'A';
        }
        else {
            uppercase_str[i] = str1[i];
        }
        i++;
    }
    uppercase_str[i] = '\0';
    return uppercase_str;
}

char* Lowercase(char* str1) {
    char* lowercase_str = (char*)malloc(sizeof(char) * strlen(str1) + 1);
    int i = 0;
    while (str1[i] != '\0') {
        if (str1[i] >= 'A' && str1[i] <= 'Z') {
            lowercase_str[i] = str1[i] - 'A' + 'a';
        }
        else {
            lowercase_str[i] = str1[i];
        }
        i++;
    }
    lowercase_str[i] = '\0';
    return lowercase_str;
}

char* mystrrev(char* str) {
    char* new_str = (char*)malloc(sizeof(char) * strlen(str) + 1);
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j) {
        new_str[i] = str[j];
        new_str[j] = str[i];
        i++;
        j--;
    }
    new_str[i] = '\0';
    return new_str;
}

void findAndReplace(string& text, const string& wordToReplace, const string& replacementWord) {
    size_t pos = 0;
    while ((pos = text.find(wordToReplace, pos)) != string::npos) {
        text.replace(pos, wordToReplace.length(), replacementWord);
        pos += replacementWord.length();
    }
}

void capitalizeSentences(string& text) {
    bool newSentence = true;
    for (char& c : text) {
        if (newSentence && (c >= 'a' && c <= 'z')) {
            c -= ('a' - 'A');
            newSentence = false;
        }
        else if (c == '.' || c == '!' || c == '?') {
            newSentence = true;
        }
    }
}

void countLetters(const string& text, int letterCount[]) {
    for (char c : text) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letterCount[toupper(c) - 'A']++;
        }
    }
}

void countNumbers(const string& text, int numberCount[]) {
    for (char c : text) {
        if (c >= '0' && c <= '9') {
            numberCount[c - '0']++;
        }
    }
}

int main() {
    string text;
    cout << "Enter the text: ";
    getline(cin, text);

    // Task 1: homework
    string wordToReplace, replacementWord;
    cout << "Enter the word to replace: ";
    cin >> wordToReplace;
    cout << "Enter the replacement word: ";
    cin >> replacementWord;

    findAndReplace(text, wordToReplace, replacementWord);

    // Task 2: homework
    capitalizeSentences(text);

    // Task 3: homework
    int letterCount[26] = { 0 };
    countLetters(text, letterCount);

    // Task 4: homework
    int numberCount[10] = { 0 };
    countNumbers(text, numberCount);

    cout << "Modified Text:\n" << text << "\n";

    cout << "Letter Count:\n";
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (letterCount[c - 'A'] > 0) {
            cout << c << ": " << letterCount[c - 'A'] << "\n";
        }
    }

    cout << "Number Count:\n";
    for (int i = 0; i < 10; ++i) {
        if (numberCount[i] > 0) {
            cout << i << ": " << numberCount[i] << "\n";
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
