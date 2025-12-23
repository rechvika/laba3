#ifdef LOGENABLED
//#pragma once

#define _LOG(lvl, x) _LOGF(lvl, "%s", x)
#define _LOGF(lvl, fmt, ...) fprintf(stderr, "[%s] | [%s:%s:%d] " \
    fmt "\n", \
    lvl, __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__)

#else
#define _LOG(lvl, x)
#define _LOGF(lvl, fmt, ...)

#endif

#if LOGLVL < 0
#error NEGATIVE LEVEL
#endif

#if LOGLVL >= 0
#undef LERR
#undef LWARN
#undef LDBG
#define LERR(X)
#define LWARN(X)
#define LDBG(X)
#endif

#if LOGLVL >= 1
#undef LERR
#define LERR(X) _LOG("ERR", X)
#endif

#if LOGLVL >= 2
#undef LWARN
#define LWARN(X) _LOG("WRN", X)
#endif

#if LOGLVL >= 3
#undef LDBG
#define LDBG(X) _LOG("DBG", X)
#endif