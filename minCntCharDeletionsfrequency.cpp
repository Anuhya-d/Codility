/* Given string S consists of N lowercase letters, returns the min number of letters that must be deleted 
to obtain a word in which each letter occurs unique number of times.
Ex: S = "aaaabbbb" -> return 1
    S = "eeee" -> return 0
    S = "example" -> return 4
 String S consists of only lowercase letters
 N is within range [0....300000]
*/

#include <algorithm>
#include <unordered_map>
#include <queue>

int solution(string &S)
{   
  unordered_map<char, int> mp;  
  priority_queue<int> pq;    
  int cnt = 0;
  int N = S.size();   
    
  for (int i = 0; i < N; i++) 
  {        
    mp[S[i]]++;
  } 
    
  for (auto it : mp) 
  {         
    pq.push(it.second);
  } 
    
  while (!pq.empty()) 
  {       
    int freq = pq.top();        
    pq.pop();        
    if (pq.empty()) 
	  {           
        return cnt;
    }        
    if (freq == pq.top()) 
	  {            
     if (freq > 1) 
	   {
        pq.push(freq - 1);
     }             
     cnt++;
    }
  } 
 return cnt;

}
