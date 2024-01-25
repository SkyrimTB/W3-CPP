#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Nth_Power {
public:
  Nth_Power(int n) : n_(n) {}

  int operator()(int x) const {
    int result = 1;
    for (int i = 0; i < n_; ++i) {
      result *= x;
    }
    return result;
  }

private:
  int n_;
};

int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  Nth_Power cube(3);

  cout << cube(7) << endl; // prints 343

  // print first five cubes
  transform(v.begin(), v.end(), ostream_iterator<int>(cout, ", "), cube);

  return 0;
}
