#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Heap{
    public:

    vector<long long> a;
    long long sum_all = 0;

    int parent(int i) {
        return (i-1)/2;
    }

    int left(int i) {
        return (2*i + 1);
    }

    int right(int i) {
        return(2*i + 2);
    }


    long long getmin() {
        return a[0];
    }

    void insert(long long data) {
        a.push_back(data);
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

        if (right(i) < a.size()  && a[left(i)] > a[right(i)])
        {
            j = right(i);
        }

        if (a[j] < a[i])
        {
            swap(a[i], a[j]);
            heapify(j);
        }
    }


    void sum_child() {
        long long root = a[0];

        long long small_child;
        long long sum_local = 0;

        bool left_child = left(0) < a.size();
        bool right_child = right(0) < a.size();

        if(!left_child && !right_child) return;
        else if(left_child && !right_child) small_child = a[left(0)];
        else if(!left_child && right_child) small_child = a[right(0)];
        else
        {
            if(a[left(0)] > a[right(0)]) small_child = a[right(0)];
            else small_child = a[left(0)];
        }
        

        sum_local =  root + small_child;

        sum_all += sum_local;
        extractMin();
        extractMin();
        insert(sum_local);
    }

    

    void print(){
        while (a.size() > 1)
        {
            sum_child();
        }
        
        cout << sum_all << " ";        
    }



    void extractMin() {
        //int root = getmin();
        swap(a[0], a[a.size()-1]);
        a.pop_back();
        if (a.size() > 0)
        {
            heapify(0);
        }
        return;
    }
};


int main() {
    long long n, x; cin >> n;
    Heap *fun = new Heap();

    for (int i = 0; i < n; i++)
    {
        cin >> x; fun->insert(x);
    }

    fun->print();

    
    
    return 0;
}