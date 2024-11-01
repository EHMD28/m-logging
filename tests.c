#include "mlogging.h"


int main(void) {
    /* normal logging functions */
    MLOG_log("Hello, World");
    MLOG_logf("My name is %s", "John Smith");
    MLOG_logc(TC_BLUE, "Lorem ipsum");
    MLOG_logfc(TC_RED, "%s %s", "Merry", "Christmas");

    /* error logging functions */
    MLOG_error("An error occured");
    MLOG_errorf("An %s occured | Code: %d", "error", 404);
    MLOG_errorc(TC_BLUE, "Another error occured");
    MLOG_errorfc(TC_RED, "This error occured %s", "mistakes were made");

    /* testing functions */
    MLOG_test(5 == 5, "Obvious");
    MLOG_testf(5 == 10, "Still %s", "obvious");
    MLOG_testc(TC_BLUE, (1 == 1), "checking if math still works");
    MLOG_testfc(TC_RED, (4 == 2.0), "Funny number %d", 420);
}
