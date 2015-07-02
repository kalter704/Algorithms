template <typename T>
struct hash_t {
	void add(const T& data);
	T* find(const T& data);                           //�����. ��� ������ ����������� ������� ����� �� ����������� � �������
	const T* find(const T& data) const;
	bool remove(const T& data);
	bool remove(T*);  //T* - �������� it_t
	size_t remove(T* begin, T* end); // �������� ��������� ���������
	
	T* next(T*);
	T* begin();
	
	template <class action_t>
	viod traverse(actoin_t& action) {
		for(T* it = begin(); it != NULL; it = next(it)) {
			action(*it);
		}
	}
};
