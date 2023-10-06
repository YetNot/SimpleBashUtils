#ifndef S21_GREP
#define S21_GREP

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAM 1000

struct grep_opt {
  int eflag;
  int iflag;
  int vflag;
  int cflag;
  int lflag;
  int nflag;
  int hflag;
  int sflag;
  int fflag;
  char **sample;
  int sample_count;
  char **files;
  int files_count;
};
struct flag_grep {
  int flag_reg;
  int flag_l;
  int count_cl;
  int count_cv;
  int count_str;
  int count_c;
  int count_n;
  char *clicker;
};

int exam_options(int argc, char *argv[], struct grep_opt *msd);
void searht_samples(int argc, char *argv[], struct grep_opt *msd);
void sample_flagf(struct grep_opt *msd, int *flag);
void cartyceps(struct grep_opt *msd);
void process_option(struct flag_grep *stalk, struct grep_opt *msd, int i);
void process_l(struct flag_grep *stalk, struct grep_opt *msd, int i);
void process_lc(struct flag_grep *stalk, struct grep_opt *msd, int i);
void process_c(struct flag_grep *stalk, struct grep_opt *msd, int i);
void process_n(struct flag_grep *stalk, struct grep_opt *msd, int i);
void process(struct flag_grep *stalk, struct grep_opt *msd, int i);
void template_validation(struct flag_grep *stalk, struct grep_opt *msd);
void restart_flags(struct flag_grep *stalk);
char **memory_on();
void memory_off(char **wer);

#endif
