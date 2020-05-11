//Utility to actually flood fill the 2D matrix
void floodFillUtil(vector<vector<int>>& image, int sr, int sc, int m, int n, int prevColor, int newColor) {
    if(sr < 0 || sr >= m || sc < 0 || sc >= n) return;
    else if(image[sr][sc] == newColor || image[sr][sc] != prevColor) return;
    image[sr][sc] = newColor;
    floodFillUtil(image, sr - 1, sc, m, n, prevColor, newColor);
    floodFillUtil(image, sr + 1, sc, m, n, prevColor, newColor);
    floodFillUtil(image, sr, sc - 1, m, n, prevColor, newColor);
    floodFillUtil(image, sr, sc + 1, m, n, prevColor, newColor);
}

//Wrapper function
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int prevColor = image[sr][sc];
    int m = image.size();
    int n = image[0].size();
    floodFillUtil(image, sr, sc, m, n, prevColor, newColor);
    return image;
}