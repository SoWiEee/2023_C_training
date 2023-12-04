#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// start at index = 0, select a min element after it, then swap
void selectSort(char* ptr[]) {
    char* swap;
    for (int i = 0; i < 99; i++) {
        for (int j = i + 1; j < 100; j++){
            // index > compare => swap
            if (strcmp(ptr[i], ptr[j]) > 0){
                swap = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = swap;
            }
        }
    }
}

int findName(char names[][20], char* name) {
    int left = 0;
    int mid = 0;
    int right = 99;
    while (left <= right) {
        mid = (left + right) / 2;
        if (strcmp(names[mid], name) == 0) {
            return mid;
        }
        else {
            if (strcmp(names[mid], name) > 0) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
    }
    return -1;
}

int main(void) {
    char name[20];
    char names[100][20];    // a array stord girls' names
    char* names_ptr[100];    // a pointer array -> names
    int index;
    FILE* inF = fopen("girls.txt", "r");
    FILE* outF = fopen("girls_sorted.txt", "w");
    // read names
    printf("-----ORIGINAL-----\n");
    for (int i = 0; i < 100; i++) {
        fgets(names[i], 20, inF);
        names[i][strlen(names[i])] = '\0';
        // pointer array point to array space
        names_ptr[i] = names[i];
        printf("%s", names_ptr[i]);
    }
    printf("\n");
    selectSort(names_ptr);

    printf("-----SORTED-----\n");
    // output sorted array via pointer array
    for (int i = 0; i < 100; i++) {
        fputs(names_ptr[i], outF);
        printf("%s", names_ptr[i]);
    }

    fclose(inF);
    fclose(outF);

    // always run but "ZZZ"
    FILE* SrchF = fopen("girls_sorted.txt", "r");
    for (int i = 0; i < 100; i++) {
        fgets(names[i], 20, SrchF);
    }

    while (1) {
        printf("Enter a name (\"ZZZ\" can exit.)=> ");
        gets_s(name, 20);
        strcat(name, "\n");
        if (strcmp(name, "ZZZ\n") == 0) {
            break;
        }
        else {
            // binary search
            index = findName(names, name);  // the result of index
            if (index == -1) {
                printf("Not search the name in file.\n");
            }
            else {
                printf("At index = %d, have same name.\n", index);
            }
        }
    }

    fclose(SrchF);
    system("pause");
    return 0;
}
