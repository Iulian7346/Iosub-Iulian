#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
using namespace std;

class Element {
public:
    int value;
    std::string sir;

   
    Element() {};

    bool operator<( const Element& other) const {
        if (this->value != other.value) {
            return this->value < other.value;
        }
        else {
            return other.sir < this->sir;
        }
    }
};

int main()
{
	string subs;
    map<string, int> M;

    string s;

    ifstream fisier("fisier_input.txt");

    if (fisier.is_open())
    {
        getline(fisier, s);
    }


    int i, j;
    i = 0;

    while (i < s.size())
    {
        j = i;
        while (s[j] != ' ' && s[j] != '.' && s[j] != '?' && s[j] != '!' && s[j] != ','&& j<s.size())
            j++;
        j--;
        subs = s.substr(i, j-i+1);
        M[subs]++;
        i = j+1;
        while ( (s[i] == ' ' || s[i] == '.' || s[i] == '?' || s[j] == '!' || s[i] == ',') && (i < s.size()) )
            i++;
    }

    map<string, int>::iterator it;

    Element sir_in_queue;
    std::priority_queue<Element> coada;

    for (it = M.begin(); it != M.end(); it++)
    {
        sir_in_queue.value= it->second;
        sir_in_queue.sir = it->first;
        coada.push(sir_in_queue);

    }
    while (!coada.empty()) {
        cout << coada.top().value << ' '<< coada.top().sir << endl;
        coada.pop(); 
    }

    fisier.close();
    return 0;

}
