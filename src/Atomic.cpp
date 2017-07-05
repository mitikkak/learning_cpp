
#include "Exercise.hpp"
#include "Atomic.hpp"
#include <iostream>
#include <vector>
#include <cstdio>
#if __cplusplus > 199711L
#include <thread>
#include <mutex>
static std::mutex barrier;
#include <atomic>
#endif
#include <pthread.h>


// Original at: https://github.com/sol-prog/threads/blob/master/part_2/cpp11_threads_03.cpp


//Split "mem" into "parts", e.g. if mem = 10 and parts = 4 you will have: 0,2,4,6,10
//if possible the function will split mem into equal chuncks, if not
//the last chunck will be slightly larger

std::vector<int> bounds(int parts, int mem) {
    std::vector<int>bnd;
    int delta = mem / parts;
    int reminder = mem % parts;
    int N1 = 0, N2 = 0;
    bnd.push_back(N1);
    for (int i = 0; i < parts; ++i) {
        N2 = N1 + delta;
        if (i == parts - 1)
            N2 += reminder;
        bnd.push_back(N2);
        N1 = N2;
    }
    return bnd;
}

//void dot_product(const std::vector<int> &v1, const std::vector<int> &v2, std::atomic<int> &result, int L, int R){
void dot_product(const std::vector<int> &v1, const std::vector<int> &v2, int &result, int L, int R){
    int partial_sum = 0;
    for(int i = L; i < R; ++i){
//        result += v1[i] * v2[i];
        partial_sum += v1[i] * v2[i];
    }
    result += partial_sum;
}
struct dot_product_old_t
{
    const std::vector<int> &v1;
    const std::vector<int> &v2;
    int &result;
    int L;
    int R;
    dot_product_old_t(const std::vector<int> &v1_, const std::vector<int> &v2_, int &result_, int L_, int R_)
    : v1(v1_), v2(v2_), result(result_), L(L_), R(R_)
    {

    }
};
void* dot_product_old(void* args)
{
    if (args)
    {
        int partial_sum = 0;
        dot_product_old_t& data = *(dot_product_old_t*) args;
        for(int i = data.L; i < data.R; ++i){
//            data.result += data.v1[i] * data.v2[i];
            partial_sum += data.v1[i] * data.v2[i];
        }
        data.result += partial_sum;
    }
    return NULL;
}

void Atomic::execute()
{
    int nr_elements = 1000000;
    int nr_threads = 6;
//    std::atomic<int> result(0);
    int result = 0;
#if __cplusplus > 199711L
    std::vector<std::thread> threads;
#else
    std::vector<pthread_t> threads;
#endif
    //Fill two vectors with some values
    std::vector<int> v1(nr_elements,1), v2(nr_elements,2);

    //Split nr_elements into nr_threads parts
    std::vector<int> limits = bounds(nr_threads, nr_elements);

    //Launch nr_threads threads:
    for (int i = 0; i < nr_threads; ++i) {
#if __cplusplus > 199711L
        threads.push_back(std::thread(dot_product, std::ref(v1), std::ref(v2), std::ref(result), limits[i], limits[i+1]));
#else
        pthread_t t;
        dot_product_old_t data(v1, v2, result, limits[i], limits[i+1]);
        pthread_create(&t, NULL, dot_product_old, (void*) &data);
        threads.push_back(t);
#endif
    }


#if __cplusplus > 199711L
    //Join the threads with the main thread
    for(auto &t : threads){
        t.join();
    }
#else
    for (std::vector<pthread_t>::iterator it = threads.begin(); it != threads.end(); ++it)
    {
        pthread_join(*it, NULL);
    }
#endif

    //Print the result
//    printf("Atomic:: result %u \n", result.load() );
    printf("Atomic:: result %u \n", result );
    log();
}


