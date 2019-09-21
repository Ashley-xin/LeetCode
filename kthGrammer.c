/*
 * 在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。
 *
 * 给定行数 N 和序数 K，返回第 N 行中第 K个字符。（K从1开始）
 *
 *
 * 例子:
 *
 * 输入: N = 1, K = 1
 * 输出: 0
 *
 * 输入: N = 2, K = 1
 * 输出: 0
 *
 * 输入: N = 2, K = 2
 * 输出: 1
 *
 * 输入: N = 4, K = 5
 * 输出: 1
 *
 * 解释:
 * 第一行: 0
 * 第二行: 01
 * 第三行: 0110
 * 第四行: 01101001
 */
#include<stdio.h>
int kthGrammar(int N, int K){
  if(N == 1 || K == 1)
  {
    return 0;
  }
  int a=kthGrammar((N-1),(K+1)/2);//求其父结点，以及父结点的下标
  int b=-(a-1);//若a=0，则b=1;若a=1,则b=0;
  if(K%2 == 1)//观察题目，若是奇数位，其返回值与父结点相同，否则相反
  {
    return a;
  }
  else 
  {
    return b;
  }
}
int main() 
{
  int ret=kthGrammar(4,3);
  printf("%d\n",ret);
  return 0;
}
