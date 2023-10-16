#include <stdio.h>

int digitSum(int n, int s){
    s = 0;
    // calculate the sum of eve
    while(n > 0){
        s += n%10;
        printf("%d\n", n%10);
        n /= 10;
    }
    return s;
}

int main(){
    int num;
    int sum = 0;
    printf("Enter a integer: ");
    scanf("%d", &num);  // 154368
    
    if(digitSum(num, sum)%9 == 0){
        printf("%d is divisibled by 9.", num);
    }
    else{
        printf("%d isn't divisibled by 9.", num);
    }
    
    return 0;
}
