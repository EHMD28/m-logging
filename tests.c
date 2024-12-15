#include "mlogging.h"

typedef struct Foo {
    int a;
    int b;
} Foo;

void print_foo(struct Foo* value) {
    printf("(%d, %d)", value->a, value->b);
}

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
    struct Foo foos[] = { (Foo) {1,2}, (Foo) {3,4}, (Foo) {5,6} };
    MLOG_array_custom(foos, 3, print_foo);

    /* error logging functions */
    MLOG_error("An error occured");
    MLOG_errorf("An %s occured | Code: %d", "error", 404);
    MLOG_errorc(TC_BLUE, "Another error occured");
    MLOG_errorfc(TC_RED, "This error occured %s", "mistakes were made");

    /* testing functions */
    MLOG_test("5 == 5", 5==5);
    MLOG_testc("1 == 2", TC_BLUE, (1 == 2));
}
