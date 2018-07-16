#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

class Dict {
public :
    string str;
    int str_size;

    bool operator < (const Dict& temp) const {
        if(temp.str_size != str_size) return temp.str_size > str_size;
        else if(temp.str.compare(str) != 0) return temp.str.compare(str) > 0;
        else return true;
    }
};

int main()
{
    int N;

    set <Dict > List;

    cin >> N;

    for(int i=0; i<N; i++) {
        Dict temp;
        cin >> temp.str;
        temp.str_size=temp.str.size();
        List.insert(temp);
    }

    string previous("");

    for(set <Dict >::iterator it=List.begin(); it != List.end(); it++) {
        if(previous != (*it).str)
            cout << (*it).str << endl;
        previous=(*it).str;
    }

    return 0;
}
