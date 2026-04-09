#include <stdio.h>
#include <stdlib.h>

void demonstrateCorrectDeclarations() {
    printf("=== 正确的声明方式 ===\n");
    
    // 方式1：动态分配单个数组
    int *a1 = malloc(sizeof(int) * 5);  // ✅ 正确
    printf("方式1 - 动态数组指针: %p\n", a1);
    
    a1[0] = 10;
    *(a1+1) = 20;//等价于a1[1] = 20
    
    printf("a1[0]: %d\n",a1[0]);
    printf("a1[1]: %d\n",a1[1]);
    
    printf("a1 address: %p\n",a1);
    a1++;//a1地址+1，根据int类型偏移
    printf("a1 address: %p\n",a1);
    a1--;//归位，后续free要使用



    // 方式2：固定指针数组
    int *a2[5];  // ✅ 正确：5个int*指针的数组
    for(int i = 0; i < 5; i++) {
        a2[i] = malloc(sizeof(int));  // 为每个指针分配内存
        *(a2[i]) = i * 10;//解引用赋值
    }
    printf("方式2 - 指针数组: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", *(a2[i]));
    }
    printf("\n");
    
    // 方式3：动态指针数组
    int **a3 = malloc(sizeof(int*) * 5);  // ✅ 正确
    for(int i = 0; i < 5; i++) {
        a3[i] = malloc(sizeof(int));//a3[i]代表每个int类型指针的地址
        *(a3[i]) = i * 100;
    }
    printf("方式3 - 动态指针数组: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", *(a3[i]));
    }
    printf("\n");
    
    // 错误方式的解释
    printf("\n=== 错误方式分析 ===\n");
    printf("int * a1[5] =  malloc(sizeof(int*) * 5) 的问题:\n");
    printf("- 左边：数组类型 int*[5]\n");
    printf("- 右边：指针类型 int*\n");
    printf("- 结果：类型不匹配错误\n");
    
    // 清理内存
    free(a1);
    for(int i = 0; i < 5; i++) {
        free(a2[i]);
        free(a3[i]);
    }
    free(a3);
}
int main(void){
    demonstrateCorrectDeclarations();
    return 0;
}