class LRUCache{
	// first->key, second->value
	list<pair<int, int>> m_list;
	// first->key, second->iterator, direct access to the element in list
	unordered_map<int, list<pair<int, int>>::iterator> m_map;

	int m_capacity;

	public:
	LRUCache(int capacity) : m_capacity(capacity) {

	}

	int get(int key) {
		auto found_iter = m_map.find(key);

		if(found_iter == m_map.end())
			return -1;

		// list.splice(a, b, c)-> transfer c elem from b to a. Will also remove c from b
		m_list.splice(m_list.begin(), m_list, found_iter->second);
		return found_iter->second->second;
	}

	void set(int key, int value) {
		auto found_iter = m_map.find(key);

		if(found_iter != m_map.end()) {
			m_list.splice(m_list.begin(), m_list, found_iter->second);
			found_iter->second->second = value;
			return;
		}
		// space if full, need to evict the oldest (tail) elem
		if(m_map.size() == m_capacity) {
			int key_to_delete = m_list.back().first;
			m_map.erase(key_to_delete);
			m_list.pop_back();
		}
		// insert the elem to the head of list
		// emplace_front(a, b) will insert pair(a, b)
		m_list.emplace_front(key, value);
		m_map[key] = m_list.begin();
	}
};
