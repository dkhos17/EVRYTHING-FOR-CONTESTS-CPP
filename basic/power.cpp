long long power(long long x, unsigned int y) { 
    ll p = 1;
    while (y > 0) { 
        if (y & 1) p = p * x; 
        y = y >> 1; 
        x = x * x;
    }
    return p; 
} 