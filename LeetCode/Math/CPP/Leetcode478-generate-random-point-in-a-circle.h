class Solution
{
public:
    double x, y, r;
    Solution(double radius, double x_center, double y_center)
    {
        r = radius, x = x_center, y = y_center;
    }

    vector<double> randPoint()
    {
        double a = (double)rand() / RAND_MAX * 2 - 1;
        double b = (double)rand() / RAND_MAX * 2 - 1;
        if (a * a + b * b > 1)
            return randPoint();
        return {x + a * r, y + b * r};
    }
};