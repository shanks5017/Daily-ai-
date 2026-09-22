#include <bits/stdc++.h>
using namespace std;

int K;

struct Node {
    int prod; // modulo K
    long long M[5][5];
    Node() {
        prod = 1 % K;
        for(int i=0;i<5;i++) for(int j=0;j<5;j++) M[i][j]=0;
    }
};

Node mergeNode(const Node& A, const Node& B){
    Node C;
    C.prod = (int)((1LL*A.prod * B.prod) % K);
    for(int v=0; v<K; ++v){
        // prefixes within A
        for(int w=0; w<K; ++w){
            C.M[v][w] += A.M[v][w];
        }
        // prefixes that go through whole A then some prefix of B
        int v2 = (int)((1LL*v * A.prod) % K);
        for(int w=0; w<K; ++w){
            C.M[v][w] += B.M[v2][w];
        }
    }
    return C;
}

struct SegTree {
    int n;
    vector<Node> seg;
    SegTree(const vector<int>& arr){
        n = arr.size();
        seg.assign(4*n, Node());
        build(1,0,n-1,arr);
    }
    void build(int idx,int l,int r,const vector<int>& arr){
        if(l==r){
            Node nd;
            nd.prod = arr[l]%K;
            for(int v=0; v<K; ++v){
                int w = (int)((1LL*v * nd.prod) % K);
                nd.M[v][w] = 1;
            }
            seg[idx]=nd;
            return;
        }
        int mid=(l+r)/2;
        build(idx*2,l,mid,arr);
        build(idx*2+1,mid+1,r,arr);
        seg[idx]=mergeNode(seg[idx*2], seg[idx*2+1]);
    }
    void pointUpdate(int pos,int val){
        pointUpdate(1,0,n-1,pos,val);
    }
    void pointUpdate(int idx,int l,int r,int pos,int val){
        if(l==r){
            Node nd;
            nd.prod = val%K;
            for(int v=0; v<K; ++v){
                int w = (int)((1LL*v * nd.prod) % K);
                nd.M[v][w] = 1;
            }
            seg[idx]=nd;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) pointUpdate(idx*2,l,mid,pos,val);
        else pointUpdate(idx*2+1,mid+1,r,pos,val);
        seg[idx]=mergeNode(seg[idx*2], seg[idx*2+1]);
    }
    Node queryRange(int ql,int qr){
        return queryRange(1,0,n-1,ql,qr);
    }
    Node queryRange(int idx,int l,int r,int ql,int qr){
        if(ql<=l && r<=qr) return seg[idx];
        if(r<ql || l>qr){
            Node id;
            id.prod = 1 % K;
            // M already zero
            return id;
        }
        int mid=(l+r)/2;
        Node left = queryRange(idx*2,l,mid,ql,qr);
        Node right = queryRange(idx*2+1,mid+1,r,ql,qr);
        return mergeNode(left,right);
    }
};

vector<int> parseIntArray(const string& s){
    vector<int> res;
    int num=0; bool in=false;
    for(char c: s){
        if(isdigit(c)){
            num = num*10 + (c-'0');
            in=true;
        }else{
            if(in){
                res.push_back(num);
                num=0; in=false;
            }
        }
    }
    if(in) res.push_back(num);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    if(!getline(cin,line)) return 0;
    vector<int> nums = parseIntArray(line);
    getline(cin,line);
    int k = stoi(line);
    K = k;
    getline(cin,line);
    vector<int> flat = parseIntArray(line);
    int q = flat.size()/4;
    vector<array<int,4>> queries(q);
    for(int i=0;i<q;i++){
        queries[i] = {flat[4*i], flat[4*i+1], flat[4*i+2], flat[4*i+3]};
    }
    vector<int> arrMod(nums.size());
    for(size_t i=0;i<nums.size();++i) arrMod[i]=nums[i]%K;
    SegTree st(arrMod);
    vector<long long> ans;
    for(auto &qr: queries){
        int idx=qr[0], val=qr[1], start=qr[2], xi=qr[3];
        st.pointUpdate(idx, val%K);
        Node res = st.queryRange(start, (int)nums.size()-1);
        int startVal = (K==0?0:1%K);
        ans.push_back(res.M[startVal][xi]);
    }
    cout<<'[';
    for(size_t i=0;i<ans.size();++i){
        if(i) cout<<',';
        cout<<ans[i];
    }
    cout<<']';
    return 0;
}