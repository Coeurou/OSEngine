#include <iostream>
#include <logger.h>

using namespace ose;

int main(int /*argc*/, char* /*argv*/[])
{
    log_debug(log_category::system, "Hello world\n");
    log_info(log_category::system, "Hello world\n");
    log_warning(log_category::system, "Hello world\n");
    log_error(log_category::system, "Hello world\n");
    return EXIT_SUCCESS;
}
