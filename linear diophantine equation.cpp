if we are given one linear equation and want to check in its solution exist or not:- 
Equation :- ax+by=c;
gcd(a,b)=g; so c%g==0 for the solution to exist. 


// Extented Eucliedian algorithm
if ax+by=g; then finding value of x and y so that they satisfy the given equation will be given by the
modified gcd function

int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
////////

using this concept only we would find the solution for the equation ax+by=c by multiplying both sides by g/c;
Ax+By=g; where A=a*g/c; B=b*g/c; and similarly finding the value of x and y using the above function

// Final code
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

////////////////

// For finding many solution
let k is a variable for different solution then:-
let (x0,y0) are the solution by using the above so now, we can generate different solution just by doing this;

(x,y)=(x0+k(b/g),y0-k(a/g)); by puting this will evalute to the same expression

/// For minimum value of (x+y) we can adjust the value of k:- 

if(a>b) then largest value of k and if(a<b) smallest value of k and if( a==b) then all solution will result to 
the same value,
we also need to see the range of x and y given in the question to select the value of k accordingly.

Helping website:- cp-algorithms.com

Theoram states that for any two relatively prime positive integers m,n, the greatest integer that cannot be 
written in the form a*m + b*n for nonnegative integers a, b is mn-m-n+1 or (m-1)*(n-1).