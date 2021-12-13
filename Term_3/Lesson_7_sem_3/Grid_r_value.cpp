#include<iostream>


class Grid {
private:
    size_t x_size, y_size;


public:
    float *memory;

    Grid(size_t x_size, size_t y_size) : x_size(x_size), y_size(y_size) {
        memory = new float[x_size * y_size];
    }

    float operator()(size_t x_idx, size_t y_idx) const {
        float number = memory[x_idx + x_size * y_idx];
        return number;
    }

    float& operator()(size_t x_idx, size_t y_idx) {
        float &reference = memory[x_idx + x_size * y_idx];
        return reference;
    }

    size_t get_xsize() const {return x_size;}

    size_t get_ysize() const {return y_size;}

    Grid& operator=(float num) {
        for (int i = 0; i < x_size * y_size; i++) {
            memory[i] = num;
        }

        Grid &element = *this;
        return element;
    }

    Grid&& operator= (Grid& grid) {
        Grid&& gr = std::move(grid);

        return gr;
    }

    Grid&& operator+ (Grid grid_2) {
        for (int i = 0; i < x_size * y_size; i++) {
            memory[i] += grid_2.memory[i];
        }
        Grid&& grid_1 = std::move(grid_1);

        return grid_1;  // gm = j + l
    }

    friend std::ostream& operator<<(std::ostream& out, Grid const& grid){
        for (int i = 0; i < grid.y_size; i++) {
            for (int j = 0; j < grid.x_size; j++) {
                out << grid.memory[i * grid.y_size + j];
                out << "/n";
            }

        }
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Grid & grid){
        for (int i = 0; i < grid.x_size * grid.y_size; i++){
            in >> grid.memory[i];
        }

        return in;
    }


    ~Grid() {
        delete[] memory;
    }

};



int main() {
    Grid grid(2, 2);

    return 0;
}
