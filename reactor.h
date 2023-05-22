#ifndef _REACTOR_H_
#define _REACTOR_H_

#include <pthread.h>
#include <poll.h>

#define MAX_FD 1024

typedef void (*handler_t)(int);

typedef struct reactor_t {
    struct pollfd fds[MAX_FD];
    handler_t handlers[MAX_FD];
    int fd_count;
    int running;
    pthread_t thread;
} reactor_t;

reactor_t* createReactor();
void stopReactor(reactor_t* reactor);
void startReactor(reactor_t* reactor);
void addFd(reactor_t* reactor, int fd, handler_t handler);
void waitFor(reactor_t* reactor);

#endif // _REACTOR_H_
