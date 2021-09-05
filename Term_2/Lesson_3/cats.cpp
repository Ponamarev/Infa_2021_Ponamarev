unsigned int count_total_mice_amount(Cat* cats, unsigned int n) {
    int mice = 0;

    for (int i = 0; i < n; i++) {
        mice += cats[i].mice_caught;
    }

    return mice;
}
