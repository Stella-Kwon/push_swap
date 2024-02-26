#include <stdio.h>

// Function to convert negative number to positive using 2's complement
long long makePositive(long long num)
{
    if (num >= 0)
        return num; // Already positive, no need to change

    // Convert to positive using 2's complement
    return ~num + 1;
}

// Function to convert an integer to binary string
void toBinary(long long num)
{
    // Number of bits in long long data type
    int bits = sizeof(long long) * 8; //sizeof()는 바이트로 나오기때문에 * 8

    // Bit manipulation to print binary representation
    //for (int i = 0; i < bits; i++) // bit의 인덱스는 0 부터 시작되기때문에 0에서 시작; 끝에서부터 꺼꾸로 비트를 출력하는거라 이건 옳지않은 방향이다
    for (int i = bits - 1; i >= 0; i--) // bit의 인덱스는 0 부터 시작되기때문에 bit-1에서 시작해야 맨첨에서부터 비트를 가져오는게 가능. 
    {
        /*
        101이라는 3개의 비트가 이씅면
        1 -> 01 두개의 01을 미뤄서 // 1&1 = 1 로 판별해서 맨 첫 비트 큰수인 1(2^2 =4)를 프린트하고
        10 -> 1 한개의 01을 미뤄서 ??
        */
        int bit = (num >> i) & 1; //  &연산자는 가장 오른쪽에 있는 비트만을 가지고 비교하게되므로 비트를 움직여 &1을 사용하여 0이면 0 1이면 // 1이 나오도록 & 연산자를 사용. (bitwise &) // 사용하지않으면 뭔 개판인 숫자가 나옴.
        /*
        (num >> i) 는 비트를 오른쪽으로 움직이는 연산자로
        5 >> 1: 5를 오른쪽으로 1비트 이동합니다. 오른쪽으로 1비트 이동하면서 오른쪽 끝에서 1비트가 삭제되고 왼쪽에는 0이 추가됩니다. 따라서 결과는 00000010입니다. 이는 2를 나타냅니다.

        5 >> 2: 5를 오른쪽으로 2비트 이동합니다. 오른쪽으로 2비트 이동하면서 오른쪽 끝에서 2비트가 삭제되고 왼쪽에는 0이 추가됩니다. 따라서 결과는 00000001입니다. 이는 1을 나타냅니다.

        5 >> 3: 5를 오른쪽으로 3비트 이동합니다. 오른쪽으로 3비트 이동하면서 오른쪽 끝에서 3비트가 삭제되고 왼쪽에는 0이 추가됩니다. 따라서 결과는 00000000입니다. 이는 0을 나타냅니다.

        이 부분에서는 i번쨰의 비트랑만 & 1 하여 비교하면 된다. &연산자는 가장 오른쪽에 있는 비트만을 가지고 비교하게된다.
        00000101이면 5 >> (6 - 1)일때 00000|00(0)|00101 인데 &1과해서 1인지 확인하면 된다.
                    5 >> 4일때 0000|000(0)|0101
                    5 >> 3일때 000|0000(0)|101
                    5 >> 2일때 00|00000(1)|01
                    5 >> 1일때 0|000001(0)|1
                    5 >> 0일때 |00000010(1)|
        */

        printf("%d", bit);
        // getchar();
        if (i % 4 == 0)
        {
            printf(" "); // 각 4비트 마다 공백을 추가하여 가독성을 높임
        }
    }
}

// int main()
// {
//     long long negativeNum = -123;
//     long long negative2 = -120;
//     long long positiveNum = makePositive(negativeNum);
//     long long positiveNum = makePositive(negative2);

//     printf("Negative number: %lld\n", negativeNum);
//     printf("Positive number: %lld\n", positiveNum);


//     return 0;
// }

// // Function to convert an integer to binary string
// void toBinary(long long num)
// {
//     // Number of bits in long long data type
//     int bits = sizeof(long long) * 8;

//     // Bit manipulation to print binary representation
//     for (int i = 0; i < bits; i++)
//     {
//         int bit = (num >> i) & 1;
//         printf("%d", bit);
//     }
// }

int main()
{
    // Test the toBinary function with a sample number
    long long num = 5;
    long long num2 = -12344;
    long long num3 = -12343;
    printf("Binary representation of %lld is: ", num);
    toBinary(num);
    printf("\n");
    printf("Binary representation of %lld is: ", num2);
    toBinary(num2);
    printf("\n");
    printf("Binary representation of %lld is: ", num3);
    toBinary(num3);
    printf("\n");
    return 0;
}