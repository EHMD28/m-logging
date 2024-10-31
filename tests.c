#include "mlogging.h"


int main(void) {
    /* normal logging functions */
    MLOG_log("Hello, World");
    MLOG_logf("My name is %s", "John Smith");
    MLOG_logc(COLOR_BLUE, "Lorem ipsum");
    MLOG_logfc(COLOR_RED, "%s %s", "Merry", "Christmas");

    /* error logging functions */

    /* testing functions */

}
