# M-Logging "Library"
This is my personal logging and testing "library" for my C projects. Granted,
the functionality is very limited, hence the use of "library" instead of
library. I am not of the belief that entire frameworks are the best option
for debugging and testing code. 

## Usage
The M-Logging "library" comes with a few basic functions: `MLOG_log(msg)`,
`MLOG_array_<type>`, `MLOG_error(msg)`, and `MLOG_test(tag, cond)`. There
are also colored/formatted variants of these functions
(e.g. `MLOG_logf(msg, <args>)`, `MLOG_errorc(color, msg)`, or
`MLOG_testfc(color, tag, cond)`). The available colors are prefixed with `TC_`, standing for terminal color (e.g. `TC_RED` and `TC_PURPLE`).

## Syntax 
See [tests.c](tests.c) for full list of examples. 

```
#include "mlogging.h"

int main(void) {
    /* prints "Hello John Doe" in blue */
    MLOG_logf("My name is %s", "John Smith");
    int x = 10;
    /* prints Test "x equals 5": [FAILED] */
    MLOG_test((x == 5), "x equals 5");
}
```
