#include<stdio.h>
int isOneBitCharacter(int* bits, int bitsSize){
   int i=0;    
   while(i<bitsSize-1)       
   {    
    if(*(bits+i)!=0)    
    {        
      i+=2;    
    }    
    else    
    {    
      i++;      
    }    
  }    
  if(i==bitsSize-1)    
  {    
    return 1;    
  }    
  return 0;    
}
int main()
{
	int bits[]={1,1,1,0};
	int len=sizeof(bits)/sizeof(bits[0]);
  int ret=isOneBitCharacter(bits,len);
  if(ret==1)
  {
    printf("no\n");
  }
  else 
  {
    printf("yes\n"); 
  }
	return 0;
}
