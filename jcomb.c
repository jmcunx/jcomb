/*
 * Copyright (c) 2001 2002 ... 2020 2021
 *     John McCue <jmccue@jmcunx.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
/*
* COMBines split binary files created by j into one file
*/
#include <sys/param.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#ifdef IS_BSD
#include <err.h>
#endif

#include <j_lib2.h>
#include <j_lib2m.h>

#include "jcomb.h"

int do_file(char *, struct s_work *);

char *jcomb_c="$Id: jcomb.c,v 3.11 2021/02/21 19:30:27 jmccue Exp $";

#define FFMT 15

/*
* main()
*/
int main(int argc, char **argv)
{
  jm_counter i;
  char fname[FFMT];
  struct s_work w;

#ifdef OpenBSD
  if (pledge("stdio rpath wpath cpath",NULL) == -1)
    err(1,"pledge\n");
#endif

  init(argc, argv, &w);

  for (i = 1; i <= (jm_counter) JS_MAX_SPLIT; i++)
    {
      snprintf(fname, FFMT, JS_FNAME, i);
      if (do_file(fname, &w) != 0)
	{
	  if (w.verbose)
	    fprintf(w.err.fp, MSG_INFO_I008, fname);
	  break;
	}
    }

  close_out(&(w.out));
  if (w.num_files == 0)
    {
      fprintf(w.err.fp, MSG_ERR_E000, w.prog_name, SWITCH_CHAR, ARG_HELP);
      close_out(&(w.err));
      exit(EXIT_FAILURE);
    }
  else
    {
      close_out(&(w.err));
      exit(EXIT_SUCCESS);
    }

}  /* main() */

/*
* do_file() -- Process a split file
*/
int do_file(char *ifile, struct s_work *w)
{
  FILE *ifp;
  int n;
  int errsave;
  char buf[BUFSIZ];

  if (w->verbose)
    {
      fprintf(w->err.fp, MSG_INFO_I006, ifile);
      fprintf(w->err.fp, MSG_INFO_I007, w->out.fname);
      fflush(w->err.fp);
    }

  ifp = fopen(ifile, READ_MODE);
  errsave = errno;

  if (ifp != (FILE *) NULL)
    (w->num_files)++;
  else
    {
      if ((w->verbose) || (w->num_files == 0))
	fprintf(w->err.fp, MSG_WARN_W002, ifile, strerror(errsave));
      return(1);
    }

  while ((n = fread(buf, 1, BUFSIZ, ifp)) != 0)
    {
      if (fwrite(buf, 1, n, w->out.fp) != n)
	{
	  fprintf(w->err.fp, MSG_ERR_E055, w->out.fname, strerror(errsave));
	  exit(EXIT_FAILURE);
	}
    }

  fclose(ifp);

  return(0);

} /* do_file() */

/* END: jcomb.c */
