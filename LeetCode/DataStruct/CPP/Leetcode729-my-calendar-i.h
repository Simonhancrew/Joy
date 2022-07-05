/*
    动态开点线段树
*/
class segtree
{
public:
    segtree(int st, int ed) : l(st), r(ed), lhs(nullptr), rhs(nullptr), val(0), tag(0) {}
    void pushdown()
    {
        int mid = l + r >> 1;
        if (!lhs)
            lhs = new segtree(l, mid);
        if (!rhs)
            rhs = new segtree(mid + 1, r);
        if (tag)
        {
            lhs->val += (mid - l + 1) * tag;
            rhs->val += (r - mid) * tag;
            lhs->tag = tag;
            rhs->tag = tag;
            tag = 0;
        }
    }

    bool query(int L, int R)
    {
        if (l >= L && r <= R)
        {
            return val;
        }
        pushdown();
        int mid = l + r >> 1;
        int flag = 0;
        if (mid >= L)
            flag += lhs->query(L, R);
        if (mid < R)
            flag += rhs->query(L, R);
        return flag;
    }
    void pushup()
    {
        val = lhs->val + rhs->val;
    }
    void add(int L, int R)
    {
        if (l >= L && r <= R)
        {
            val += (r - l + 1) * 1;
            tag += 1;
        }
        else
        {
            pushdown();
            int mid = l + r >> 1;
            if (mid >= L)
                lhs->add(L, R);
            if (mid < R)
                rhs->add(L, R);
            pushup();
        }
    }
    segtree *lhs, *rhs;
    int l, r;
    int val;
    int tag;
};
class MyCalendar
{
public:
    segtree *tr;
    MyCalendar()
    {
        tr = new segtree(0, 1e9);
    }

    bool book(int start, int end)
    {
        if (tr->query(start, end - 1))
            return false;
        tr->add(start, end - 1);
        return true;
    }
};