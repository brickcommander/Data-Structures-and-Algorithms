// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        int mx = 1;
        int c = 1;
        sort(arr, arr+N);
        for(int i=1; i<N; i++) {
            if(arr[i] == arr[i-1]) continue;
            if(arr[i] == arr[i-1] + 1) {
                c++;
                mx = max(mx, c);
            } else {
                c = 1;
            }
        }
        mx = max(mx, c);
        return mx;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends