#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>

using namespace std;
using quantity_of_chars = pair<char, int>;
auto compare = [](quantity_of_chars v1, quantity_of_chars v2){
        return v1.second > v2.second;
    };

void CountOfCharacters(string, vector<quantity_of_chars>&);
void Coding(map<char, char>&, const vector<quantity_of_chars>&, const vector<quantity_of_chars>&);

int main() {
    int cases;
    string to_ignore;
    vector<string> result;
    cin >> cases; cin.ignore();
    getline(cin, to_ignore);


    for(int i = 0; i < cases; ++i){
        vector<quantity_of_chars> v_encode, v_not_encode;
        map<char, char> code;
        string encode, not_encode, answer = "";
        cin >> not_encode; cin.ignore();
        cin >> encode; cin.ignore();
        getline(cin, to_ignore);
        
        CountOfCharacters(not_encode, v_not_encode);
        CountOfCharacters(encode, v_encode);

        Coding(code, v_encode, v_not_encode);

        for(auto i : encode){
            auto search = code.find(i);
            if(search != code.end())
                answer += search->second;
            else
                break;
        }

        result.push_back(answer);
    }

    for(int i = 0; i < cases-1; ++i)
        cout << result[i] << endl << endl;
    
    cout << result[cases-1] << endl;

    return 0;
}

void CountOfCharacters(string line, vector<quantity_of_chars>& v){
    unordered_map<char, int> temp;
    for(auto const& i : line) 
        temp[i]++;
    
    for(auto const& i : temp)
        v.push_back(i);
    
    sort(v.begin(), v.end(), compare);
}

void Coding(map<char, char>& code, const vector<quantity_of_chars>& v1, const vector<quantity_of_chars>& v2){
    for(auto it1 = v1.begin(), it2 = v2.begin(); it1 != v1.end(), it2 != v2.end(); ++it1, ++ it2)
        code[(it1->first)] = it2->first;
}
