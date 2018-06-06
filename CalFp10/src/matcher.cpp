/*
 * matcher.cpp
 */
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

std::vector<int> prefix(std::string toSearch) {
    unsigned long m = toSearch.size();
    std::vector<int> p(m, 0);
    int k = 0;
    for (int q = 1; q < (int) m; q++) {
        while (k > 0 && toSearch[k] != toSearch[q])
            k = p[k - 1];

        if (toSearch[k] == toSearch[q])
            k++;
        p[q] = k;
    }
    return p;
}


int kmpMatcher(std::string text, std::string pattern) {
    unsigned long n = text.size();
    unsigned long m = pattern.size();
    std::vector<int> pi = prefix(pattern);
    int q = 0;
    int occurences = 0;
    for (int i = 0; i < n; ++i) {
        while (q > 0 && pattern[q] != text[i]){
            q = pi[q - 1];
        }
        if(pattern[q] == text[i]){
            q = q + 1;
        }
        if(q == m ){
            occurences++;
            q = pi[q - 1];
        }

    }
    return occurences;
}


int numStringMatching(std::string filename, std::string toSearch) {
    std::ifstream in(filename.c_str());
    if(!in.good()){
        std::cerr << "Error opening file\n";
        exit(-1);
    }
    std::string str;
    int n = 0;
    while(std::getline(in, str)){
        //std::cout << str << std::endl;
        n += kmpMatcher(str, toSearch);
    }
    in.close();
    return n;
}


unsigned long  editDistance(std::string pattern, std::string text) {
    unsigned long P = pattern.size();
    unsigned long T = text.size();
    std::vector< unsigned long  > matrix(T + 1, 0);

    for (unsigned long  j = 0; j < T + 1; ++j) {
        matrix.at(j) = j;
    }

    for (unsigned long  i = 1; i <= P; ++i) {
        unsigned long  old =  matrix.at(0);
        matrix.at(0) = i;
        for (unsigned long  j = 1; j <= T; ++j) {
            unsigned long  new_v;
            if(pattern.at(i - 1) == text.at(j - 1)) {
                new_v = old;
            }else {
                new_v = 1 + std::min(std::min(old, matrix[j]), matrix[j - 1]);
            }
            old = matrix[j];
            matrix[j] = new_v;
        }
    }
    return matrix.at(T);
}

float numApproximateStringMatching(std::string filename, std::string toSearch) {
    std::ifstream in(filename.c_str());
    if(!in.good()){
        std::cerr << "Error opening file\n";
        exit(-1);
    }
    std::string str;
    float sum = 0;
    int n = 0;
    while(in >> str){
        //std::cout << str << std::endl;
        sum += editDistance(str, toSearch);
        n++;
    }
    in.close();
    return sum/n;
}
