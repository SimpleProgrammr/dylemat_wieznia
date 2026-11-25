//
// Created by pelon.michal.158208 on 11/25/26.
//
#pragma once


class SignalHandlers {
public:
    static void setup(int signal, void  handler(int ));
};

void sigquit_handler(int);
