template <typename T>
struct hash_t {
	void add(const T& data);
	T* find(const T& data);                           //Маерс. как писать константную функция через не константную и обратно
	const T* find(const T& data) const;
	bool remove(const T& data);
	bool remove(T*);  //T* - итератор it_t
	size_t remove(T* begin, T* end); // Удаление диапазона элементов
	
	T* next(T*);
	T* begin();
	
	template <class action_t>
	viod traverse(actoin_t& action) {
		for(T* it = begin(); it != NULL; it = next(it)) {
			action(*it);
		}
	}
};
