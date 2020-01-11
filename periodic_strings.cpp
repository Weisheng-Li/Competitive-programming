#include<stdio.h>
//#define LOCAL
#define maxlength 100

int main() {

#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int N;
  scanf("%d", &N);
  while(N--) {
    int i;
    char s[maxlength];
    int ptrList[maxlength] = {-1};
    scanf("%s", s);
    for (i = 0; s[i] != 0; i++) {
      if (i != 0) {
        if (s[i] == s[0]) {
          ptrList[i-1] = 0; 
        }

        // traverse ptrList
        for (int j = 0; j < i; j++) {
          if (s[ptrList[j]] != s[i]) ptrList[j] = -1;
          else ptrList[j] += 1;
        }
      }
      // if (i != 0) {
      //   if (s[ptr] != s[i]) {
      //     ptr = 0;
      //     if (s[ptr] == s[i]) {
      //       ptr++;
      //     }
      //   } else ptr++;
      // }
    }

    // traverse ptrList to find largest ptr
    int max_ptr = 0;
    for (int j = 0; j < i; j++) {
      if (ptrList[j] > max_ptr) max_ptr = ptrList[j];
    }

    int period = i - max_ptr;
    if (N == 0) {
      if ((i%period) == 0)  printf("%d\n", period);
      else printf("%d\n", i);
    } else {
      if ((i%period) == 0)  printf("%d\n\n", period);
      else printf("%d\n\n", i);
    }
  }
  return 0;
}