 /* Given string consists of digits. Find the biggest 2 digit value i.e a consistent frgment of given string
 Ex: ["50552"] -> are ["50", "05", "55", "52"] returns 55
     ["10101"] -> returns 10
     ["88"] -> returns 88
 S consists of only digits [0...9]
 The number of digits S within the range [ 2...100]     
 */
 #include <algorithm>
 #include <string>

int solution(string &S) 
{
    int big = 0;
    for(int i = 0; i < S.size() - 1; i++)
    {
        big = max(big, stoi(S.substr(i, 2)));
    }
    return big;
}
