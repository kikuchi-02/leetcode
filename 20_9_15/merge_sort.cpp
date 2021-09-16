#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec.at(i) << ' ';
  }
  cout << endl;
}

vector<int> mergeSort(vector<int> vec)
{
  int len = vec.size();
}

int main()
{
  vector<int> vec(30);
  for (int i = 0; i < vec.size(); i++)
  {
    vec.at(i) = rand() % 100 + 1;
  }
  printArray(vec);

  cout << vec.begin() << endl;
}
