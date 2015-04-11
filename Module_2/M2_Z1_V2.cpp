#include <cstdio>
#include <vector>

bool less(const int &lhs, const int &rhs) {
  return (lhs < rhs);
}

template <typename data_t>
void swap(data_t &lhs, data_t &rhs) {
  data_t temp = lhs;
  lhs = rhs;
  rhs = temp;
}

template <typename data_t, typename less_t>
void ins_sort(data_t *begin, data_t *end, less_t &less) {
  for(data_t *i = begin + 1; i < end; ++i) {
    data_t temp = *i;
    data_t *j = i;
    for( ; (j != begin) && less(temp, *(j - 1)); --j) {
      *(j) = *(j - 1);
    }
    *(j) = temp;
  }
}

int main() {
  std::vector<int> mas;
  int value;
  while(scanf("%d", &value) == 1) {
    mas.push_back(value);
  }
  ins_sort(&mas[0], &mas[mas.size()], less);
  for(int i = 0; i < mas.size(); ++i) {
    printf("%d ", mas[i]);
  }
  return 0;
}
