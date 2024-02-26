#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_COUNT 500
#define MAX_NUMBER 9223372036854775807 // long 타입의 최댓값

int main()
{
    long numbers[NUM_COUNT];
    int i, j;
    bool isDuplicate;

    // 난수 생성을 위한 시드 설정
    srand(time(NULL));

    // 겹치지 않는 숫자 100개 생성
    for (i = 0; i < NUM_COUNT; i++)
    {
        do //조건을 먼저 시작하지 않기위해 do하고 while밑에진행
        {
            // 새로운 숫자 생성
            numbers[i] = rand() % MAX_NUMBER;

            // 중복 체크
            isDuplicate = false;
            for (j = 0; j < i; j++)
            {
                if (numbers[j] == numbers[i])
                {
                    isDuplicate = true;
                    break;
                }
            }
        } while (isDuplicate); // 중복된 숫자라면 다시 생성

        // 생성된 숫자 출력
        printf("%ld ", numbers[i]);
    }
    printf("\n");

    return 0;
}
