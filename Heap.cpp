#include "Heap.h"
#include <fstream>

Heap::Heap() {
  size = 0;
}

void Head::insert(int value) {
  if (size >= 100) {
    cout << "heap is full" << endl;
    return;
  }
  heap[++size] = value;
  heapUp(size);
}

void Heap::heapUp(int index) {
  while (index > 1 && heap[index] > heap[index / 2]) {
    swap(heap[index], heap[index / 2]);
    index /= 2;
  }
}

void Heap::heapDown(int index) {
  while (index * 2 <= size) {
    int largest = index * 2;
    
    if (largest + 1 <= size && heap[largest + 1] > heap[largest]) {
      largest++;
    }
	
    if (heap[index] >= heap[largest]) {
      break;
    }
    
    swap(heap[index], heap[largest]);
    index = largest;
  }
}

void Heap::removeMax() {
  if (size == 0) {
    cout << "empty heap" << endl;
    return;
  }

  cout << heap[1] << " "; 
  heap[1] = heap[size--];
  heapDown(1);
}

void Heap::removeAll() {
  while (size > 0) {
    removeMax();
  }
  cout << endl;
}

void Heap::utilPrint(int index, int depth) {
  if (index > size) {
    return;
  }

  utilPrint(index * 2 + 1, depth + 1);

  for (int i = 0; i < depth; i++) {
    cout << "\t";
  }
  
  cout << heap[index] << endl;
  utilPrint(index * 2, depth + 1);
}

void Heap::printHeap() {
  utilPrint(1, 0);
}

void Heap::fileRead(const char* filename) {
  ifstream file(filename);
  int number;
  while (file >> number) {
    if (number >= 1 && number <= 1000) {
      insert(number);
    } else {
      cout << "bad number" << endl;
    }
  }

  file.close();
}
