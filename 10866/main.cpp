#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    enum Command { PUSH_FRONT=0, PUSH_BACK, POP_FRONT, POP_BACK, SIZE, EMPTY, FRONT, BACK};
    string command_line[8]={"push_front","push_back","pop_front","pop_back","size","empty","front","back"};

    deque <int > List;

    int N;

    cin >> N;

    for(int j=0; j<N; j++) {
        //cout << j << "/" << N << ":";
        Command command_cur;

        string command_cur_line;
        cin >> command_cur_line;

        for(int i=0; i<8; i++) {
            if(command_cur_line.compare(command_line[i]) == 0) {
                command_cur=(Command) i;
                break;
            }
        }
        switch(command_cur) {
        case PUSH_FRONT : {
            int temp;
            cin >> temp;
            List.push_front(temp);
            break;
        }
        case POP_FRONT : {
            int res;
            if(List.empty()) {
                res=-1;
            }
            else {
                res=List.front();
                List.pop_front();
            }
            cout << res << endl;
            break;
        }
        case PUSH_BACK : {
            int temp;
            cin >> temp;
            List.push_back(temp);
            break;
        }
        case POP_BACK : {
            int res;
            if(List.empty()) {
                res=-1;
            }
            else {
                res=List.back();
                List.pop_back();
            }
            cout << res << endl;
            break;
        }
        case SIZE : {
            cout << List.size() << endl;
            break;
        }
        case EMPTY : {
            cout << (List.empty()?1:0) << endl;
            break;
        }
        case FRONT : {
            int res;
            if(List.empty()) {
                res=-1;
            }
            else {
                res=List.front();
            }
            cout << res << endl;
            break;
        }
        case BACK : {
            int res;
            if(List.empty()) {
                res=-1;
            }
            else {
                res=List.back();
            }
            cout << res << endl;
            break;
        }
        default : {
            cout << "NO COMMAND" << endl; break;
        }
        }
    }

    return 0;
}
