#ifndef MTECH__PRETTY_TERMINAL_COLORS_H_
    #define MTECH__PRETTY_TERMINAL_COLORS_H_

    /* Terminal Colors */
    
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
    #include <time.h>
    #define CURRENT_TIME_STR_LEN 25

    static inline const char* _getCurrentTime(void) {
        time_t currentTime;
        time(&currentTime);
        char* strTime = ctime(&currentTime);
        /* Removes the trailing '\n' character */
        strTime[CURRENT_TIME_STR_LEN - 2] = '\0';
        return strTime;
    }


    #include <stdio.h>
    #include <stdarg.h>
    #include <stdbool.h>
    typedef _Bool boolean_t;
    /* TIME | [TYPE] | INFO | PATH */

    static inline void _mlog_logNormal(const char* msg, const char* path) {
        printf("%24s | [NORMAL] | %s | %s \n", _getCurrentTime(), msg, path);
    }


    static inline void _mlog_logFormattedInfo(const char* path, const char* msg, ...) {
        va_list ap;
        va_start(ap, msg);
        printf("%24s | [NORMAL] | ", _getCurrentTime());
        vprintf(msg, ap);
        printf(" | %s \n", path);
        va_end(ap);
    }


    static inline void _mlog_logError(const char* msg, const char* path) {
        fprintf(stderr, "%24s | %s[ERROR]%s | %s | %s \n",\
            _getCurrentTime(), FG_RED, SET_DEFAULT, msg, path);
    }

    static inline void _mlog_logFormattedError(const char* path, const char* msg, ...) {
        va_list ap;
        va_start(ap, msg);
        printf("%24s | %s[ERROR]%s | ", _getCurrentTime(), FG_RED, SET_DEFAULT);
        vfprintf(stderr, msg, ap);
        printf(" | %s \n", path);
        va_end(ap);
    }


    #define MLOG_logNormal(msg) _mlog_logNormal(msg, __FILE__)
    #define MLOG_logFormattedInfo(msg, ...) _mlog_logFormattedInfo(__FILE__, msg, __VA_ARGS__)
    #define MLOG_logError(msg) _mlog_logError(msg, __FILE__)
    #define MLOG_logFormattedError(msg, ...) _mlog_logFormattedError(__FILE__, msg, __VA_ARGS__)

#endif
