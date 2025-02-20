#include "Heap.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void processInput(Heap &heap) {
  char choice[8];

  cout << "manual or file input? (manual/file): ";
  cin >> choice;
  
  if (strcmp(choice, "file") == 0) {
    char filename[256];
    cout << "enter filename: ";
    cin >> filename;

    ifstream file(filename); 
    if (!file) {
      cout << "cannot find file " << filename << endl;
      return;
    }

    int number;
    while (file >> number) {
      if (number >= 1 && number <= 1000) {
	heap.insert(number);
      } else {
	cout << "bad number" << endl;
      }
    }

    file.close();
  } 
  else if (strcmp(choice, "manual") == 0) {
    cout << "enter space seperated numbers, you can end by ctrl-D or non number character" << endl;

    int number;
    while (cin >> number) {
      if (number >= 1 && number <= 1000) {
	heap.insert(number);
      } else {
	cout << "bad number" << endl;
      }
    }
  } else {
    cout << "invalid input" << endl;
  }
}

int main() {
    Heap heap;
    processInput(heap);

    cout << "heap representation\n";
    heap.printHeap();

    cout << "removing elements in order:\n";
    heap.removeAll();

    return 0;
}
