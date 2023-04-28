#include<stdio.h>
#include<stdlib.h>
int nums[100000];
int len;
int main()
{
	int dp[100010] = {0};
	int i=0;
	int res = -10010;
	int tool=0;
    scanf("%d",&len);
		for(i=0;i<len;i++){
			scanf("%d",&nums[i]);
			if(nums[i]>0)tool=1;
		}
		if(tool == 0){
			printf("0");
			return 0;
		}
        dp[0] = nums[0];

        for(i=1;i<=len;i++){
            dp[i] = (nums[i]+dp[i-1])>nums[i]? nums[i]+dp[i-1]:nums[i];
        }
        for( i=0;i<=len;i++)
        {
           if(res<dp[i])res = dp[i];

        }
	printf("%d",res);
	system("pause");
	return 0;
}
