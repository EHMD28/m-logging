# M-Logging Library

This is my personal logging library for C. This library is specifically designed
for what I want in a logging library, but feel free to use it for your own
projects.

## Usage
See a full list of examples in [tests.c](tests.c). All of the code is contained
in a single header-file, making it easy to add to a project. There are four
types of logging: standard, error, testing, and panics.

### Standard logging
The standard logging functions are `MLOG.log(msg)`, `MLOG.logf(msg, ...)`,
`MLOG.logc(color, msg)`, `MLOG.logfc(color, msg, ...)`. You can also log arrays
using the `MLOG.{type}_array(arr, arr_size)`. For custom data types, you can use
the `MLOG.array_custom(arr, arr_size, type_size, to_str_fn)`.

```
// Custom Array Logging Example
#include "mlogging.h"

struct Point {
    int a;
    int b;
}

char* point_to_str(void* p) {
    struct Point* point = (struct Point*)p;
    static char buffer[100];
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, 100, "(%d,%d)", point->a, point->b);
    return buffer;
}

int main() {
    struct Point points[] = {
        (struct Point) { 1, 2 },
        (struct Point) { 3, 4 },
        (struct Point) { 5, 6 },
        (struct Point) { 7, 8 },
        (struct Point) { 9, 10 }
    };
    MLOG.array_custom(points, sizeof(points)/sizeof(points[0]),
                        sizeof(struct Point), &point_to_str);
}
```

### Error Logging
The error logging functions are `MLOG.error(msg)`, `MLOG.errorf(msg, ...)`,
`MLOG.errroc(color, msg)`, and `MLOG.errorf(color, msg, ...)`.

### Testing 
M-Logging also comes equipped with the testing functions `MLOG.test(tag, cond)`
and `MLOG.test_equ(tag, equ_func, inp_one, inp_two)`. These functions will
check the condition, and if it is true, then the test will pass, returning 1.
If it is false, then the test will fail, returning 0.

```
// Equality Test Example
#include "mlogging.h"

struct Point {
    int a;
    int b;
};

int points_equal(void* p1, void* p2) {
    struct Point* point_one = p1;
    struct Point* point_two = p2;

    return (point_one->a == point_two->a) && (point_one->b == point_two->b);
}

int main() {
    struct Point p1 = {2, 5};
    struct Point p2 = {2, 5};
    MLOG.test_equ("Points Equal", &points_equal, &p1, &p2);
}
```

### Panicking
M-Logging comes with two functions that will cause the program to immediately
exit: `MLOG.panic(msg)` and `MLOG.panicf(msg, ...)`.
