/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

map<int, int> findOcurrences(vector<int>& v){
    map<int, int> m;
    for (auto it = v.begin(); it != v.end(); it++){
        if (m.find(*it) == m.end()){
            m[*it] = 1;
        }else{
            m[*it]++;
        }
    }
    return m;
}

int main(int argc, char** argv) {
    vector<int> v;
    
    v.push_back(10);
    v.push_back(20);
    v.push_back(10);v.push_back(10);
    v.push_back(20);v.push_back(30);v.push_back(40);
    v.push_back(30);v.push_back(50);
    
    
    map<int, int> m = findOcurrences(v);
    for (auto it = m.begin(); it != m.end(); it++){
        cout << it->first << " -> " << it->second << endl;
    }
    cout << endl;
    return 0;
}

