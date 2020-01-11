#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define LOCAL

struct student {
  char cycle[12];
  int pos, bs_pos, c_length;
} students[10];

int main() {

  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

  int n, kase = 1;
  while (scanf("%d", &n) && n) {
    memset(students, 0, sizeof(students));
    // initialize all students
    for (int k=1; k <= n; k++) {
      int a,b,c;
      scanf("%d%d%d", &a, &b, &c);
      students[k].pos = c;
      students[k].bs_pos = a;
      students[k].c_length = a+b;
      for (int i = 1; i <= a; i++) 
        students[k].cycle[i] = 'A'; // A for awake
      for (int i = a+1; i <= a+b; i++)
        students[k].cycle[i] = 'S'; // S for sleep
    }

    int time = 1, sleep_fl = 0;
    while (time++) {
      if (time > 100) break;
      sleep_fl = 0;
      for (int i = 1; i <= n; i++) {
        if (students[i].cycle[students[i].pos] == 'A')
          sleep_fl--;
        else sleep_fl++;
      }
      if (sleep_fl == -n) break; // time-1 is the actual time
      sleep_fl = (sleep_fl > 0)? 1:0;

      // update pos for all students
      for (int i = 1; i <= n; i++) {
        if (students[i].pos == students[i].bs_pos) {
          if (!sleep_fl) 
            students[i].pos = 1;
          else (students[i].pos)++;
        } else {
          (students[i].pos)++;
          if (students[i].pos > students[i].c_length)
            students[i].pos = students[i].pos % students[i].c_length;
        }
        //printf("student%d: %c\n", i, students[i].cycle[students[i].pos]);
      }
      //printf("--------\n");
    }

    // output the result
    printf("Case %d: %d\n", kase++, (time>100)? -1:time-1);
  }
}

