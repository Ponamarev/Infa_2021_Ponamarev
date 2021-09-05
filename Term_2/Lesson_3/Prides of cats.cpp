Cat* get_home_for_a_cats_pride(unsigned int n) {
    Cat* ptr_element = new Cat[n];

    return ptr_element[0];
}


void clear_home_of_a_cats_pride(Cat* cats, unsigned int n) {
    Cat* ptr_element cats;
    for (int i = 0; i < n; i++) {
        ptr_element++;
        delete[] cats;
        cats = ptr_element;
    }
}
