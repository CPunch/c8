#include "chip.h"
#include "tui.h"

int main() {
    C8State *vm = vm_start();
    renderer_init();

    // load rom
    vm_load(vm, "roms/keypad.ch8");

    while (1) {
        renderer_step(vm);
    }

    return 0;
}