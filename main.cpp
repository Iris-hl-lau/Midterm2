#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <fstream>
#include <sstream>

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
    int sum = 0;
    int count = 0;
    for(auto i = first; i != last; i++) {
        sum += i;
        count++;
    }
    double avg = sum / count;

}


int main() {
    ifstream read_file;
    read_file.open("../studentMarks.txt");
    string read_person, person, val;
    myMap<string, int> map;


    //Read file into STL map
    while(getline(read_file, read_person)) {
        istringstream person_val(read_person);
        person_val >> person >> val;
        map.add(person, val);
    }

    return 0;
}