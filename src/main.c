#include "chip.h"
#include "tui.h"

int main(int nargs, char **args) {
    if (nargs != 2) {
        printf("Usage: c8 [ROM]\n");
        exit(0);
    }

    C8State *vm = vm_start();
    renderer_init();

    // load rom
    vm_load(vm, args[1]);

    while (1) {
        renderer_step(vm);
    }

    return 0;
}