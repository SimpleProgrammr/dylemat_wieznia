//
// Created by Elmo on 24/11/2026.
//

#pragma once
#include <list>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <sys/fcntl.h>
#include <sys/semaphore.h>
#include <sys/_types/_s_ifmt.h>

class Intercoms {

    std::map<sem_t *, const char*> semaphores;


    public:
    Intercoms() :semaphores() {};

    ~Intercoms() {
        for (auto [ptr, name] : semaphores) {
            sem_close(ptr);
            sem_unlink(name);
        }
    };

    sem_t *get_sem(const char *name, int oflag, int perm, int value) {
        sem_t *sem = sem_open(name, oflag, perm, value);
        semaphores.emplace(sem, name);
        return sem;
    }

    void close_sem(sem_t *sem) {

        sem_close(sem);
        sem_unlink(semaphores[sem]);

        semaphores.erase(sem);
    }

    

};
