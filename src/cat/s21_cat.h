#ifndef S21_CAT
#define S21_CAT

#include <getopt.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int nflag;
  int eflag;
  int sflag;
  int tflag;
  int vflag;
  int bflag;
  int rez;
  int mistake;
  char ch;
  int count1;
  int current_position;
  int count2;
  int current_line;
  int next_line;
  int line;
} options_t;

const char *short_options = "+bEensTtv";
const struct option long_options[] = {
    {"number-nonblank", no_argument, NULL, 'b'},
    {"number", no_argument, NULL, 'n'},
    {"squeeze-blank", no_argument, NULL, 's'},
    {NULL, 0, NULL, 0}};

void options_implementation(FILE *file, options_t *vr);
void reading_file(char argv[optind], options_t *vr);
void flags(options_t *vr);
int s_options(options_t *vr);
void b_options(options_t *vr);
void n_options(options_t *vr);
void t_options(options_t *vr);
void e_options(options_t *vr);
void v_options(options_t *vr);

#endif
