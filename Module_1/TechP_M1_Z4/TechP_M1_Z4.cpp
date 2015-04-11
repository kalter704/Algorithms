#include <iostream>

struct DQueue_L {
  private:
    int *mas;
    int first, last;
    int sizeBuffer;
    
    bool isEmpty() const;
    bool isFull() const;
    void increaseMas();
     
  public:
    DQueue_L( int n ):
      first( 0 ),
      last( 0 ), 
      sizeBuffer( n ) 
    {
      mas = new int[sizeBuffer];
    }
    ~DQueue_L() { delete[] mas; }
    int popFront();
    void pushBack( int );     
};

bool DQueue_L::isEmpty() const {
  return ( first == last );
}

bool DQueue_L::isFull() const {
  return ( ( ( last + 1) % sizeBuffer) == first );
}

void DQueue_L::increaseMas() {
  int lastSize = sizeBuffer;
  sizeBuffer *= 2;
  int *tempMas = new int[sizeBuffer];
  int count = 0,
      i = first;
  while( i != last ){
    tempMas[count] = mas[i];
    i++;
    if( i == lastSize ) i = 0;
    count++;
  }
  delete[] mas;
  first = 0;
  last = count;
  mas = tempMas;
}

int DQueue_L::popFront() {
  if( isEmpty() ) { return -1; }
  int result = mas[first];
  first++;
  if( first == sizeBuffer) { first = 0; }
  return result;
}

void DQueue_L::pushBack( int n ) {
  if( isFull() ) { increaseMas(); }
  mas[last++] = n;
  if( last == sizeBuffer ) { last = 0; }
}

int main() {
  DQueue_L queue1( 5 );
  int a, b, n;
  bool expectation = true;
  std::cin >> n;
  int i = 0;
  while( ( i < n ) &&  ( expectation == true) ) {
    std::cin >> a >> b;
    switch( a ) {
      case 3:
        queue1.pushBack( b );
        break;
      case 2: 
        if( b != queue1.popFront() ) { expectation = false; }
        break;
    }
    i++;
  }
  if( expectation == true ) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
  return 0;
}
