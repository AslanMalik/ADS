#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    int n; cin >> n;
    map<string, string> steam;


    for (int i = 0; i < n; i++)
    {
        string qart, zhana;
        cin >> qart >> zhana;
        
        if (steam.size() == 0)
        {
            steam[qart] = zhana;
        }

        else
        {
            bool flag = false;

            map<string, string>::iterator it;
            for (it = steam.begin(); it != steam.end(); it++)
            {
                if (it->second == qart)
                {
                    flag = true;
                    steam[it->first] = zhana;
                }
            }

            if (flag == false)
            {
                steam[qart] = zhana;
            }
            
        }
                
    }

    map<string, string>::iterator it;

    cout << steam.size() << endl;
    for ( it = steam.begin(); it != steam.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    
    
    return 0;
}