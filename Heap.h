#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Heap {
private:
  int heap[101];
  int size = 0;

  void heapUp(int index);
  void heapDown(int index);
  void utilPrint(int index, int depth);

public:
  Heap();
  void insert(int value);
  void removeMax();
  void removeAll();
  void printHeap();

  void fileRead(const char* filename);
  
}

#endif HEAP_H
