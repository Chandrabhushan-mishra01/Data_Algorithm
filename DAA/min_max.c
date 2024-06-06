#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Heap {
    int* array;
    int capacity;
    int size;
};

struct Heap* createHeap(int capacity) {
    struct Heap* heap = (struct Heap*)malloc(sizeof(struct Heap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(struct Heap* heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->array[left] < heap->array[smallest])
        smallest = left;

    if (right < heap->size && heap->array[right] < heap->array[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}


void insertKey(struct Heap* heap, int key) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow\n");
        return;
    }

   
    int i = heap->size++;
    heap->array[i] = key;

    
    while (i != 0 && heap->array[(i - 1) / 2] > heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


int extractMin(struct Heap* heap) {
    if (heap->size <= 0){

        return INT_MAX;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    
    int root = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    heapify(heap, 0);

    return root;
}


void displayHeap(struct Heap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->array[i]);
    printf("\n");
}


int main() {
    struct Heap* minHeap = createHeap(10);

    insertKey(minHeap, 3);
    insertKey(minHeap, 2);
    insertKey(minHeap, 1);
    insertKey(minHeap, 15);
    insertKey(minHeap, 5);

    displayHeap(minHeap);

    printf("Extract Min: %d\n", extractMin(minHeap));

    displayHeap(minHeap);

    return 0;
}
