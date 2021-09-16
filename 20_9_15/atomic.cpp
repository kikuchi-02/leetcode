#include <bits/stdc++.h>
using namespace std;

bool isAtomic(int num)
{

  int squart = int(sqrt(num));
  for (int i = 0; i < squart; i++)
  {
    if (i + 1 == 1)
    {
      continue;
    }
    if (num % (i + 1) == 0)
    {
      return false;
    }
  }
  return true;
}

int atomicNumber(int number)
{
  if (number == 1)
  {
    return 2;
  }
  int lastAtomicNumber = atomicNumber(number - 1);
  while (true)
  {
    lastAtomicNumber++;
    if (isAtomic(lastAtomicNumber))
    {
      return lastAtomicNumber;
    }
  }
}

int main()
{
  int N;
  cin >> N;
  clock_t start = clock();
  cout << atomicNumber(N) << endl;
  clock_t end = clock();
  cout << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0 << endl;
}
