#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

template<typename K = string, typename V = int>
class myMap{
private:
    map<K, V> my_map;
public:
    void add(K key, V value) {
        while(my_map.find(key)) {
            cout << "Enter new key." << endl;
            cin >> key;
        }
        my_map.insert(make_pair(key, value));
        my_map.sort();
    }
    pair<K, V> operator[] (int index) const {
        return my_map[index];
    }

    V operator[] (K key) {
        return my_map.find(key)->second;
    }

    friend ostream& operator<< (ostream& os, const myMap& my_map) {
        for(auto it = my_map.begin(); it != my_map.end(); it++) {
            os << it->first << " " << it->second << endl;
        }
        return os;
    }
};

template <typename InputIterator>
auto standardDeviation(InputIterator first, InputIterator last) {
    auto iter  = distance(first, last);
    //double average = accumulate(begin, end, 0) / iter;
    //auto term = [average]

}


int main() {
    ifstream read_file;
    read_file.open("../studentMarks.txt");
    string read_person, person, val;
    myMap<string, int> map;

    while(getline(read_file, read_person)) {
        istringstream person_val(read_person);
        person_val >> person >> val;
        int
        map.add(person, Integer.valueOf(val));
    }

    return 0;
}