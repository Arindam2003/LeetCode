class DataStream {
public:
    int value,k;
    vector<int>ip;
    DataStream(int value, int k) {
        this->value=value;
        this->k=k;
    }
    int i=0,j=0;
    int cnt=0;
    bool consec(int num) {
        ip.push_back(num);
        bool ans;

        if(ip[j]==value)
        {
            cnt++;
        }

        if(j-i+1<k)
        {
            j++;
            ans=false;
        }
        else if(j-i+1==k){
            if(cnt==k)
            {
                ans=true;
            }else{
                ans=false;
            }

            if(ip[i]==value)
            {
                cnt--;
            }

            i++;
            j++;
        }

        return ans;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */