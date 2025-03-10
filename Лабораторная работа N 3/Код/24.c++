#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

string translit(const string& text) {
    unordered_map<char, string> translitMap = {
        {'а', "a"}, {'б', "b"}, {'в', "v"}, {'г', "g"},
        {'д', "d"}, {'е', "e"}, {'ё', "yo"}, {'ж', "zh"},
        {'з', "z"}, {'и', "i"}, {'й', "y"}, {'к', "k"},
        {'л', "l"}, {'м', "m"}, {'н', "n"}, {'о', "o"},
        {'п', "p"}, {'р', "r"}, {'с', "s"}, {'т', "t"},
        {'у', "u"}, {'ф', "f"}, {'х', "kh"}, {'ц', "ts"},
        {'ч', "ch"}, {'ш', "sh"}, {'щ', "shch"}, {'ъ', ""},  {'ы', "y"},  
        {'ь', ""},  {'э', "e"},  {'ю', "yu"}, {'я', "ya"},
        {'А', "A"}, {'Б', "B"}, {'В', "V"}, {'Г', "G"},
        {'Д', "D"}, {'Е', "E"}, {'Ё', "Yo"}, {'Ж', "Zh"},
        {'З', "Z"}, {'И', "I"}, {'Й', "Y"}, {'К', "K"},
        {'Л', "L"}, {'М', "M"}, {'Н', "N"}, {'О', "O"},
        {'П', "P"}, {'Р', "R"}, {'С', "S"}, {'Т', "T"},
        {'У', "U"}, {'Ф', "F"}, {'Х', "Kh"}, {'Ц', "Ts"},
        {'Ч', "Ch"}, {'Ш', "Sh"}, {'Щ', "Shch"},
        {'Ъ', ""},  {'Ы', "Y"}, {'Ь', ""},
        {'Э', "E"}, {'Ю', "Yu"}, {'Я', "Ya"}
    };

    string result;
    for (char c : text) {
        if (translitMap.find(c) != translitMap.end()) {
            result += translitMap[c];
        } else {
            result += c; 
        }
    }
    return result;
}

int main() {
    ifstream inputFile("input.txt"); 
    ofstream outputFile("output.txt"); 

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1; 
    }

    string line;
    while (getline(inputFile, line)) { 
        string translitdLine = translit(line); 
        outputFile << translitdLine << endl; 
    }

    inputFile.close(); 
    cout << "Transliteration finished! The result is saved in output.txt" << endl; 
    return 0;
}