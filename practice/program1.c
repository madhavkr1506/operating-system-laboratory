#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *addstring(void *arg) {
	char *string1 = (char *)arg;
        char *string2 = (char *)(arg + strlen(string1) + 1);
        char result[100];
        strcpy(result, string1);
        strcat(result, string2);
        printf("String concatenation: %s\n", result);
        return NULL;
}

int main() {
        pthread_t thread1;
        char str1[] = "Madhav";
        char str2[] = " kumar";
        char res[100];
        strcpy(res,str1);
        strcat(res,str2);
        pthread_create(&thread1, NULL, addstring, res);
        pthread_join(thread1, NULL);

return 0;
}
