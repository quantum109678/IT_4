
#include <stdio.h>
#include <limits.h>
#include <tuple>
 
int max(int a, int b) { return (a > b)? a : b; }
 

int max(int a, int b, int c) { return max(max(a, b), c); }
 
std::tuple<int, int, int> maxCrossingSum(int arr[], int l, int m, int h)
{
    
    int sum = 0;
    int left_sum = INT_MIN;
    int left_index=l;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
          {left_sum = sum;
          	left_index=i;
          }
    }
 
    sum = 0;
    int right_sum = INT_MIN;
    int right_index=m+1;
    for (int i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
        {
          right_sum = sum;
          right_index=i;
        }
    }

    int fin_sum=left_sum+right_sum;
 
    
    return std::make_tuple(left_index,right_index,fin_sum);
}
 

std::tuple<int, int, int> maxSubArraySum(int arr[], int l, int h)
{
	 int li,le,ls,ri,re,rs,mi,me,ms;
  
   if (l == h)
     return std::make_tuple(l,h,arr[l]);
 
  else{
   int m = (l + h)/2;
  
 
  
    std::tie(li,le,ls)=maxSubArraySum(arr, l, m),
    std::tie(ri,re,rs)=maxSubArraySum(arr, m+1, h),
    std::tie(mi,me,ms)=maxCrossingSum(arr, l, m, h);

   if(ls>=rs&&ls>=ms){
   	return std::make_tuple(li,le,ls);
   }
   else if(rs>=ls&&rs>=ms){
   	return std::make_tuple(ri,re,rs);
   }
   else
   	return std::make_tuple(mi,me,ms);
}
 }
int main()
{
   int arr[] = {1,2,3,4,5};
   int n = 5;
   int max_sum,i,j; 
    std::tie(i,j,max_sum)=maxSubArraySum(arr, 0, n-1);
   printf("Maximum contiguous sum is %d\nThe indices are: %d %d\n", max_sum,i,j);
   return 0;
}