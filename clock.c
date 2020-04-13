#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char*
gettime() {
  time_t time_raw;
  struct tm *ttime;
  time(&time_raw);
  ttime = localtime(&time_raw);
  char * time_return = strtok(asctime(ttime), " ");
  for(int count = 0; count < 3; count++)
    time_return = strtok(NULL, " ");
  return time_return;
}

int
main() {
  char *ampm;
  char *tokens_time = strtok(gettime(), ":");
  int int_hour_token = atoi(tokens_time);
  if(int_hour_token == 0) {
    fprintf(stderr, "Failed to convert time to integer");
    return 1;
  } else { tokens_time = strtok(NULL, ":"); }
  if(int_hour_token > 12) {
    ampm = "PM";
    int_hour_token -= 12;
  } else { ampm = "AM"; }
  char hour[2];
  sprintf(hour, "%d", int_hour_token);
  printf("%s:%s %s\n", hour, tokens_time, ampm);
}
