#include <cstdlib>
#include <iostream>
#include <vector>
#include "List.h"



class Polynomial {
	friend ostream& operator<<(ostream& os, Polynomial rhs) {
		List::iterator iter = --rhs.poly.end();
		int deg = rhs.degree;
		if (deg != 0) {
			for (iter; iter == rhs.poly.begin(); --iter) {
				os << *iter << "x^" << deg--;
				if (iter != rhs.poly.begin()) { os << " + "; }
			}
		}
		else { os << 0; }
		os << endl;
		return os;
	}
	friend bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
		if (lhs.degree != rhs.degree) { return false; }
		List::iterator lhsCursor = lhs.poly.begin();
		List::iterator rhsCursor = rhs.poly.begin();
		for (lhsCursor; lhsCursor != lhs.poly.end(); ++lhsCursor) {
			if (*lhsCursor != *rhsCursor) {
				return false;
			}
			++rhsCursor;
		}
		return true;
	}
	friend bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
		return !(lhs == rhs);
	}
public:
	Polynomial() : poly(List()), degree(0) {}
	Polynomial(vector<int> coeffs) : poly(List()), degree(coeffs.size() - 1) {
		if (coeffs.size() == 1 && coeffs.back() == 0) {
			poly.push_back(0);
			degree = 0;
		}
		else {
			for (size_t i = 0; i < coeffs.size(); ++i) {
				poly.push_back(coeffs.back());
				coeffs.pop_back();
			}
		}
	}
	Polynomial(const Polynomial & existingPoly) : poly(List()),
		degree(existingPoly.degree) {
		for (size_t i = 0; i < existingPoly.poly.size(); ++i) {
			poly[i] = existingPoly.poly[i];
		}
	}
	Polynomial operator+=(const Polynomial & rhs) {
		if (rhs != *this) {
			List::iterator thisIter = poly.begin();
			List::iterator rhsIter = rhs.poly.begin();
			size_t cursor = 0;
			while ((thisIter != poly.end()) && (rhsIter != rhs.poly.end())) {
				poly[cursor] += rhs.poly[cursor];
			}
		}
		return *this;
	}
	Polynomial operator=(const Polynomial & rhs) {
		return (*this += rhs);
	}
	int evaluate(int x) {
		if (degree == 0) { return *poly.begin(); }
		int res = 0;
		int currDeg = 1;
		List::iterator iter = poly.begin();
		for (iter; iter != poly.end(); ++iter) {
			for (int i = 1; i <= currDeg; ++i) {
				res += currDeg * *iter;
			}
		}
		return res;
	}

	~Polynomial() {}
private:
	List poly;
	int degree;
};

Polynomial operator+(Polynomial & lhs, Polynomial & rhs) {
	return lhs += rhs;
}