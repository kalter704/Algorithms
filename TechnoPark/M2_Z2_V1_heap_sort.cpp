#include <cstdio>
#include <vector>

struct Box {
  long int min_value;
  int num;
};

bool less(const int &lhs, const int &rhs) {
  return lhs < rhs;
}

template <typename data_t>
void swap(data_t &lhs, data_t &rhs) {
  data_t temp = lhs;
  lhs = rhs;
  rhs = temp;
}

template <typename data_t, typename data_v, typename less_t>
void heap_insert(data_t *heap, size_t n, data_v elem, less_t &less) {
  heap[n] = elem;
  for(int i = n; i > 0; i = (i - 1) / 2) {
    if(less(heap[(i - 1) / 2].min_value, heap[i].min_value)) {
      swap(heap[i], heap[(i - 1) / 2]);
    } else {
      break;
    }
  }
}

template <typename data_t, typename less_t>
data_t heap_pop(data_t *heap, size_t &n, less_t &less) {
  data_t temp = heap[0];
  heap[0] = heap[--n];
  size_t i = 0;
  while(i < n) {
    size_t lag = i;
    if(((2 * i + 1) < n) && less(heap[i].min_value, heap[2 * i + 1].min_value)) {
      lag = 2 * i + 1;
    }
    if(((2 * i + 2) < n) && less(heap[lag].min_value, heap[2 * i + 2].min_value)) {
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

template <typename data_t>
data_t less_comp(data_t a, data_t b, data_t c) {
  data_t min = a;
  if(min > b) {
    min = b;
  }
  if(min > c) {
    min = c;
  }
  return min;
}

int main() {
  size_t n;
  fscanf(stdin, "%d", &n);
  Box *mas = new Box[n];
  int a, b, c;
  for(int i = 0; i < n; ++i) {
    fscanf(stdin, "%d %d %d", &a, &b, &c);
    mas[i].min_value = less_comp(a, b ,c);
    mas[i].num = i;
  }
  heap_sort(&mas[0], &mas[n], less);
  for(int i = 0; i < n; ++i) {
    printf("%d ", mas[i].num);
  }
  delete[] mas;
  return 0;
}
