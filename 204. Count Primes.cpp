class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> notPrime(n, false);
        notPrime[0] = true, notPrime[1] = true;
        int cnt = 1;
        for(int i = 3; i < n; i += 2){
            if(notPrime[i]) continue;
            cnt++;
            if(i > sqrt(n)) continue;
            for(int j = i * i; j < n; j += i)
                notPrime[j] = true;
        }
        return cnt;
        
    }
};
