#include <iostream>
#include "HeapSort.h"

using namespace std;

ostream& operator<<(ostream& os, const HeapSort& array){
  for (int i = 0; i < array.length; i++) {
    os << array.items[i] << " ";
  }
  os << endl;
  return os;
}

int main() {
  // Untemplated queue of char
  // Templated heap
  using namespace std;
  int character;
  int* characters   = new int[100];
  int count = 0;

  cout << "Enter several numbers again; press return." << endl;
  cin >> character; 
  while (character != -1)
    {
      characters[count] = character;
      cin >> character;
      count++;
    }

  HeapSort heap(100, characters, count);

  cout << heap;
  heap.sort();
  cout << heap;
  
}
