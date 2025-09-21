#include <iostream>
#include <cmath>
#include <vector>
#include<algorithm>
using namespace std;




int main() {

    float number, flight;
    cin >> number >> flight;
    vector<float> island;

    for (float i = 0; i < number; i++)
    {
        float n;
        cin >> n;
        island.push_back(n);
    }

    sort(island.begin(), island.end());

    int max_number = island[island.size()-1];

    vector<float> min_capacity;


    int left = 1, right = max_number;

    while (left <= right)
    {
        int mid = left + (right-left)/2;

        float count = 0;

        for (int i = 0; i < island.size(); i++)
        {
            count += ceil(island[i]/mid);
        }
        
        if (count <= flight)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
        


        
        
    }
    


    

    cout << left;

    return 0;
}