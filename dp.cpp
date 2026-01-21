#include <stdio.h>
int max(int a,int b){
    return (a>b)?a:b;
}
int main(){
    int items,i,w;
    printf("Enter th e no of items: ");
    scanf("%d",&items);
    int weights[items+1],price[items+1];
    weights[0]= price[0]=0;
    printf("Enter the weight- prices\n");
    for(int i=0;i<items;i++){
        printf("Item no %d : ", i );
        scanf("%d%d",&weights[i],&price[i]);
    }
    int cap;
    printf("Enter the capacity of bag: ");
    scanf("%d",&cap);
    int dp[items+1][cap+1];
    for(int i=0;i<=items;i++){
        for(int w=0;w<=cap;w++){
            if(i==0 || w==0){
                dp[i][w]==0;
            }else if {
                dp[i][w]=max(dp[i-1][w],price[i]+dp[i-1][w-weights[i]]);
            }else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
}