// Copy paste for fast USACO file I/O redirection
#include <iostream>
#include <cstdio>
void InitIO(const char* FileName) {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    constexpr std::size_t BufferSize = 256;
    char StrBuf[BufferSize];

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.in", FileName);
    std::freopen(StrBuf, "r", stdin);

    StrBuf[0] = '\0';
    std::snprintf(StrBuf, BufferSize, "%s.out", FileName);
    std::freopen(StrBuf, "w", stdout);    
}

#include <string>

int main() {
    InitIO("whereami");
    int n;
    std::cin >> n;
    std::string MailboxColors;
    MailboxColors.reserve(n);
    std::cin >> MailboxColors;

    /*
    For all k 1...N / 2
    For all substrings starting at 1 ... N - K + 1
    Check if it occurs before 
    */

   for(int k = 1; k <= n / 2; k++) {
       bool ShortestNonrepetitive = true;
       for(int i = 0; i < n - k + 1; i++) {
           std::string CurrentSequence = MailboxColors.substr(i, k);
           size_t Position[2] {
               MailboxColors.find(CurrentSequence, 0    ),
               MailboxColors.find(CurrentSequence, i + 1),
           };
           if(Position[0] != i || Position[1] != std::string::npos) {
               ShortestNonrepetitive = false;
               break;
           }
       }
       if(ShortestNonrepetitive) {
           std::cout << k << '\n';
           return 0;
       }
   }
   std::cout << n / 2 + 1 << '\n';
   return 0;
}