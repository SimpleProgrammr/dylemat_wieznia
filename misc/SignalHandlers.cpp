//
// Created by pelon.michal.158208 on 11/25/26.
//

#include <signal.h>
#include "SignalHandlers.h"

#include <cerrno>
#include <cstdio>
#include <iostream>
#include <string>
#include <asm-generic/errno-base.h>


void SignalHandlers::setup(const int signal, void handler(int)) {

    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(signal, &sa, nullptr) == -1) {
        if (errno != EINVAL) {
            perror(("Sigaction for " + std::to_string(signal) + " failed").c_str());
            exit(SIGABRT);
        }
    }


}

void sigquit_handler(int s) {
    std::cerr << "File \'./config/payout_table.txt\' could not be open";
    exit(s);
}
