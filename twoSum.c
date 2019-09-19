/*
* 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
*
* 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数字中同样的元素。
*
* 示例:
*
* 给定 nums = [2, 7, 11, 15], target = 9
*
* 因为 nums[0] + nums[1] = 2 + 7 = 9
* 所以返回 [0, 1]

*/
#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
  int *result=NULL;//分配空间用来存储和为目标值的整数
  int i=0;
  int j=0;
  for(i=0;i<numsSize-1;i++)
  {
    for(j=i+1;j<numsSize;i++)
    {
      if(nums[i]+nums[j]==target)
      {
        result=(int*)malloc(sizeof(int)*2);
        result[0]=i;
        result[1]=j;
        *returnSize=2;
        return result;
      }
    }
  }
  return result;
}
int main()
{
  int nums[]={3,2,3};
  int numsSize=sizeof(nums)/sizeof(nums[0]);
  int target=6;
  int returnSize;
  int *result=twoSum(nums, numsSize, target, &returnSize);
  int i=0;
  for(i=0;i<returnSize;i++)
  {
    printf("%d\n",result[i]);
//    free(result[i]);
  }
  free(result);
  return 0;
}
