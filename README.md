## jcomb -- Combine Files

jcomb will combine files created by
[jsplit(1)](https://github.com/jmcunx/jsplit)
and obsolete utility j(1).

This was created for Systems that do not have
an easy method of concatenating Files.

[j\_lib2](https://github.com/jmcunx/j_lib2) is an **optional** dependency.

[GNU automake](https://en.wikipedia.org/wiki/Automake)
only confuses me, but this seems to be good enough for me.

**To compile:**
* If "DESTDIR" is not set, will install under /usr/local
* Execute ./build.sh to create a Makefile
* Works on Linux, BSD and AIX

_To uninstall_, execute
"make uninstall"
from the source directory
