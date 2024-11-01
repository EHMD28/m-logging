#include "mlogging.h"


int main(void) {
    /* normal logging functions */
    MLOG_log("Hello, World");
    MLOG_logf("My name is %s", "John Smith");
    MLOG_logc(TC_BLUE, "Lorem ipsum");
    MLOG_logfc(TC_RED, "%s %s", "Merry", "Christmas");

    /* array logging functions */
    MLOG_array_int(((int[]) {1, 2, 3, 4, 5}), 5);
    MLOG_array_char(((char[]) {'H', 'e', 'l', 'l', 'o'}), 5);
    MLOG_array_double(((double[]) {3.14, 2.72, 1.62, 0.886}), 4);
    MLOG_array_str(((char* []) {"Euler", "Gauss", "Laplace", "Fourier"}), 4);

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
