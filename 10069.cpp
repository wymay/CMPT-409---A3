#include <iostream>
#include <cstring>
#include <iomanip> 
#include <algorithm> 
#include <vector>

using namespace std;

#define MAXN 9999
#define DLEN 4

class BigNum {
private:
    int a[300];
    int len;
public:
    BigNum(){ len = 1; memset(a,0,sizeof(a)); }   
    BigNum(const int);      
    BigNum(const BigNum &);
    BigNum &operator=(const BigNum &); 

    friend ostream& operator<<(ostream&,  BigNum&);

    BigNum operator+(const BigNum &) const;
};

BigNum::BigNum(const int b)    
{ 
    int c,d = b;
    len = 0;
    memset(a,0,sizeof(a));
    while(d > MAXN)
    {
        c = d - (d / (MAXN + 1)) * (MAXN + 1); 
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}

BigNum::BigNum(const BigNum & T) : len(T.len) 
{  
    int i; 
    memset(a,0,sizeof(a)); 
    for(i = 0 ; i < len ; i++)
        a[i] = T.a[i]; 
}

BigNum & BigNum::operator=(const BigNum & n)  
{
    int i;
    len = n.len;
    memset(a,0,sizeof(a)); 
    for(i = 0 ; i < len ; i++) 
        a[i] = n.a[i]; 
    return *this; 
}

ostream& operator<<(ostream& out,  BigNum& b)   
{
    int i;  
    cout << b.a[b.len - 1]; 
    for(i = b.len - 2 ; i >= 0 ; i--)
    {   
        cout.width(DLEN); 
        cout.fill('0'); 
        cout << b.a[i]; 
    } 
    return out;
}

BigNum BigNum::operator+(const BigNum & T) const   
{
    BigNum t(*this);
    int i,big;     
    big = T.len > len ? T.len : len; 
    for(i = 0 ; i < big ; i++) 
    { 
        t.a[i] +=T.a[i]; 
        if(t.a[i] > MAXN) 
        { 
            t.a[i + 1]++; 
            t.a[i] -=MAXN+1; 
        } 
    } 
    if(t.a[big] != 0)
        t.len = big + 1; 
    else
        t.len = big;   
    return t;
}

int main()
{
    vector<BigNum> temp(10000),result(10000);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string X;
        string Z;
        cin >> X >> Z;
        int size_X = X.size();
        int size_Z = Z.size();

        for( int i = 0; i < size_X; i++){
            if( X[i] == Z[0] ){
                temp[i] = i == 0 ? 1 : temp[i-1] + 1;
            }
            else{
                temp[i] = i == 0 ? 0 : temp[i-1];
            }
        }
        for( int i = 1; i < size_Z; i++ ){
            result[i-1] = 0;
            for( int j = i; j < size_X; j++ ){
                result[j] = X[j] == Z[i] ? temp[j-1]+result[j-1] : result[j-1];
            }
            temp = result;
        }
        cout << result[size_X-1];
        cout << endl;
    }

    return 0;
}