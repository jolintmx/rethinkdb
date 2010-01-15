
#ifndef __WORKER_POOL_HPP__
#define __WORKER_POOL_HPP__

#include "event_queue.hpp"

// Worker pool
struct worker_pool_t {
    event_queue_t *workers;
    int nworkers;
    int active_worker;
    pthread_t main_thread;
};

void create_worker_pool(worker_pool_t *worker_pool, event_handler_t event_handler, pthread_t main_thread);
void create_worker_pool(worker_pool_t *worker_pool, event_handler_t event_handler, pthread_t main_thread,
                        int workers);
void destroy_worker_pool(worker_pool_t *worker_pool);
event_queue_t* next_active_worker(worker_pool_t *worker_pool);

#endif // __WORKER_POOL_HPP__

