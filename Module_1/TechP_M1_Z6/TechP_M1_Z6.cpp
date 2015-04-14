#include <iostream>

typedef int my_type;
const int SIZE_MAS = 8;

class My_Heap {
	private: 
	  size_t last;
	  size_t size;
	  my_type *array;
	  void siftDown(int);
	  void siftUp(int);
	  void increase();
	  void swapElem(my_type &first, my_type &second) {
	  	my_type tmp = first;
	  	first = second;
	  	second = tmp;
	  }
	public: 
	  My_Heap(): last(0), size(8), array(NULL) {
		  array = new my_type[size];
		}
	  ~My_Heap() {
	  	delete[] array;
	  }
	  My_Heap(size_t _size): last(0), size(_size) {
	  	if(size < 8) { 
	  	  size = 8;
	  	}
			array = new my_type[size];
	  }	
	  void Add(int);
	  my_type Max();
	  size_t Size() {
	  	return last;
	  }
	  size_t ShowMax() {
	  	if(last == 0) {
	  		return 0;
	  	}
	  	return array[0];
	  }
	  void Print() {
	  	for(int i = 0; i < last; ++i) {
	  		std::cout << array[i] << ' ';
	  	}
	  }
};


void My_Heap::siftDown(int index) {
	int left = 2 * index + 1,
      right = 2 * index + 2,
      largest = index;
  if((left < last) && (array[left] > array[largest])) {
  	largest = left;
  }
  if((right < last) && (array[right] > array[largest])) {
  	largest = right;
  }
  if(largest != index) {
  	swapElem(array[index], array[largest]);
  	siftDown(largest);
  }
}

void My_Heap::siftUp(int index) {
	while(index > 0) {
		int parent = (index - 1) / 2;
		if(array[index] > array[parent]){
			swapElem(array[index], array[parent]);
			index = parent;
		} else {
			return;
		}
	}
}

void My_Heap::increase() {
	size *= 2;
	my_type *tmp = new my_type[size];
	for(int i = 0; i < last; ++i) {
		tmp[i] = array[i];
	}
	delete[] array;
	array = tmp;
}

void My_Heap::Add(int elem) { 
  	if(last == 0) {
  		array[last++] = elem;
  		return;
  	}
  	if(last == size) {
  		increase();
  	}
  	array[last++] = elem;
  	siftUp(last - 1);
}

my_type My_Heap::Max() {
	if(last == 0) {
		return 0;
	}
	my_type max = array[0];
	--last;
	array[0] = array[last];
	siftDown(0);
	return max;
}

void growMas(my_type** mas, size_t& sizeMas) {
  size_t newSize = sizeMas * 2;
	my_type* tmpMas = new my_type[newSize];
	for(int i = 0; i < sizeMas; ++i) {
		tmpMas[i] = (*mas)[i];
	}
	delete[] (*mas);
	(*mas) = tmpMas;
	sizeMas = newSize;
}

int summ(my_type* mas,int last, int chislo) { 
	int summ = chislo;
	for(int i = 0; i < last; ++i) {
		summ += mas[i];
	}
	return summ;
}

int kolPodchodov(My_Heap& heap, int grz_pod) {
	size_t sizeMas = SIZE_MAS;
	my_type* mas = new my_type[sizeMas];
	int last = 0;
	int kol = 0;
	while(heap.ShowMax() != 0) {
	  mas[last++] = heap.Max();
		while((heap.ShowMax() != 0 ) && (summ(mas, last, heap.ShowMax()) <= grz_pod)) {
		  if(last == sizeMas) {
			  growMas(&mas, sizeMas);
		  }
		  mas[last++] = heap.Max();
		}
    for(int i = 0; i < last; ++i) {
			if(mas[i] != 1) {
				mas[i] /= 2;           // heap.Add(mas[i] / 2);
				heap.Add(mas[i]);
			}
		}
		kol++;
		last = 0;
	}
	delete[] mas;
	return kol;
}

int main() {
	/*size_t size;
	my_type elem;
	std::cin >> size;
	My_Heap heap(size);
	for(int i = 0; i < size; ++i) {
    std::cin >> elem;
    heap.Add(elem);
	}
	
	std::cout << std::endl;
	heap.Print();
	
	std::cout << std::endl;
	size = heap.Size();
	for(int i = 0; i < size; ++i) {
		elem = heap.Max();
		std::cout << elem << ' ';
	}*/
	size_t size;
	std::cin >> size;
	My_Heap heap(size);
	for(int i = 0; i < size; ++i) {
		int elem;
		std::cin >> elem;
		heap.Add(elem);
	}
	int grz_pod;
	std::cin >> grz_pod;
	int kol = kolPodchodov(heap, grz_pod);
	std::cout << kol;
	return 0;
}
