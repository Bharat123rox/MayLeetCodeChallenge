int findComplement(int num) {
        int y = num;
        if(y == 1) return 0;
        int ct = 0, x = 0;
        while(y)
        {
            if(!(y & 1)) x += (1 << ct);
            ct++;
            y = y >> 1;
        }
        return x;
    }