/*
  The STL. Standard Template Library
  Sec D
*/

#include <vector>
#include <iostream> 
#include <list>
#include <algorithm>
using namespace std;

char* myfind(char* start, char* stop, char target) {
    for (char* p = start; p != stop; ++p) {
        if (target == *p) return p;
    }
    return stop;
}

template <typename T, typename U>
T myfind(T start, T stop, U target) {
    for (T p = start; p != stop; ++p) {
        if (target == *p) return p;
    }
    return stop;
}

template <typename T, typename U>
T myfind_if(T start, T stop, U pred) {
    for (T p = start; p != stop; ++p) {
        if (pred(*p)) return p;
    }
    return stop;
}

bool isOdd(int n) {
    return n%2 == 1;
}



struct IsOdd {
    bool operator() (int n) {
        return n%2 == 1;
    }
};

struct IsMultiple {
    IsMultiple(int factor) : factor(factor) {}
    bool operator() (int n) {
        return n%factor == 0;
    }
    int factor;
}

int main() {

  char array[] = "Bjarne Stroustrup";
  int len = 17;
  sort(array, array+len);

  vector<char> vc(array, array+len);
  list<char> lc(array, array+len);
  list<char> lc2(lc.begin(), lc.end());

  char* where = find(array, array+len, 'S');
  where = find(array, array+len, 'Q');


  list<char>::iterator where2 = find(lc.begin(), lc.end(), 'S');

  where2 = find(lc.begin(), --lc.end(), 'Q');

  vector<int> vi{2,3,5,8,13,21};

  vector<int>::iterator firstOdd = find_if(vi.begin(), vi.end(), isOdd);

  //firstOdd = find_if(vi.begin(), vi.end(), n%2 == 1  );
  firstOdd = find_if(vi.begin(), vi.end(), [] (int n) { return n%2 == 1; }  );
  
  [](int n) { return n % 2 == 1; } (42);

  [] { cout << "lambda"; } ();
  [] () -> void { cout << "lambda"; } ();

  IsOdd isOddFunctor;
  isOddFunctor(42);

  firstOdd = find_if(vi.begin(), vi.end(), isOddFunctor);
  vector<int>::iterator firstMulThree = find_if(vi.begin(), vi.end(), IsMultiple(3));
}

