#include <cstdio>
#include <iterator>

template <typename data_t>
void swap(data_t &lhs, data_t &rhs) {
	data_t temp = lhs;
	lhs = rhs;
	rhs = temp;
}

bool less(const int &lhs, const int &rhs) {
	return lhs < rhs;
}

template <typename data_t, typename less_t>
void merge(
		data_t *a, size_t a_size, 
		data_t *b, size_t b_size, 
		data_t *c, 
		less_t less) 
{
	size_t i = 0,
				 j = 0;
	for( ; i < a_size && j < b_size; ){
		if(less(b[j], a[i])) {
			c[i + j] = b[j];
			++j;
		} else {
			c[i + j] = a[i];
			++i;
		}
	}
	if(i == a_size) {
		for( ; j < b_size; ++j){
			c[i + j] = b[j];
		}
	} else {
		for( ; i < a_size; ++i){
			c[i + j] = a[i];
		}
	}
}

template <typename data_t, typename less_t>
void merge_sort(data_t *begin, data_t *end, less_t less) {
	size_t n = std::distance(begin, end);
	data_t *temp = new data_t[n];
	size_t count_iter = 0;
	for(size_t chunk_size = 1; chunk_size < n; chunk_size *= 2, ++count_iter) {
		size_t begin_chunk = 0;
		for( ; begin_chunk + chunk_size < n; begin_chunk += chunk_size * 2){
			size_t last_chunk_size = chunk_size;
			if((begin_chunk + chunk_size * 2) > n) {
				last_chunk_size = n - begin_chunk - chunk_size;
			}
			merge(&begin[begin_chunk], chunk_size, &begin[begin_chunk + chunk_size], last_chunk_size, &temp[begin_chunk], less);
		}
		if(begin_chunk < n) {
			merge(&begin[begin_chunk], n - begin_chunk, &begin[n], 0, &temp[begin_chunk], less);
		}
		swap(begin, temp);
	}
	if((count_iter % 2) == 1) {
		swap(begin, temp);
		for(int i = 0; i < n; ++i) {
			begin[i] = temp[i];
		}
	}
	delete[] temp;
}

template <typename data_t>
void print_mas(data_t* mas, size_t size) {
	for(size_t i = 0; i < size; ++i) {
		printf("%d ", mas[i]);
	}
}

int main() {
	size_t n, k;
	scanf("%d %d", &n, &k);
	int* first = new int[2 * k];
	size_t i = 0;
	size_t j = 0;
	for( ; i < n; ) {
		for( ; i < n && j < (k * 2); ++i, ++j) {
			scanf("%d", &first[j]);
		}
		if(i != n) {
			merge_sort(&first[0], &first[j], less);
			print_mas(first, k);
			j = k;
			for(size_t q = 0; q < k; ++q) {
				first[q] = first[q + k];
			}
		} else {
			merge_sort(&first[0], &first[j], less);
			print_mas(first, j);
		}
	}
	return 0;
}
