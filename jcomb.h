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

#ifndef JCOMB_H

#define JCOMB_H "$Id: jcomb.h,v 3.3 2020/06/14 16:46:25 jmccue Exp $"

#define PROG_NAME  "jcomb"

#ifdef DJGPP
#  undef MSDOS
#endif

#if VMS || MSDOS || _WIN32 || __ZTC__ || MSDOSTYPE
#define READ_MODE  "rb"
#define WRITE_MODE "wb"
#else
#define READ_MODE  "r"
#define WRITE_MODE "w"
#endif

/*** structures ***/
struct s_file_info
  {
    FILE *fp;
    char *fname;
  } ;

struct s_work
  {
    struct s_file_info out;         /* default stdout        */
    struct s_file_info err;         /* default stderr        */
    char *prog_name;                /* real program name     */
    int num_files;                  /* # of files to process */
    int verbose;                    /* TRUE or FALSE         */
    int force;                      /* TRUE or FALSE         */
  } ;

/*** messages ***/

/*** prototypes ***/
void init(int, char **, struct s_work *);
void init_finfo(struct s_file_info *);
int  show_brief_help(FILE *, char *);
int  show_rev(FILE *, char *);
void process_arg(int, char **, struct s_work *);
int  open_out(FILE *, struct s_file_info *, char *, int);
void close_out(struct s_file_info *);
void close_in(FILE **, char *);
char *get_progname(char *, char *);

#endif /*  JCOMB_H  */

/******************************* END: jcomb.h ********************************/
