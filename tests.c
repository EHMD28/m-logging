#include "mlogging.h"


int main(void) {
    /* normal logging functions */
    MLOG_log("Hello, World");
    MLOG_logf("My name is %s", "John Smith");
    MLOG_logc(COLOR_BLUE, "Lorem ipsum");
    MLOG_logfc(COLOR_RED, "%s %s", "Merry", "Christmas");

    /* error logging functions */
    MLOG_error("An error occured");
    MLOG_errorf("An %s occured | Code: %d", "error", 404);
    MLOG_errorc(COLOR_BLUE, "Another error occured");
    MLOG_errorfc(COLOR_RED, "This error occured %s", "mistakes were made");

    /* testing functions */

}
