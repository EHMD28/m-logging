#ifndef MLOGGING_LIBRARY_H_
    #define MLOGGING_LIBRARY_H_

    /** Terminal Colors */
    
    /* Reset */
    #define SET_DEFAULT "\033[0m"
    /* Foreground Colors */
    #define NO_COLOR SET_DEFAULT
    #define COLOR_BLACK  "\033[0;30m"
    #define COLOR_RED    "\033[0;31m"
    #define COLOR_GREEN  "\033[0;32m"
    #define COLOR_YELLOW "\033[0;33m"
    #define COLOR_BLUE   "\033[0;34m"
    #define COLOR_PURPLE "\033[0;35m"
    #define COLOR_CYAN   "\033[0;36m"
    #define COLOR_WHITE  "\033[0;37m"

    /* Logging Functions */

    #include <stdio.h>
    #include <stdarg.h>
    
    /* basic logging */

    // ! WARNING: this function should not be called directly. Instead, use corresponding macro 
    // * Newline is included as part of function. 
    static void mlog_log(const char* msg) {
        printf("%s\n", msg);
    }

    // ! WARNING: this function should not be called directly. Instead, use corresponding macro.
    // * Newline is included as part of function. 
    static void mlog_logf(const char* msg, ...) {
        va_list args;
        va_start(args, msg);
        vprintf(msg, args);
        puts("");
        va_end(args);
    }

    // ! WARNING: this function should not be called directly. Instead, use corresponding macro.
    // * Newline is included as part of function. 
    static void mlog_logc(const char* color, const char* msg) {
        printf("%s%s%s\n", color, msg, NO_COLOR);
    }

    // ! WARNING: this function should not be called directly. Instead, use corresponding macro.
    // * Newline is included as part of function. 
    static void mlog_logfc(const char* color, const char* msg, ...) {
        va_list args;
        va_start(args, msg);
        printf("%s", color);
        vprintf(msg, args);
        puts(NO_COLOR);
        va_end(args);

    }

    /* error logging */


    /* test logging */


    #ifndef NMLOG
        /* standard */
        #define MLOG_log(msg) mlog_log(msg); 
        #define MLOG_error(msg) ;
        #define MLOG_test(cond, msg) ;

        /* format */
        #define MLOG_logf(msg, ...) mlog_logf(msg, __VA_ARGS__); 
        #define MLOG_errorf(msg, ...) ;
        #define MLOG_testf(cond, msg) ;

        /* color */
        #define MLOG_logc(color, msg) mlog_logc(color, msg); 
        #define MLOG_errorc(color, msg) ;
        #define MLOG_testc(color, cond, msg) ;

        /* color and format */
        #define MLOG_logfc(color, msg, ...) mlog_logfc(color, msg, __VA_ARGS__); 
        #define MLOG_errorfc(color, msg, ...) ;
        #define MLOG_testfc(color, cond, msg, ...) ;
    #endif

    #ifdef NMLOG
        #define MLOG_log(msg) ; 
        #define MLOG_error(msg) ;
        #define MLOG_test(cond, msg) ;

        #define MLOG_logf(msg, ...) ; 
        #define MLOG_errorf(msg, ...) ;
        #define MLOG_testf(cond, msg) ;

        #define MLOG_logc(color, msg) ; 
        #define MLOG_errorc(color, msg) ;
        #define MLOG_testc(color, cond, msg) ;

        #define MLOG_logfc(color, msg, ...) ; 
        #define MLOG_errorfc(color, msg, ...) ;
        #define MLOG_testfc(color, cond, msg, ...) ;
    #endif
#endif
