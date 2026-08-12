class Solution {
  public:
    
    void merge(vector<int>&arr,int l, int mid,int r)
    {
        vector<int>left,right;
        for(int i=l;i<=mid;i++)
        {
            left.push_back(arr[i]);
        }
        for(int i = mid + 1; i <= r; i++)
        {
            right.push_back(arr[i]);
        }
        
          int i=0,j=0,k=l;
          while(i<left.size() && j<right.size())
          {
              if(left[i]<=right[j])
              {
                  arr[k]= left[i];
                  i++;
              }
              else{
                  arr[k] = right[j];
                  j++;
              }
              k++;
          }
          
          
          if(i<left.size())
          {
              while(i<left.size())
              {
                  arr[k] = left[i];
                  i++,k++;
              }
          }
          if(j<right.size())
          {
              while(j<right.size())
              {
                  arr[k] = right[j];
                  k++,j++;
              }
          }
          
        
        
    }
    
    void mergesort(vector<int>&arr, int l,int r)
    {
        if(l>=r) return ;
        int mid = (r+l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
  
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        mergesort(arr,l,r);
    }
};