//Greedy + Binary Search
int sum(vector<int>p, int x, int a, int y, int b, int mid){
      int noTickets = 0;
      int n = p.size();
      int cxy, cx, cy;
      cxy=cy=cx=0;
      if(x<y){
            swap(x,y);
            swap(a,b);
      }
      for(int i=1; i<=mid; i++){
            if(i%a == 0 && i%b == 0){
                  cxy++;
            }
            else if(i%a==0){
                  cx++;
            }
            else if(i%b==0){
                  cy++;
            }
      }
      int sum = 0;
      for(int i=0; i<cxy; i++)
            sum += p[i]*(x+y);
      for(int i=0; i<cx; i++){
            sum += p[i+cxy]*x;
      }
      for(int i=0; i<cy; i++){
            sum += p[i+cxy+cx]*y;
      }
      return sum;
}
int solve(){
      int n;
      cin>>n;
      vector<int>p(n+1);
      for(int i=1; i<n+1; i++){
            cin>>p[i];
            p[i]/=100;
      }
      int x,a,y,b,k;
      cin>>x>>a>>y>>b>>k;
      sort(all(p),greater<int>());

      int low = 0, high = n+1, ans = INT_MAX;
      while(low<=high){
            int mid = (low + high)/2;
            if(sum(p,x,a,y,b,mid)>=k){
                  ans = min(ans,mid);
                  high = mid-1;
            }
            else{
                  low = mid+1;
            }
      }
      if(ans>n)
            cout<<-1<<endl;
      else
            cout<<ans<<endl;
      return 0;

}
