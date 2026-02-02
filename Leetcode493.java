class Solution {
        // MERGE SORT
    public static int MergeSort(int arr[],int si, int ei){
        int count=0;
        if(si>=ei){
            return count;
        }
        int mid=si+(ei-si)/2;
        count+= MergeSort(arr, si, mid);
        count+= MergeSort(arr, mid+1, ei);
        count+= countPairs(arr,si,mid,ei);
        merge(arr,si,mid,ei);
        return count;
    }
    public static void merge(int arr[],int si,int mid,int ei){
        int temp[]=new int[ei-si+1];
        int i=si;
        int j=mid+1;
        int k=0;
        while(i<=mid&&j<=ei){
            if(arr[i]<=arr[j]){
                temp[k]=arr[i];
                i++;
            }else{
                temp[k]=arr[j];
                j++;
            }
            k++;
        }
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=ei){
            temp[k++]=arr[j++];
        }
        for(k=0,i=si;k<temp.length;k++,i++){
            arr[i]=temp[k];
        }
    }
    public static int countPairs(int arr[],int low,int mid,int high){
        int count=0;
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high && (long)arr[i]>2L*(long)arr[right]) right++;
            count+=(right-(mid+1));
        }
        return count;
    }

    public int reversePairs(int[] nums) {
        int n=nums.length;
        return MergeSort(nums,0,n-1);

    }
}