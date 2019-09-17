/*
 * 索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到并返回最大的集合S，S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }
 * 且遵守以下的规则。
 *假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，不断添加直到S出现重复的元素。
 *输入: A = [5,4,0,3,1,6,2]
 *输出: 4
 *解释: 
 *A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2. 
 *其中一种最长的 S[K]:
 *S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
 *解题思路
 对遍历过的数字进行标记。
 一旦发现等于标记，一次循环结束
 任意数字都可以作为起点
 遍历完数组，比较出最大的长度。
 */
 
#include<stdio.h>
#include<stdlib.h>
int arrayNesting(int* nums, int numsSize){
  int i=0;
  int Max=0;
  for(i=0;i<numsSize;i++)
  {
    if(nums[i]==-1)
    {
      continue;
    }
    int T=i;
    int count=0;
    while(nums[T]!=-1)
    {
      count++;
      int X=nums[T];
      nums[T]=-1;
      T=X;
    }
    Max=Max>count?Max:count;
  }
  return Max;
}

int main()
{
  int nums[]={0,1,2};
  int numsSize=sizeof(nums)/sizeof(nums[0]);
  int count=arrayNesting(nums, numsSize);
  printf("%d\n",count);
  return 0;
}
