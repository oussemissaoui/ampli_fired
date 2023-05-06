#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string.h>

//arduino
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <sys/select.h>
#include "arduino.h"


int serialport_init(const char* serialport, int baud){
    struct termios toptions;
    int fd;

    //fd = open(serialport, O_RDWR | O_NOCTTY | O_NDELAY);
    fd = open(serialport, O_RDWR | O_NONBLOCK );

    if (fd == -1)  {
        perror("serialport_init: Unable to open port ");
        return -1;
    }

    //int iflags = TIOCM_DTR;
    //ioctl(fd, TIOCMBIS, &iflags);     // turn on DTR
    //ioctl(fd, TIOCMBIC, &iflags);    // turn off DTR

    if (tcgetattr(fd, &toptions) < 0) {
        perror("serialport_init: Couldn't get term attributes");
        return -1;
    }
    speed_t brate = baud; // let you override switch below if needed
    switch(baud) {
    case 4800:   brate=B4800;   break;
    case 9600:   brate=B9600;   break;
#ifdef B14400
    case 14400:  brate=B14400;  break;
#endif
    case 19200:  brate=B19200;  break;
#ifdef B28800
    case 28800:  brate=B28800;  break;
#endif
    case 38400:  brate=B38400;  break;
    case 57600:  brate=B57600;  break;
    case 115200: brate=B115200; break;
    }
    cfsetispeed(&toptions, brate);
    cfsetospeed(&toptions, brate);

    // 8N1
    toptions.c_cflag &= ~PARENB;
    toptions.c_cflag &= ~CSTOPB;
    toptions.c_cflag &= ~CSIZE;
    toptions.c_cflag |= CS8;
    // no flow control
    toptions.c_cflag &= ~CRTSCTS;

    //toptions.c_cflag &= ~HUPCL; // disable hang-up-on-close to avoid reset

    toptions.c_cflag |= CREAD | CLOCAL;  // turn on READ & ignore ctrl lines
    toptions.c_iflag &= ~(IXON | IXOFF | IXANY); // turn off s/w flow ctrl

    toptions.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // make raw
    toptions.c_oflag &= ~OPOST; // make raw

    // see: http://unixwiz.net/techtips/termios-vmin-vtime.html
    toptions.c_cc[VMIN]  = 0;
    toptions.c_cc[VTIME] = 0;
    //toptions.c_cc[VTIME] = 20;

    tcsetattr(fd, TCSANOW, &toptions);
    if( tcsetattr(fd, TCSAFLUSH, &toptions) < 0) {
        perror("init_serialport: Couldn't set term attributes");
        return -1;
    }

    return fd;
}


//-----mine------


void InitArduino(ArduinoMaster *ard_ms){
    ard_ms->dev_name = "/dev/ttyUSB0";
    ard_ms->ard_return = "";
    int byte_nb = 9600;

    int fd = serialport_init(ard_ms->dev_name, byte_nb);
    if (fd == -1) {
        printf("Error: could not open serial port.\n");
        //return -1;
    }
}

void read_from_arduino(ArduinoMaster *ard_ms){

   int fd = open(ard_ms->dev_name, O_RDONLY | O_NOCTTY | O_NONBLOCK);
    if (fd < 0) {
        //printf("Error opening serial port: %s\n", strerror(errno));
        return;
    }

    struct termios options;
    tcgetattr(fd, &options);
    cfsetspeed(&options, B9600);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_iflag |= IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcsetattr(fd, TCSANOW, &options);

    char buf[1024];
    int nbytes = read(fd, buf, sizeof(buf) - 1);
    if (nbytes < 0) {
        printf("Error reading from serial port: %s\n", strerror(errno));
        close(fd);
        return;
    }
    buf[nbytes] = '\0';

    //printf("Data received from Arduino: %s\n", buf);

    ard_ms->ard_return = strdup(buf);

    close(fd);
}

int ArduinoKeyCheck(ArduinoMaster *ard_ms, char *key_str){
    char to_check[50];
    strcpy(to_check, "");

    if (ard_ms->ard_return != NULL && strstr(ard_ms->ard_return, "left_start")) {
        //printf("Yes\n");
        strcpy(to_check, "left_start");
    }

    if (ard_ms->ard_return != NULL && strstr(ard_ms->ard_return, "right_start")) {
        //printf("Yes\n");
        strcpy(to_check, "right_start");
    }

    if (ard_ms->ard_return != NULL && strstr(ard_ms->ard_return, "interact")) {
        //printf("Yes\n");
        strcpy(to_check, "interact");
    }

    if (ard_ms->ard_return != NULL && strstr(ard_ms->ard_return, "left_right_null")) {
        //printf("Yes\n");
        strcpy(to_check, "left_right_null");
    }

    if (ard_ms->ard_return != NULL && strstr(ard_ms->ard_return, "up_start")) {
        //printf("Yes\n");
        strcpy(to_check, "up_start");
    }

    if (ard_ms->ard_return != NULL && strstr(ard_ms->ard_return, "down_start")) {
        //printf("Yes\n");
        strcpy(to_check, "down_start");
    }

    if (ard_ms->ard_return != NULL && strstr(ard_ms->ard_return, "left_right_null")) {
        //printf("Yes\n");
        strcpy(to_check, "left_right_null");
    }

    if (ard_ms->ard_return != NULL && strstr(ard_ms->ard_return, "up_down_null")) {
        //printf("Yes\n");
        strcpy(to_check, "up_down_null");
    }

    if (ard_ms->ard_return != NULL && strstr(ard_ms->ard_return, "blaster")) {
        //printf("Yes\n");
        strcpy(to_check, "blaster attack");
    }

    if (ard_ms->ard_return != NULL && strstr(ard_ms->ard_return, "attack")) {
        //printf("Yes\n");
        strcpy(to_check, "normal attack");
    }

    if (ard_ms->ard_return != NULL && strstr(ard_ms->ard_return, "heal")) {
        //printf("Yes\n");
        strcpy(to_check, "heal");
    }

    if (ard_ms->ard_return != NULL && strstr(ard_ms->ard_return, "live")) {
        //printf("Yes\n");
        strcpy(to_check, "live");
    }

    if (ard_ms->ard_return != NULL && strstr(ard_ms->ard_return, "energy")) {
        //printf("Yes\n");
        strcpy(to_check, "energy");
    }


    //------------------------------------------------------------------------------------

    if ( strcmp(to_check, key_str) == 0){
        //printf("1\n");
        return 1;
    }
    else{
        return 0;
    }


}

