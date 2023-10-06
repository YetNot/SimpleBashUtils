#include "s21_cat.h"

int main(int argc, char *argv[]) {
  options_t vr = {0};
  while ((vr.rez = getopt_long(argc, argv, short_options, long_options,
                               NULL)) != -1) {
    flags(&vr);
  }
  while (argv[optind] != NULL) {
    reading_file(argv[optind], &vr);
    optind++;
  }
  return 0;
}

void options_implementation(FILE *file, options_t *vr) {
  vr->count1 = 0;
  vr->count2 = 0;
  vr->current_position = 0;
  vr->current_line = 0;
  vr->next_line = 0;
  vr->line = 1;
  if (!vr->mistake) {
    while ((vr->ch = fgetc(file)) != EOF) {
      int s = s_options(vr);
      if (s) continue;
      b_options(vr);
      n_options(vr);
      t_options(vr);
      e_options(vr);
      v_options(vr);
      vr->line = (vr->ch == '\n') ? 1 : 0;
      printf("%c", vr->ch);
    }
  }
}

void reading_file(char argv[optind], options_t *vr) {
  FILE *file = fopen(argv, "r");
  if (file != NULL) {
    options_implementation(file, vr);
    fclose(file);
  } else {
    fprintf(stderr, "s21_cat: %s: No such file or directory", argv);
  }
}

void flags(options_t *vr) {
  switch (vr->rez) {
    case 'b':
      vr->bflag = 1;
      break;
    case 'E':
      vr->eflag = 1;
      break;
    case 'e':
      vr->eflag = 1;
      vr->vflag = 1;
      break;
    case 'n':
      vr->nflag = 1;
      break;
    case 's':
      vr->sflag = 1;
      break;
    case 'T':
      vr->tflag = 1;
      break;
    case 't':
      vr->tflag = 1;
      vr->vflag = 1;
      break;
    case 'v':
      vr->vflag = 1;
      break;
    case '?':
    default:
      fprintf(stderr, "usage: s21_cat [-benstv] [file ...]\n");
      vr->mistake = 1;
      break;
  }
}
int s_options(options_t *vr) {
  int a = 0;
  if (vr->sflag) {
    vr->current_line = 0;
    if (!vr->current_position && vr->ch == '\n') vr->current_line = 1;
    if (vr->ch == '\n' && vr->current_position) vr->current_position = 0;
    if (vr->ch != '\n' && !vr->current_position) vr->current_position = 1;
    if (vr->current_line && vr->next_line) a = 1;
    vr->next_line = vr->current_line;
  }
  return a;
}
void b_options(options_t *vr) {
  if (vr->bflag) {
    if (vr->line && vr->ch != '\n') printf("%6d\t", ++vr->count1);
  }
}
void n_options(options_t *vr) {
  if (vr->nflag) {
    if (vr->line && !vr->bflag) printf("%6d\t", ++vr->count2);
  }
}
void t_options(options_t *vr) {
  if (vr->tflag) {
    if (vr->ch == '\t') {
      printf("^");
      vr->ch = 'I';
    }
  }
}
void e_options(options_t *vr) {
  if (vr->eflag) {
    if (vr->ch == '\n') printf("$");
  }
}
void v_options(options_t *vr) {
  if (vr->vflag) {
    if (vr->ch < 32 && vr->ch != 9 && vr->ch != 10) {
      printf("^");
      vr->ch = vr->ch + 64;
    } else if (vr->ch == 127) {
      printf("^");
      vr->ch = vr->ch - 64;
    }
  }
}