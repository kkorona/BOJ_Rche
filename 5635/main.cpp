#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class stud {
public :
    string name;
    int dd,mm,yyyy;

    bool operator < (const stud& temp) const {
        if(yyyy != temp.yyyy) return yyyy > temp.yyyy;
        if(mm != temp.mm) return mm > temp.mm;
        if(dd != temp.dd) return dd > temp.dd;
    }
};

int main()
{
    int N;
    cin >> N;
    vector <stud > students;

    for(int i=0; i<N; i++) {
        stud temp;
        cin >> temp.name >> temp.dd >> temp.mm >> temp.yyyy;
        students.push_back(temp);
    }

    sort(students.begin(),students.end());

    cout << students[0].name << endl << students[students.size()-1].name;
    return 0;
}
