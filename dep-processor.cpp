/*
dependency calculator.

includes cycle detector.

input file:

a b
a c
a d
b d
b e
c d
e a


some code kyped from StackOverflow.
*/
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

template<typename T>
bool in_vec(vector<T> vec, T item) {
   return std::find(vec.begin(), vec.end(), item) != vec.end();
}


void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

void dfs(map<char, string> graph, char node, vector<char> seens, int depth) {
   if (! graph.count(node)) {
      return;
   }
   else {
      for (int j = 0; j < depth; j++) {
         cout << ' ';
      }

      cout << node << endl;
      if (in_vec(seens, node)) {
         cout << "CYCLE" << endl;
         return;
      }
      seens.push_back(node);
   }

   for (int i = 0; i < graph[node].length(); i++) {
      char c = graph[node][i];
      dfs(graph, c, seens, depth + 1);
   }

}

void dfs(map<char, string> graph) {
   for (map<char,string>::iterator it = graph.begin();
        it != graph.end();
        ++it) {
      vector<char> seens;
      dfs(graph, it->first, seens, 1);
   }
}

int main() {
   ifstream f("deps.dat");
   string temp;
   map<char, string> deps;
   while(getline(f, temp)) {
      vector<string> vec = split(temp, ' ');
      if (deps.count(vec[0][0]) == 0) {
         deps[vec[0][0]] = vec[1];
      }
      else {
         deps[vec[0][0]] += vec[1];
      }
   }
   dfs(deps);
}
