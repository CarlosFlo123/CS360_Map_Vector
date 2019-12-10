/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: carlos
 *
 * Created on November 19, 2019, 7:40 PM
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void printMap(map<string, map<string, string> > & m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        string course = it->first;
        auto students = it-> second;
        cout << course << " => ";
        for (auto it2 = students.begin(); it2 != students.end(); it2++) {
            string student = it2-> first;
            string grade = it2-> second;
            cout << student << ";" << grade << " ,";
        }
        cout << endl;
    }
}

map<string, vector<string> > getBadStudents(map<string, map<string, string> > & m){
    map<string, vector<string> > m2;
    for (auto it = m.begin(); it != m.end(); it++) {
        string course = it->first;
        auto students = it-> second;
        for (auto it2 = students.begin(); it2 != students.end(); it2++) {
            string student = it2->first;
            string grade = it2-> second;
            if (grade == "F") {
                m2[student].push_back(course);
            }
        }

    }
    return m2;
}

int main() {
    map<string, map<string, string> > m;
    m["CS204"]["Ken"] = "P";
    m["CS204"]["Peter"] = "P";
    m["CS204"]["Nancy"] = "F";

    m["CS350"]["Ken"] = "P";
    m["CS350"]["Peter"] = "P";
    m["CS350"]["Judy"] = "F";
    m["CS350"]["Tom"] = "F";

    m["CS360"]["Ken"] = "P";
    m["CS360"]["Nancy"] = "F";
    m["CS360"]["Judy"] = "F";
    m["CS360"]["Tom"] = "F";

    m["CS480"]["Ken"] = "P";
    m["CS480"]["Peter"] = "P";
    m["CS480"]["Wendy"] = "F";
    m["CS480"]["Tom"] = "F";
    printMap(m);
    cout << endl;
    map<string, vector<string> > m2 = getBadStudents(m);
    for (auto it = m2.begin(); it != m2.end(); it++) {
        cout << it->first << " => ";
        for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
            cout << *it2 << ", ";
        }
        cout << endl;
    }
    return 0;

}