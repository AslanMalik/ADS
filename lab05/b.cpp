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

        if (right(i) < a.size()  && a[left(i)] < a[right(i)])
        {
            j = right(i);
        }

        if (a[j] > a[i])
        {
            swap(a[j], a[i]);
            heapify(j);
        }
    }

    void find_max() {
        while (a.size() > 1)
        {
            int first_number = extractMin();
            int second_number = extractMin();
            int dif = first_number - second_number;

            if (dif == 0)
            {
                continue;
            }
            else
            {
                insert(dif);
            }
        }
        
        if (a.size() == 1)
        {
            cout << a[0] << " ";
        }
        else
        {
            cout << 0 << " ";
        }
        
        


        
    }


    

    void print(){
        
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
                
    }



    int extractMin() {
        int root = getmin();
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
    long long n, x; cin >> n;
    Heap *fun = new Heap();

    for (int i = 0; i < n; i++)
    {
        cin >> x; fun->insert(x);
    }

    fun->find_max();

    
    
    return 0;
}