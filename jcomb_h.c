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
 * jcomb_h.c -- Show/help routines
*/

#include <sys/param.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <j_lib2.h>
#include <j_lib2m.h>

#include "jcomb.h"

char *jcomb_h_c="$Id: jcomb_h.c,v 3.7 2021/02/21 19:30:27 jmccue Exp $";

extern char *jcomb_c;
extern char *jcomb_a_c;
extern char *jcomb_i_c;
extern char *jcomb_h_c;
extern char *jcomb_u_c;

/*** Messages ***/
#define MSG_HELP_11 "    Combines Files created by jsplit(local) into file 'FILE'"
#define MSG_HELP_12 "    (or stdout if no FILE).   All input files are formatted"
#define MSG_HELP_13 "    as v#######.x where ####### is a 7 digit number.  Input"
#define MSG_HELP_14 "    files must reside in the current directory."

/*
 * show_brief_help()
 */
int show_brief_help(FILE *fp, char *pname)

{

  fprintf(fp, USG_MSG_USAGE_5, pname);
  fprintf(fp, "\t%s\n", MSG_HELP_11);
  fprintf(fp, "\t%s\n", MSG_HELP_12);
  fprintf(fp, "\t%s\n", MSG_HELP_13);
  fprintf(fp, "\t%s\n", MSG_HELP_14);
  fprintf(fp, USG_MSG_OPTIONS);
  fprintf(fp, USG_MSG_ARG_ERR,       SWITCH_CHAR, ARG_ERR);
  fprintf(fp, USG_MSG_ARG_FORCE,     SWITCH_CHAR, ARG_FORCE);

  fprintf(fp, USG_MSG_ARG_HELP,      SWITCH_CHAR, ARG_HELP);
  fprintf(fp, USG_MSG_ARG_VERBOSE_4, SWITCH_CHAR, ARG_VERBOSE);
  fprintf(fp, USG_MSG_ARG_VERSION,   SWITCH_CHAR, ARG_VERSION);

  return(EXIT_FAILURE);

}  /* show_brief_help() */

/*
 * show_rev()
 */
int show_rev(FILE *fp, char *pname)

{

  fprintf(fp,"%s %s:\n", pname, LIT_REV);
  fprintf(fp,"\t%s\n", JCOMB_H);
  fprintf(fp,"\t%s\n", jcomb_c);
  fprintf(fp,"\t%s\n", jcomb_a_c);
  fprintf(fp,"\t%s\n", jcomb_h_c);
  fprintf(fp,"\t%s\n", jcomb_i_c);
  fprintf(fp,"\t%s\n", jcomb_u_c);
#ifdef J_LIB2_H
  fprintf(fp, "\t%s\n", J_LIB2_H);
  fprintf(fp,"\t     %s %s\n", LIT_INFO_02, j2_get_build());
#endif

#ifdef J_LIB2M_H
  fprintf(fp, "\t%s\n", J_LIB2M_H);
#endif

#ifdef OSTYPE
  fprintf(fp,"\t%s\n",OSTYPE);
#endif  /* OSTYPE  */
#ifdef PRETTY_NAME
  fprintf(fp,"\t%s\n",PRETTY_NAME);
#endif  /* PRETTY_NAME  */
  fprintf(fp, LIT_INFO_01, __DATE__, __TIME__);

  return(EXIT_FAILURE);

}  /* show_rev() */

/* END: jcomb_h.c */
