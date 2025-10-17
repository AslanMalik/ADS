#include <iostream>
#include <vector>
using namespace std; 


class MinHeap{
    public:

    vector<int> a;
    int parent(int i) {
        return (i-1)/2;
    }

    int left(int i) {
        return (2*i + 1);
    }

    int right(int i) {
        return (2*i + 2);
    }

    int getmin() {
        return a[0];
    }

    void insert(int k) {
        a.push_back(k);
        int ind = a.size()-1;

        while (ind > 0 && a[ind] <  a[parent(ind)])
        {
            swap(a[ind], a[parent(ind)]);
            ind = parent(ind);
        } 
    }


    void heapify(int i) {
        if (left(i) > a.size()-1) return;

        int j = left(i);

        if (right(i) < a.size() && a[right(i)] < a[left(i)])
        {
            j = right(i);
        }

        if (a[j] < a[i])
        {
            swap(a[i], a[j]);
            heapify(j);
        }
        
        
        
    }

    int extractmin() {
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
    MinHeap *heap = new MinHeap();
    int n, m, x; cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> x; heap->insert(x);
    }

    int cnt = 0;

    while (heap->a.size() > 1)
    {
        if (heap->a[0] >= m)
        {
            break;
        }
        
        int first = heap->extractmin();
        int second = heap->extractmin();

        int density = first + 2*second;
        heap->insert(density);
        cnt++;
    }
    
    if (heap->a.size() == 0 || heap->a[0] < m)
    {
        cout << -1;
        return 0;
    }
    
    cout << cnt;
    return 0;
}