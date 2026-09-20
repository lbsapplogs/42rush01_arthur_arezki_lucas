int counting_visible_from_left(int row[4], int count, int maxh)
{
    int count;
    int maxh;
    int i;

    count = 0;
    maxh = 0;
    int i = 0;
    while (i < 4)
    {
        if (row[i] > maxh)
        {
            maxh = row[i];
            count++;
        }
        i++;
    }
    return count;
}

int counting_visible_from_right(int row[4], int count, int maxh)
{
    int count;
    int maxh;
    int i;

    count = 0;
    maxh = 0;
    int i = 3;
    while (i >= 0)
    {
        if (row[i] > maxh)
        {
            maxh = row[i];
            count++;
        }
        i--;
    }
    return count;
}

int counting_visible_from_top(int grid[4][4], int count, int maxh)
{
    int count;
    int maxh;
    int i;

    count = 0;
    maxh = 0;
    int i = 0;
    while (i < 4)
    {
        if (grid[i][col] > maxh)
        {
            maxh = grid[i][col];
            count++;
        }
        i++;
    }
    return count;
}

int counting_visible_from_bottom(int grid[4][4], int count, int maxh)
{
    int count;
    int maxh;
    int i;

    count = 0;
    maxh = 0;
    int i = 3;
    while (i >= 0)
    {
        if (grid[i][col] > maxh)
        {
            maxh = grid[i][col];
            count++;
        }
        i--;
    }
    return count;
}