class manacher{
    vector<int> p;
    public:
    string build(string s){
        string t = "#";

        for (char c : s) {
            t += c;
            t += '#';
        }
        run_manacher(t);

        int best=0,center=0;
        for(int i=0;i<t.size();i++){
            if(p[i]>best){
                best=p[i];
                center=i;
            }
        }
        int start=(center-best)/2;
        return s.substr(start,best);
    }

    void run_manacher(string s){
        int n=s.size();
        p.assign(n,0);
        int l=0,r=0;
        for(int i=0;i<n;i++){
            if(i<=r) p[i]=min(r-i,p[r+l-i]);
            while(i-p[i]-1>=0 && i+p[i]+1<n && s[i+p[i]+1]==s[i-p[i]-1]) p[i]++;
            if(i+p[i]>r){
                l=i-p[i];
                r=i+p[i];
            }
        }
    }

    int getlongestpal(int cen,bool odd){
        int pos=2*cen+1+(!odd);
        return p[pos];
    }

    bool checkpal(int l,int r){
        if((r-l+1)<=getlongestpal((r+l)/2,l%2==r%2)) return 1;
        else return 0;
    }
}m;

class Solution {

public:
    string longestPalindrome(string s) {
        manacher m;
        return m.build(s);
    }
};