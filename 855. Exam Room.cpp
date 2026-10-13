class ExamRoom {
public:
	struct gap_t {
		int get_best_seat(int n) const {
			if (start == 0) {
				return 0;
			} if (start + size == n) {
				return n - 1;
			} return start + size / 2 - (size % 2 ^ 1);
		}
		int max_seat_dist(int n) const {
			if (start == 0) {
				return size - 1;
			} if (start + size == n) {
				return size - 1;
			} return size / 2 - (size % 2 ^ 1);
		}
		tuple<gap_t, gap_t> split(int n) const {
			int seat = get_best_seat(n);
			return {{start, seat - start}, {seat + 1, start + size - seat - 1}};
		}
		bool empty() const {
			return size <= 0;
		}
        bool operator == (const gap_t& another) const {
            return start == another.start && size == another.size;
        }
        bool operator != (const gap_t& another) const {
            return !(*this == another);
        }
		int start{};
		int size{};
	};
	struct gap_order_compare_t {
		bool operator() (const gap_t& g1, const gap_t& g2) const {
			return g1.start < g2.start;
		}
	};
	struct gap_size_compare_t {
		bool operator() (const gap_t& g1, const gap_t& g2) const {
			int d1 = g1.max_seat_dist(n);
            int d2 = g2.max_seat_dist(n);
            if (d1 != d2) {
                return d1 < d2;
            } return g1.start > g2.start;
		}
		int n{};
	};
    ExamRoom(int _n) : n{_n} {
		gaps.push_back({0, n});
		seats.insert(-1);
		seats.insert(n);
	}
	gap_t get_gap(int gap) {
		auto it = seats.lower_bound(gap);
		int start = *it + 1;
		--it;
		int size = *it - start;
		return {start, size};
	}
	void pop_gap() {
		pop_heap(gaps.begin(), gaps.end(), gap_size_compare_t{n});
		gaps.pop_back();
    }
	void push_gap(const gap_t& gap) {
		gaps.push_back(gap);
		push_heap(gaps.begin(), gaps.end(), gap_size_compare_t{n});
	}
    int seat() {
		while (!gaps.empty()) {
			auto gap = gaps.front();
			auto true_gap = get_gap(gap.start);
			pop_gap();
			if (gap != true_gap) {
				continue;
			}
			int new_seat = gap.get_best_seat(n);
			seats.insert(new_seat);

			auto [g1, g2] = gap.split(n);
			if (!g1.empty()) {
				push_gap(g1);
			} if (!g2.empty()) {
				push_gap(g2);
			}
			return new_seat;
		} return -1;
    }
    void leave(int p) {
		seats.erase(p);
		push_gap(get_gap(p));
    }
    int n{};
	set<int, greater<int>> seats;
	vector<gap_t> gaps;
};
