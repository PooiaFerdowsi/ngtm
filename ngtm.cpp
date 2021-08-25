#include <stdio.h>

#include <algorithm>
#include <random>

const uint8_t alpha_start = 97;
const uint8_t alpha_end = 122;

bool is_reg(int num) {
    if (num != 97 && num != 101 && num != 105 && num != 111)
        return true;
    return false;
}

int main(int argc, char *argv[]) {
    int range = argv[1] ? atoi(argv[1]) : 5;
    int times = argc > 2 && argv[2] ? atoi(argv[2]) : 1;
    std::random_device device;
    std::default_random_engine engine{device()};
    std::uniform_int_distribution<> generate{alpha_start, alpha_end};
    int prev_rg = 0;
    for (; times > 0; times--) {
        uint16_t idx = 0;
        while (idx < range) {
            int rg = generate(engine);
            if (is_reg(prev_rg) == is_reg(rg) && idx != 0)
                continue;
            printf("%c", rg);
            prev_rg = rg;
            idx++;
        }
        printf("\n");
    }
}