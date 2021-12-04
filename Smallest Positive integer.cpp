/* Given an array A of N integers, returns the smallest positive integer(greater than 0) that doesn't occur in A
Ex: A = [1,3,6,4,1,2 ] -> function should return 5
    A = [1,2,3] -> function should return 4
    A = [-1,-3] -> function should return 1
 N is within range [1 to 100000] 
*/

#include <algorithm>
#include <set>
#include <unordered_set>

int solution(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)    
    unordered_set <int> Set;    
    for(auto a:A)
    {
      if(a>0)
      Set.insert(a);
    }
    int N = Set.size();
    for(int i =1; i<=N+1;i++)
    {
        if(!(Set.find(i) != Set.end()))
        return i;
    }

}
