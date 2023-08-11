# m-logging header file
__My personal logging "framework." Feel free to use it for your own projects__

## Functions
- MLOG_error(err: str) -> writes error to stderr filestream.
- MLOG_formatted_error(err: str, fmt) -> writes error to stderr filestream.
  - @param err: message to be written (including format specifiers)
  - @param fmt: values for each format specifier (seperated by commas)
- MLOG_output_test(description, expectedOutput, input) -> prints \[PASSED\] if expectedOutput equals input; prints \[FAILED\] if expectedOutput does not equal input.
- MLOG_log_array(arr, arrSize: int, formatSpecifier: str) -> logs all of elements in an array, including the index.
  - ARR_SIZE(arr) -> expands to sizeof(arr) / sizeof(arr\[0\])
- MLOG_log_matrix(description: str, arr, formatSpecifier: str, width: int, height: int) -> prints out matrix/2D array. Included title and labels each array with an index.
- MLOG_log_variable(label, varName, formatSpecifier) -> prints out value of variable using label.
- MLOG_normal(output) -> logs unformatted string to stdout filestream.
