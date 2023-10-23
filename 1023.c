#include <stdio.h>
#include <string.h>

// reverse string
char* reverse(char* str)
{
    if (*str){
        for(char *first = s, *last = s + strlen(s); first < --last; ++first){
            // swap
            char c = *first;
            *first = *last;
            *last = c;
        }
    }
    return str;
}

int main(void) {
    char str1[] = "323";
    char str2[] = "12242";
    char str3[] = "09";

    puts( reverse(str1) );
    puts( reverse(str2) );
    puts( reverse(str3) );
    return 0;
}   
