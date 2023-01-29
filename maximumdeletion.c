int minimum(int *arr,int size){
    int min =arr[0];
    for (int i=0;i<size;i++){
        if (min>arr[i]){
            min=arr[i];
        }
    }
    return min;
}
int minOperations(int* nums, int numsSize, int* numsDivide, int numsDivideSize){
    int delete=0;
    int i=0;
    int y=numsSize;
    int find;
    int result;
    int min;
    while(numsSize>=0){
        min=minimum(nums,numsSize);
        //printf("min:%d\n",min);
        int output[100000];
        int l=0;
        while(i<numsDivideSize){
            if (numsDivide[i]%min!=0){
                find=0;
                break;
            }
            else{
                find=1;
                i++;
            }
        }
        if (find==0){
            for (int i=0;i<numsSize;i++){
                if (nums[i]==min){
                    //printf("deleted i:%d\n",nums[i]);
                    nums[i]=-1;
                    delete++;
                    //printf("delete:%d\n",delete);
                }
            }
            for (int j=0;j<numsSize;j++){
                if (nums[j]!=-1){
                    output[l]=nums[j];
                    l++;
                }
            }
            for (int m=0;m<l;m++){
                nums[m]=output[m];
            }
            numsSize=l;
        }
        else{
            if (delete !=y){
                return delete;
            }
            else{
                return -1;
            }
        }
    }
    if (numsSize<0){
        result=-1;
    }
    return result;
}
int main(){
    int nums[5]={2,3,2,4,3};
    int nsize=5;
    int numsdivide[5]={9,6,9,3,15};
    int t=minOperations(nums,nsize,numsdivide,nsize);
    printf("minnimum num of deletions:%d ",t);
}