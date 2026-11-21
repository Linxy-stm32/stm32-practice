#include <stdint.h>

volatile uint32_t counter = 0;

int main(void)
{
    for (;;)
    {
        counter++;
    }
}
