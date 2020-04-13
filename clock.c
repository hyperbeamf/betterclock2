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
twelvehr(int second) {
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
  if(second == 1) {
    char *minute = tokens_time;
    tokens_time = strtok(NULL, ":");
    printf("%s:%s:%s %s\n", hour, minute, tokens_time, ampm);
  } else {
    printf("%s:%s %s\n", hour, tokens_time, ampm);
  }
  return 0;
}

int
main(int argc, char *argv[]) {
  if(argc == 2) {
    if(strcmp(argv[1], "--help") == 0) {
      printf("betterclock2 help:\n");
      printf("--military: print military time\n");
    } else if(strcmp(argv[1], "--military") == 0) {
      printf("%s\n", gettime());
      return 0;
    } else if(strcmp(argv[1], "--militaryns") == 0) {
      tokens = strtok(gettime(), ":");
      hour = tokens;
      tokens = strtok(NULL, ":");
      printf("%d:%d\n");
      return 0;
    } else if(strcmp(argv[1], "--seconds") == 0) {
      return twelvehr(1);
    } else {
      fprintf(stderr, "flag %s not found\n", argv[1]);
      return 1;
    }
  } else {
    return twelvehr(0);
  }
}
