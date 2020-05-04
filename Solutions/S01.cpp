int firstBadVersion(int n) {
        int mid = 1, beg = 1, last = n;
        while(beg < last) {
            mid = beg + (last - beg) / 2;
            if(isBadVersion(mid)) {
                last = mid;
            } else {
                beg = mid + 1;
            }
        }
        if(beg == last) return last; 
        return mid;
    }