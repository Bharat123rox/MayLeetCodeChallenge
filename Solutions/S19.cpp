class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    }

    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};