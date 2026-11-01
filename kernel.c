void kernel_main(void) {
    volatile unsigned short *video = (volatile unsigned short *)0xB8000;
    const char *msg = " First Step ";

    for (int i = 0; i < 80 * 25; i ++) {
        video[i] = 0x0400 | ' ';
    }

    for (int i = 0; msg[i] != 0; i++) {
      video[80 + i ] = 0x0F00 | (unsigned char)msg[i];
    }
}