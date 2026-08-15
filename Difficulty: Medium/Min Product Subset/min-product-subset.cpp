class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int product =1,mnNeg=INT_MAX,mnPos=INT_MAX,zero=0,neg=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
            {
                zero++;continue;
            }
            
            
            if(arr[i]<0)
            {
                mnNeg = min(mnNeg,abs(arr[i]));
                neg++;
            }
            else{
                mnPos = min(mnPos,arr[i]);
            }
            product *= arr[i];
        }
        
        // if(neg%2==1)
        // {
        //     return product;
        // }
        // else{
        //     product /=(-mnNeg);return product;
        // }
        
        
        
        
        
        
        // if(mnPos == INT_MAX && neg==0)
        // {
        //     return 0;
        // }
        // return mnPos;
        
        if (neg == 0)
        {
            if (zero > 0)
                return 0;

            return mnPos;
        }

        if (neg % 2 == 1)
        {
            return product;
        }

        product /= (-mnNeg);

        return product;
        
    }
};