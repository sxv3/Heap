#include "Heap.h"
#include <fstream>

//heap c++ file
//created by Tai Wong
//Feb 19th

//heap constructor, makes empty heap
Heap::Heap() {
  size = 0;
}

//insert value into heap
void Heap::insert(int value) {
  if (size >= 100) {
    cout << "heap is full" << endl;
    return;
  }
  heap[++size] = value;
  heapUp(size);
}

//bubble up
void Heap::heapUp(int index) {
  while (index > 1 && heap[index] > heap[index / 2]) {
    swap(heap[index], heap[index / 2]); //swaps with parent
    index /= 2; //move up in tree
  }
}

//bubble down
void Heap::heapDown(int index) {
  while (index * 2 <= size) {
    int largest = index * 2; //left child
    
    if (largest + 1 <= size && heap[largest + 1] > heap[largest]) {
      largest++; //right child is larger
    }
	//if heap is built properly 
    if (heap[index] >= heap[largest]) {
      break; 
    }
    
    swap(heap[index], heap[largest]);
    index = largest;
  }
}
//remove root
void Heap::removeMax() {
  if (size == 0) {
    cout << "empty heap" << endl;
    return;
  }

  cout << heap[1] << " "; 
	//last element is root
  heap[1] = heap[size--];
	//restore heap
  heapDown(1);
}
//remove all elements
void Heap::removeAll() {
  while (size > 0) {
    removeMax();
  }
  cout << endl;
}

//recursive print function to show heap
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

//display heap
void Heap::printHeap() {
  utilPrint(1, 0);
}

//read file
void Heap::fileRead(const char* filename) {
  ifstream file(filename);
  int number;
  while (file >> number) {
    if (number >= 1 && number <= 1000) {
      insert(number); //insert into heap
    } else {
      cout << "bad number" << endl;
    }
  }

  file.close();
}
