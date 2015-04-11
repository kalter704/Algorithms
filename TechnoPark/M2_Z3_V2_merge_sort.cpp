#include <cstdio>
//#include <vector>
#include <iterator>


struct Dates_Of_Life {
  int eighteen, 
      eighty;  
};

template <typename data_t>
void swap(data_t &lhs, data_t &rhs) {
	data_t temp = lhs;
	lhs = rhs;
	rhs = temp;
}

bool less_int(const int &lhs, const int &rhs) {
	return lhs < rhs;
}

bool less_dates(const struct Dates_Of_Life &lhs, const struct Dates_Of_Life &rhs) {
	return lhs.eighteen < rhs.eighteen;
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
	//if((count_iter % 2) == 1) {
		//swap(begin, temp);
	//}
	
	//if((count_iter % 2) == 1) {
		//swap(begin, temp);
		//for(int i = 0; i < n; ++i) {
			//begin[i] = temp[i];
		//}
	//}
	
	//delete[] temp;
	
	//begin = temp;
}

int count_contemp(struct Dates_Of_Life *dates, size_t num) {
	int max_contemp = 1;
	//    temp_contemp = 0;
	for(int i = num - 1; (i > 0) && (max_contemp < i); --i) {
		int j = i - 1;
		int temp_contemp = 1;
		if(dates[i].eighteen < dates[i].eighty) {
			for( ; j >= 0; --j) {
				if(dates[j].eighteen < dates[j].eighty && dates[i].eighteen < dates[j].eighty) {
				//dates[j].eighteen < dates[j].eighty &&
				//if(dates[i].eighteen < dates[j].eighty) {
					++temp_contemp;
				}
			}
		}
		if(temp_contemp > max_contemp) {
			max_contemp = temp_contemp;
		}
	}
	return max_contemp;
}

int main() {
	//std::vector<struct Dates_Of_Life> dates;
	size_t num = 0;
	scanf("%d", &num);
	struct Dates_Of_Life *dates = new Dates_Of_Life[num];
	size_t count_dates = 0;
	for(size_t i = 0; i < num; ++i) {
		int DD, MM, YYYY_birth, YYYY_death;
		scanf("%d %d %d", &DD, &MM, &YYYY_birth);
		YYYY_birth += 18;
		struct Dates_Of_Life d;
		d.eighteen = YYYY_birth * 10000 + MM * 100 + DD;
		scanf("%d %d %d", &DD, &MM, &YYYY_death);
		d.eighty = YYYY_death * 10000 + MM * 100 + DD;
		if(d.eighteen >= d.eighty) {
			continue;
		}
		int YYYY_eighty = (YYYY_birth + 62) * 10000 + MM * 100 + DD;
		//if (less_int(YYYY_eighty, d.eighty)) {
		if(YYYY_eighty < d.eighty) {
			d.eighty = YYYY_eighty;
		}
	  //dates.push_back(d);
		dates[count_dates++] = d;
	}
	num = count_dates;
	/*
	for(int i = 0; i < dates.size(); ++i) {
		printf("%d %d\n", dates[i].eighteen, dates[i]. eighty);
	}*/
	
	//merge_sort(&dates[0], &dates[dates.size()], less_dates);
	merge_sort(&dates[0], &dates[num], less_dates);
	int contemp = count_contemp(dates, num);
	printf("%d", contemp);
	delete[] dates;
  return 0; 
}
