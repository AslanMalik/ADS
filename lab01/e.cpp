#include <iostream>
#include <deque>
using namespace std;
int main() {
    deque<int> Boris;
    deque<int> Nurik;

    for (int i = 0; i < 5; i++)
    {
        int n;
        cin >> n;
        Boris.push_back(n);
    }
    
    for (int i = 0; i < 5; i++)
    {
        int n;
        cin >> n;
        Nurik.push_back(n);
    }


    int count = 0;

    while (!Boris.empty() && !Nurik.empty())
    {
        int carta_borisa = Boris.front();
        int carta_nurika = Nurik.front();

        if (carta_borisa == 0 && carta_nurika == 9)
        {
            Boris.pop_front();
            Nurik.pop_front();
            Boris.push_back(carta_borisa);
            Boris.push_back(carta_nurika);
            count++;
        }
        else if (carta_borisa == 9 && carta_nurika == 0)
        {
            Boris.pop_front();
            Nurik.pop_front();
            Nurik.push_back(carta_borisa);
            Nurik.push_back(carta_nurika);
            count++;
        }
        
        else if (carta_borisa < carta_nurika)
        {
            Boris.pop_front();
            Nurik.pop_front();
            Nurik.push_back(carta_borisa);
            Nurik.push_back(carta_nurika);
            count++;
        }
        else if (carta_borisa > carta_nurika)
        {
            Boris.pop_front();
            Nurik.pop_front();
            Boris.push_back(carta_borisa);
            Boris.push_back(carta_nurika);
            count++;
        }


        if (count == 1000000)
        {
            cout << "blin nichya";
            return 0;
        }
    }


    if (Boris.empty())
    {
        cout << "Nursik " << count;
    }
    else
    {
        cout << "Boris " << count; 
    }
    
    
    

    return 0;
}