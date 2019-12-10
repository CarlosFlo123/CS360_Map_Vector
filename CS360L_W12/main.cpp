/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: carlos
 *
 * Created on November 19, 2019, 7:25 PM
 */

#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
map<string, double> getAverageScores (map<string, map<string, int> >& m){
    map<string, vector<int> > m2;
    for (auto it = m.begin(); it != m.end(); it++){
        //string course = it->first;
        auto student = it->second;
        //cout << course << " => ";
        for (auto it2 = student.begin(); it2 != student.end(); it2++){
            string stu = it2->first;
            int score = it2->second;
            m2[stu].push_back(score);
        }
    }
    map<string, double> m3;
    for (auto it = m2.begin(); it != m2. end(); it++){
        string stu= it->first;
        auto scores = it->second;
        int sum = 0;
        for (auto it2 = scores.begin(); it2 != scores.end(); it2++){
            sum += *it2;
        }
        double average = (double) sum / scores.size();
        m3[stu] = average;
    }
    return m3;
}

void printMap(map<string, map<string, int> >& m){
    for (auto it = m.begin(); it!= m.end(); it++){
        string course = it-> first;
        auto students = it-> second;
        cout << course << " => ";
        for (auto it2 = students.begin(); it2 != students.end(); it2++){
            string student = it2-> first;
            int score = it2->second;
            cout << student << ": " << score << ", ";
        }
        cout << endl;
    }
}
int main(int argc, char** argv) {
    map<string, map<string, int> > m;
    m["CS204"]["Ken"] = 10;
    m["CS204"]["Peter"] = 10;
    m["CS204"]["Nancy"] = 7;
    
    m["CS350"]["Ken"] = 10;
    m["CS350"]["Peter"] = 9;
    m["CS350"]["Judy"] = 5;
    m["CS350"]["Tom"] = 8;

    m["CS360"]["Ken"] = 10;
    m["CS360"]["Nancy"] = 8;
    m["CS360"]["Judy"] = 6;
    m["CS360"]["Tom"] = 9;
    
    m["CS480"]["Ken"] = 10;
    m["CS480"]["Peter"] = 8;
    m["CS480"]["Wendy"] = 4;
    m["CS480"]["Tom"] = 10;
    
    printMap(m);
    
    
    map<string, double> m2 = getAverageScores(m);
    cout << fixed << setprecision(1);
    for (auto it = m2.begin(); it != m2.end(); it++){
        cout << it->first << "->" << it->second << endl;
    }
    return 0;
}

