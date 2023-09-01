#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>


//       (pai)      
//         |        
//    +----+----+
//    |         |   
// filho_1   filho_2


// ~~~ printfs  ~~~
// pai (ao criar filho): "Processo pai criou %d\n"
//    pai (ao terminar): "Processo pai finalizado!\n"
//  filhos (ao iniciar): "Processo filho %d criado\n"

// Obs:
// - pai deve esperar pelos filhos antes de terminar!


//int main(int argc, char** argv) {
int main(void) {
    pid_t pid = fork();

    if (pid) { 
        printf("Processo pai criou %d\n", pid);
        pid = fork();
        if (pid) {
            printf("Processo pai criou %d\n", pid);
        }
    }

    if (pid) {
        printf("Processo pai finalizado!\n");
    }

    if (pid == 0) {
        printf("Processo filho %d criado\n", getpid());
    }

    return 0;
}
