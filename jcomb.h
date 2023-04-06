/*
 * Copyright (c) 2001 2002 ... 2023 2024
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

#define JCOMB_H "INCLUDED"

#define PROG_NAME  "jcomb"

#ifdef DJGPP
#  undef MSDOS
#endif

#if VMS || MSDOS || _WIN32 || __ZTC__ || MSDOSTYPE
#define READ_MODE  "rb"
#define WRITE_MODE "wb"
#define SSIZE_T unsigned long int
#else
#define READ_MODE  "r"
#define WRITE_MODE "w"
#endif

#ifndef JLIB2_CHAR_NULL
#define NO_JLIB 1
#define JLIB2_CHAR_NULL  ((char) '\0')
#endif

#ifndef NULL
#define NULL '\0'
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#ifndef SSIZE_T
#define SSIZE_T ssize_t
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
#ifdef NO_JLIB
typedef unsigned long jm_counter;  /* allow 16 bit systems */
#define ARG_ERR           'e'  /* Output Error File                  */
#define ARG_FORCE         'f'  /* force create files                 */
#define ARG_HELP          'h'  /* Show Help                          */
#define ARG_VERBOSE       'v'  /* Verbose                            */
#define ARG_VERSION       'V'  /* Show Version Information           */
#define FILE_NAME_STDIN   "-"
#define JS_FNAME          "v%07lu.x"   /* see jm_counter above if changed        */
#define JS_MAX_SPLIT      ((jm_counter) 9999999)
#define LIT_INFO_01       "\tBuild: %s %s\n"
#define LIT_REV           "Revision"
#define MSG_ERR_E000      "Try '%s %c%c' for more information\n"
#define MSG_ERR_E002      "ERROR E002: Cannot open '%s' for write, processing aborted\n"
#define MSG_ERR_E025      "ERROR E025: File %s cannot be created, already exists\n"
#define MSG_ERR_E028      "ERROR E028: too many files specified\n"
#define MSG_ERR_E055      "ERROR E055: Write Error on File '%s' : %s\n"
#define MSG_INFO_I006     "I006: Appending %s\n"
#define MSG_INFO_I007     "I007:        to %s\n"
#define MSG_INFO_I008     "I008: File: %s\n      may not exist or error occurred\n"
#define MSG_WARN_W002     "W002: Open Error Bypass File '%s' : %s\n"
#define SWITCH_CHAR       '-'
#define USG_MSG_ARG_ERR          "\t%c%c file\t\t: Write errors to file 'file', default stderr\n"
#define USG_MSG_ARG_FORCE        "\t%c%c\t\t: force create of files when found\n"
#define USG_MSG_ARG_HELP         "\t%c%c\t\t: Show brief help and exit\n"
#define USG_MSG_ARG_VERBOSE_4    "\t%c%c\t\t: Show detail File Stats\n"
#define USG_MSG_ARG_VERSION      "\t%c%c\t\t: Show revision information and exit\n"
#define USG_MSG_OPTIONS          "Options\n"
#define USG_MSG_USAGE_5          "usage:\t%s [OPTIONS] [FILE]\n"
#endif /* NO_JLIB */

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

#ifdef NO_JLIB
char *j2_get_prgname(char *argv_0, char *default_name);
int j2_f_exist(char *file_name);
#endif /* NO_JLIB */

#endif /*  JCOMB_H  */
