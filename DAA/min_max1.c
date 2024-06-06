#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a heap
struct Heap {
    int* array;
    int capacity;
    int size;
    int isMinHeap;  // Flag to indicate whether it's a min-heap (1) or max-heap (0)
};

// Function to create a new heap
struct Heap* createHeap(int capacity, int isMinHeap) {
    struct Heap* heap = (struct Heap*)malloc(sizeof(struct Heap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->isMinHeap = isMinHeap;
    heap->array = (int*)malloc(capacity * sizeof(int));
    return heap;
}

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted with the given index
void heapify(struct Heap* heap, int i) {
    int extreme = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < heap->size &&
        ((heap->isMinHeap && heap->array[left] < heap->array[extreme]) ||
         (!heap->isMinHeap && heap->array[left] > heap->array[extreme])))
        extreme = left;

    // Check right child
    if (right < heap->size &&
        ((heap->isMinHeap && heap->array[right] < heap->array[extreme]) ||
         (!heap->isMinHeap && heap->array[right] > heap->array[extreme])))
        extreme = right;

    // If extreme is not the root
    if (extreme != i) {
        swap(&heap->array[i], &heap->array[extreme]);
        heapify(heap, extreme);
    }
}

// Function to insert a new key to the heap
void insertKey(struct Heap* heap, int key) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow\n");
        return;
    }

    // Insert the new key at the end
    int i = heap->size++;
    heap->array[i] = key;

    // Fix the heap property
    while (i != 0) {
        int parent = (i - 1) / 2;
        if ((heap->isMinHeap && heap->array[i] < heap->array[parent]) ||
            (!heap->isMinHeap && heap->array[i] > heap->array[parent])) {
            swap(&heap->array[i], &heap->array[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

// Function to extract the extreme value (min or max) from the heap
int extractExtreme(struct Heap* heap) {
    if (heap->size <= 0)
        return heap->isMinHeap ? INT_MAX : INT_MIN;

    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    // Store the extreme value and remove it from the heap
    int extreme = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    heapify(heap, 0);

    return extreme;
}

// Function to display the heap
void displayHeap(struct Heap* heap) {
    printf(heap->isMinHeap ? "Min Heap: " : "Max Heap: ");
    for (int i = 0; i < heap->size; i++)
        printf("%d ", heap->array[i]);
    printf("\n");
}

// Example usage
int main() {
    // Create a min heap
    struct Heap* minHeap = createHeap(10, 1);

    // Insert elements into the min heap
    insertKey(minHeap, 3);
    insertKey(minHeap, 2);
    insertKey(minHeap, 1);
    insertKey(minHeap, 15);
    insertKey(minHeap, 5);

    // Display the min heap
    displayHeap(minHeap);

    // Extract the minimum element
    printf("Extract Min: %d\n", extractExtreme(minHeap));

    // Display the min heap after extraction
    displayHeap(minHeap);

    // Create a max heap
    struct Heap* maxHeap = createHeap(10, 0);

    // Insert elements into the max heap
    insertKey(maxHeap, 3);
    insertKey(maxHeap, 2);
    insertKey(maxHeap, 1);
    insertKey(maxHeap, 15);
    insertKey(maxHeap, 5);

    // Display the max heap
    displayHeap(maxHeap);

    // Extract the maximum element
    printf("Extract Max: %d\n", extractExtreme(maxHeap));

    // Display the max heap after extraction
    displayHeap(maxHeap);

    return 0;
}
