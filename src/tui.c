#include "tui.h"
#include "chip.h"

WINDOW *mainw;

void renderer_init(C8State *v) {
    mainw = initscr();
    raw();
    noecho();
    //halfdelay(1);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    clear();
}

void renderer_refresh(C8State *vm) {
    for (int row = 0; row < VGFX; row++) {
        for (int col = 0; col < HGFX; col++) 
            mvprintw(row, col, vm->frame[row][col] ? "#" : " ");
    }

    // print the screen
    refresh();
}

C8KEY getC8Key(int c) {
    switch (c) {
        case '1': case '!': return C8KEY_1;
        case '2': case '@': return C8KEY_2;
        case '3': case '#': return C8KEY_3;
        case '4': case '$': return C8KEY_C;
        case 'q': case 'Q': return C8KEY_4;
        case 'w': case 'W': return C8KEY_5;
        case 'e': case 'E': return C8KEY_6;
        case 'r': case 'R': return C8KEY_D;
        case 'a': case 'A': return C8KEY_7;
        case 's': case 'S': return C8KEY_8;
        case 'd': case 'D': return C8KEY_9;
        case 'f': case 'F': return C8KEY_E;
        case 'z': case 'Z': return C8KEY_A;
        case 'x': case 'X': return C8KEY_0;
        case 'c': case 'C': return C8KEY_B;
        case 'v': case 'V': return C8KEY_F;
    default:
        return C8KEY_MAX; // error return
    }
}

int grabkeys(C8State *vm) {
    int c;
    int pressed = -1;

    // first, reset the keys
    for (int i = 0; i < C8KEY_MAX; i++)
        vm_setKey(vm, i, 0);

    // while there are still keys to grab, set the keys in the vm
    while ((c = getch()) != ERR) {
        C8KEY key = getC8Key(c);
        mvprintw(0, 1, "got key '%c' : %d ", c, key);
        refresh();
        if (key != C8KEY_MAX) {
            vm_setKey(vm, key, 1);
            pressed = key;
        } else if (c == 3 || c == 27) { // if esc or ctrl^c
            endwin();
            exit(0);
        }
    }

    return pressed;
}

int renderer_waitforinput(C8State *vm) {
    int key;
    while ((key = grabkeys(vm)) == -1);
    mvprintw(0, 1, "returning");
    refresh();
    return key;
}

int renderer_step(C8State *vm) {
    // tick the vm
    vm_tick(vm);
    grabkeys(vm);

    return 0;
}