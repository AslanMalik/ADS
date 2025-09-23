#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        numbers.push_back(t);
    }

    int l, m;
    cin >> l >> m;

    vector<vector<int>> snake(l, vector<int>(m));
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            cin >> snake[i][j];
        }
    }

    for (int j = 0; j < numbers.size(); j++) {
        int target = numbers[j];
        bool found = false;

        for (int j = 0; j < l && !found; j++) {
            int left = 0, right = m - 1;

            if (j % 2 == 1) { 
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (snake[j][mid] == target) {
                        cout << j << " " << mid << endl;
                        found = true;
                        break;
                    } else if (snake[j][mid] < target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            } else { 
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (snake[j][mid] == target) {
                        cout << j << " " << mid << endl;
                        found = true;
                        break;
                    } else if (snake[j][mid] < target) {
                        // 
                        right = mid - 1;
                    } else {
                        // 
                        left = mid + 1;
                    }
                }
            }

        }
        if(found == false) {
            cout << -1 << endl;
        }
        
    }

    return 0;
}
