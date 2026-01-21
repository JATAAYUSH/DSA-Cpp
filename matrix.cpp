#include <iostream>
using namespace std;
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int row= 3;
    int colm= 3;
    int target = 5;
    int ans;
    int rowof;
    int colof;
    int maxsum = 0;
    for(int i=0;i<row;i++){
        int sum = 0;
        for(int j=0;j<colm;j++){
            cout<<arr[i][j]<<"  ";
            sum += arr[i][j];
            if(arr[i][j] == target) {
                ans = arr[i][j];
                rowof = i;
                colof = j;
            }
        }
        maxsum = max(maxsum, sum);
        cout<<endl;
    }
    cout<<ans <<" Found at ("<<rowof<<","<<colof<<")"<<endl;
    cout<< "Max Sum is: "<<maxsum;
}
