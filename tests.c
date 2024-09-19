#include "mlogging.h"

int main(void) {
    /* normal */
    MLOG_logNormal("Message One");
    MLOG_logFormattedInfo("Message Two | %s: %d", "John Smith", 24);

    /* errors */
    MLOG_logError("Error One");
    MLOG_logFormattedError("Error Two | An error occured: %s", "error");

    /* tests */
    MLOG_run_tests("Test One", (1 < 2));
    MLOG_run_tests("Test Two", (5 == 1));
}
