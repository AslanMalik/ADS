#include <iostream>
#include <vector>
using namespace std;


char binarySearch(vector<char> arr, char letter) {
    int left = 0, right = arr.size()-1;
    char find_letter = 'A';


    while (left <= right)
    {
        int mid = left + (right-left)/2;

        if(letter < arr[mid]) {
            right = mid - 1;
            find_letter = arr[mid];
        }
        else
        {
            left = mid + 1;
        }
    }

    return find_letter;
    


}


int main() {
    int n; cin >> n;

    vector<char> arr;
    for (int i = 0; i < n; i++)
    {
        char ch; cin >> ch; arr.push_back(ch);                     
    }

    char ch; cin >> ch;

    char answer = binarySearch(arr, ch);

    if (answer == 'A')
    {
        cout << arr[0];
    }
    else
    {
        cout << answer;
    }
    
    
    

    return 0; 
}