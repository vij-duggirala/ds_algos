#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;
    public:
        MinHeap(int cap)
        {
            heap_size=0;
            capacity=cap;
            harr = new int[cap];
        }

        int parent(int i)
        {
            return (i-1)/2;
        }

        void insert(int key)
        {
            heap_size++;
            int i= heap_size-1;
            harr[i] = key;

            while(i!=0 && harr[parent(i)]>harr[i])
            {
                swap(&harr[i], &harr[parent(i)]);
                i=parent(i);
            }
        }

        int extractMin()
        {
            if(heap_size==1)
            {
                    heap_size=0;
                    return harr[0];
            }

            int root = harr[0];
            harr[0]=harr[heap_size-1];
            heap_size--;
            MinHeapify(0);
            return root;
        }


        void MinHeapify(int i)
        {
            int l = 2*i+1;
            int r = 2*i +2;
            int smallest = i;

            if(l<heap_size && harr[l]<harr[smallest])
                smallest=l;
            
            if(r<heap_size && harr[r]<harr[smallest])
                smallest=r;

            if(smallest!=i)
            {
                swap(&harr[i], &harr[smallest]);
                MinHeapify(smallest);
            }
        }

};



int main()
{
    MinHeap m(10);
    m.insert(10);
    m.insert(12);
    m.insert(14);
    m.insert(3);
    cout<<m.extractMin();
    cout<<"\n"<<m.extractMin();

    
}

