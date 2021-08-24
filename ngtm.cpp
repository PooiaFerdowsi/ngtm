#include <stdio.h>

#include <algorithm>
#include <random>
#include <vector>

const uint8_t alpha_start = 97;
const uint8_t alpha_end = 122;

bool is_reg(int num) {
    // a, e, i, o
    if (num != 97 && num != 101 && num != 105 && num != 111) {
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    // range: letters count
    int range = argv[1] ? atoi(argv[1]) : 5;
    // times: how many times generated
    int times = argv[2] ? atoi(argv[2]) : 1;
    std::random_device device;
    std::default_random_engine engine{device()};
    std::uniform_int_distribution<> generate{alpha_start, alpha_end};
    int prev_num = 0;
    for (; times > 0; times--) {
        int idx = 0;
        while (idx < range) {
            int rg = generate(engine);
            if (is_reg(prev_num) && is_reg(rg) && idx != 0) {
                continue;
            }
            printf("%c", rg);
            prev_num = rg;
            idx++;
        }
        printf("\n");
    }
}