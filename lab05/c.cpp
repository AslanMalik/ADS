#include <iostream>
#include <vector>
using namespace std;

long long total_sum = 0;


class MaxHeap{
    public:

    vector<int> a;

    int parent(int i) {
        return (i-1)/2;
    }

    int left(int i) {
        return 2*i + 1;
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

        while (ind > 0 && a[ind] > a[parent(ind)])
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

        if (right(i) < a.size() && a[right(i)] > a[left(i)])
        {
            j = right(i);
        }

        if (a[j] > a[i])
        {
            swap(a[j], a[i]);
            heapify(j);
        }
        
        
        
    }

    int ExtractMin() {
        int root = a[0];
        swap(a[0], a[a.size()-1]);
        a.pop_back();

        if (a.size() > 1)
        {
            heapify(0);
        }
        return root;
        
        
    }

    void print() {
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        
    }



};


int main() {

    MaxHeap *heap = new MaxHeap();

    int n, c, x; cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        cin >> x; heap->insert(x);
    }
    
    while (c--)
    {
        int number = heap->ExtractMin();
        total_sum += number;
        number--;
        if (number > 0)
        {
            heap->insert(number);
        }
        
        //heap->insert(number);
    }
    

    cout << total_sum;

    return 0;
}