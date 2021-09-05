#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrix;
matrix.push_back()


struct Graph {
    int count_of_elements = 0;

    std::vector<std::vector<int>> matrix;
};


bool is_graph_directed(Graph* graph) {
    /*
    Проверяет, является ли граф направленным.
    */
    bool answer = false;

    for (int x = 0; x < graph->count_of_elements; x++) {
        for (int y = 0; y < graph->count_of_elements; y++) {
            if (graph->matrix.at(x).at(y) != graph->matrix.at(y).at(x)) {
                answer = true;
            }
        }
    }

    return answer;
}


void add_value(Graph* graph) { //TODo
    /*
        Добавляет новую вершину в граф.
        После применения попросит задать ЕЁ связи со всеми имеющимися вершинами по порядку щт первой до последней - без самой себя.
        Если таковой связи нет - введите -1;
        После чего задать связи ОТ ДРУГИХ ВЕРШИН к ней ( сучетом самой вершины ).
    */
    int current;
    std::vector<int> column;

    if (graph->count_of_elements != 0) {
        for (int i = 1; i < graph->count_of_elements; i++) {
            std::cin >> current;
        }
        graph->matrix.push_back()
    }
}
