#include <algorithm.h>
#include <container.h>
#include <kabuto.h>
#include <logger.h>

#include <iostream>

using namespace ose;

int main(int argc, char* argv[]) {
    string cmd_line = "";

    for (auto i = 1; i < argc; i++) {
        cmd_line += ' ';
        cmd_line += argv[i];
    }
    log_debug(log_category::system, "{}\n", cmd_line);
    scanner scanner(cmd_line);
    return scanner.scan() ? EXIT_SUCCESS : EXIT_FAILURE;
}
