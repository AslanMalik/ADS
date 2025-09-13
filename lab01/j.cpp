#include <iostream>
#include <deque>
using namespace std;
int main() {

    deque<int> answer;

    string x;
    int all;
    while (cin >> x)
    {
        if (x == "+")
        {
            int k;
            cin >> k;
            answer.push_front(k);
        }
        else if (x == "-")
        {
            int k;
            cin >> k;
            answer.push_back(k);
        }
        else if(x == "*") {
            if(answer.size() > 1) {
                all = answer.front() + answer.back();
                answer.pop_front();
                answer.pop_back();
                cout << all << endl;
            }
            else if(answer.size() ==  1)
            {
                all = answer.front() * 2;
                answer.pop_front();
                cout << all << endl;
            }
            else if(answer.empty())
            {
                cout << "error" << endl;
            } 
        }
        else if(x == "!") {
            break;
        }
    }
    return 0;
}

