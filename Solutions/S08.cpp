bool check(vector<int> co, int m, int c) {
    if (co[1] == m * co[0] + c)
        return true;
    return false;
}

bool checkStraightLine(vector<vector<int>>& coordinates) {
    if(coordinates.size() == 2) return true; //2 points always lie on a straight line

    // If the x differs, then there is a finite slope, so we can proceed to calculate it
    else if(coordinates[1][0] != coordinates[0][0])
    {
        int m =  (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        int c = coordinates[0][1] - m * coordinates[0][0];
        for(int i = 2; i < coordinates.size(); i++)
        {
            if(!check(coordinates[i], m, c)) return false;
        }
        return true;
    }

    // To handle x = k (x is a constant, hence infinite slope) cases
    else
    {
        int ans = coordinates[0][0];
        for(int i = 2; i < coordinates.size(); i++)
        {
            if(coordinates[i][0] != ans) return false;
        }
        return true;
    }
}