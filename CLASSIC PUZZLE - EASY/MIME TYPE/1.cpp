#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, string pattern) {
    string::size_type pos;
    vector<string> result;

    int size = str.size();

    for (int i = 0; i < size; ++i) {
        pos = str.find(pattern, i);
        if (pos != string::npos) {
            string s = str.substr(i, pos - 1);
            result.push_back(s);
            i = pos + pattern.size() - 1;
        } else {
            string s = str.substr(i, str.size() - 1);
            result.push_back(s);
            break;
        }
    }

    return result;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
    int N; // Number of elements which make up the association table.
    cin >> N;
    cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q;
    cin.ignore();
    map<string, string> myMap;

    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT;  // MIME type.
        cin >> EXT >> MT;
        cin.ignore();
        transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
        myMap[EXT] = MT;
    }

    for (int i = 0; i < Q; i++) {
        string FNAME;
        getline(cin, FNAME); // One file name per line.
        transform(FNAME.begin(), FNAME.end(), FNAME.begin(), ::tolower);

        if (FNAME.find(".") == string::npos || FNAME.rfind(".") == FNAME.size() - 1) {
            cout << "UNKNOWN" << endl;
            continue;
        }

        vector<string> splits = split(FNAME, ".");
        bool flag = false;
        for (auto element : splits) {
            if (myMap.find(element) != myMap.end()) {
                cout << myMap[element] << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "UNKNOWN" << endl;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
}