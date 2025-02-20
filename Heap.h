#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

//header file for the Heap class (manages the heap)
//by Tai Wong, Feb 19th

using namespace std;

//class definition
class Heap {
private:
//creates heap with max size of 100
  int heap[101];
  int size = 0;

  void heapUp(int index); // restore heap after insert
  void heapDown(int index); //restore heap after delete
  void utilPrint(int index, int depth); //print out heap

public:
  Heap(); // constructor
  void insert(int value); //inser value to heap
  void removeMax(); //remove the root element
  void removeAll(); //remove all elements
  void printHeap(); // print heap

  void fileRead(const char* filename); //read in file
  
};

#endif
