#include <cstdio>
//#include <iostream>
#include <iterator>

bool less(const int &lhs, const int &rhs) {
	return lhs > rhs;
}

template <typename data_t>
void swap(data_t* &lhs, data_t* &rhs) {
  data_t* temp = lhs;
  lhs = rhs;
  rhs = temp;
}


// надобы убрать data_v
template <typename data_t,/*typename data_v,*/ typename less_t>
void heap_insert(data_t **heap, size_t n, data_t *elem, less_t &less) {
  heap[n] = elem;
  for(size_t i = n; i > 0; i = (i - 1) / 2) {
    if(less(*(heap[(i - 1) / 2]), *(heap[i]))) {
      swap(heap[i], heap[(i - 1) / 2]);
    } else {
      break;
    }
  }
}

template <typename data_t, typename less_t>
data_t heap_pop(data_t **heap, size_t &n, less_t &less, data_t **iter) {
  data_t temp = *(heap[0]);
  *(iter) = heap[0];
  heap[0] = heap[--n];
  size_t i = 0;
  while(i < n) {
    size_t lag = i;
    if(((2 * i + 1) < n) && less(*(heap[i]), *(heap[2 * i + 1]))) {
      lag = 2 * i + 1;
    }
    if(((2 * i + 2) < n) && less(*(heap[lag]), *(heap[2 * i + 2]))) {
      lag = 2 * i + 2;
    }
    if(lag == i) {
      break;
    } else {
      swap(heap[i], heap[lag]);
    }
    i = lag;
  }
  return temp;
}

/*
template <typename data_t, typename less_t>
void heap_sort(data_t *begin, data_t *end, less_t &less) {
  size_t n = 0;
  for(data_t *it = begin; it != end; ++it, ++n) {}
  data_t *heap = new data_t[n];
  size_t heap_real_size = 0;
  for(data_t *it = begin; it != end; ++it, ++heap_real_size) {
    heap_insert(&heap[0], heap_real_size, *it, less);
  }
  for(data_t *it = end; it != begin; --it) {
    *(it - 1) = heap_pop(&heap[0], heap_real_size, less);
  }
  delete[] heap;
}
*/

/*
template <typename data_t, typename less_t>
void merge(
				 data_t *a, size_t size_a, 
				 data_t *b, size_t size_b, 
				 data_t *c, 
				 less_t &less) 
{
	int i = size_a - 1,
			j = size_b - 1;
	for( ; i >= 0 && j >= 0; ) {
		if(less(a[i], b[j])) {
			c[i + j + 1] = b[j];
			j--;
		} else {
			c[i + j + 1] = a[i];
			i--;
		}
	}
	if(i < 0) {
		i++;
		for( ; j >= 0; --j) {
			c[i + j] = b[j];
		}
	} else {
		j++;
		for( ; i >= 0; --i) {
			c[i + j] = a[i];
		}
	}
}
*/

template <typename data_t, typename less_t>
void k_way_sort(data_t *begin, data_t *end, size_t k, less_t &less) {
	//data_t **heap = new data_t[k];
	data_t **heap;
	heap = new data_t*[k];
	for(size_t i = 0; i < k; ++i) {
		heap_insert(heap, i, (begin + i), less);
	}
	
	data_t *iter = begin;
	data_t *next_mas = begin + 1;
	size_t heap_size = k;
	size_t n = std::distance(begin, end);
	*begin = heap_pop(heap, heap_size, less, &iter);
	for(size_t i = 1; i < n; ++i) {
		begin++;
		iter += k;
		if((iter) >= end) {
			// надо что-то делать
			// heap_rebuild();
			// --heap_size
			--heap_size;
			iter = next_mas + k;
			++next_mas;
		}
		heap_insert(heap, heap_size, iter, less);
		*begin = heap_pop(heap, heap_size, less, &iter);
	}
	
	/*
	for(size_t i = 0; i < k; ++i) {
		printf("%d ", *(heap[i]));
	}
	*/
} 

int main() {
	/*
	int a[] = {0, 4, 7};
	int b[] = {2, 3, 9};
	int *c = new int[6];
	*/
	//merge(a, 3, b, 3, c, less);
	/*
	for(int i = 0; i < 6; ++i) {
		std::cout << c[i] << ' ';
	}
	*/
	size_t n, k;
	scanf("%d %d", &n, &k);
	int *mas = new int[n];
	for(size_t i = 0; i < n; ++i) {
		scanf("%d", &mas[i]);
	}
	
	k_way_sort(&mas[0], &mas[n], k, less);
	
	for(size_t i = 0; i < n; ++i) {
		printf("%d ", mas[i]);
	}
	delete[] mas;
	return 0;
}
