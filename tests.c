#include "mlogging.h"
#include <string.h>

#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

void log_normal(void) {
    MLOG.log("Hello, World");
    MLOG.logf("Hello %s World", "Blue");
    MLOG.logc(MLOG_Color.Blue, "Blue World");
    MLOG.logfc(MLOG_Color.Red, "%s World", "Red");
}

struct Point {
    int a;
    int b;
};

struct Point new_point(int a, int b) {
    return (struct Point){
        .a = a,
        .b = b,
    };
}

char* point_to_str(void* p) {
    struct Point* point = (struct Point*)p;
    static char buffer[100];
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, 100, "(%d,%d)", point->a, point->b);
    return buffer;
}

void log_arrays(void) {
    char char_array[] = {'H', 'e', 'l', 'l', 'o'};
    MLOG.char_array(char_array, ARR_SIZE(char_array));
    short short_array[] = {0, 1, 2, 3, 4};
    MLOG.short_array(short_array, ARR_SIZE(short_array));
    int int_array[] = {5, 6, 7, 8, 9};
    MLOG.int_array(int_array, ARR_SIZE(int_array));
    long long_array[] = {10, 11, 12, 13, 14};
    MLOG.long_array(long_array, ARR_SIZE(long_array));
    long long long_long_array[] = {15, 16, 17, 18, 19};
    MLOG.long_long_array(long_long_array, ARR_SIZE(long_long_array));
    struct Point points[] = {new_point(1, 2), new_point(3, 4), new_point(5, 6),
                             new_point(7, 8), new_point(9, 10)};
    MLOG.array_custom(points, ARR_SIZE(points), sizeof(struct Point),
                      &point_to_str);
}

void log_error(void) {
    MLOG.error("An error occured");
    MLOG.errorf("This error occured: %s", "Never gonna give you up...");
    MLOG.errorc(MLOG_Color.Green, "A green error occured");
    MLOG.errorfc(MLOG_Color.Purple, "A %s error occured", "purple");
}

int points_equal(void* p1, void* p2) {
    struct Point* point_one = p1;
    struct Point* point_two = p2;

    return (point_one->a == point_two->a) && (point_one->b == point_two->b);
}

void log_tests(void) {
    MLOG.test("2 + 4", (2 + 4) == 6);
    MLOG.test("String Comparison", strcmp("John", "john") == 0);
    struct Point p1 = {2, 5};
    struct Point p2 = {2, 5};
    MLOG.test_equ("Points Equal", &points_equal, &p1, &p2);
}

void log_panic(void) {
    MLOG.panic("Very bad error occured");
    // vv The lines below are unreachable because panic makes program exit vv
    //  MLOG.panicf("Don't think. Just %s", "panic");

    /* The first argument can also be NULL if you don't want to provide
        additional information. __FILE__ and __LINE__ are macros which are to
       create a barebones stack trace. */
    // MLOG.todo("Finish integrating library first", __FILE__, __LINE__);
}

int main(void) {
    /*
        Trying uncommenting each of the lines one at a time and see how that
        affects the output.
    */
    // MLOG.set_config(MLOG_CONF_ALL_ON);
    // MLOG.set_config(MLOG_CONF_ALL_OFF);
    // MLOG.set_config(MLOG_CONF_LOG_ON);
    // MLOG.set_config(MLOG_CONF_ERR_ON);
    // MLOG.set_config(MLOG_CONF_TEST_ON);
    // MLOG.set_config(MLOG_CONF_PANIC_ON);
    // MLOG.set_config(MLOG_CONF_LOG_ON | MLOG_CONF_TEST_ON);

    log_normal();
    log_arrays();
    log_error();
    log_tests();
    log_panic();
}
