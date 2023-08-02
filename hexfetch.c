#include <stdio.h>
#include <stdlib.h>


/* HexFetch 1.0 
HexFetch 1.0 is created by Hexis and was created to be simple and fast.
*/


void current_windowmanager() {
    char buffer[128];
    FILE* fp;

    // Get current windowmanager
    fp = popen("echo $DESKTOP_SESSION", "r");
    if (fp == NULL) {
        perror("Failed to execute command");
        return;
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Print current windowmanager 
        printf("%-15s %s", "\033[0;33mWM:      ", buffer);
    }

    pclose(fp);

}


void print_distroart() {
    system("lsb_release -si | figlet");
}



void uptime() {
    char buffer[128];
    FILE* fp;

    // Get system uptime
    fp = popen("uptime -p", "r");
    if (fp == NULL) {
        perror("Failed to execute command");
        return;
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Print uptime
        printf("%-15s %s", "\033[0;31mUptime:  ", buffer);
    }

    pclose(fp);
}



void memory() {
    char buffer[128];
    FILE* fp;

    // Get memory information
    fp = popen("free -mh | awk 'NR==2{print $7}'", "r");
    if (fp == NULL) {
        perror("Failed to execute command");
        return;
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Print the memory information
        printf("%-15s %s", "\033[0;34mmemory:  ", buffer);
    }

    pclose(fp);
}



void get_kernel_version() {
    char buffer[128];
    FILE* fp;

    // Get kernel version
    fp = popen("uname -r", "r");
    if (fp == NULL) {
        perror("Failed to execute command");
        return;
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Print the kernel version
        printf("\r%-15s %s", "\033[0;32mKmernel: ", buffer);
    }

    pclose(fp);
}



void get_distro_name() {
    char buffer[128];
    FILE* fp;

    // Get distro name
    fp = popen("lsb_release -si", "r");
    if (fp == NULL) {
        perror("Failed to execute command");
        return;
    }

    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Print the distro name
        printf("\r%-15s %s", "\033[0;35mDistname:", buffer);
    }

    pclose(fp);
}



int main() {
    // Print ASCII art
    print_distroart();

    // Get system information
    current_windowmanager();
    memory();
    get_kernel_version();
    get_distro_name();
    uptime();

    return 0;
}
