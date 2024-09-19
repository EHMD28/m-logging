#ifndef MTECH__PRETTY_TERMINAL_COLORS_H_
    #define MTECH__PRETTY_TERMINAL_COLORS_H_

    /** Terminal Colors */
    
    /* Reset */
    #define SET_DEFAULT "\033[0m"
    /* Foreground Colors */
    #define FG_BLACK  "\033[0;30m"
    #define FG_RED    "\033[0;31m"
    #define FG_GREEN  "\033[0;32m"
    #define FG_YELLOW "\033[0;33m"
    #define FG_BLUE   "\033[0;34m"
    #define FG_PURPLE "\033[0;35m"
    #define FG_CYAN   "\033[0;36m"
    #define FG_WHITE  "\033[0;37m"
    /* Background Colors */
    #define BG_BLACK  "\033[40m"
    #define BG_RED    "\033[41m"
    #define BG_GREEN  "\033[42m"
    #define BG_YELLOW "\033[43m"
    #define BG_BLUE   "\033[44m"
    #define BG_PURPLE "\033[45m"
    #define BG_CYAN   "\033[46m"
    #define BG_WHITE  "\033[47m"

    /* Logging Functions */

    #include <stdio.h>

    static inline void MLOG_run_tests(const char* tag, int cond) {
        if (cond) {
            printf("%s: %s[PASS]%s\n", tag, FG_GREEN, SET_DEFAULT);
        } else {
            printf("%s: %s[FAIL]%s\n", tag, FG_RED, SET_DEFAULT);
        }
    }

#endif
