class Solution:
    # Has some issues with integer overflow in C++
    def isPerfectSquare(self, num: int) -> bool:
        if(num == 1):
            return True
        else:
            b = 1
            l = num
            while (b <= l):
                m = b + (l - b) // 2
                if m * m == num:
                    return True
                elif m * m < num and (m+1)*(m+1) > num:
                    return False
                elif m * m < num:
                    b = m + 1
                else:
                    l = m - 1