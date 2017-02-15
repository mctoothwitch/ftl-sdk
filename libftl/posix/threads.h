/**
* \file threads.h - Posix Threads Abstractions
*
* Copyright (c) 2015 Stefan Slivinski
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
**/

#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "gettimeofday/gettimeofday.h"

typedef pthread_mutex_t OS_MUTEX;
typedef bool BOOL;

typedef pthread_t OS_THREAD_HANDLE;
typedef void* OS_THREAD_TYPE;
typedef void* OS_THREAD_ROUTINE;
typedef void* OS_THREAD_START_ROUTINE;
typedef void OS_THREAD_ATTRIBS; //todo implement attributes

typedef struct {
	sem_t *sem;
	char *name;
}OS_SEMAPHORE;

int os_init();

int os_create_thread(OS_THREAD_HANDLE *handle, OS_THREAD_ATTRIBS *attibs, OS_THREAD_START_ROUTINE func, void *args);
int os_destroy_thread(OS_THREAD_HANDLE handle);
int os_wait_thread(OS_THREAD_HANDLE handle);

int os_init_mutex(OS_MUTEX *mutex);
int os_lock_mutex(OS_MUTEX *mutex);
int os_trylock_mutex(OS_MUTEX *mutex);
int os_unlock_mutex(OS_MUTEX *mutex);
int os_delete_mutex(OS_MUTEX *mutex);

int os_semaphore_create(OS_SEMAPHORE *sem, const char *name, int oflag, unsigned int value);
int os_semaphore_pend(OS_SEMAPHORE *sem, int ms_timeout);
int os_semaphore_post(OS_SEMAPHORE *sem);
int os_semaphore_delete(OS_SEMAPHORE *sem);

void sleep_ms(int ms);


