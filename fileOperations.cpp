#include <iostream>
#include <string>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <gtest/gtest.h>
#include <fstream>
#include <sstream>

using namespace curlpp::options;
using namespace std;

int isFilePresent(const char* fileName) {
    ifstream file;
    file.open(fileName);
    if (file)
        return 1;
    else
        return 0;
}

int createFileAndWriteData(const char* fileName, string data) {
    fstream my_file;
	my_file.open(fileName, ios::out);
	if (!my_file) {
		cout << "File not created!";
        return 0;
	}
	else {
		cout << "File created successfully!";
		my_file << data;
		my_file.close();
        return 1;
	}
}

int openFileAndAppendData(const char* fileName, string data) {
    fstream file;
    file.open(fileName, ios::app);
    if (!file) {
        cout << "No such file found";
        return 0;
    } else {
        file << data;
        cout << "Data appended successfully\n";
        file.close();
        return 1;
    }
}

string readData(const char* fileName) {
    ifstream file;
    file.open(fileName);
    if (file) {
        stringstream strStream;
        strStream << file.rdbuf();
        return strStream.str();
    } else {
        cout << "Error: File does not exists";
        return "";
    }
}

int searchText(const char* fileName, string search) {
    fstream Myfile;
    Myfile.open(fileName, ios::in|ios::out);
    string currentLine = "";
    int lineNumber = 1;
    bool isFound = false;
    if(Myfile.is_open()) {
        while(getline(Myfile, currentLine))
            if (currentLine.find(search) != std::string::npos) {
                isFound = true;
                cout << "Found on this line number: \n" << lineNumber << endl;
                return lineNumber;
            }
            lineNumber++;
            return lineNumber;
    } else {
        cout << "Unable to open file\n";
        return 0;
    }
    if(!isFound) {
        cout << search << " not found\n";
        return 0;
    }
    return 0;
}
