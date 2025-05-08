#include <core/logger.h>

int main(void) {
    AFATAL("A test message: %f", 4.24f);
    AERROR("A test message: %f", 4.24f);
    AWARN("A test message: %f", 4.24f);
    AINFO("A test message: %f", 4.24f);
    ADEBUG("A test message: %f", 4.24f);
    ATRACE("A test message: %f", 4.24f);
    return 0;
}