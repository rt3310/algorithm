    for (int i = 1; i <= k; i++) {
        if (state[r][c][0] & (1 << i)) {
            unit[i][0] = nr;
            unit[i][1] = nc;
        }
    }