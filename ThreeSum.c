#include<stdio.h>
#include<stdlib.h>
/*
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 *
 * 满足要求的三元组集合为：
 * [
 *   [-1, 0, 1],
 *     [-1, -1, 2]
 * ]
 * 解题思路
 *首先对数组进行排序，排序后固定一个数 nums[i]，再使用左右指针指向 nums[i]后面的两端，数字分别为nums[left]和nums[right],计算三个数的和sum断是否满足为0,满足则添加进结果集合
 *如果 nums[i]大于0，则三数之和必然无法等于0，结束循环
 *如果 nums[i]== nums[i−1]，则说明该数字重复，会导致结果重复，所以应该跳过
 *nums[left]== nums[left+ 1]则会导致结果重复，应该跳过，left++
 *nums[right]== nums[right−1]则会导致结果重复，应该跳过，right--
 *
 */
int compare(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
  //qsort(nums,numsSize,sizeof(nums[0]),compare);//对数组进行排序
  int i=0;
  int pos_column=0;
  *returnSize=0;
  int **resultArrary=(int **)malloc(sizeof(int*)*numsSize*numsSize);
  *returnColumnSizes=(int *)malloc(sizeof(int*)*numsSize*numsSize);
  qsort(nums,numsSize,sizeof(nums[0]),compare);//对数组进行排序

 
  for(i=0;i<numsSize-2;i++)
  {
    if(i == 0 || (i>0)&& (nums[i] != nums[i-1]))
    {
      int left=i+1;
      int right=numsSize-1;  
      while(left<right)
      { 
        if(nums[left] + nums[right] == -nums[i])
          {
          resultArrary[*returnSize]=(int *)malloc(sizeof(int *)*3);
          resultArrary[*returnSize][0]=nums[i];
          resultArrary[*returnSize][1]=nums[left];
          resultArrary[*returnSize][2]=nums[right];
          (*returnColumnSizes)[pos_column]=3;
          pos_column++;
          (*returnSize)++;
          while(left < right && nums[left] == nums[left+1])
          {
            left++;
          }
          while(left < right && nums[right]==nums[right-1])
          {
            right--;
          }
          left++;
          right--;
        }
        else if(nums[left]+nums[right]<-nums[i])
        {
            left++;
        }
        else if(nums[left]+nums[right]>-nums[i])
        {
            right--;
        }
      }
    }
  }
  return  resultArrary;       
}
int main()
{
  int nums[]={-1,0,1,2,-1,-4};
  int numsSize=sizeof(nums)/sizeof(nums[0]);
  int returnSize;
  int *returnColumnSizes=NULL;
  int **result=threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
  int i;
  for(i=0;i<returnSize;i++)
  {
    printf("num=[%d,%d,%d]\n",result[i][0],result[i][1],result[i][2]);
    free(result[i]);
  }
  for(i=0;i<returnSize;i++)
  {
    printf("returnColumnSizes[%d]:%d\n",i,returnColumnSizes[i]);
  }
  free(result);
  free(returnColumnSizes);
  printf("returnSize=%d\n",returnSize);
  return 0;
}
