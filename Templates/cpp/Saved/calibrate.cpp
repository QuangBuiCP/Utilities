template <typename T>
struct Calibrate {
	T sum = 0;
	priority_queue<T> pq;

	void pop() {
		sum -= pq.top();
		pq.pop();
	}

	void push(T x) {
		sum += x;
		pq.push(x);
	}

	void kill(T cutoff) {
		while (sum > cutoff) {
			pop();
		}
	}

	int get_size() {
		return (int) pq.size();
	}
};