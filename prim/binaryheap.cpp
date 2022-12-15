#include <iostream>
#include <vector>

using namespace std;

typedef struct minheap
{
    vector<int> heap;
    int size = 0;
} minheap;

int insert(minheap &heap, int k);
int parent(int i);
int leftChild(int i);
int rightChild(int i);
int extract_min(minheap &heap); 

int main() {

    
    // Shape property
    // Value property 
    /*
    Cada camada da árvore vai conseguir alocar 2^x; 
    Para a primeira camada (0): 1 elemento
    Para a segunda camada (1): 2 elementos
    E assim por diante 
    
    Para acessar nosso nó pai:
    Ex: nó 2
    index - 1 / 2 => 2 - 1 / 2 = 1 / 2 = 0.xxx
    Ex: nó 5
    5 - 1 / 2 = 4 / 2 = 2

    Para acessar o filho da esquerda: 
    Ex: filhos do nó 1
    2 * index + 1 => 2 * 1 + 1
    Ex: filhos do nó 2
    2 * 2 + 1 = 4 + 1 = 5

    Para acessar o filho da esquerda:
    2 * index + 2
    */

    minheap heap; 
    insert(heap, 3);
    insert(heap, 2);
    insert(heap, 10);
    insert(heap, 4);
    insert(heap, 13);
    insert(heap, 243);
    insert(heap, 35);
    insert(heap, 22);
    insert(heap, 1);
    insert(heap, 234);
    insert(heap, 100);
    insert(heap, 23);

    int i = extract_min(heap);
    cout << i;

}

int parent(int i) {
    return (i - 1)/2;
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2; 
}

void swap(minheap &heap, int i, int j) {
    int aux = heap.heap[i];
    heap.heap[i] = heap.heap[j];
    heap.heap[j] = aux; 
}

int insert(minheap &heap, int k) {
    heap.size++; 

    int i = heap.size - 1; 
    heap.heap.push_back(k);

    while (i != 0 && heap.heap[parent(i)] > heap.heap[i]) {
        swap(heap, heap.heap[parent(i)], heap.heap[i]);
        i = parent(i);
    }
}

int fix(minheap &heap, int i) {
    int l = leftChild(i);
    int r = rightChild(i);
    int size = heap.size;
    int smallest = i; 

    if ((l < size) && (heap.heap[l] < heap.heap[smallest])) {
        smallest = l;
    }
    if ((r < size) && (heap.heap[r] < heap.heap[smallest])) {
        smallest = r;
    }

    if (smallest != i) {
        swap(heap, heap.heap[i], heap.heap[smallest]);
        fix(heap, i);
    }

}

int extract_min(minheap &heap) {
    if (heap.size == 0) {
        return -1; 
    } else if (heap.size == 1) {
        heap.size--; 
        return heap.heap[0];
    } else {
        int root = heap.heap[0];
        heap.heap[0] = heap.heap[heap.size - 1];
        heap.size--;
        fix(heap, 0);

        return root; 
    }
};