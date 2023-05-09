int solve(){
      int m,n;
      cin>>n>>m;
      vector<int>city(n);
      vector<int>cells(m);
      for(int i=0; i<n; i++)
            cin>>city[i];
 
      for(int i=0; i<m; i++)
            cin>>cells[i];
      debug(cells);
      debug(city);
      int right = 0, left = 0, r=0, ans = 0;
      for(auto x : city){
            while(r+1<m && cells[r]<x){
                  r++;
            }
            if(r!=0){
                  left = r-1;
            }
            ans = max(ans,min(abs(cells[r]-x),abs(cells[left]-x)));
      }
      cout<<ans<<endl;
      return 0;
}
