#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {

	while(1) {

		printf("basic272-shell> ");
                char command[20];
		char* test;
                scanf("%[^\n]%*c", command);	//Takes the whole line as input
		pid_t childpid, childpid2;
		int status;
//ls
		if(strcmp(command, "ls") == 0){ 
			childpid = fork();
			if(childpid == 0) {
				execl("/usr/bin/java","/usr/bin/java", "-jar", "ls/ls.jar", NULL);
			}
			else if(childpid > 0) {
				wait(&status);
			}
		}
		
//generate
		else if(strcmp(command, "generate") == 0) {
			childpid = fork();
			if(childpid == 0) {
				execl("/usr/bin/java", "/usr/bin/java", "-jar", "generate/generate.jar", NULL);
			}
			else if(childpid > 0) {
				wait(&status);
			}
		}
		
//sum
		else if(strcmp(command,"sum") == 0) {
			childpid = fork();
                        if(childpid == 0) {
                                execl("/usr/bin/java", "/usr/bin/java", "-jar", "sum/sum.jar", NULL);
                        }
                        else if(childpid > 0) {
                                wait(&status);
                        }
		}
		
//substract
		else if(strcmp(command,"substract") == 0) {
                        childpid = fork();
                        if(childpid == 0) {
                                execl("/usr/bin/java", "/usr/bin/java", "-jar", "substract/substract.jar", NULL);
                        }
                        else if(childpid > 0) {
                                wait(&status);
                        }
                }
		
	
//generate | sum
                else if(strcmp(command, "generate | sum") == 0) {
                        int fd[2];
                        pipe(fd);
                        childpid = fork();
                        if(childpid == 0) {
                                close(fd[0]);
                                close(1);
                                dup2(fd[1], 1);
                                close(fd[1]);
                                execl("/usr/bin/java", "/usr/bin/java", "-jar", "generate/generate.jar", NULL);
                        }
                        else {					
				close(fd[1]);
                                childpid2 = fork();
                                if(childpid2 == 0){
                                        close(0);
                                        dup2(fd[0], 0);                                        
					close(fd[0]);
                                        execl("/usr/bin/java", "/usr/bin/java", "-jar", "sum/sum.jar", NULL);
                                }
                                else {
                                        close(fd[0]);
                                        waitpid(childpid, NULL, 0);
                                        waitpid(childpid2, NULL, 0);
				}
                        }
             	}
//generate | substract
		else if(strcmp(command, "generate | substract") == 0) {
                        int fd[2];
                        pipe(fd);
                        childpid = fork();
                        if(childpid == 0) {
                                close(fd[0]);
                                close(1);
                                dup2(fd[1], 1);
                                close(fd[1]);
                                execl("/usr/bin/java", "/usr/bin/java", "-jar", "generate/generate.jar", NULL);
                        }
                        else {
				close(fd[1]);
                                childpid2 = fork();
                                if(childpid2 == 0){	
                                        close(0);	
                                       	dup2(fd[0], 0);
					close(fd[0]);
					execl("/usr/bin/java", "/usr/bin/java", "-jar", "substract/substract.jar", NULL);
                                }
                                else {
                                        close(fd[0]);
                                        waitpid(childpid, NULL, 0);
                                        waitpid(childpid2, NULL, 0);
                                }
                        }
		}	

//tee
		else if(command[0] == 't' && command[1] == 'e' && command [2] == 'e'){
			test = strtok(command, " ");
                        test = strtok(NULL, ",\n");
			childpid = fork();
        	        if(childpid == 0) {
			execl("/usr/bin/java","/usr/bin/java", "-jar", "tee/tee.jar", test, NULL);
        	        }
        	        else if(childpid > 0) {
        	               wait(&status);
        	        }
	

		}
//ls | tee
                else if( command[0] == 'l' && command[1] == 's' && command[2] == ' ' && command[3] == '|') {
			
			//test will be the file to be written to
			test = strtok(command, " ");
			test = strtok(NULL, ",\n");
			test = strtok(test, " ");
                        test = strtok(NULL, ",\n");
			test = strtok(test, " ");
			test = strtok(NULL, ",\n");
			
			int fd[2];
                        pipe(fd);
                        childpid = fork();
                        if(childpid == 0) {
                                close(fd[0]);
                                close(1);
                                dup2(fd[1], 1);
                                close(fd[1]);
                                execl("/usr/bin/java", "/usr/bin/java", "-jar", "ls/ls.jar", NULL);
                        }
                        else {
                                close(fd[1]);
                                childpid2 = fork();
                                if(childpid2 == 0){
                                        close(0);
                                        dup2(fd[0], 0);
                                        close(fd[0]);
                                        execl("/usr/bin/java", "/usr/bin/java", "-jar", "tee/tee.jar", test, NULL);
                                }
                                else {
                                        close(fd[0]);
                                        waitpid(childpid, NULL, 0);
                                        waitpid(childpid2, NULL, 0);
                                }
                        }
                }

//generate | tee
                else if( command[0] == 'g' && command[9] == '|' && command[11] == 't') {

                        //test will be the file to be written to
                        test = strtok(command, " ");
                        test = strtok(NULL, ",\n");
                        test = strtok(test, " ");
                        test = strtok(NULL, ",\n");
                        test = strtok(test, " ");
                        test = strtok(NULL, ",\n");

                        int fd[2];
                        pipe(fd);
                        childpid = fork();
                        if(childpid == 0) {
                                close(fd[0]);
                                close(1);
                                dup2(fd[1], 1);
                                close(fd[1]);
                                execl("/usr/bin/java", "/usr/bin/java", "-jar", "generate/generate.jar", NULL);
                        }
                        else {
                                close(fd[1]);
                                childpid2 = fork();
                                if(childpid2 == 0){
                                        close(0);
                                        dup2(fd[0], 0);
                                        close(fd[0]);
                                        execl("/usr/bin/java", "/usr/bin/java", "-jar", "tee/tee.jar", test, NULL);
                                }
                                else {
                                        close(fd[0]);
                                        waitpid(childpid, NULL, 0);
                                        waitpid(childpid2, NULL, 0);
                                }
                        }

		}
//sum | tee
                else if( command[0] == 's' && command[1] == 'u' && command[2] == 'm' && command[4] == '|') {

                        //test will be the file to be written to
                        test = strtok(command, " ");
                        test = strtok(NULL, ",\n");
                        test = strtok(test, " ");
                        test = strtok(NULL, ",\n");
                        test = strtok(test, " ");
                        test = strtok(NULL, ",\n");

                        int fd[2];
                        pipe(fd);
                        childpid = fork();
                        if(childpid == 0) {
                                close(fd[0]);
                                close(1);
                                dup2(fd[1], 1);
                                close(fd[1]);
                                execl("/usr/bin/java", "/usr/bin/java", "-jar", "sum/sum.jar", NULL);
                        }
                        else {
                                close(fd[1]);
                                childpid2 = fork();
                                if(childpid2 == 0){
                                        close(0);
                                        dup2(fd[0], 0);
                                        close(fd[0]);
                                        execl("/usr/bin/java", "/usr/bin/java", "-jar", "tee/tee.jar", test, NULL);
                                }
                                else {
                                        close(fd[0]);
                                        waitpid(childpid, NULL, 0);
                                        waitpid(childpid2, NULL, 0);
                                }
                        }
		}
//substract | tee
                else if( command[0] == 's' && command[1] == 'u' && command[2] == 'b' && command[10] == '|') {

                        //test will be the file to be written to
                        test = strtok(command, " ");
                        test = strtok(NULL, ",\n");
                        test = strtok(test, " ");
                        test = strtok(NULL, ",\n");
                        test = strtok(test, " ");
                        test = strtok(NULL, ",\n");

                        int fd[2];
                        pipe(fd);
                        childpid = fork();
                        if(childpid == 0) {
                                close(fd[0]);
                                close(1);
                                dup2(fd[1], 1);
                                close(fd[1]);
                                execl("/usr/bin/java", "/usr/bin/java", "-jar", "substract/substract.jar", NULL);
                        }
                        else {
                                close(fd[1]);
                                childpid2 = fork();
                                if(childpid2 == 0){
                                        close(0);
                                        dup2(fd[0], 0);
                                        close(fd[0]);
                                        execl("/usr/bin/java", "/usr/bin/java", "-jar", "tee/tee.jar", test, NULL);
                                }
                                else {
                                        close(fd[0]);
                                        waitpid(childpid, NULL, 0);
                                        waitpid(childpid2, NULL, 0);
                                }
                        }
		}
		else printf("Command not found\n");
		printf("\n");
	}
}

