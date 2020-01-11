#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define LOCAL

struct point{
  short H, V;
} dot_array[10][10];

int hasSqr(int i, int j, int size);
int isConnected(int i1, int j1, int i2, int j2, char dir);

int main() {

  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int n, m;
  int pb_nb = 1;

  while (scanf("%d%d", &n, &m) == 2) {
    memset(dot_array, 0, sizeof(dot_array));
    int sqr_cnt[9]; // max sqr size is 8
    memset(sqr_cnt, 0, 9*sizeof(int));

    while (m--) {
      // input one line
      char hv[3];
      int i, j;
      scanf("%s%d%d", &hv, &i, &j);

      if (*hv == 'H') dot_array[i][j].H = 1;
      else dot_array[j][i].V = 1;
    }

    // count squares
    int temp_ret;
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < n; j++) {
        // at each point(except points at right&bot side),
        // count numbe of squares.
        int max_size = (i > j)? i:j;
        max_size = n - max_size;
        for (int s = 1; s <= max_size; s++) 
          if (temp_ret = hasSqr(i, j, s)) (sqr_cnt[s])++;
      }
    }

    // print out the result
    int has_sqr = 0;
    if (pb_nb > 1)
      printf("\n**********************************\n\n");
    printf("Problem #%d\n\n", pb_nb++);
    for (int i = 1; i <= n-1; i++) {
      if (sqr_cnt[i]) {
        printf("%d square (s) of size %d\n", sqr_cnt[i], i);
        has_sqr = 1;
      }
    }
    if (!has_sqr) 
      printf("No completed squares can be found.\n");
  }
}

int hasSqr(int i, int j, int size) {
  int s1, s2, s3, s4;
  s1 = s2 = s3 = s4 = 0;
  if (isConnected(i, j, i+size, j, 'V')) s1 = 1;
  if (isConnected(i, j, i, j+size, 'H')) s2 = 1;
  if (isConnected(i+size, j, i+size, j+size, 'H')) s3 = 1;
  if (isConnected(i, j+size, i+size, j+size, 'V')) s4 = 1;
  if (s1 && s2 && s3 && s4) return 1;
  else return 0;
}

// check if two points are at same coloum or same row
int isConnected(int i1, int j1, int i2, int j2, char dir) {
  if (i1 == i2 && j1 == j2) return 1;
  if (dir == 'V') {
    return dot_array[i1][j1].V && isConnected(i1+1, j1, i2, j2, 'V');
  } else {
    return dot_array[i1][j1].H && isConnected(i1, j1+1, i2, j2, 'H');
  }
}