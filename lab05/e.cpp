#include <iostream>
#include <vector>
using namespace std;

long long sum_all = 0;


class MinHeap{
    public:

    vector<int> a;
    int parent(int i) {
        return (i-1)/2;
    }

    int left(int i) {
        return 2*i +1;
    }

    int right(int i) {
        return 2*i + 2;
    }

    int getmin() {
        return a[0];
    }

    void insert(int k) {
        a.push_back(k);
        int ind = a.size()-1;

        while (ind > 0 && a[ind] < a[parent(ind)])
        {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        }
    }

    void heapify(int i) {
        if (left(i) > a.size()-1)
        {
            return;
        }

        int j = left(i);

        if (right(i) < a.size() && a[right(i)] < a[left(i)])
        {
            j = right(i);
        }

        if (a[j] < a[i])
        {
            swap(a[j], a[i]);
            heapify(j);
        }
                
    }

    int exactmin() {
        int root = a[0];
        swap(a[0], a[a.size()-1]);

        a.pop_back();
        if (a.size() > 0)
        {
            heapify(0);
        }
        return root;
        
    }
};


int main() {

    MinHeap* heap = new MinHeap();
    int q, k; cin >> q >> k;
    while (q--)
    {
        string query; cin >> query;

        if (query == "print")
        {
            cout << sum_all << endl;
        }
        else
        {
            int number; cin >> number;
            if (heap->a.size() < k)
            {
                heap->insert(number);
                sum_all += number;
            }
            else
            {
                if (heap->getmin() < number)
                {
                    int del = heap->exactmin();
                    sum_all -= del;
                    sum_all += number;
                    heap->insert(number);
                }
                
            }
            
            
        }
        
    }
    
    return 0;
}