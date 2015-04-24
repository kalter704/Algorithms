// 3_2. ������������.
// ������ ����� ���������� �������������� ���� ��� ����� ������, 
// ����� ��� ����� ��������� ������. ��� ����� � ���� ������ 
// ������� �� ��� ������ ����  ��� ����������� 18 ���, �� ��� �� ����������� 80 ���.
// ��� ������ ����� ������� �����. ���������� �������� ������������ ���������� �������������. 
// � ���� 18����� ������� ��� ����� ��������� ������� � ���������, 
// � � ���� 80����� � � ���� ������ ��� �� �����.

// ������� ��� ���� � ������, �������� ��� �����, ������� �� ����������� 18 ���, 
// ������������ ������� �������
// ����� � ��������������� ������� �������� �� ������ �� ����� � ��������������� �������,
// ���� ������� ���� �����������������, � ���������������, ���� ������� ���� ������ ��� �����������������.

// �������� ���������.
// ������ � ������������� ���� ������ ��� ���� �����������������. ���������� ��� �������:
// 1. ������������� ����, ���� ���� ����� � ���.
// 2. ������������� ����, �������������� � ���� YYYYMMDD. 
// ���� ������, ��� �����?

#include <cstdio>
#include <iterator>

#include <iostream>


struct Dates_Of_Life {
  int date; 
  bool born;
};

void print_vector_dates(Dates_Of_Life* mas, size_t n) {
	for(size_t i = 0; i < n; ++i) {
		//printf("%d %d\n", mas->date, mas->born);
		std::cout << mas[i].date << ' ';
		if(mas[i].born) {
			std::cout << "True" << std::endl;
		} else {
			std::cout << "False" << std::endl;
		}
	}
}

template <typename data_t>
void swap(data_t &lhs, data_t &rhs) {
	data_t temp = lhs;
	lhs = rhs;
	rhs = temp;
}

bool less_dates(const struct Dates_Of_Life &lhs, const struct Dates_Of_Life &rhs) {
	return lhs.date < rhs.date;
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

int count_contemp(struct Dates_Of_Life *dates, size_t num) {
	int max_contemp = 1,
	    temp_contemp = 0;
	for(int i = 0; i < num; ++i) {
		if(dates[i].born) {
			temp_contemp++;
			if(temp_contemp > max_contemp) {
				max_contemp = temp_contemp;
			}
		} else {
			temp_contemp--;
		}
	}
	return max_contemp;
}

int main() {
	size_t num = 0;
	scanf("%d", &num);
	struct Dates_Of_Life *dates = new Dates_Of_Life[num * 2];
	size_t count_dates = 0;
	for(size_t i = 0; i < num; ++i) {
		int DD_b, MM_b, YYYY_b, 
				DD_d, MM_d, YYYY_d;
		scanf("%d %d %d", &DD_b, &MM_b, &YYYY_b);
		YYYY_b += 18;
		struct Dates_Of_Life date_b = {YYYY_b * 10000 + MM_b * 100 + DD_b, true};
		scanf("%d %d %d", &DD_d, &MM_d, &YYYY_d);
		struct Dates_Of_Life date_d = {YYYY_d * 10000 + MM_d * 100 + DD_d, false};
		if(date_b.date >= date_d.date) {
			continue;
		}
		int date_eighty = (YYYY_b + 62) * 10000 + MM_b * 100 + DD_b;
		if(date_eighty < date_d.date) {
			date_d.date = date_eighty;
		}
		//date_d.date--;
		dates[count_dates++] = date_d;
		dates[count_dates++] = date_b;
	}
	num = count_dates;
	
	/*
	std::cout << std::endl << "Before sorting:" << std::endl;
	print_vector_dates(dates, num);
	*/
	
	merge_sort(&dates[0], &dates[num], less_dates);
	int contemp = count_contemp(dates, num);
	
	/*
	std::cout << std::endl << "After sorting:" << std::endl;
	print_vector_dates(dates, num);
	*/
	
	printf("%d", contemp);
	delete[] dates;
  return 0; 
}
