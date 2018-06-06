#include <map>
#include <set>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[]) {
  std::map<char, int> map;
  char value;
  while (scanf("%c", &value) == 1) {
    if (value != '\n')
      map[value]++;
  }

  int n = 0;
  set<pair<int, char>> ordered;
  for (auto i = map.begin(); i != map.end(); i++) {
    n += i->second;
    ordered.insert(pair<int, char>(i->second, i->first));
  }
  int n_zeros = 0;
  int compressed_size = 0;
  for (auto i = ordered.rbegin(); i != ordered.rend(); i++, n_zeros++) {
    compressed_size += i->first * (n_zeros + 1);
    printf("'%c' - %d - %0*d\n", i->second, i->first, n_zeros + 1,
           1);
  }
  printf("N bits: %d\n", n * 8);
  printf("Compressed bits: %d\n", compressed_size);
  return 0;
}
